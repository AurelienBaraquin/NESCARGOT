#ifndef __NESC_H__
#define __NESC_H__

#include "color.h"
#include "text.h"
#include "index.h"
#include "SPRITE/sprite.h"
#include "SPRITE/metasprite.h"
#include "SPRITE/Isprite.h"
#include "controller.h"
#include "bg.h"
#include "collision.h"

#define SCREEN_WIDTH 32
#define SCREEN_HEIGHT 30

#define POS_TO_MAP(x, y, map_width) (((y / 8) << 4) + (x / 8))

#define POS_TO_ADDR(x, y) (NTADR_A(x / 8, y / 8))

#define INIT() \
    do { \
        ppu_off(); \
        bank_spr(1); \
        ppu_on_all(); \
        set_vram_buffer(); \
    } while (0)

#define START() do { \
    oam_clear(); \
    pad_poll_all(); \
} while (0)

#define END() do { \
    ppu_wait_nmi(); \
    oam_hide_rest(); \
} while (0)

#endif
