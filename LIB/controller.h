#ifndef __NESC_CONTROLLER_H__
#define __NESC_CONTROLLER_H__

#include "ESSENTIAL/nesc_ess.h"

#ifndef _NESLIB_PADS_H
#define _NESLIB_PADS_H
    #define PAD_A			0x80
    #define PAD_B			0x40
    #define PAD_SELECT		0x20
    #define PAD_START		0x10
    #define PAD_UP			0x08
    #define PAD_DOWN		0x04
    #define PAD_LEFT		0x02
    #define PAD_RIGHT		0x01
#endif

typedef enum {
    NESC_PAD_A = PAD_A,
    NESC_PAD_B = PAD_B,
    NESC_PAD_SELECT = PAD_SELECT,
    NESC_PAD_START = PAD_START,
    NESC_PAD_UP = PAD_UP,
    NESC_PAD_DOWN = PAD_DOWN,
    NESC_PAD_LEFT = PAD_LEFT,
    NESC_PAD_RIGHT = PAD_RIGHT
} NESC_PAD;

typedef struct {
    unsigned char pad;
    unsigned char connected;
    bool (*is_pressed)(NESC_PAD);
} PAD;

bool _is_pressed_pad1(NESC_PAD button);
bool _is_pressed_pad2(NESC_PAD button);

static PAD PAD1 = {0, 0, _is_pressed_pad1};
static PAD PAD2 = {1, 0, _is_pressed_pad2};

bool _is_pressed_pad1(NESC_PAD button) {
    return (PAD1.pad & button) == button;
}

bool _is_pressed_pad2(NESC_PAD button) {
    return (PAD2.pad & button) == button;
}

static inline void pad_poll_all() {
    static PAD* pads[] = {&PAD1, &PAD2};
    unsigned char i;

    for (i = 0; i < 2; ++i) {
        pads[i]->pad = pad_poll(i);
        if (pads[i]->pad != 0) {
            pads[i]->connected = 1;
        } else {
            pads[i]->connected = 0;
        }
    }
}

#endif
