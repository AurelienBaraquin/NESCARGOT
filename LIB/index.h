#ifndef __NESC_INDEX_H__
#define __NESC_INDEX_H__

#include "ESSENTIAL/nesapi.h"

/**
 * @brief Get the current VRAM address.
 * 
 * @return int VRAM address.
 */
unsigned char index_x() {
    return _ppu_addr(1, 0, 0);
}

/**
 * @brief Get the current VRAM address.
 * 
 * @return int VRAM address.
 */
unsigned char index_y() {
    return _ppu_addr(2, 0, 0);
}

/**
 * @brief Set the VRAM address to the specified tile position.
 * 
 * @param x X coordinate (tile position 0-31).
 * @param y Y coordinate (tile position 0-29).
 */
void index(unsigned char x, unsigned char y) {
    if (x > 31 || y > 29) return;
    vram_adr(NTADR_A(x, y));
    _ppu_addr(0, x, y);
}

#endif
