#ifndef WINDOW_H
#define WINDOW_H

struct CAP{
    int framerate;
    double overflow;
    uint32_t tim, start;
    double delayperframe;
    int extratimei;
    int extratimev;
    int fpsi;
    int fpsv;

    CAP();
    void setCap(int fps);
    void update();
    void print();
};


struct WINDOW{
    unsigned short owid, ohgt;   //Storing the previous res during fullscreen
    unsigned short fwid, fhgt;   //System screen res
    unsigned short rwid, rhgt;   //Current res

    int bpp;

    bool fullscreen;
    bool vsync;
    bool resizable;
    unsigned char aaLevel;

    CAP cap;

    WINDOW();
    int initiate();
    int refreshContextWithStore();
    int refreshContext();
    int quit();
};

#endif // WINDOW_H
