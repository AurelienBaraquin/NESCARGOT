#ifndef __NESC_COLLISION_H__
#define __NESC_COLLISION_H__

#include "ESSENTIAL/nesc_ess.h"
#include "SPRITE/Isprite.h"

/**
 * @brief Check if two sprites are colliding.
 * 
 * @param sp1 First sprite.
 * @param sp2 Second sprite.
 * @return true If the sprites are colliding.
 * @return false If the sprites are not colliding.
 */
bool is_colliding(ISprite* sp1, ISprite* sp2);

typedef struct {
    unsigned char ul;     // Tile ID for upper-left collision
    unsigned char ur;     // Tile ID for upper-right collision
    unsigned char dl;     // Tile ID for down-left collision
    unsigned char dr;     // Tile ID for down-right collision
} CollisionResult;

/**
 * @brief Check for collisions between a sprite and the background tiles.
 *
 * @param x Sprite x position.
 * @param y Sprite y position.
 * @param map Pointer to the background map.
 * @return CollisionResult The collision result containing flags and tile IDs.
 */
void check_collision_bg(Box *box, unsigned char *map, CollisionResult* result) {
    unsigned char tx, ty, p;

    memfill(result, 0, sizeof(CollisionResult));

    tx = box->x;
    ty = box->y;
    p = (tx >> 4) + (ty & 0xf0);
    if (map[p] != 0) {
        result->ul = map[p];
    }

    tx = box->x + (box->width - 1);
    ty = box->y;
    p = (tx >> 4) + (ty & 0xf0);
    if (map[p] != 0) {
        result->ur = map[p];
    }

    tx = box->x;
    ty = box->y + (box->height - 1);
    p = (tx >> 4) + (ty & 0xf0);
    if (map[p] != 0) {
        result->dl = map[p];
    }

    tx = box->x + (box->width - 1);
    ty = box->y + (box->height - 1);
    p = (tx >> 4) + (ty & 0xf0);
    if (map[p] != 0) {
        result->dr = map[p];
    }
}

#endif
