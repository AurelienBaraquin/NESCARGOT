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

#define START() do { \
    oam_clear(); \
    pad_poll_all(); \
} while (0)

#define END() do { \
    ppu_wait_nmi(); \
    oam_hide_rest(); \
} while (0)

#endif
