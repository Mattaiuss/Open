#include "open.h"

data_t *get_data(data_t *data)
{
    static data_t *save;

    if (data != NULL)
        save = data;
    return save;
}
