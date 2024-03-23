#ifndef ENGINE_H
    #define ENGINE_H

    #include "structs.h"

    data_t *get_data(data_t *data);

    #define GAME          (*get_data(NULL))
    #define LINK_GAME(x)  get_data(x)

#endif
