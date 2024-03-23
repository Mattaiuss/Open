#pragma once

#include "engine.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

data_t *init_data(void);
void events(data_t *data);
void destroy(data_t *data);
