#ifndef __NESC_TEXT_H__
#define __NESC_TEXT_H__

#include "ESSENTIAL/nesc_ess.h"

static inline void put(unsigned char c) {
    vram_put(c);
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

    for (i = 0; text[i] != '\0'; ++i)
        put(text[i]);
}

#endif
