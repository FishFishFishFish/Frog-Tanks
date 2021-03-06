#ifndef TANK_H
#define TANK_H

#include "math.h"
#include "geometry.h"
#include "game.h"

struct TANK{
    GAME* parent;

    short power;    // 0 -> 100

    short aimAng;   // 0 -> 180
    VECTOR aim;     // Calculates every time aimAng is changed

    VECTOR p;
    VECTOR dp;

    VECTOR normal;

    bool isInHitbox();
    void render();
};

#endif // TANK_H
