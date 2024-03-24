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
    while (1) {
        data_t *data = init_data();
        display_menu(data);
        while (sfRenderWindow_isOpen(data->window)) {
            events(data);
            check_validation(data);
            sfRenderWindow_clear(data->window, sfBlack);
            (GAME).graph->current->happen();
        }
        destroy(data);
        if (data->status == 2)
            break;
    }
    return 0;
}
