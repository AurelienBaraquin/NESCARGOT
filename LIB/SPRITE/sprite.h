#ifndef __NESC_SPRITE_MANAGER_H__
#define __NESC_SPRITE_MANAGER_H__

#include "Isprite.h"

typedef struct {
    unsigned char tile;    // Tile index in CHR ROM
    OAMFlip attr;    // Attribute byte (palette, flipping, etc.)
} Sprite;

/**
 * @brief Draw all sprites managed by the system.
 * This function should be called every frame.
 */
static inline void sprite_draw(ISprite* isprite, unsigned char x, unsigned char y) {
    Sprite* sprite = (Sprite*)isprite->data;

    if (sprite != NULL) {
        oam_spr(x, y, sprite->tile, sprite->attr);
    }
}

/**
 * @brief Add a new sprite to the system.
 *
 * @param x X position of the sprite.
 * @param y Y position of the sprite.
 * @param tile Tile index in CHR ROM.
 * @param attr Attribute byte for the sprite (palette, flipping, etc.).
 * @return ISprite* Pointer to the sprite object.
 */
static inline ISprite* sprite_add(unsigned char x, unsigned char y, Sprite* sprite) {
    return isprite_add((const unsigned char*)sprite, x, y, (draw_sprite)sprite_draw);
}

#endif // __NESC_SPRITE_MANAGER_H__
