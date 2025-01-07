#include "LIB/nesc.h"
#pragma bss-name(push, "ZEROPAGE")

void main(void) {
    INIT();

	load_palette(PALETTE_BG, &PALETTE_GRAY);

	while (1) {
        START();
        put_str("Hello\nWorld!", 10, 10);
        put('A', 10, 20);
        put('X', 1, 2);
        END();
    }
}
