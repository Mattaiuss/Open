
#include "../include/open.h"

static void is_touched(data_t *data, button_t *start, button_t *quit)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(data->window);
    sfFloatRect start_rect = sfSprite_getGlobalBounds(start->sprite);
    sfFloatRect quit_rect = sfSprite_getGlobalBounds(quit->sprite);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&start_rect, mouse.x, mouse.y))
            start->callback(data);
        if (sfFloatRect_contains(&quit_rect, mouse.x, mouse.y))
            quit->callback(data);
    }
}

void display_menu(data_t *data, bool first)
{
    menu_t *menu = data->menu;

    if (first)
        sfMusic_play(menu->music);
    while (sfRenderWindow_pollEvent(data->window, data->event)) {
        if (data->event->type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        if (data->event->type == sfEvtKeyPressed)
            check_keys(data);
    }
    is_touched(data, menu->start, menu->quit);
    sfRenderWindow_drawSprite(data->window, menu->start->sprite, NULL);
    sfRenderWindow_drawSprite(data->window, menu->quit->sprite, NULL);
    sfRenderWindow_drawSprite(data->window, menu->bg, NULL);
    for (int i = 0; i < data->nb_endings; i++) {
        if (data->optained_endings[i] == 1)
            sfRenderWindow_drawSprite(data->window, data->menu_endings_sprites[i], NULL);
        sfRectangleShape_setPosition(menu->rect, (sfVector2f){1500, i * 100 + 200});
        sfRenderWindow_drawRectangleShape(data->window, menu->rect, NULL);
    }
}
