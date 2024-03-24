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
        printf("mouse_x: %d  mouse_y: %d\n", sfMouse_getPositionRenderWindow(data->window).x, sfMouse_getPositionRenderWindow(data->window).y);
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
    if (sfMouse_getPositionRenderWindow(data->window).x >= 1784 && sfMouse_getPositionRenderWindow(data->window).x <= 1919
        && sfMouse_getPositionRenderWindow(data->window).y >= 351 && sfMouse_getPositionRenderWindow(data->window).y <= 778) {
        data->validators->frigo = true;
    }
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
