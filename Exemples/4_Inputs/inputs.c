#include "LIB/nesc.h"
#include "main.h"
#pragma bss-name(push, "ZEROPAGE")

Sprite spr = {0x00, NO_FLIP};

void main(void) {
	ISprite* sp = sprite_add(30, 70, &spr);

    INIT();

	load_palette(PALETTE_SPRITE, &PALETTE_COLORFUL);

	while (1) {
		START();

		if (PAD1.is_pressed(NESC_PAD_UP)) {
			sp->y--;
		}
		if (PAD1.is_pressed(NESC_PAD_DOWN)) {
			sp->y++;
		}
		if (PAD1.is_pressed(NESC_PAD_LEFT)) {
			sp->x--;
		}
		if (PAD1.is_pressed(NESC_PAD_RIGHT)) {
			sp->x++;
		}

		draw(sp);
		END();
	}
}
