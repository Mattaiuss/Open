/*
** EPITECH PROJECT, 2024
** Open
** File description:
** init_data
*/

#include "open.h"

data_t *init_data(void)
{
    data_t *data = malloc(sizeof(data_t));
    data->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "OPEN", sfClose | sfFullscreen, NULL);
    data->event = malloc(sizeof(sfEvent));
    data->clock = sfClock_create();
    return data;
}