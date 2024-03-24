#include "open.h"

static sfSprite *my_create_sprite(const char *path)
{
    sfSprite *sprite = sfSprite_create();

    sfTexture *text = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(sprite, text, false);
    return sprite;
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
    sprites->playSprite = my_create_sprite("assets/sprite/play.png");
    sprites->quitSprite = my_create_sprite("assets/sprite/quite.png");
    sprites->fridge_sprite = my_create_sprite("assets/sprite/frigo/frigo.png");
    sprites->box_open = my_create_sprite("assets/sprite/box.png");
    sprites->box_top = my_create_sprite("assets/sprite/couvercle_box.png");
    sprites->milk = my_create_sprite("assets/sprite/fridge_milk.png");
    sprites->cake = my_create_sprite("assets/sprite/fridge_cake.png");
    sprites->apple = my_create_sprite("assets/sprite/fridge_apple.png");
    sprites->tv = my_create_sprite("assets/sprite/tv.png");
    sprites->key = my_create_sprite("assets/sprite/key.png");
    sprites->cheese = my_create_sprite("assets/sprite/cheese.png");
    sprites->chala = my_create_sprite("assets/sprite/chala.jpg");
    sprites->wait_ending_screen = my_create_sprite("assets/sprite/wait_ending_screen.png");
    return sprites;
}
