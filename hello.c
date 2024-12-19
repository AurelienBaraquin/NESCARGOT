#include "LIB/nesc.h"
#pragma bss-name(push, "ZEROPAGE")

void main(void) {
	ISprite* sprite = sprite_add(10, 10, 0x00, NO_FLIP);

	ppu_off();

	load_palette(PALETTE_BG, PALETTE_GRAY);
	load_palette(PALETTE_SPRITE, PALETTE_COLORFUL);

	bank_spr(1);
	index(10, 1);
	write("Coucou\nHello\n");

	ppu_on_all();

	while (1) {
		ppu_wait_nmi();

		draw_sprites();

		// sprite->x++;
	}
}
