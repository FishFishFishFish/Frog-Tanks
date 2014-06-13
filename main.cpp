#include "include.h"
#include "window.h"
#include "math.h"
#include "geometry.h"
#inlcude "game.h"

int main(){
    WINDOW window;
    window.initiate();

    bool KEYS[512]; for(int i = 0; i < 512; i++){ KEYS[i] = false; }

    GAME game;

    int iter = 0; int MOUSEX = 0; int MOUSEY = 0;

    while (true){
#ifdef WIN32
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN: KEYS[event.key.keysym.sym] = true;  break;
                case SDL_KEYUP:   KEYS[event.key.keysym.sym] = false; break;
                case SDL_MOUSEMOTION:   MOUSEX = event.motion.x; MOUSEY = event.motion.y; break;
                case SDL_MOUSEBUTTONDOWN:   break;
                case SDL_MOUSEBUTTONUP:     break;
//                case SDL_VIDEORESIZE:
//						window.rwid = window.owid = event.resize.w;
//						window.rhgt = window.ohgt = event.resize.h;
//
//						SDL_SetVideoMode(window.rwid, window.rhgt, window.bpp, SDL_OPENGL | SDL_RESIZABLE );
//						glViewport(0, 0, window.rwid, window.rhgt);
//						break;
                case SDL_QUIT: window.quit(); break;
            }
        }
#endif

        glClearColor( 255, 255, 255, 255 );
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION); glLoadIdentity();
        glOrtho(0,window.rwid,window.rhgt,0,-100,100);
        glMatrixMode(GL_MODELVIEW); glLoadIdentity();

        glCullFace(GL_FRONT);

        glColor3ub(0,0,0);

        window.cap.update();       //restrain framerate
        //window.cap.fps();          //display framerate

        SDL_GL_SwapBuffers();           //Display to screen
    }
}


