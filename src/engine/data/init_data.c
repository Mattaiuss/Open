/*
** EPITECH PROJECT, 2024
** Open
** File description:
** init_data
*/

#include "open.h"
#include <fcntl.h>
#include <unistd.h>

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

static graph_t *init_graph(void)
{
    graph_t *graph = malloc(sizeof(graph));

    graph->rooms = init_rooms();
    graph->current = graph->rooms->current;
    graph->nb_rooms = 2;
    return graph;
}

static void set_endings(data_t *data)
{
    data->nb_endings = 5;
    int fd = open("save.txt", O_RDONLY);
    char *buffer = malloc(sizeof(char) * 100);
    read(fd, buffer, 100);
    data->optained_endings = malloc(sizeof(int) * data->nb_endings);
    if (buffer[0] == '\0' || buffer[0] == '\n') {
        for (int i = 0; i < data->nb_endings; i++)
            data->optained_endings[i] = 0;
    } else {
        for (int i = 0; i < data->nb_endings; i++)
            data->optained_endings[i] = buffer[i] - '0';
    }
    close(fd);
    data->menu_endings_sprites = malloc(sizeof(sfSprite *) * data->nb_endings);
    data->menu_endings_textures = malloc(sizeof(sfTexture *) * data->nb_endings);
    char *textures[] = {"./assets/sprite/succes/attente_longue.png",
                        "./assets/sprite/succes/basic.png",
                        "./assets/sprite/succes/caca.png",
                        "./assets/sprite/succes/goblin.png",
                        "./assets/sprite/succes/goku.png"};
    for (int i = 0; i < data->nb_endings; i++) {
        data->menu_endings_textures[i] = sfTexture_createFromFile(textures[i], NULL);
        data->menu_endings_sprites[i] = sfSprite_create();
        sfSprite_setTexture(data->menu_endings_sprites[i], data->menu_endings_textures[i], sfTrue);
        sfSprite_setPosition(data->menu_endings_sprites[i], (sfVector2f){1500, i * 100});
    }
    free(buffer);
}

data_t *init_data(void)
{
    data_t *data = malloc(sizeof(data_t));
    data->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "OPEN", sfClose | sfFullscreen, NULL);
    data->sound = sfSound_create();
    data->soundbuffer = sfSoundBuffer_createFromFile("./assets/song/minecraft_click.ogg");
    sfSound_setBuffer(data->sound, data->soundbuffer);
    data->box_clicked = 0;
    set_endings(data);
    data->event = malloc(sizeof(sfEvent));
    data->clock = sfClock_create();
    data->graph = init_graph();
    LINK_GAME(data);
    return data;
}
