#include <stdbool.h>
#include <SFML/Graphics.h>
#include "open.h"

bool test_validator(void) {
    return GAME.box_clicked == 2;
}

void test_handle(data_t *data) {
    sfRectangleShape* square = sfRectangleShape_create();

    sfRectangleShape_setSize(square, (sfVector2f){100, 100});
    sfRectangleShape_setPosition(square, (sfVector2f){50, 50});
    sfRectangleShape_setFillColor(square, sfRed);
    sfRenderWindow_drawRectangleShape(data->window, square, NULL);
    sfRectangleShape_destroy(square);
}
