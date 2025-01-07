#include "LIB/nesc.h"
#pragma bss-name(push, "ZEROPAGE")

Sprite spr = {0x00, NO_FLIP};

void main(void) {
	ISprite* sp = sprite_add(30, 70, &spr);

    INIT();

	load_palette(PALETTE_BG, &PALETTE_GRAY);
	load_palette(PALETTE_SPRITE, &PALETTE_COLORFUL);

	while (1) {
		START();
		draw(sp);
		END();
	}
}
