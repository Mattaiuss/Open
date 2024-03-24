#include "open.h"

sprites_t *init_sprites(void)
{
    sprites_t *sprites = malloc(sizeof(sprites_t));

    sprites->playSprite = sfSprite_create();
    sprites->quitSprite = sfSprite_create();
    sprites->bg = sfSprite_create();
    sprites->logo_sprite = sfSprite_create();
    sprites->default_room_sprite = sfSprite_create();
    sprites->fridge_sprite = sfSprite_create();
    sprites->chala = sfSprite_create();

    int menu_endings_sprites_size = 5; // replace with actual size
    sprites->menu_endings_sprites = malloc(sizeof(sfSprite*) * menu_endings_sprites_size);
    for (int i = 0; i < menu_endings_sprites_size; i++) {
        sprites->menu_endings_sprites[i] = sfSprite_create();
    }
    sprites->box_open = sfSprite_create();
    sprites->box_top = sfSprite_create();
    sprites->milk = sfSprite_create();
    sprites->cake = sfSprite_create();
    sprites->apple = sfSprite_create();
    sprites->tv = sfSprite_create();
    sprites->key = sfSprite_create();
    sprites->cheese = sfSprite_create();
    sfTexture *text = sfTexture_createFromFile("assets/sprite/box.png", NULL);
    sfSprite_setTexture(sprites->box_open, text, false);
    sfTexture_destroy(text);
    text = sfTexture_createFromFile("assets/sprite/couvercle_box.png", NULL);
    sfSprite_setTexture(sprites->box_top, text, false);
    sfTexture_destroy(text);
    text = sfTexture_createFromFile("assets/sprite/fridge_milk.png", NULL);
    sfSprite_setTexture(sprites->milk, text, false);
    sfTexture_destroy(text);
    text = sfTexture_createFromFile("assets/sprite/fridge_cake.png", NULL);
    sfSprite_setTexture(sprites->cake, text, false);
    sfTexture_destroy(text);
    text = sfTexture_createFromFile("assets/sprite/fridge_apple.png", NULL);
    sfSprite_setTexture(sprites->apple, text, false);
    sfTexture_destroy(text);
    text = sfTexture_createFromFile("assets/sprite/tv.png", NULL);
    sfSprite_setTexture(sprites->tv, text, false);
    sfTexture_destroy(text);
    text = sfTexture_createFromFile("assets/sprite/key.png", NULL);
    sfSprite_setTexture(sprites->key, text, false);
    sfTexture_destroy(text);
    text = sfTexture_createFromFile("assets/sprite/cheese.png", NULL);
    sfSprite_setTexture(sprites->cheese, text, false);
    sfTexture_destroy(text);
    text = sfTexture_createFromFile("assets/sprite/chala.jpg", NULL);
    sfSprite_setTexture(sprites->chala, text, false);
    sfTexture_destroy(text);
    return sprites;
}
