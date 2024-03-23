/*
** EPITECH PROJECT, 2024
** Open
** File description:
** destroy
*/

#include "open.h"

void destroy(data_t *data)
{
    sfRenderWindow_destroy(data->window);
    sfClock_destroy(data->clock);
    free(data->event);
    if (sfSound_getStatus(data->sound) == sfPlaying)
        sfSound_stop(data->sound);
    sfSound_destroy(data->sound);
    sfSoundBuffer_destroy(data->soundbuffer);
    for (int i = 0; i < data->nb_endings; i++) {
        sfSprite_destroy(data->menu_endings_sprites[i]);
        sfTexture_destroy(data->menu_endings_textures[i]);
    }
    free(data);
}