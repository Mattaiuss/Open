#include "open.h"

void add_at_front(link_t **link, room_t *room)
{
    link_t *new_link = malloc(sizeof(link_t));

    new_link->link = room;
    new_link->next = *link;
    *link = new_link;
}

room_t *add_at_back_rooms(rooms_t **rooms, char *name, bool (*validator)(), void (*happen)())
{
    rooms_t *new_rooms = malloc(sizeof(rooms_t));
    room_t *data = init_room(name, validator, happen);
    new_rooms->current = data;
    new_rooms->next = NULL;

    if (*rooms == NULL) {
        *rooms = new_rooms;
        return data;
    }
    rooms_t *last = *rooms;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_rooms;
    return data;
}

room_t *find_in_list(rooms_t *rooms, const char *target)
{
    while (rooms != NULL) {
        if (strcmp(rooms->current->name, target) == 0) {
            return rooms->current;
        }
        rooms = rooms->next;
    }
    return NULL;
}
