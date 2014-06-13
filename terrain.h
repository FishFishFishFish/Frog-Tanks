#ifndef TERRAIN_H
#define TERRAIN_H

#include "math.h"
#include "geometry.h"
#include "game.h"

#define WIDTH 512 // Decide on width...

enum{T_FOREST=0, T_DESERT, T_MOUNTAIN, T_DARK, T_RANDOM};

struct TERRAIN{
    GAME* parent;

    short height[WIDTH];

    short currentType;

    void generate();

    bool isUnder(VECTOR v);
    VECTOR normalAt(double x);

    void explode(VECTOR v, short kind);
    void tick();
    void render();
};

#endif // TERRAIN_H
