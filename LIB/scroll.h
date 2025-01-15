#ifndef __NESC_SCROLL_H__
#define __NESC_SCROLL_H__

#include "ESSENTIAL/nesc_ess.h"

static unsigned int _scrolling_handler(unsigned char mode, unsigned int v) {
    static unsigned int scroll_x = 0;
    static unsigned int scroll_y = 0;

    switch (mode) {
        case 0: // scroll x setter
            set_scroll_x(v);
            scroll_x = v;
            break;
        case 1: // scroll x getter
            return scroll_x;
        case 2: // scroll y setter
            set_scroll_y(v);
            scroll_y = v;
            break;
        case 3: // scroll y getter
            return scroll_y;
    }

    return 0;
}

#define scroll_x(v) (_scrolling_handler(0, v))
#define scroll_y(v) (_scrolling_handler(2, v))

#define scroll_x_get() (_scrolling_handler(1, 0))
#define scroll_y_get() (_scrolling_handler(3, 0))

#define scroll_x_add(v) (_scrolling_handler(0, scroll_x_get() + v))
#define scroll_y_add(v) (_scrolling_handler(2, scroll_y_get() + v))

#endif
