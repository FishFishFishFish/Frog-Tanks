#include "window.h"

CAP::CAP(){
    overflow = 0;
    extratimei = 0;
    extratimev = 0;
    fpsi = 0;
    fpsv = 0;
    start = tim = SDL_GetTicks();
    setCap(60);
}
void CAP::setCap(int fps){
    framerate = fps;
    delayperframe = 1000.0 / (double) framerate;
}
void CAP::update(){
    uint32_t newtim = SDL_GetTicks();
    int tmp = floor( delayperframe ) - ( newtim - tim );
    if( floor( overflow ) != 0 ){
        tmp += floor( overflow );
        overflow -= floor( overflow );
    }
    if( tmp > 0 ){
        SDL_Delay( tmp );
        extratimei += tmp;
    }

    overflow += delayperframe - floor( delayperframe );
    fpsi++;

    tim = SDL_GetTicks();
    if( tim - start >= 1000 ){
        fpsv = fpsi;
        fpsi = 0;
        extratimev = extratimei;
        extratimei = 0;
        start = tim;
    }
}
void CAP::print(){
    printf("\rFPS: %i IDLE: %.2f%% ",fpsv,(float)extratimev/10.);
}

WINDOW::WINDOW(){
    owid = rwid = fwid = 1280;
    ohgt = rhgt = fhgt = 720;

    //printf("[%i, %i]", rwid, rhgt);

    bpp = 0;

    fullscreen = false;
    vsync = true;
    resizable = false;
    aaLevel = 8;

    cap.setCap(60);
}
int WINDOW::initiate(){
    //putenv(strdup("SDL_VIDEO_CENTERED=1"));

    const SDL_VideoInfo* info = 0;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){return -1;}
    if (!(info = SDL_GetVideoInfo())){return -2;}

    bpp = info->vfmt->BitsPerPixel;

    fwid = info->current_w;
    fhgt = info->current_h;

    //printf("[%i, %i]", rwid, rhgt);

    if (!refreshContext()){ return 0; }

    return 1;
}
int WINDOW::refreshContextWithStore(){
    SDL_SysWMinfo info2;
    SDL_VERSION(&info2.version);

    if (SDL_GetWMInfo(&info2) == -1) { return -1; }

    HDC tempDC = GetDC( info2.window );
    HGLRC tempRC = wglCreateContext( tempDC );

    if (tempRC == NULL) { return -2; }
    if (!wglShareLists(info2.hglrc, tempRC)) { return -3; }


    if (!refreshContext()){ return 0; }


    SDL_VERSION(&info2.version);
    if (SDL_GetWMInfo(&info2) == -1) { return -4; }
    if (!wglShareLists(tempRC, info2.hglrc)) { return -5; }
    if (!wglDeleteContext(tempRC)) { return -6; }

    return 1;
}
int WINDOW::refreshContext(){

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1); //1*(aaLevel != 0));
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 2); //aaLevel);

    SDL_GL_SetAttribute(SDL_GL_SWAP_CONTROL, 0 + 1*(vsync == true));

    int flags = 0;

    if (fullscreen){
        rwid = fwid;
        rhgt = fhgt;
        flags |= SDL_FULLSCREEN;
    }
    else{
        rwid = owid;
        rhgt = ohgt;
    }

    if (resizable){
        flags |= SDL_RESIZABLE;
    }

    //printf("[%i, %i]", rwid, rhgt);

    if (!(SDL_SetVideoMode(rwid, rhgt, bpp, SDL_OPENGL | flags))){ return 0; } //| SDL_INIT_AUDIO


    glViewport(0, 0, rwid, rhgt);

    glEnable (GL_BLEND); glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST); glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE); glCullFace(GL_BACK);

//    glEnable(GL_FOG);
//    glFogf(GL_FOG_MODE, GL_LINEAR);
//    glFogf(GL_FOG_START, 2);
//    glFogf(GL_FOG_END, -12);


//    glDisable(GL_DEPTH_TEST);
//    glDisable(GL_CULL_FACE);

    return 1;
}
int WINDOW::quit(){
    exit(42);
}

