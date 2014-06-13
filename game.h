#ifndef GAME_H
#define GAME_H

#include "math.h"
#include "geometry.h"
#include "tank.h"
#include "terrain.h"
#include "projectile.h"

struct GAME{
    TERRAIN terrain;
    PROJECTILES projectiles;
    std::vector<TANK> tanks;

    double ddp;

    short type;

    void tick();
    void render();
};

#endif // GAME_H
