#include "open.h"

int start_game(data_t *data)
{
    sfMusic* music;
    music = sfMusic_createFromFile("assets/song/Game_audio.ogg");

    sfRenderWindow_clear(data->window, sfBlack);
    sfMusic_play(music);
    data->status = PLAY;
    sfClock_restart(data->clock);
    LINK_GAME(data);
    return 0;
}

int quit_game(data_t *data)
{
    sfRenderWindow_close(data->window);
    data->status = END;
    LINK_GAME(data);
    return 0;
}

int help_game(data_t *data)
{
    sfRenderWindow_clear(data->window, sfBlack);
    data->status = HELP;
    LINK_GAME(data);
    return 0;
}

static void set_buttons(button_t *start, button_t *quit, button_t *help, sfRectangleShape *rect)
{
    start->sprite = sfSprite_create();
    start->texture = sfTexture_createFromFile("assets/sprite/play.png", NULL);
    sfSprite_setTexture(start->sprite, start->texture, sfTrue);
    start->pos = (sfVector2f){260 + sfTexture_getSize(start->texture).x / 2, 510};
    sfSprite_setPosition(start->sprite, start->pos);
    quit->sprite = sfSprite_create();
    quit->texture = sfTexture_createFromFile("assets/sprite/quit.png", NULL);
    sfSprite_setTexture(quit->sprite, quit->texture, sfTrue);
    quit->pos = (sfVector2f){250 + sfTexture_getSize(quit->texture).x / 2, 885};
    sfSprite_setPosition(quit->sprite, quit->pos);
    help->sprite = sfSprite_create();
    help->texture = sfTexture_createFromFile("assets/sprite/play.png", NULL);
    sfSprite_setTexture(help->sprite, help->texture, sfTrue);
    help->pos = (sfVector2f){260 + sfTexture_getSize(help->texture).x / 2, 700};
    sfSprite_setPosition(help->sprite, help->pos);
    start->callback = &start_game;
    quit->callback = &quit_game;
    help->callback = &help_game;
    sfRectangleShape_setSize(rect, (sfVector2f){200, 100});
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(rect, 5);
    sfRectangleShape_setOutlineColor(rect, sfWhite);
}

menu_t *init_menu()
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->bg = sfSprite_create();
    menu->bg_t = sfTexture_createFromFile("./assets/sprite/menu.png", NULL);
    sfSprite_setTexture(menu->bg, menu->bg_t, sfTrue);
    menu->start = malloc(sizeof(button_t));
    menu->quit = malloc(sizeof(button_t));
    menu->help = malloc(sizeof(button_t));
    menu->rect = sfRectangleShape_create();
    set_buttons(menu->start, menu->quit, menu->help, menu->rect);
    menu->music = sfMusic_createFromFile("./assets/song/Menu_audio.ogg");
    return menu;
}
