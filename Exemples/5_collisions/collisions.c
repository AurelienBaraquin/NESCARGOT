#include "LIB/nesc.h"
#include "main.h"
#pragma bss-name(push, "ZEROPAGE")

Sprite spr = {0x00, NO_FLIP};

CSVTile tiles[] = {
	{0, 0, 0},
	{1, 0, 1},
	CSV_END
};

void main(void) {
	ISprite* sp = sprite_add(30, 70, &spr);
    Box box;
    CollisionResult result;
	char px, py, p;
	char x, y;

    INIT();

	load_palette(PALETTE_BG, &PALETTE_GRAY);
	load_palette(PALETTE_SPRITE, &PALETTE_COLORFUL);

	BG_DRAW(px, py, p, 2, 2,
		index(px, py);
		PUT(get_map_tile(map[p], tiles));
		PUT(get_map_tile(map[p], tiles));
		index(px, py + 1);
		PUT(get_map_tile(map[p], tiles));
		PUT(get_map_tile(map[p], tiles));
	);

	while (1) {
		x = 0;
		y = 0;

		START();

		sp->box(sp, &box);

		if (PAD1.is_pressed(NESC_PAD_UP)) {
			sp->y--;
		}
		if (PAD1.is_pressed(NESC_PAD_DOWN)) {
			sp->y++;
		}
		if (PAD1.is_pressed(NESC_PAD_LEFT)) {
			sp->x--;
		}
		if (PAD1.is_pressed(NESC_PAD_RIGHT)) {
			sp->x++;
		}

		check_collision_bg(&box, map, &result);
		if (result.ul != 0) {
			x += 1;
			y += 1;
		}
		if (result.dl != 0) {
			x += 1;
			y -= 1;
		}
		if (result.ur != 0) {
			x -= 1;
			y += 1;
		}
		if (result.dr != 0) {
			x -= 1;
			y -= 1;
		}

		x > 0 ? sp->x += 1 : 0;
		y > 0 ? sp->y += 1 : 0;
		x < 0 ? sp->x -= 1 : 0;
		y < 0 ? sp->y -= 1 : 0;

		draw(sp);

		END();
	}
}
