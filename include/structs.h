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

    int nb_endings;
    int *optained_endings;
    sfSprite **menu_endings_sprites;
    sfTexture **menu_endings_textures;

    // Game states
    int box_clicked; // nb de fois que le joueur a cliquer sur la boite
};
