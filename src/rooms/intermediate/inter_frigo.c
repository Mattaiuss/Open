#include "open.h"

bool frigo_validator(void) {
    data_t *data = &GAME;
    bool result = data->validators->frigo;

    if (result) {
        data->validators->frigo = false;
        LINK_GAME(data);
    }
    return result;
}

void frigo_happen(void) {
    static bool first = true;
    static sfSprite *fridge_sprite;
    static sfTexture *fridge_texture;

    if (first) {
        fridge_sprite = sfSprite_create();
        fridge_texture = sfTexture_createFromFile("assets/sprite/frigo/frigo.png", NULL);
        sfSprite_setTexture(fridge_sprite, fridge_texture, false);
    }
    sfRenderWindow_clear(GAME.window, sfBlack);
    sfRenderWindow_drawSprite(GAME.window, fridge_sprite, NULL);
    // afficher le sprite frigo sur tout l'écran
}
