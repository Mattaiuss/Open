#pragma once

#include "engine.h"
#include "endings.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

data_t *init_data(void);
graph_t *init_graph(void);
room_t *init_room(char *name, bool (*validator)(), void (*happen)());
menu_t *init_menu(void);
void reset_data(data_t *data);
void events(data_t *data);
void check_keys(data_t *data);

void destroy(data_t *data);
void check_validation(data_t *data);
void add_at_front(link_t **link, room_t *room);
room_t *add_at_back_rooms(rooms_t **rooms, char *name, bool (*validator)(), void (*happen)());

void return_to_basic(void);

//menu
void display_menu(data_t *data, bool first);

// status
#define MENU    0
#define PLAY    1
#define END     2

#define MOUSE_X sfMouse_getPositionRenderWindow(data->window).x
#define MOUSE_Y sfMouse_getPositionRenderWindow(data->window).y
