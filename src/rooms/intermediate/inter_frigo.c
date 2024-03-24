#include "open.h"

bool frigo_validator(void) {
    data_t *data = &GAME;
    bool result = data->validators->frigo;

    if (result) {
        data->validators->frigo = false;
        data->validators->fridge_door = false;
        LINK_GAME(data);
    }
    return result;
}

void frigo_happen(void) {
    static bool first = true;

    if (first) {
        sfSprite_setPosition(SPRITE->milk, (sfVector2f){150, -550});
        sfSprite_setPosition(SPRITE->cake, (sfVector2f){-50, -550});
        sfSprite_setPosition(SPRITE->apple, (sfVector2f){150, 300});
    }
    sfRenderWindow_clear(GAME.window, sfBlack);
    sfRenderWindow_drawSprite(GAME.window, SPRITE->fridge_sprite, NULL);
    sfRenderWindow_drawSprite(GAME.window, SPRITE->milk, NULL);
    sfRenderWindow_drawSprite(GAME.window, SPRITE->cake, NULL);
    sfRenderWindow_drawSprite(GAME.window, SPRITE->apple, NULL);
    // afficher le sprite frigo sur tout l'écran
}
