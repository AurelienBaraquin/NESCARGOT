#ifndef __NESC_MUSIC_H__
#define __NESC_MUSIC_H__

#include "ESSENTIAL/nesc_ess.h"

#define DEFAULT_MUSIC_SPEED 6

void play_music(unsigned char music_id) {
    music_play(music_id);
}

void pause_music(void) {
    music_pause(1);
}

void resume_music(void) {
    music_pause(0);
}

void stop_music(void) {
    music_stop();
}

void set_music_speed(unsigned char speed);

#endif
