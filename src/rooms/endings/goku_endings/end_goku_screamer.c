#include "open.h"

bool goku_screamer_validator(void)
{
    return GAME.validators->door;
}

void goku_screamer_happen(void)
{
    sfSleep(sfSeconds(1));
    sfClock_restart(GAME.clock);
    while (sfTime_asSeconds(sfClock_getElapsedTime(GAME.clock)) < 1) {
        sfRenderWindow_drawSprite(GAME.window, GAME.items->door, NULL);
        sfRenderWindow_display(GAME.window);
    }
}
