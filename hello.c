#include "LIB/nesc.h"
#pragma bss-name(push, "ZEROPAGE")

const char text[] = "Hello World!";
const Color text_colors[] = {RED, GREEN, BLUE, YELLOW, MAGENTA, WHITE, CYAN, GREEN, ORANGE, LIGHT_RED, DARK_BLUE, LIGHT_BLUE};	

void main(void) {
	ppu_off();

	load_palette(PALETTE_BG, PALETTE_COLORFUL);
	index(index_x(), index_y());
	write("Coucou\npopo");

	ppu_on_all();

	while (1){
	}
}
