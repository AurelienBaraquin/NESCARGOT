/**
 * @file collision_detection.c
 * 
 * @brief Demonstrates sprite-to-sprite collision detection using bounding boxes.
 * 
 * This program creates two sprites and detects when they collide. The background color changes
 * to indicate whether a collision has occurred. The first sprite is controlled by the first controller (PAD1).
 */

#include "LIB/nesc.h"
#include "main.h"
#pragma bss-name(push, "ZEROPAGE")

// Define a simple sprite
Sprite spr = {0x00, NO_FLIP};

void main(void) {
	// Create two sprites with their initial positions
	ISprite* sp1 = sprite_add(30, 70, &spr); // Controlled by PAD1
	ISprite* sp2 = sprite_add(40, 60, &spr); // Stationary sprite

    INIT();

	// Load a colorful background palette
	load_palette(PALETTE_BG, &PALETTE_COLORFUL);

	while (1) {
		START();

        // Check for collision between the two sprites
        if (is_colliding(sp1, sp2)) {
            set_palette_color(0, YELLOW); // Change background color to yellow on collision (by default, the index 0 is the background color)
        } else {
			set_palette_color(0, RED); // Change background color to red when no collision (by default, the index 0 is the background color)
		}

		// Handle input for controlling the first sprite
		if (PAD1.is_pressed(NESC_PAD_UP)) {
			sp1->y--;
		}
		if (PAD1.is_pressed(NESC_PAD_DOWN)) {
			sp1->y++;
		}
		if (PAD1.is_pressed(NESC_PAD_LEFT)) {
			sp1->x--;
		}
		if (PAD1.is_pressed(NESC_PAD_RIGHT)) {
			sp1->x++;
		}

		// Draw the sprites on the screen
		draw(sp1);
		draw(sp2);

		END();
	}
}
