/*
** EPITECH PROJECT, 2024
** Open
** File description:
** window
*/

#include "open.h"

int main(int ac, __attribute__((unused)) char **av)
{
    if (ac != 1)
        return (84);
    data_t *data = init_data();
    while (sfRenderWindow_isOpen(data->window)) {
        events(data);
        sfRenderWindow_clear(data->window, sfBlack);
        sfRenderWindow_display(data->window);
    }
    destroy(data);
    return 0;
}