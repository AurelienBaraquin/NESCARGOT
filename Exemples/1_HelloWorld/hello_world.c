/**
 * @file hello_world.c
 * 
 * @brief Demonstrates basic text rendering with the NES API.
 * 
 * This program initializes the NES and displays the text "Hello World!" on the screen.
 * It also demonstrates the use of `put_str` for multi-character strings and `put` for individual characters 
 * to specific positions on the screen. The screen is updated in a continuous loop.
 */

#include "LIB/nesc.h"
#pragma bss-name(push, "ZEROPAGE")

void main(void) {
    // Initialize NES hardware and API
    INIT();

    // Load a grayscale background palette
    load_palette(PALETTE_BG, &PALETTE_GRAY);

    while (1) {
        // Begin the rendering frame
        START();

        // Display "Hello World!" at position (10, 10) on the screen
        put_str("Hello\nWorld!", 10, 10);

        // Display the character 'A' at position (10, 20)
        put('A', 10, 20);

        // Display the character 'X' at position (1, 2)
        put('X', 1, 2);

        // End the rendering frame and synchronize with the PPU
        END();
    }
}
