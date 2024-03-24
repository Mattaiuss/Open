#include "open.h"

static void my_create_sprite(const char *path, sfSprite **sprite, sfTexture **text)
{
    *sprite = sfSprite_create();
    *text = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(*sprite, *text, false);
}

sprites_t *init_sprites(void)
{
    sprites_t *sprites = malloc(sizeof(sprites_t));

    sprites->logo_sprite = sfSprite_create();
    sprites->bg = sfSprite_create();

    int menu_endings_sprites_size = 5; // replace with actual size
    sprites->menu_endings_sprites = malloc(sizeof(sfSprite*) * menu_endings_sprites_size);
    for (int i = 0; i < menu_endings_sprites_size; i++) {
        sprites->menu_endings_sprites[i] = sfSprite_create();
    }
    my_create_sprite("assets/sprite/play.png", &(sprites->play), &(sprites->play_text));
    my_create_sprite("assets/sprite/quit.png", &(sprites->quit), &(sprites->quit_text));
    my_create_sprite("assets/sprite/frigo/frigo.png", &(sprites->fridge_sprite), &(sprites->fridge_sprite_text));
    my_create_sprite("assets/sprite/box.png", &(sprites->box_open), &(sprites->box_open_text));
    my_create_sprite("assets/sprite/couvercle_box.png", &(sprites->box_top), &(sprites->box_top_text));
    my_create_sprite("assets/sprite/fridge_milk.png", &(sprites->milk), &(sprites->milk_text));
    my_create_sprite("assets/sprite/fridge_cake.png", &(sprites->cake), &(sprites->cake_text));
    my_create_sprite("assets/sprite/frigo/apple.png", &(sprites->apple), &(sprites->apple_text));
    my_create_sprite("assets/sprite/tv.png", &(sprites->tv), &(sprites->tv_text));
    my_create_sprite("assets/sprite/key.png", &(sprites->key), &(sprites->key_text));
    my_create_sprite("assets/sprite/cheese.png", &(sprites->cheese), &(sprites->cheese_text));
    my_create_sprite("assets/sprite/chala.jpg", &(sprites->chala), &(sprites->chala_text));
    my_create_sprite("assets/sprite/wait_ending_screen.png", &(sprites->wait_ending_screen), &(sprites->wait_ending_screen_text));
    my_create_sprite("assets/sprite/goku1.png", &(sprites->goku1), &(sprites->goku1_text));
    my_create_sprite("assets/sprite/goku2.png", &(sprites->goku2), &(sprites->goku2_text));
    return sprites;
}
