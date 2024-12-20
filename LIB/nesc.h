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

#define SCREEN_WIDTH 32
#define SCREEN_HEIGHT 30

static inline void start() {
    oam_clear();
    pad_poll_all();
}

static inline void end() {
    ppu_wait_nmi();
    oam_hide_rest();
}

#endif
