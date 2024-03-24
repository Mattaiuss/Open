/*
** EPITECH PROJECT, 2024
** Open
** File description:
** window
*/

#include "open.h"

void display(data_t *data)
{
    for (int i = 0; i < data->nb_endings; i++) {
        if (data->optained_endings[i] == 1)
            sfRenderWindow_drawSprite(data->window, data->menu_endings_sprites[i], NULL);
    }
}

int main(int ac, __attribute__((unused)) char **av)
{
    if (ac != 1)
        return (84);
    data_t *data = init_data();
    while (sfRenderWindow_isOpen(data->window)) {
        if (data->status == MENU) {
            display_menu(data);
        }
        events(data);
        check_validation(data);
        if (data->status == PLAY) {
            sfMusic_stop(data->menu->music);
            (GAME).graph->current->happen();
        }
        sfRenderWindow_display(GAME.window);
        if (data->status == END)
            break;
    }
    destroy(data);
    return 0;
}
