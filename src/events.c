/*
** EPITECH PROJECT, 2024
** Open
** File description:
** events
*/

#include "open.h"

void check_keys(data_t *data)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(data->window);
}

void events(data_t *data)
{
    while (sfRenderWindow_pollEvent(data->window, data->event)) {
        if (data->event->type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        if (data->event->type == sfEvtKeyPressed)
            check_keys(data);
    }
}