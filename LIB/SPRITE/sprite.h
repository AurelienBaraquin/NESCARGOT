#ifndef __NESC_SPRITE_MANAGER_H__
#define __NESC_SPRITE_MANAGER_H__

#include "ESSENTIAL/nesc_ess.h"
#include "Isprite.h"

typedef enum {
    NO_FLIP = 0,
    FLIP_H = 0 | OAM_FLIP_H,
    FLIP_V = 0 | OAM_FLIP_V
} OAMFlip;

#define MAX_SPRITES 64

typedef struct {
    unsigned char tile;    // Tile index in CHR ROM
    OAMFlip attr;    // Attribute byte (palette, flipping, etc.)
} SpriteEntity;

static SpriteEntity sprites[MAX_SPRITES];

/**
 * @brief Draw all sprites managed by the system.
 * This function should be called every frame.
 */
static inline void sprite_draw(ISprite* isprite, unsigned char x, unsigned char y) {
    SpriteEntity* sprite = (SpriteEntity*)isprite->data;

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
static inline ISprite* sprite_add(
    unsigned char x,
    unsigned char y,
    unsigned char tile,
    OAMFlip attr
) {
    SpriteEntity* sprite = NULL;
    ISprite* isprite = NULL;
    static unsigned char sprite_count = 0;

    if (sprite_count >= MAX_SPRITES) {
        return NULL;
    }

    sprite = &sprites[sprite_count];
    sprite_count++;
    sprite->tile = tile;
    sprite->attr = attr;

    isprite = isprite_add((const unsigned char*)sprite, x, y, (draw_sprite)sprite_draw);
    return isprite;
}

#endif // __NESC_SPRITE_MANAGER_H__
