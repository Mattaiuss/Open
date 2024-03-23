/*
** EPITECH PROJECT, 2024
** Open
** File description:
** destroy
*/

#include "open.h"

void destroy(data_t *data)
{
    sfRenderWindow_destroy(data->window);
    sfClock_destroy(data->clock);
    free(data->event);
    free(data);
}