#ifndef __INCLUDEGUARD__geometry_h
#define __INCLUDEGUARD__geometry_h

#include <cmath>            //Math stuff
#include <vector>

#include "math.h"

//#define CENTER

#define INSET .001


void circle(double steps, double rad);
void drawCircle(double steps, double rad);

struct VECTOR{
    double x;
    double y;

    void set(double _x, double _y);

    bool operator==(VECTOR v);
    void operator=(VECTOR v);

    void operator+=(VECTOR v);
    VECTOR operator+(VECTOR v);

    void operator-=(VECTOR v);
    VECTOR operator-(VECTOR v);

    void operator*=(double factor);
    VECTOR operator*(double factor);

    void operator/=(double factor);
    VECTOR operator/(double factor);

    double magn();
    bool isZero();

    void unitEquals();
    VECTOR unit();

    double dot(VECTOR v);

    void draw();
    void print();
    void printNL();
    void line();
    inline void translated();
    inline void scaled();

    void rotateZ(double radians);
    VECTOR clockwisePerp();
    void rotateTo(VECTOR toVector, double coef);

    VECTOR perp();
};

/*
struct QUAD{
    VECTOR b;
    VECTOR e;

    double w;
    double h;

    bool flex;

    double a;

    double p;

    void set(VECTOR _b, VECTOR _e, double _p, double _w);
    void set(VECTOR _b, VECTOR _e, double _p, double _w, double _h);
    void setE(VECTOR _e);
    void setV(bool _v);

    void operator+(VECTOR v);
    void operator+=(VECTOR v);
    void operator=(QUAD q);

    void setArea();

    bool in(VECTOR p);

    VECTOR c();

    void tick();
    void render();
};
*/

#include "include.h"

#endif
