#include "graph.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

typedef struct data_s data_t;

typedef struct button_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;

    int (*callback)(data_t *data);
    int is_active;
} button_t;

typedef struct {
    sfSprite *playSprite;
    sfSprite *quitSprite;
    sfTexture *newTexture;
} Sprites;

typedef struct {
    sfSprite *bg;
    sfTexture *bg_t;
    button_t *start;
    button_t *help;
    button_t *quit;
    sfRectangleShape *rect;
    sfMusic *music;
    sfSprite *logo_sprite;
    sfTexture *logo_texture;
} menu_t;

typedef struct validators_s{
    bool frigo;
    bool phone;
    bool door;
    bool cheese;
    bool tv;
    bool caca_door;
    bool box;
    bool mouse_hole;
    bool key;
    bool is_fridge_open;
    bool fridge_door;

    bool fridge_apple;
    bool fridge_cake;
    bool fridge_milk;
} validators_t;

typedef struct {
    sfSprite *playSprite;
    sfSprite *goku1;
    sfSprite *goku2;
    sfSprite *quitSprite;
    sfSprite *bg;
    sfSprite *logo_sprite;
    sfSprite *default_room_sprite;
    sfSprite **menu_endings_sprites;
    sfSprite *fridge_sprite;
    sfSprite *box_open;
    sfSprite *box_top;
    sfSprite *milk;
    sfSprite *cake;
    sfSprite *apple;
    sfSprite *tv;
    sfSprite *key;
    sfSprite *cheese;
    sfSprite *door;
    sfSprite *chala;
    sfSprite *play;
    sfSprite *quit;
    sfSprite *wait_ending_screen;

    sfTexture *goku1_text;
    sfTexture *goku2_text;
    sfTexture *quitSprite_text;
    sfTexture *bg_text;
    sfTexture *logo_sprite_text;
    sfTexture *default_room_sprite_text;
    sfTexture **_textmenu_endings_sprites;
    sfTexture *fridge_sprite_text;
    sfTexture *box_open_text;
    sfTexture *box_top_text;
    sfTexture *milk_text;
    sfTexture *cake_text;
    sfTexture *apple_text;
    sfTexture *tv_text;
    sfTexture *key_text;
    sfTexture *cheese_text;
    sfTexture *door_text;
    sfTexture *chala_text;
    sfTexture *play_text;
    sfTexture *quit_text;
    sfTexture *wait_ending_screen_text;

    sfSprite *screamer_goku;
    sfIntRect rect;
} sprites_t;

struct data_s {
    sfRenderWindow *window;
    sfEvent *event;
    sfClock *clock;
    int status;

    sfSprite *bg;
    sfTexture *bg_t;

    sfSound *sound;
    sfSoundBuffer *soundbuffer;

    int nb_buttons;
    button_t **buttons;

    // graph
    room_t *default_room;
    sfSprite *default_room_sprite;
    sfTexture *default_room_texture;
    graph_t *graph;

    sprites_t *items;

    int nb_endings;
    int *optained_endings;
    sfSprite **menu_endings_sprites;
    sfTexture **menu_endings_textures;

    validators_t *validators;

    // menu
    menu_t *menu;
    // Game states
    int box_clicked; // nb de fois que le joueur a cliquer sur la boite
    sfMusic *cha_la_music;
    sfMusic *tok_tok_goku;
    sfMusic *chiasse_inf;
};
