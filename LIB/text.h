#ifndef __NESC_TEXT_H__
#define __NESC_TEXT_H__

#include "ESSENTIAL/nesc_ess.h"
#include "index.h"

/**
 * @brief Write a character to the screen.
 * 
 * @param tile_x chr tile position x.
 * @param tile_y chr tile position y. 4 - 5
 */
static inline void put(unsigned char tile_x, unsigned char tile_y) {
    vram_put(tile_y * 16 + tile_x);
}

/**
 * @brief Write a string of text to the screen.
 * 
 * @param x X coordinate (tile position 0-31).
 * @param y Y coordinate (tile position 0-29).
 * @param text Pointer to the text string (null-terminated).
 */
static inline void write(const char* text) {
    unsigned char i;
    unsigned char x = index_x();
    unsigned char y = index_y();

    for (i = 0; text[i] != '\0'; ++i) {
        if (text[i] == '\n') {
            y++;
            index(x, y);
        } else {
            vram_put(text[i]);
        }
    }
}

#endif
