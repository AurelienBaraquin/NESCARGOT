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

unsigned char tmp;

void put_nbr(unsigned char n, unsigned char x, unsigned char y) {
	unsigned char i = 0;
	unsigned char digits[3] = {0, 0, 0};

	while (n > 0) {
		digits[i++] = n % 10;
		n /= 10;
	}
	one_vram_buffer(digits[2] + '0', NTADR_A(x++, y));
	one_vram_buffer(digits[1] + '0', NTADR_A(x++, y));
	one_vram_buffer(digits[0] + '0', NTADR_A(x++, y));
}

void main(void) {
	ISprite* sp1 = sprite_add(30, 70, &spr);
	ISprite* sp2 = metasprite_add(40, 60, &met);
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

	set_vram_buffer();

	while (1) {
		START();

		put('0', 1, 1);
		put('0', 2, 1);
		put('0', 3, 1);

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
		if (result.ul != 0 && result.ur != 0) {
			map[POS_TO_MAP(box.x, box.y, 16)] = 0;
			// map[POS_TO_MAP(box.x + 1, box.y, 16)] = 0;
			// map[POS_TO_MAP(box.x, box.y + 1, 16)] = 0;
			// map[POS_TO_MAP(box.x + 1, box.y + 1, 16)] = 0;

			put('0', DIVIDE(box.x, 8), DIVIDE(box.y, 8));
			// put('0', box.x / 8 + 1, box.y / 8);
			// put('0', box.x / 8, box.y / 8 + 1);
			// put('0', box.x / 8 + 1, box.y / 8 + 1);

			put_nbr(POS_TO_MAP(box.x, box.y, 16), 1, 1);
		}
		// if (result.dl != 0) {
		// 	sp1->y--;
		// 	sp1->x++;
		// }
		// if (result.dr != 0) {
		// 	sp1->y--;
		// 	sp1->x--;
		// }

		draw(sp1);
		draw(sp2);

		END();
	}
}
