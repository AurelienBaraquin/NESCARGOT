#ifndef __NESC_TEXT_H__
#define __NESC_TEXT_H__

#include "ESSENTIAL/nesc_ess.h"
#include "index.h"

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
