#ifndef __NESC_INDEX_H__
#define __NESC_INDEX_H__

#include "ESSENTIAL/nesc_ess.h"

/**
 * @brief Get the current VRAM address.
 * 
 * @return int VRAM address.
 */
#define index_x() (_ppu_addr(1, 0, 0))

/**
 * @brief Get the current VRAM address.
 * 
 * @return int VRAM address.
 */
#define index_y() (_ppu_addr(2, 0, 0))

/**
 * @brief Set the VRAM address to the specified tile position.
 * 
 * @param x X coordinate (tile position 0-31).
 * @param y Y coordinate (tile position 0-29).
 */
void index(int x, int y) {
    vram_adr(NTADR_A(x, y));
    _ppu_addr(0, x, y);
}

#endif
