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

static inline unsigned char _get_map_tile(unsigned char id, CSVTile *tile_map, unsigned char tile_map_size) {
    unsigned char i;

    for (i = 0; i < tile_map_size; ++i) {
        if (tile_map[i].map_tile_id == id) {
            return tile_map[i].tile_y * 16 + tile_map[i].tile_x;
        }
    }
    return 0;
}

// static inline void bg_draw(const unsigned char* map, CSVTile *tiles_map, unsigned char tiles_map_size) {
//     unsigned char tile;
//     unsigned char temp_x, temp_y, temp1;

//     set_scroll_y(0xff);
//     ppu_off();

// 	for(temp_y = 0; temp_y < 16; ++temp_y){
// 		for(temp_x = 0; temp_x < 16; ++temp_x){
// 			temp1 = (temp_y << 4) + temp_x;
//             vram_put(_get_map_tile(map[temp1], tiles_map, tiles_map_size));
//             vram_put(_get_map_tile(map[temp1], tiles_map, tiles_map_size));
// 		}
// 	}

//     ppu_on_all();
// }

#define BG_DRAW(px, py, p, px_it, py_it, x) \
    set_scroll_y(0xff); \
    ppu_off(); \
    for(py = 0; py / py_it < 15; py += py_it){ \
        for(px = 0; px / px_it < 16; px += px_it){ \
            p = (py / py_it << 4) + px / px_it; \
            x \
        } \
    } \
    ppu_on_all();

#endif // __NESC_BG_MANAGER_H__
