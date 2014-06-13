#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "math.h"
#include "geometry.h"
#include "game.h"

enum {P_BASIC=0, P_CARPETBOMB, P_CARPETBOMBCARPET, P_SMLATOMBOMB, P_ATOMBOMB};

struct PROJECTILES{
    GAME* parent;

    std::vector<VECTOR> p;
    std::vector<VECTOR> dp;

    std::vector<short> type;

    void fire(VECTOR _p, VECTOR _dp, short _type);
    void tick();
    void render();
};

#endif // PROJECTILE_H
