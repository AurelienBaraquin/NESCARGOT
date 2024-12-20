#ifndef __NESC_ESS_H__
#define __NESC_ESS_H__

#include "ESSENTIAL/neslib.h"
#include "ESSENTIAL/nesapi.h"

#define bool unsigned char

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
