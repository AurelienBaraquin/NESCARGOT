/**
 * @file inputs.c
 * 
 * @brief Demonstrates handling input from two NES controllers to move sprites on the screen.
 * 
 * This program maps the D-pad inputs from two controllers (PAD1 and PAD2) to control the positions of two sprites.
 * Each controller can move its assigned sprite independently in four directions.
 */

#include "LIB/nesc.h"
#pragma bss-name(push, "ZEROPAGE")

// Define a single-tile sprite for demonstration
Sprite spr = {0x00, NO_FLIP};

void main(void) {
	// Add two sprites to be controlled by PAD1 and PAD2
	ISprite* sp1 = sprite_add(30, 70, &spr); // Controlled by PAD1
	ISprite* sp2 = sprite_add(40, 60, &spr); // Controlled by PAD2

    INIT();

	// Load a colorful sprite palette
	load_palette(PALETTE_SPRITE, &PALETTE_COLORFUL);

	while (1) {
		START();

		// Handle input for the first controller (PAD1)
		if (PAD1.is_pressed(NESC_PAD_UP)) {
			sp1->y--; // Move sprite 1 up
		}
		if (PAD1.is_pressed(NESC_PAD_DOWN)) {
			sp1->y++; // Move sprite 1 down
		}
		if (PAD1.is_pressed(NESC_PAD_LEFT)) {
			sp1->x--; // Move sprite 1 left
		}
		if (PAD1.is_pressed(NESC_PAD_RIGHT)) {
			sp1->x++; // Move sprite 1 right
		}

		// Handle input for the second controller (PAD2)
		if (PAD2.is_pressed(NESC_PAD_UP)) {
			sp2->y--; // Move sprite 2 up
		}
		if (PAD2.is_pressed(NESC_PAD_DOWN)) {
			sp2->y++; // Move sprite 2 down
		}
		if (PAD2.is_pressed(NESC_PAD_LEFT)) {
			sp2->x--; // Move sprite 2 left
		}
		if (PAD2.is_pressed(NESC_PAD_RIGHT)) {
			sp2->x++; // Move sprite 2 right
		}

		// Draw the sprites on the screen
		draw(sp1);
		draw(sp2);

		END();
	}
}
