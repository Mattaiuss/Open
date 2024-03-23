#pragma once

#include "graph.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
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

    sfSound *sound;
    sfSoundBuffer *soundbuffer;

    int nb_buttons;
    button_t **buttons;
    graph_t *graph;
} data_t;

data_t *init_data(void);
void events(data_t *data);
void destroy(data_t *data);
data_t *get_data(data_t *data);

#define GAME        (*get_data(NULL))
