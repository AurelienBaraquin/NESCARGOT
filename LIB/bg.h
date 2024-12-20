#ifndef __NESC_BG_MANAGER_H__
#define __NESC_BG_MANAGER_H__

#include "ESSENTIAL/nesc_ess.h"
#include "box.h"

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

static inline void bg_draw(const unsigned char* map, CSVTile *tiles_map, unsigned char tiles_map_size) {
    unsigned char temp_x, temp_y;
    unsigned char tile;

    ppu_off();

    for(temp_y = 0; temp_y < 30; ++temp_y){
        for(temp_x = 0; temp_x < 32; ++temp_x){
            tile = _get_map_tile(map[temp_y * 32 + temp_x], tiles_map, tiles_map_size);
            vram_put(tile);
        }
    }

    ppu_on_all();
}

static inline bool bg_collide_upper_right(const Box *box, const unsigned char *map, CSVTile *tiles_map, unsigned char tiles_map_size) {
    unsigned char tile;
    unsigned char right_tile, top_tile;

    right_tile = (box->x + box->width - 1) / 8;
    top_tile = box->y / 8;

    tile = _get_map_tile(map[top_tile * 32 + right_tile], tiles_map, tiles_map_size);

    return tile != 0;
}

static inline bool bg_collide_upper_left(const Box *box, const unsigned char *map, CSVTile *tiles_map, unsigned char tiles_map_size) {
    unsigned char tile;
    unsigned char left_tile, top_tile;

    left_tile = box->x / 8;
    top_tile = box->y / 8;

    tile = _get_map_tile(map[top_tile * 32 + left_tile], tiles_map, tiles_map_size);

    return tile != 0;
}

static inline bool bg_collide_lower_right(const Box *box, const unsigned char *map, CSVTile *tiles_map, unsigned char tiles_map_size) {
    unsigned char tile;
    unsigned char right_tile, bottom_tile;

    right_tile = (box->x + box->width - 1) / 8;
    bottom_tile = (box->y + box->height - 1) / 8;

    tile = _get_map_tile(map[bottom_tile * 32 + right_tile], tiles_map, tiles_map_size);

    return tile != 0;
}

static inline bool bg_collide_lower_left(const Box *box, const unsigned char *map, CSVTile *tiles_map, unsigned char tiles_map_size) {
    unsigned char tile;
    unsigned char left_tile, bottom_tile;

    left_tile = box->x / 8;
    bottom_tile = (box->y + box->height - 1) / 8;

    tile = _get_map_tile(map[bottom_tile * 32 + left_tile], tiles_map, tiles_map_size);

    return tile != 0;
}

#endif // __NESC_BG_MANAGER_H__
