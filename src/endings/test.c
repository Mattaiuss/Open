#include <stdbool.h>
#include <SFML/Graphics.h>
#include "open.h"

bool test_validator(void) {
    return GAME.box_clicked == 2;
}

void test_happen(void) {
    data_t *data = &GAME;
    sfRectangleShape* square = sfRectangleShape_create();

    sfRectangleShape_setSize(square, (sfVector2f){100, 100});
    sfRectangleShape_setPosition(square, (sfVector2f){50, 50});
    sfRectangleShape_setFillColor(square, sfRed);
    sfRenderWindow_drawRectangleShape(data->window, square, NULL);
    sfRenderWindow_display(data->window);
    sfRectangleShape_destroy(square);
}

void test2_happen(void) {
    data_t *data = &GAME;
    sfRectangleShape* square = sfRectangleShape_create();

    printf("AZE\n");
    sfRectangleShape_setSize(square, (sfVector2f){100, 100});
    sfRectangleShape_setPosition(square, (sfVector2f){200, 50});
    sfRectangleShape_setFillColor(square, sfBlue);
    sfRenderWindow_drawRectangleShape(data->window, square, NULL);
    sfRenderWindow_display(data->window);
    sfRectangleShape_destroy(square);
}
