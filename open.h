/*
** EPITECH PROJECT, 2024
** Open
** File description:
** open
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct data_s data_t;

typedef struct button_s {
    sfSprite *sprite;
    sfTexture *textures;
    sfVector2f pos;

    int (*callback)(data_t *data);
    int is_active;
} button_t;

typedef struct data_s {
    sfRenderWindow *window;
    sfEvent *event;
    sfClock *clock;

    sfSprite *bg;
    sfTexture *bg_t;

    int nb_buttons;
    button_t **buttons;
} data_t;

data_t *init_data(void);
void events(data_t *data);
void destroy(data_t *data);
