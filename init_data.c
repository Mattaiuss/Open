/*
** EPITECH PROJECT, 2024
** Open
** File description:
** init_data
*/

#include "open.h"

static room_t *init_room(char *name, int nb, int visited, bool (*validator)(), bool(*happen)())
{
    room_t *room = malloc(sizeof(room_t));

    return room;
}

static rooms_t *init_rooms(void)
{
    rooms_t *rooms = malloc(sizeof(rooms_t));

    rooms->current = init_room("test1", 0, 0, NULL, NULL);
    return rooms;
}

static graph_t *init_graph(void)
{
    graph_t *graph = malloc(sizeof(graph));

    graph->rooms = init_rooms();
    return graph;
}

data_t *get_data(data_t *data)
{
    static data_t *save;

    if (data != NULL)
        save = data;
    return save;
}

data_t *init_data(void)
{
    data_t *data = malloc(sizeof(data_t));
    data->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "OPEN", sfClose | sfFullscreen, NULL);
    data->sound = sfSound_create();
    data->soundbuffer = NULL;
    data->event = malloc(sizeof(sfEvent));
    data->clock = sfClock_create();
    data->graph = init_graph();
    return data;
}
