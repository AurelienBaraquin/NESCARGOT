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

void main(void) {
	ISprite* sp = metasprite_add(40, 60, &met);

    INIT();

	load_palette(PALETTE_SPRITE, &PALETTE_COLORFUL);

	while (1) {
		START();
		draw(sp);
		END();
	}
}
