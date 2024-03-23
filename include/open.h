#pragma once

#include "engine.h"
#include "endings.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

data_t *init_data(void);
void events(data_t *data);
void destroy(data_t *data);
void check_validation(data_t *data);
void add_at_front(link_t **link, room_t *room);
