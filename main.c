#include "LIB/nesc.h"
#include "main.h"
#pragma bss-name(push, "ZEROPAGE")

Metasprite met = {
	{
		{0, 0, 0x01, NO_FLIP},
		{0, 8, 0x11, NO_FLIP},
		{8, 0, 0x01, FLIP_H},
		{8, 8, 0x11, FLIP_H},
		MET_STOP
	}
};

Sprite spr = {0x00, NO_FLIP};

CSVTile tiles[] = {
	{0, 0, 0},
	{1, 0, 1},
	CSV_END
};

void main(void) {
	ISprite* sp1 = sprite_add(20, 10, &spr);
	ISprite* sp2 = metasprite_add(40, 50, &met);
	Box box;
	CollisionResult result;
	unsigned char px, py, p;

	ppu_off();

	load_palette(PALETTE_BG, &PALETTE_GRAY);
	load_palette(PALETTE_SPRITE, &PALETTE_COLORFUL);

	bank_spr(1);

	BG_DRAW(px, py, p, 2, 2,
		index(px, py);
		PUT(get_map_tile(map[p], tiles));
		PUT(get_map_tile(map[p], tiles));
		index(px, py + 1);
		PUT(get_map_tile(map[p], tiles));
		PUT(get_map_tile(map[p], tiles));
	);

	ppu_on_all();

	while (1) {
		START();

		sp1->box(sp1, &box);

		if (PAD1.is_pressed(NESC_PAD_UP)) {
			sp1->y--;
		}
		if (PAD1.is_pressed(NESC_PAD_DOWN)) {
			sp1->y++;
		}
		if (PAD1.is_pressed(NESC_PAD_LEFT)) {
			sp1->x--;
		}
		if (PAD1.is_pressed(NESC_PAD_RIGHT)) {
			sp1->x++;
		}

		check_collision_bg(&box, map, &result);
		if (result.ul != 0) {
			sp1->y++;
			sp1->x++;
		}
		if (result.ur != 0) {
			sp1->y++;	
			sp1->x--;
		}
		if (result.dl != 0) {
			sp1->y--;
			sp1->x++;
		}
		if (result.dr != 0) {
			sp1->y--;
			sp1->x--;
		}

		draw(sp1);
		draw(sp2);

		END();
	}
}
