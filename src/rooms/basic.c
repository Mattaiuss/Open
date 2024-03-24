#include <stdbool.h>
#include <SFML/Graphics.h>
#include "open.h"

void return_to_basic(void) {
    data_t *data = &GAME;

    data->graph->current = data->default_room;
}

bool basic_validator(void) {
    data_t *data = &GAME;
    bool result = data->validators->fridge_door && data->validators->fridge_apple;
    if (strcmp(data->graph->current->name, "frigo") == 0 && result) {
        printf("%d %d", data->validators->fridge_door, data->validators->fridge_apple);
        data->validators->frigo = false;
        data->validators->fridge_door = false;
        data->validators->is_fridge_open = false;
        LINK_GAME(data);
        return true;
    }
    return false;
}

void basic_happen(void) {
    static bool first = true;

    if (first) {
        first = false;
        sfRenderWindow_clear(GAME.window, sfBlack);
    }
    sfRenderWindow_drawSprite(GAME.window, GAME.default_room_sprite, NULL);
}
