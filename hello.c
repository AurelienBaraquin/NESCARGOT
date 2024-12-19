#include "LIB/nesc.h"
#pragma bss-name(push, "ZEROPAGE")

void main(void) {
	SpriteEntity* sprite = NULL;

	ppu_off();

	load_palette(PALETTE_BG, PALETTE_GRAY);
	load_palette(PALETTE_SPRITE, PALETTE_COLORFUL);

	bank_spr(1);
	index(10, 1);
	write("Coucou\nHello\n");

	sprite_manager_init();

	ppu_on_all();

	sprite = sprite_add(10, 10, 0x00, 0);

	while (1){
		ppu_wait_nmi();

		sprite_draw_all();

		sprite->x++;
	}
}
