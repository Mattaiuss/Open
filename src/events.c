/*
** EPITECH PROJECT, 2024
** Open
** File description:
** events
*/

#include "open.h"

void check_keys(data_t *data)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(data->window);
        data->status = END;
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        printf("mouse_x: %d  mouse_y: %d\n", MOUSE_X, MOUSE_Y);
    }
}

void check_click(data_t *data)
{
    if (data->event->mouseButton.button == sfMouseLeft) {
        if (sfSound_getStatus(data->sound) == sfPlaying)
            sfSound_stop(data->sound);
        sfSound_play(data->sound);
        data->box_clicked++;
    }
    if (MOUSE_X >= 1784 && MOUSE_X <= 1919
        && MOUSE_Y >= 351 && MOUSE_Y <= 778)
        data->validators->frigo = true;
    if (MOUSE_X >= 601 && MOUSE_X <= 806
        && MOUSE_Y >= 436 && MOUSE_Y <= 552)
        data->validators->tv = true;
    if (MOUSE_X >= 1576 && MOUSE_X <= 1677
        && MOUSE_Y >= 407 && MOUSE_Y <= 694)
        data->validators->caca_door = true;
    
}

void events(data_t *data)
{
    while (sfRenderWindow_pollEvent(data->window, data->event)) {
        if (data->event->type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        if (data->event->type == sfEvtKeyPressed)
            check_keys(data);
        if (data->event->type == sfEvtMouseButtonPressed)
            check_click(data);
        LINK_GAME(data);
    }
}
