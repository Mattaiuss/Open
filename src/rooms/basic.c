#include <stdbool.h>
#include <SFML/Graphics.h>
#include "open.h"

void return_to_basic(void) {
    data_t *data = &GAME;

    data->graph->current = data->default_room;
}

bool basic_validator(void) {
    data_t *data = &GAME;
    bool result = data->validators->fridge_door;
    if (strcmp(data->graph->current->name, "frigo") == 0 && result) {
        data->validators->frigo = false;
        data->validators->fridge_door = false;
        LINK_GAME(data);
        return true;
    }
    return false;
}

void basic_happen(void) {
    sfRenderWindow_clear(GAME.window, sfBlack);
    sfRenderWindow_drawSprite(GAME.window, GAME.default_room_sprite, NULL);
}
