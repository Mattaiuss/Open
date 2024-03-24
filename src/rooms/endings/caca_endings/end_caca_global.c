#include "open.h"

bool caca_global_validator(void) {
    return GAME.validators->fridge_apple;
}

void caca_global_happen(void) {
    static bool first =true;

    if (first) {
       sfMusic_play(GAME.chiasse_inf);
        first = false;
    }
}
