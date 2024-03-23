#include "graph.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

typedef struct data_s data_t;

typedef struct button_s {
    sfSprite *sprite;
    sfTexture *textures;
    sfVector2f pos;

    int (*callback)(data_t *data);
    int is_active;
} button_t;

struct data_s {
    sfRenderWindow *window;
    sfEvent *event;
    sfClock *clock;

    sfSprite *bg;
    sfTexture *bg_t;

    sfSound *sound;
    sfSoundBuffer *soundbuffer;

    int nb_buttons;
    button_t **buttons;
    graph_t *graph;

    int nb_endings;
    int *optained_endings;
    sfSprite **menu_endings_sprites;
    sfTexture **menu_endings_textures;

    // Game states
    int box_clicked; // nb de fois que le joueur a cliquer sur la boite
};
