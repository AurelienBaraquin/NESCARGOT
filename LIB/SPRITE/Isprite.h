#ifndef __I_SPRITE_NESC_H__
#define __I_SPRITE_NESC_H__

#define MAX_SPRITES 64

typedef enum {
    SPRITE_SIMPLE,
    SPRITE_METASPRITE
} SpriteType;

typedef struct ISprite ISprite;

typedef void (*draw_sprite)(ISprite*, unsigned char, unsigned char);

struct ISprite {
    const unsigned char *data;
    unsigned char x;
    unsigned char y;
    draw_sprite draw;
};

static ISprite isprite_manager[MAX_SPRITES];

static inline void isprite_manager_clear() {
    unsigned char i;
    for (i = 0; i < MAX_SPRITES; i++) {
        isprite_manager[i].data = NULL;
    }
}

static inline ISprite *isprite_add(const unsigned char *data, unsigned char x, unsigned char y, draw_sprite draw) {
    unsigned char i;
    ISprite* isprite = NULL;

    for (i = 0; i < MAX_SPRITES; i++) {
        if (isprite_manager[i].data == NULL) {
            isprite = &isprite_manager[i];
            isprite->data = data;
            isprite->x = x;
            isprite->y = y;
            isprite->draw = draw;
            break;
        }
    }

    return isprite;
}

static inline void draw_sprites() {
    unsigned char i;

    oam_clear();
    for (i = 0; i < MAX_SPRITES; i++) {
        if (isprite_manager[i].data != NULL) {
            isprite_manager[i].draw(&isprite_manager[i], isprite_manager[i].x, isprite_manager[i].y);
        }
    }
}

#endif
