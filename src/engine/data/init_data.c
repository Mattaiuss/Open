/*
** EPITECH PROJECT, 2024
** Open
** File description:
** init_data
*/

#include "open.h"
#include <fcntl.h>
#include <unistd.h>

void init_sprites(struct Sprites *sprites)
{
    sprites->playSprite = sfSprite_create();
    sprites->quitSprite = sfSprite_create();
    sprites->bg = sfSprite_create();
    sprites->logo_sprite = sfSprite_create();
    sprites->default_room_sprite = sfSprite_create();
    sprites->fridge_sprite = sfSprite_create();


    int menu_endings_sprites_size = 5; // replace with actual size
    sprites->menu_endings_sprites = malloc(sizeof(sfSprite*) * menu_endings_sprites_size);
    for (int i = 0; i < menu_endings_sprites_size; i++) {
        sprites->menu_endings_sprites[i] = sfSprite_create();
    }
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
        sfSprite_setPosition(data->menu_endings_sprites[i], (sfVector2f){1500, i * 100 + 200});
        sfSprite_setScale(data->menu_endings_sprites[i], (sfVector2f){200.0f / sfTexture_getSize(data->menu_endings_textures[i]).x, 100.0f / sfTexture_getSize(data->menu_endings_textures[i]).y});
    }
    free(buffer);
}

static validators_t *init_validators(void)
{
    validators_t *validators = malloc(sizeof(validators_t));

    validators->frigo = false;
    validators->phone = false;
    validators->door = false;
    validators->cheese = false;
    validators->tv = false;
    validators->caca_door = false;
    validators->box = false;
    validators->mouse_hole = false;
    validators->key = false;
    validators->is_fridge_open = false;
    return validators;
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
    data->status = MENU;
    data->event = malloc(sizeof(sfEvent));
    data->clock = sfClock_create();
    data->graph = init_graph();
    data->default_room = data->graph->current;
    data->default_room_texture = sfTexture_createFromFile("./assets/sprite/image_test.png", NULL);
    data->default_room_sprite = sfSprite_create();
    data->menu = init_menu();
    data->validators = init_validators();
    sfSprite_setTexture(data->default_room_sprite, data->default_room_texture, false);
    data->cha_la_music = sfMusic_createFromFile("assets/song/cha-la-head-cha-la.ogg");
    data->tok_tok_goku = sfMusic_createFromFile("assets/song/HEY_ITS_ME_GOKU.ogg");
    LINK_GAME(data);
    return data;
}
