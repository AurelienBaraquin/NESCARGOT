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
	{1, 0, 1}
};

void main(void) {
	ISprite* sp1 = sprite_add(50, 50, &spr);
	ISprite* sp2 = sprite_add(20, 10, &spr);
	ISprite* metasprite = metasprite_add(40, 10, &met);
	unsigned char px, py, p;

	ppu_off();

	load_palette(PALETTE_BG, &PALETTE_GRAY);
	load_palette(PALETTE_SPRITE, &PALETTE_COLORFUL);

	bank_spr(1);

	BG_DRAW(px, py, p, 2, 2,
		index(px, py);
		vram_put(_get_map_tile(map[p], tiles, 2));
		vram_put(_get_map_tile(map[p], tiles, 2));
		index(px, py + 1);
		vram_put(_get_map_tile(map[p], tiles, 2));
		vram_put(_get_map_tile(map[p], tiles, 2));
	);

	ppu_on_all();

	while (1) {
		start();

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

		draw(metasprite);
		metasprite->x++;
		draw(sp1);
		draw(sp2);

		end();
	}
}
