/*
** EPITECH PROJECT, 2024
** Open
** File description:
** window
*/

#include "open.h"

void display_help(data_t *data)
{
    sfRenderWindow_clear(data->window, sfBlack);
    sfSprite *helpSprite = sfSprite_create();
    sfTexture *helpTexture = sfTexture_createFromFile("assets/sprite/help.png", NULL);
    sfSprite_setTexture(helpSprite, helpTexture, sfTrue);
    sfRenderWindow_drawSprite(data->window, helpSprite, NULL);
    sfRectangleShape *backButton = sfRectangleShape_create();
    sfRectangleShape_setPosition(backButton, (sfVector2f){50, 50});
    sfRectangleShape_setSize(backButton, (sfVector2f){150, 150});
    sfRectangleShape_setFillColor(backButton, sfColor_fromRGBA(255, 0, 0, 0));
    sfRenderWindow_drawRectangleShape(data->window, backButton, NULL);

    sfEvent event;
    while (sfRenderWindow_pollEvent(data->window, &event)) {
        if (event.type == sfEvtClosed || 
            (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)) {
            sfRenderWindow_close(data->window);
        }
        if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft) {
            sfVector2i mousePos = sfMouse_getPositionRenderWindow(data->window);
            sfFloatRect bounds = sfRectangleShape_getGlobalBounds(backButton);
            if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y)) {
                data->status = MENU;
                break;
            }
        }
    }
    sfTexture_destroy(helpTexture);
    sfSprite_destroy(helpSprite);
    sfRectangleShape_destroy(backButton);
}
