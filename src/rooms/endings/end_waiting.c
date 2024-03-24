#include "open.h"

bool waiting_validator(void) {
    return (sfClock_getElapsedTime(GAME.clock).microseconds >= 3 * 60 * 1000000);
}

void waiting_happen(void) {
    // la boite explose
    //display the explosion
    sfRenderWindow_display(GAME.window);
}
