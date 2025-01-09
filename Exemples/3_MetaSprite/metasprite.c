/**
 * @file metasprite.c
 * 
 * @brief Demonstrates the use of metasprites with the NES API.
 * 
 * This program creates a metasprite composed of multiple tiles and displays it on the screen.
 * A metasprite is a composite of smaller sprites arranged in a specific layout, useful for creating larger or more complex characters.
 */

#include "LIB/nesc.h"
#pragma bss-name(push, "ZEROPAGE")

// Define a metasprite composed of 4 tiles arranged in a 2x2 grid
Metasprite met = {
	{
		{0, 0, 0x01, NO_FLIP},   // Top-left tile
		{0, 8, 0x11, NO_FLIP},   // Bottom-left tile
		{8, 0, 0x01, FLIP_H},    // Top-right tile (horizontally flipped)
		{8, 8, 0x11, FLIP_H},    // Bottom-right tile (horizontally flipped)
		MET_STOP                 // Terminates the metasprite
	}
};

void main(void) {
	// Add the metasprite to the screen at position (40, 60)
	ISprite* sp = metasprite_add(40, 60, &met);

    INIT();

	// Load a colorful sprite palette
	load_palette(PALETTE_SPRITE, &PALETTE_COLORFUL);

	while (1) {
		START();

		// Draw the metasprite
		draw(sp);

		END();
	}
}
