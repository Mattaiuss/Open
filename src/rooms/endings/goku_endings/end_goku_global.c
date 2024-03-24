#include "open.h"

bool goku_global_validator(void)
{
    return GAME.validators->tv;
}

void goku_global_happen(void)
{
    static bool first = true;
    //metre la photo chala.jpg
    // sfRenderWindow_drawSprite(GAME.window, GAME.sprites->chala, NULL);
    // sfRenderWindow_display(GAME.window);
    if (first) {
        sfMusic_play(GAME.cha_la_music);
        sfSleep(sfSeconds(5));
        sfMusic_stop(GAME.cha_la_music);
        sfMusic_play(GAME.tok_tok_goku);
        first = false;
    }

}
