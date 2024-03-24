#include "open.h"

static void init_links(room_t *room_src, room_t *room_dest)
{
    add_at_front(&(room_src->links), room_dest);
}

room_t *init_room(char *name, bool (*validator)(), void (*happen)())
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
    rooms_t *rooms = NULL;
    room_t *basic = NULL;
    room_t *room_a = NULL;
    room_t *room_b = NULL;

    basic = add_at_back_rooms(&rooms, "basic", basic_validator, basic_happen);


    // goku
    room_a = add_at_back_rooms(&rooms, "goku_global", goku_global_validator, goku_global_happen);
    room_b = add_at_back_rooms(&rooms, "goku_screamer", goku_screamer_validator, goku_screamer_happen);
    init_links(basic, room_a);
    init_links(room_a, basic);
    init_links(room_a, room_b);

    // caca
    // frigo
    room_b = add_at_back_rooms(&rooms, "frigo", frigo_validator, frigo_happen);
    init_links(basic, room_b);
    init_links(room_b, basic);
    room_a = add_at_back_rooms(&rooms, "caca_global", caca_global_validator, caca_global_happen);
    init_links(room_b, room_a);
    room_b = add_at_back_rooms(&rooms, "caca_toilet", caca_toilet_validator, caca_toilet_happen);
    init_links(room_a, room_b);
    init_links(room_b, basic);
    room_b = add_at_back_rooms(&rooms, "caca_sur_soi", caca_sur_soi_validator, caca_sur_soi_happen);
    init_links(room_a, room_b);

    // waiting
    room_a = add_at_back_rooms(&rooms, "waiting", waiting_validator, waiting_happen);
    init_links(basic, room_a);

    return rooms;
}

graph_t *init_graph(void)
{
    graph_t *graph = malloc(sizeof(graph_t));

    graph->rooms = init_rooms();
    graph->current = graph->rooms->current;
    graph->nb_rooms = 2;
    return graph;
}
