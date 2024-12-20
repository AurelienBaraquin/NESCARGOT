#include "LIB/nesc.h"
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

void main(void) {
	ISprite* sp1 = sprite_add(10, 10, &spr);
	ISprite* sp2 = sprite_add(20, 10, &spr);
	ISprite* metasprite = metasprite_add(40, 10, &met);

	ppu_off();

	load_palette(PALETTE_BG, PALETTE_GRAY);
	load_palette(PALETTE_SPRITE, PALETTE_COLORFUL);

	bank_spr(1);
	index(10, 10);
	write("Coucou\nHello\n");

	ppu_on_all();

	while (1) {
		start();

		if (PAD1.is_pressed(NESC_PAD_LEFT)) {
			sp1->x--;
		}
		if (PAD1.is_pressed(NESC_PAD_RIGHT)) {
			sp1->x++;
		}
		if (PAD1.is_pressed(NESC_PAD_UP)) {
			sp1->y--;
		}
		if (PAD1.is_pressed(NESC_PAD_DOWN)) {
			sp1->y++;
		}

		if (PAD2.is_pressed(NESC_PAD_LEFT)) {
			sp2->x--;
		}
		if (PAD2.is_pressed(NESC_PAD_RIGHT)) {
			sp2->x++;
		}
		if (PAD2.is_pressed(NESC_PAD_UP)) {
			sp2->y--;
		}
		if (PAD2.is_pressed(NESC_PAD_DOWN)) {
			sp2->y++;
		}

		draw(metasprite);
		metasprite->x++;
		draw(sp1);
		draw(sp2);

		end();
	}
}
