#include "LIB/nesc.h"
#pragma bss-name(push, "ZEROPAGE")

Sprite spr = {0x00, NO_FLIP};

void main(void) {
    ISprite* sp1 = sprite_add(30, 70, &spr);
    unsigned char speed = DEFAULT_MUSIC_SPEED;  // Set the default music speed
    unsigned char music_id = 1;  // Initialize the music ID to 1

    INIT();

    play_music(1);  // Start playing music with ID 1

    load_palette(PALETTE_SPRITE, &PALETTE_COLORFUL);

    while (1) {
        START();

        // Increase music speed if UP button is pressed
        if (PAD1.is_pressed(NESC_PAD_UP)) {
            speed++;
        }
        // Decrease music speed if DOWN button is pressed
        if (PAD1.is_pressed(NESC_PAD_DOWN)) {
            speed--;
        }
        set_music_speed(speed);  // Set the music speed

        // Resume music if A button is pressed
        if (PAD1.is_pressed(NESC_PAD_A)) {
            resume_music();
        }
        // Pause music if B button is pressed
        if (PAD1.is_pressed(NESC_PAD_B)) {
            pause_music();
        }

        // Change music if LEFT or RIGHT button is pressed
        if (PAD1.is_pressed(NESC_PAD_LEFT) || PAD1.is_pressed(NESC_PAD_RIGHT)) {
            music_id--;
            if (music_id > 1) {  // Ensure music ID does not go below 1
                music_id = 1;
            }
            play_music(music_id);  // Play the new music
        }

        draw(sp1);

        END();
    }
}
