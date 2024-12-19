#ifndef __NESC_COLOR_H__
#define __NESC_COLOR_H__

#include "ESSENTIAL/nesc_ess.h"

// NES uses a 64-color palette (0x00 to 0x3F)
// 0x0F is black, 0x30 is white (important: don't use other values for black and white)

#include "colors_enum.h"

// Palette types
typedef enum {
    PALETTE_BG,      // Background palette ($3F00-$3F0F)
    PALETTE_SPRITE   // Sprite palette ($3F10-$3F1F)
} PaletteType;

// Example BG palette: grayscale (white, light gray, dark gray, black)
static const char PALETTE_GRAY[] = {
    BLACK, LIGHT_GRAY, DARK_GRAY, WHITE,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
};

// Example SPRITE palette: transparent, red, blue, green
static const char PALETTE_COLORFUL[] = {
    BLACK, RED, BLUE, GREEN,
    BLACK, BLACK, YELLOW, WHITE,
    0, 0, 0, 0,
    0, 0, 0, 0
};

/**
 * @brief Load a full 16-color palette for either BG or SPRITES.
 * 
 * @param type Palette type (PALETTE_BG or PALETTE_SPRITE).
 * @param palette Pointer to a 16-byte array defining the palette.
 */
static inline void load_palette(PaletteType type, const char* palette) {
    if (type == PALETTE_BG) {
        pal_bg(palette);
    } else if (type == PALETTE_SPRITE) {
        pal_spr(palette);
    }
}

/**
 * @brief Change a specific color in the palette.
 * 
 * @param index Color index (0x00 to 0x1F).
 * @param color New color value (0x00 to 0x3F).
 */
static inline void set_palette_color(unsigned char index, Color color) {
    pal_col(index, color);
}

/**
 * @brief Reset palettes to default (black for all colors).
 */
static inline void reset_palettes() {
    const char default_palette[16] = {
        BLACK, BLACK, BLACK, BLACK,
        BLACK, BLACK, BLACK, BLACK,
        BLACK, BLACK, BLACK, BLACK,
        BLACK, BLACK, BLACK, BLACK
    };
    load_palette(PALETTE_BG, default_palette);
    load_palette(PALETTE_SPRITE, default_palette);
}

#endif // __NESC_COLOR_H__
