/**
 * @file simple_sprite.c
 * 
 * @brief Demonstrates the use of a simple sprite with the NES API.
 * 
 * This program creates a single sprite and displays it on the screen.
 * The sprite's position and appearance are defined during initialization.
 */

#include "LIB/nesc.h"
#pragma bss-name(push, "ZEROPAGE")

// Define a simple sprite with tile ID 0x00 and no flipping
Sprite spr = {0x00, NO_FLIP};

void main(void) {
	// Add the sprite to the screen at position (30, 70)
	ISprite* sp = sprite_add(30, 70, &spr);

    INIT();

	// Load a colorful sprite palette
	load_palette(PALETTE_SPRITE, &PALETTE_COLORFUL);

	while (1) {
		START();

		// Draw the sprite
		draw(sp);

		END();
	}
}
