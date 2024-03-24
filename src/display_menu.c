
#include <SFML/Audio.h>
#include "../include/open.h"

int start_game(data_t *data)
{
    data->status = 1;
    return 0;
}

int quit_game(data_t *data)
{
    sfRenderWindow_close(data->window);
    data->status = 2;
    return 0;
}

static void is_touched(data_t *data, button_t *start, button_t *quit)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(data->window);
    sfFloatRect start_rect = sfSprite_getGlobalBounds(start->sprite);
    sfFloatRect quit_rect = sfSprite_getGlobalBounds(quit->sprite);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&start_rect, mouse.x, mouse.y))
            start->callback(data);
        if (sfFloatRect_contains(&quit_rect, mouse.x, mouse.y))
            quit->callback(data);
    }
}

static void set_buttons(button_t *start, button_t *quit, sfRectangleShape *rect)
{
    start->sprite = sfSprite_create();
    start->texture = sfTexture_createFromFile("assets/sprite/play.png", NULL);
    sfSprite_setTexture(start->sprite, start->texture, sfTrue);
    start->pos = (sfVector2f){800 + sfTexture_getSize(start->texture).x / 2, 500};
    sfSprite_setPosition(start->sprite, start->pos);
    quit->sprite = sfSprite_create();
    quit->texture = sfTexture_createFromFile("assets/sprite/quit.png", NULL);
    sfSprite_setTexture(quit->sprite, quit->texture, sfTrue);
    quit->pos = (sfVector2f){800 + sfTexture_getSize(quit->texture).x / 2, 650};
    sfSprite_setPosition(quit->sprite, quit->pos);
    start->callback = &start_game;
    quit->callback = &quit_game;
    sfRectangleShape_setSize(rect, (sfVector2f){200, 100});
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(rect, 5);
    sfRectangleShape_setOutlineColor(rect, sfWhite);
}

void display_menu(data_t *data)
{
    sfMusic *music = sfMusic_createFromFile("assets/song/Menu_audio.ogg");
    sfMusic_play(music);
    sfSprite *bg = sfSprite_create();
    sfTexture *bg_t = sfTexture_createFromFile("assets/sprite/fond.jpg", NULL);
    sfSprite_setTexture(bg, bg_t, sfTrue);
    button_t *start = malloc(sizeof(button_t));
    button_t *quit = malloc(sizeof(button_t));
    sfRectangleShape *rect = sfRectangleShape_create();
    sfSprite *newSprite = sfSprite_create();
    sfTexture *newTexture = sfTexture_createFromFile("assets/sprite/Logo.png", NULL);
    sfSprite_setTexture(newSprite, newTexture, sfTrue);
    sfVector2u windowSize = sfRenderWindow_getSize(data->window);
    sfVector2f spritePos = {windowSize.x / 2.0f - sfTexture_getSize(newTexture).x / 2.0f, 100};
    sfSprite_setPosition(newSprite, spritePos);

    set_buttons(start, quit, rect);
    sfRenderWindow_clear(data->window, sfBlack);
    while (sfRenderWindow_isOpen(data->window) && data->status == 0) {
        while (sfRenderWindow_pollEvent(data->window, data->event)) {
            if (data->event->type == sfEvtClosed)
                sfRenderWindow_close(data->window);
            if (data->event->type == sfEvtKeyPressed)
                check_keys(data);
        }
        is_touched(data, start, quit);
        sfRenderWindow_drawSprite(data->window, bg, NULL);
        sfRenderWindow_drawSprite(data->window, start->sprite, NULL);
        sfRenderWindow_drawSprite(data->window, quit->sprite, NULL);
        sfRenderWindow_drawSprite(data->window, newSprite, NULL);
        for (int i = 0; i < data->nb_endings; i++) {
            if (data->optained_endings[i] == 1)
                sfRenderWindow_drawSprite(data->window, data->menu_endings_sprites[i], NULL);
            sfRectangleShape_setPosition(rect, (sfVector2f){1500, i * 100 + 200});
            sfRenderWindow_drawRectangleShape(data->window, rect, NULL);
        }
        sfRenderWindow_display(data->window);
    }
    sfMusic_stop(music);
    sfMusic_destroy(music);
}
