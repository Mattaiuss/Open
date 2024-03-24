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

graph_t *init_graph(void)
{
    graph_t *graph = malloc(sizeof(graph));

    graph->rooms = init_rooms();
    graph->current = graph->rooms->current;
    graph->nb_rooms = 2;
    return graph;
}
