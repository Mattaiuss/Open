/*
** EPITECH PROJECT, 2024
** Open
** File description:
** init_data
*/

#include "open.h"

static void init_links(room_t *room_src, room_t *room_dest)
{
    add_at_front(&(room_src->links), room_dest);
}

static room_t *init_room(char *name, bool (*validator)(), void (*happen)())
{
    static int nb = 0;
    room_t *room = malloc(sizeof(room_t));

    room->name = strdup(name);
    room->nb = nb++;
    room->visited = 0;
    room->validator = validator;
    room->happen = happen;
    room->links = NULL;
    return room;
}

static rooms_t *init_rooms(void)
{
    rooms_t *rooms = malloc(sizeof(rooms_t));

    rooms->current = init_room("test1", test_validator, test_happen);
    rooms->next = malloc(sizeof(rooms_t));
    rooms->next->current = init_room("test2", test_validator, test2_happen);
    rooms->next->next = NULL;
    init_links(rooms->current, rooms->next->current);
    return rooms;
}

static graph_t *init_graph(void)
{
    graph_t *graph = malloc(sizeof(graph));

    graph->rooms = init_rooms();
    graph->current = graph->rooms->current;
    graph->nb_rooms = 2;
    return graph;
}

data_t *init_data(void)
{
    data_t *data = malloc(sizeof(data_t));
    data->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "OPEN", sfClose | sfFullscreen, NULL);
    data->sound = sfSound_create();
    data->soundbuffer = sfSoundBuffer_createFromFile("./assets/song/minecraft_click.ogg");
    sfSound_setBuffer(data->sound, data->soundbuffer);
    data->box_clicked = 0;
    data->event = malloc(sizeof(sfEvent));
    data->clock = sfClock_create();
    data->graph = init_graph();
    LINK_GAME(data);
    return data;
}
