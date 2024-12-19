#include "LIB/nesc.h"
#pragma bss-name(push, "ZEROPAGE")

void main(void) {
	ppu_off();

	load_palette(PALETTE_BG, PALETTE_COLORFUL);
	index(10, 1);
	write("Coucou\npopo");

	ppu_on_all();

	while (1){
	}
}
