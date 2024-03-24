#include "open.h"

bool waiting_validator(void) {
    return (sfClock_getElapsedTime(GAME.clock).microseconds >= 3 * 1000000);
}

void waiting_happen(void) {
    // la boite explose
    sfRenderWindow_clear(GAME.window, sfBlack);
    //display the explosion
    sfRenderWindow_display(GAME.window);
}
