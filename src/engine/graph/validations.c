#include "open.h"

void check_validation(data_t *data)
{
    room_t *current = data->graph->current;
    link_t *tmp = current->links;

    for (; tmp; tmp = tmp->next) {
        if (tmp->link->validator()) {
            data->graph->current = tmp->link;
            LINK_GAME(data);
            return;
        }
    }
}
