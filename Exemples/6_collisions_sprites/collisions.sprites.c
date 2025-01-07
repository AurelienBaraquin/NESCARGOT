#include "LIB/nesc.h"
#include "main.h"
#pragma bss-name(push, "ZEROPAGE")

Sprite spr = {0x00, NO_FLIP};

void main(void) {
	ISprite* sp1 = sprite_add(30, 70, &spr);
	ISprite* sp2 = sprite_add(40, 60, &spr);
	Box box1;
    Box box2;
    INIT();

	load_palette(PALETTE_BG, &PALETTE_COLORFUL);

	while (1) {
		START();

		sp1->box(sp1, &box1);
        sp2->box(sp2, &box2);

        if (check_collision(&box1, &box2)) {
            pal_col(0, 0x30);
        } else {
			pal_col(0, 0x00);
		}

		if (PAD1.is_pressed(NESC_PAD_UP)) {
			sp1->y--;
		}
		if (PAD1.is_pressed(NESC_PAD_DOWN)) {
			sp1->y++;
		}
		if (PAD1.is_pressed(NESC_PAD_LEFT)) {
			sp1->x--;
		}
		if (PAD1.is_pressed(NESC_PAD_RIGHT)) {
			sp1->x++;
		}

		draw(sp1);
		draw(sp2);

		END();
	}
}
