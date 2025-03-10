#ifndef __NESC_ESS_H__
#define __NESC_ESS_H__

#include "ESSENTIAL/neslib.h"
#include "ESSENTIAL/nesapi.h"

#define bool unsigned char
#define true 1
#define false 0

#define DIVIDE(a, b) ((a) == 0 ? 0 : (a) / (b))

int _ppu_addr(int mode, int x, int y) {
    static struct {
        unsigned char x;
        unsigned char y;
    } pos = {0, 0};

    switch (mode) {
        case 0:
            pos.x = x;
            pos.y = y;
            return 0;
        case 1:
            return pos.x;
        case 2:
            return pos.y;
    }
}

#endif
