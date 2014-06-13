#ifndef __INCLUDEGUARD__include_h
#define __INCLUDEGUARD__include_h

#include <SDL/SDL.h>        //SDL
#undef main
#include "SDL/SDL_syswm.h"

#include <GL\gl.h>         //OpenGL
#include <GL\glu.h>

#define _XOPEN_SOURCE
#define _SVID_SOURCE

#include <cstdlib>         //Console stuff
#include <cstdio>

#include <cmath>            //Math stuff
#include <cstdint>

#include <vector>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define WIN32

#endif
