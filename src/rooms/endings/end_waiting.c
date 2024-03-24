#include "open.h"

bool waiting_validator(void) {
    return (sfClock_getElapsedTime(GAME.clock).microseconds >= 2 * 60 * 1000000);
}

void waiting_happen(void) {
    static bool first = true;
    
    if (first) {
        sfSound *sound = sfSound_create();
        sfSoundBuffer *soundbuffer = sfSoundBuffer_createFromFile("./assets/song/big-explosion.ogg");
        sfSound_setBuffer(sound, soundbuffer);
        sfSound_play(sound);
        free(sound);
        first = false;
    }
    sfRenderWindow_drawSprite(GAME.window, GAME.items->wait_ending_screen, NULL);
    sfRenderWindow_display(GAME.window);
}
