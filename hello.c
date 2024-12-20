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
	ISprite* sprite = sprite_add(10, 10, &spr);
	ISprite* metasprite = metasprite_add(40, 10, &met);
	unsigned char i, j;

	ppu_off();

	load_palette(PALETTE_BG, PALETTE_GRAY);
	load_palette(PALETTE_SPRITE, PALETTE_COLORFUL);

	bank_spr(1);
	index(10, 10);
	write("Coucou\nHello\n");

	ppu_on_all();

	while (1) {
		start_drawing();

		draw(metasprite);
		metasprite->x++;
		draw(sprite);
		sprite->y += 10;
		draw(sprite);
		sprite->y -= 10;
		sprite->x++;

		end_drawing();
	}
}
