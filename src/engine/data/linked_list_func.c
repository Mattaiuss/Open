#include "open.h"

void add_at_front(link_t **link, room_t *room)
{
    link_t *new_link = malloc(sizeof(link_t));

    new_link->link = room;
    new_link->next = *link;
    *link = new_link;
}
