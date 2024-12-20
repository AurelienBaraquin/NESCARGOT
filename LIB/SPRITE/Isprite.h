#ifndef __I_SPRITE_NESC_H__
#define __I_SPRITE_NESC_H__

#include "ESSENTIAL/nesc_ess.h"
#include "../box.h"

typedef enum {
    NO_FLIP = 0,
    FLIP_H = 0 | OAM_FLIP_H,
    FLIP_V = 0 | OAM_FLIP_V
} OAMFlip;

#define MAX_SPRITES 64

typedef enum {
    SPRITE_SIMPLE,
    SPRITE_METASPRITE
} SpriteType;

typedef struct ISprite ISprite;

typedef void (*draw_sprite)(ISprite*, unsigned char, unsigned char);
typedef void (*hitbox)(ISprite*, struct Box*);

struct ISprite {
    const unsigned char *data;
    unsigned char x;
    unsigned char y;
    draw_sprite draw;
    hitbox box;
};

static ISprite isprite_manager[MAX_SPRITES];

static inline ISprite *isprite_add(const unsigned char *data, unsigned char x, unsigned char y, draw_sprite draw, hitbox box) {
    unsigned char i;
    ISprite* isprite = NULL;

    for (i = 0; i < MAX_SPRITES; i++) {
        if (isprite_manager[i].data == NULL) {
            isprite = &isprite_manager[i];
            isprite->data = data;
            isprite->x = x;
            isprite->y = y;
            isprite->draw = draw;
            isprite->box = box;
            break;
        }
    }

    return isprite;
}

bool collide(ISprite* isprite1, ISprite* isprite2) {
    struct Box box1, box2;
    isprite1->box(isprite1, &box1);
    isprite2->box(isprite2, &box2);

    return check_collision(&box1, &box2);
}

static inline void draw(ISprite* isprite) {
    isprite->draw(isprite, isprite->x, isprite->y);
}

static inline void draw_at(ISprite* isprite, unsigned char x, unsigned char y) {
    isprite->draw(isprite, x, y);
}

#endif
