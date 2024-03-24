#include "open.h"

bool frigo_validator(void) {
    data_t *data = &GAME;
    bool result = data->validators->frigo;

    if (result) {
        data->validators->frigo = false;
        data->validators->fridge_door = false;
        data->validators->is_fridge_open = true;
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
    if (GAME.validators->fridge_milk == false)
        sfRenderWindow_drawSprite(GAME.window, SPRITE->milk, NULL);
    if (GAME.validators->fridge_cake == false)
        sfRenderWindow_drawSprite(GAME.window, SPRITE->cake, NULL);
    if (GAME.validators->fridge_apple == false)
        sfRenderWindow_drawSprite(GAME.window, SPRITE->apple, NULL);
    // afficher le sprite frigo sur tout l'écran
}
