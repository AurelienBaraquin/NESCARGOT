#ifndef __NESC_METASPRITE_H__
#define __NESC_METASPRITE_H__

#include "sprite.h"

#define MAX_METASPRITES_FRAME 16

#define MET_STOP {128, 0, 0, NO_FLIP}

typedef struct {
    unsigned char x;
    unsigned char y;
    unsigned char tile;
    OAMFlip attr;
} MetaspriteFrame;

typedef struct {
    MetaspriteFrame frames[MAX_METASPRITES_FRAME];
} Metasprite;

/**
 * @brief Draw a metasprite.
 * 
 * @param metasprite Pointer to the metasprite object.
 * @param x X position of the metasprite.
 * @param y Y position of the metasprite.
 */
static inline void draw_metasprite(ISprite* sprite, unsigned char x, unsigned char y) {
    Metasprite *metasprite = (Metasprite*)sprite->data;
    const MetaspriteFrame *frame;
    unsigned char met[MAX_METASPRITES_FRAME * 4 + 1];
    unsigned char i = 0, j = 0;

    while (i < MAX_METASPRITES_FRAME && metasprite->frames[i].tile != 128) {
        frame = &metasprite->frames[i];
        met[j++] = frame->x;
        met[j++] = frame->y;
        met[j++] = frame->tile;
        met[j++] = frame->attr;
        i++;
    }

    met[j] = 128;

    oam_meta_spr(x, y, met);
}

/**
 * @brief Add a new metasprite to the system.
 *
 * @param x X position of the metasprite.
 * @param y Y position of the metasprite.
 * @param frames List of metasprite frames.
 * @return Metasprite* Pointer to the metasprite object.
 */
static inline ISprite* metasprite_add(unsigned char x, unsigned char y, Metasprite *met) {
    return isprite_add((const unsigned char*)met->frames, x, y, (draw_sprite)draw_metasprite);
}

#endif // __NESC_METASPRITE_H__
