#ifndef __NESC_BG_MANAGER_H__
#define __NESC_BG_MANAGER_H__

#include "ESSENTIAL/nesc_ess.h"
#include "box.h"
#include "SPRITE/Isprite.h"

typedef struct {
    unsigned char map_tile_id;
    unsigned char tile_x;
    unsigned char tile_y;
} CSVTile;

#define CSV_END {255, 255, 255}

static inline unsigned char get_map_tile(unsigned char id, CSVTile *tile_map) {
    unsigned char i;

    for (i = 0; tile_map[i].map_tile_id != 255 && tile_map[i].tile_x != 255 && tile_map[i].tile_y != 255; ++i) {
        if (tile_map[i].map_tile_id == id) {
            return tile_map[i].tile_y * 16 + tile_map[i].tile_x;
        }
    }
    return 0;
}

#define BG_DRAW(px, py, p, px_it, py_it, x) \
    ppu_off(); \
    for(py = 0; py / py_it < 15; py += py_it){ \
        for(px = 0; px / px_it < 16; px += px_it){ \
            p = (py / py_it << 4) + px / px_it; \
            x \
        } \
    } \
    ppu_on_all();

#endif // __NESC_BG_MANAGER_H__
