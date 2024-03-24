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
        GAME.validators->door = true;
        GAME.validators->key = true;
        GAME.validators->tv = true;
        LINK_GAME(data);
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
        && MOUSE_Y >= 351 && MOUSE_Y <= 778) {
        data->validators->frigo = true;
    }
    if (MOUSE_X >= 601 && MOUSE_X <= 806
        && MOUSE_Y >= 436 && MOUSE_Y <= 552)
        data->validators->tv = true;
    if (MOUSE_X >= 1576 && MOUSE_X <= 1677
        && MOUSE_Y >= 407 && MOUSE_Y <= 694)
        data->validators->caca_door = true;
    if (MOUSE_X >= 614 && MOUSE_X <= 641
        && MOUSE_Y >= 861 && MOUSE_Y <= 898)
        data->validators->key = true;
    if (MOUSE_X >= 713 && MOUSE_X <= 741
        && MOUSE_Y >= 1006 && MOUSE_Y <= 885)
        data->validators->box = true;
    if (MOUSE_X >= 1639 && MOUSE_X <= 702
        && MOUSE_Y >= 1692 && MOUSE_Y <= 751)
        data->validators->cheese = true;
    if (MOUSE_X >= 1149 && MOUSE_X <= 252
        && MOUSE_Y >= 1367 && MOUSE_Y <= 606)
        data->validators->door = true;
    if (MOUSE_X >= 1743 && MOUSE_X <= 1769
        && MOUSE_Y >= 706 && MOUSE_Y <= 729)
        data->validators->mouse_hole = true;
    if (data->validators->frigo == true && MOUSE_X >= 1594
        && MOUSE_X <= 1919 && MOUSE_Y >= 111 && MOUSE_Y <= 1075)
        data->validators->fridge_door = true;
    if (data->validators->is_fridge_open == true && MOUSE_X >= 535
        && MOUSE_X <= 722 && MOUSE_Y >= 210 && MOUSE_Y <= 568)
    if (data->validators->is_fridge_open == true && MOUSE_X >= 557
        && MOUSE_X <= 687 && MOUSE_Y >= 232 && MOUSE_Y <= 448)
        data->validators->fridge_milk = true;
    if (data->validators->is_fridge_open == true && MOUSE_X >= 1117
        && MOUSE_X <= 1502 && MOUSE_Y >= 278 && MOUSE_Y <= 459)
        data->validators->fridge_cake = true;
    if (data->validators->is_fridge_open == true && MOUSE_X >= 885
        && MOUSE_X <= 1042 && MOUSE_Y >= 617 && MOUSE_Y <= 755)
        data->validators->fridge_apple = true;
    LINK_GAME(data);
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
