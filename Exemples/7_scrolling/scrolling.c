/**
 * @file scrolling.c
 * 
 * @brief Demonstrates basic background scrolling in response to user input.
 * 
 * This program initializes a background map and allows the player to scroll the view
 * horizontally and vertically using the NES controller. The scrolling is achieved by
 * modifying the NES hardware scroll registers, creating a seamless movement effect.
 */

#include "LIB/nesc.h"
#include "CSV/map.c"
#pragma bss-name(push, "ZEROPAGE")

// Tile definitions for the map
CSVTile tiles[] = {
	{0, 0, 0}, // Empty tile
	{1, 0, 1}, // Solid tile
	CSV_END
};

void main(void) {
	char px, py, p;

    INIT();

	// Load the palettes for the background and sprites
	load_palette(PALETTE_BG, &PALETTE_GRAY);
	load_palette(PALETTE_SPRITE, &PALETTE_COLORFUL);

	// Draw the background map to the screen
	BG_DRAW(px, py, p, 2, 2,
		index(px, py);
		PUT(get_map_tile(map[p], tiles));
		PUT(get_map_tile(map[p], tiles));
		index(px, py + 1);
		PUT(get_map_tile(map[p], tiles));
		PUT(get_map_tile(map[p], tiles));
	);

	while (1) {
		START();

		// Handle user input for scrolling the background
		if (PAD1.is_pressed(NESC_PAD_UP)) {
			scroll_y_add(-1); // Scroll up
		}
		if (PAD1.is_pressed(NESC_PAD_DOWN)) {
			scroll_y_add(1); // Scroll down
		}
		if (PAD1.is_pressed(NESC_PAD_LEFT)) {
			scroll_x_add(-1); // Scroll left
		}
		if (PAD1.is_pressed(NESC_PAD_RIGHT)) {
			scroll_x_add(1); // Scroll right
		}

		END();
	}
}
