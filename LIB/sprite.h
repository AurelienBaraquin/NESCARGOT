#ifndef __NESC_SPRITE_MANAGER_H__
#define __NESC_SPRITE_MANAGER_H__

#include "ESSENTIAL/nesc_ess.h"

#define MAX_SPRITES 64

typedef struct {
    unsigned char x;       // X position of the sprite
    unsigned char y;       // Y position of the sprite
    unsigned char tile;    // Tile index in CHR ROM
    unsigned char attr;    // Attribute byte (palette, flipping, etc.)
} SpriteEntity;

typedef struct {
    SpriteEntity sprites[MAX_SPRITES]; // Array of sprites
    unsigned char sprite_count;        // Number of active sprites
} SpriteManager;

static SpriteManager sprite_manager = {};

/**
 * @brief Initialize the sprite system.
 * Clears all sprites and prepares the system for use.
 */
static inline void sprite_manager_init() {
    oam_clear();
    sprite_manager.sprite_count = 0;
}

/**
 * @brief Add a new sprite to the system.
 *
 * @param x X position of the sprite.
 * @param y Y position of the sprite.
 * @param tile Tile index in CHR ROM.
 * @param attr Attribute byte for the sprite (palette, flipping, etc.).
 * @return SpriteEntity* Pointer to the new sprite, or NULL if the system is full.
 */
static inline SpriteEntity* sprite_add(
    unsigned char x,
    unsigned char y,
    unsigned char tile,
    unsigned char attr
) {
    SpriteEntity* sprite = NULL;

    if (sprite_manager.sprite_count >= MAX_SPRITES) {
        return NULL;
    }

    sprite = &sprite_manager.sprites[sprite_manager.sprite_count];
    sprite_manager.sprite_count++;
    sprite->x = x;
    sprite->y = y;
    sprite->tile = tile;
    sprite->attr = attr;

    return sprite;
}

/**
 * @brief Draw all sprites managed by the system.
 * This function should be called every frame.
 */
static inline void sprite_draw_all() {
    SpriteEntity* sprite = NULL;
    unsigned char i;

    oam_clear();
    for (i = 0; i < sprite_manager.sprite_count; i++) {
        sprite = &sprite_manager.sprites[i];
        oam_spr(sprite->x, sprite->y, sprite->tile, sprite->attr);
    }
}

/**
 * @brief Move a sprite to a new position.
 *
 * @param sprite Pointer to the sprite to move.
 * @param x New X position.
 * @param y New Y position.
 */
static inline void sprite_move(SpriteEntity* sprite, unsigned char x, unsigned char y) {
    sprite->x = x;
    sprite->y = y;
}

/**
 * @brief Remove all sprites from the system.
 */
static inline void sprite_manager_clear() {
    sprite_manager.sprite_count = 0;
}

#endif // __NESC_SPRITE_MANAGER_H__
