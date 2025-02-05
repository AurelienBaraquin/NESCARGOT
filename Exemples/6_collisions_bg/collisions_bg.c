/**
 * @file collision_bg.c
 * 
 * @brief Demonstrates collision detection between a sprite and a background map.
 * 
 * This program initializes a background map and a sprite. The sprite can move around using the first controller (PAD1). 
 * When the sprite collides with specific tiles in the background, it is slightly repelled in the opposite direction, 
 * simulating basic collision response.
 */

#include "LIB/nesc.h"
#include "CSV/map.c"
#pragma bss-name(push, "ZEROPAGE")

// Define a simple sprite
Sprite spr = {0x00, NO_FLIP};

// Tile definitions for the map
CSVTile tiles[] = {
	{0, 0, 0}, // Empty tile
	{1, 0, 1}, // Solid tile
	CSV_END
};

void main(void) {
	// Add a sprite to the screen
	ISprite* sp = sprite_add(30, 70, &spr);
    Box box;
    CollisionResult result;
	char px, py, p;
	char x, y;

    INIT();

	// Load background and sprite palettes
	load_palette(PALETTE_BG, &PALETTE_GRAY);
	load_palette(PALETTE_SPRITE, &PALETTE_COLORFUL);

	// Draw the background map
	BG_DRAW(px, py, p, 2, 2,
		index(px, py);
		PUT(get_map_tile(map[p], tiles));
		PUT(get_map_tile(map[p], tiles));
		index(px, py + 1);
		PUT(get_map_tile(map[p], tiles));
		PUT(get_map_tile(map[p], tiles));
	);

	while (1) {
		// Reset collision response deltas
		x = 0;
		y = 0;

		START();

		// Update the sprite's bounding box
		sp->box(sp, &box);

		// Handle input for moving the sprite
		if (PAD1.is_pressed(NESC_PAD_UP)) {
			sp->y--;
		}
		if (PAD1.is_pressed(NESC_PAD_DOWN)) {
			sp->y++;
		}
		if (PAD1.is_pressed(NESC_PAD_LEFT)) {
			sp->x--;
		}
		if (PAD1.is_pressed(NESC_PAD_RIGHT)) {
			sp->x++;
		}

		// Check for collisions with the background
		check_collision_bg(&box, map, &result);

		// Apply collision response based on results
		if (result.ul != 0) { // Upper-left collision
			x += 1;
			y += 1;
		}
		if (result.dl != 0) { // Lower-left collision
			x += 1;
			y -= 1;
		}
		if (result.ur != 0) { // Upper-right collision
			x -= 1;
			y += 1;
		}
		if (result.dr != 0) { // Lower-right collision
			x -= 1;
			y -= 1;
		}

		// Apply the calculated deltas to the sprite's position
		x > 0 ? sp->x += 1 : 0;
		y > 0 ? sp->y += 1 : 0;
		x < 0 ? sp->x -= 1 : 0;
		y < 0 ? sp->y -= 1 : 0;

		// Draw the sprite on the screen
		draw(sp);

		END();
	}
}
