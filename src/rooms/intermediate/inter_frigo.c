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
    sfRenderWindow_clear(GAME.window, sfBlack);
    sfRenderWindow_drawSprite(GAME.window, GAME.items->fridge_sprite, NULL);
    // afficher le sprite frigo sur tout l'écran
}
