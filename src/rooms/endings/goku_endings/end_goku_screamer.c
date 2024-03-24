#include "open.h"

bool goku_screamer_validator(void)
{
    return GAME.validators->door;
}

void goku_screamer_happen(void)
{
    sfRenderWindow_clear(GAME.window, sfBlack);
    sfRenderWindow_drawSprite(GAME.window, GAME.default_room_sprite, NULL);
    if (sfClock_getElapsedTime(GAME.clock).microseconds >= 0.071 * 1000000) {
        sfSprite_setPosition(GAME.items->screamer_goku, (sfVector2f){sfSprite_getPosition(GAME.items->screamer_goku).x -50, sfSprite_getPosition(GAME.items->screamer_goku).y - 50});
        sfSprite_setScale(GAME.items->screamer_goku, (sfVector2f){sfSprite_getScale(GAME.items->screamer_goku).x + 0.2, sfSprite_getScale(GAME.items->screamer_goku).y + 0.2});
        GAME.items->rect.width = 502;
        if (GAME.items->rect.left == 0)
            GAME.items->rect.left = 502;
        else
            GAME.items->rect.left = 0;
        sfSprite_setTextureRect(GAME.items->screamer_goku, GAME.items->rect);
        sfClock_restart(GAME.clock);
    }
    sfRenderWindow_drawSprite(GAME.window, GAME.items->screamer_goku, NULL);
    sfRenderWindow_display(GAME.window);
}
