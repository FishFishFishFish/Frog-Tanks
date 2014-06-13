#include "geometry.h"

void circle(double steps, double rad){
    for (double ang = 0; ang < M_PI*2; ang += 2*M_PI/steps){
		glVertex2d(sin(ang)*rad, cos(ang)*rad);
	}
}

void drawCircle(double steps, double rad){
	glBegin(GL_LINE_LOOP);
	circle(steps, rad);
	glEnd();
}


//VECTOR
void VECTOR::set(double _x, double _y){
    x = _x; y = _y;
}
bool VECTOR::operator==(VECTOR v){
    return (x == v.x && y == v.y);
}
void VECTOR::operator=(VECTOR v){
    x = v.x;
    y = v.y;
}
void VECTOR::operator+=(VECTOR v){
    x += v.x; y += v.y;
}
VECTOR VECTOR::operator+(VECTOR v){
    VECTOR returnThis = *this;
    returnThis += v;
    return returnThis;
}
void VECTOR::operator-=(VECTOR v){
    x -= v.x; y -= v.y;
}
VECTOR VECTOR::operator-(VECTOR v){
    VECTOR returnThis = *this;
    returnThis -= v;
    return returnThis;
}
void VECTOR::operator*=(double factor){
    x *= factor; y *= factor;
}
VECTOR VECTOR::operator*(double factor){
    VECTOR returnThis = *this;
    returnThis *= factor;
    return returnThis;
}
void VECTOR::operator/=(double factor){
    x /= factor; y /= factor;
}
VECTOR VECTOR::operator/(double factor){
    VECTOR returnThis = *this;
    returnThis /= factor;
    return returnThis;
}
double VECTOR::magn(){
    return sqrt(x*x + y*y);
}
bool VECTOR::isZero(){
    return (x == 0 && y == 0);
}
void VECTOR::unitEquals(){
    if (magn()){
        *this /= (magn());
    }
} // vectors with magn() of zero are left as they are
VECTOR VECTOR::unit(){
    if (magn()){
        VECTOR returnThis = *this;
        returnThis /= (returnThis.magn());
        return returnThis;
    }
}
inline void VECTOR::draw(){
    glVertex2d(x,y);
}
void VECTOR::print(){
    printf("[%.2f,%.2f]",x,y);
}
void VECTOR::printNL(){
    printf("[%.2f,%.2f]\n",x,y);
}
void VECTOR::line(){
    glVertex2d(0,0);
    draw();
}
inline void VECTOR::translated(){
    glTranslated(x,y,0);
}
inline void VECTOR::scaled(){
    glScaled(x,y,1);
}
void VECTOR::rotateZ(double radians){
    set(x*cos(radians) - y*sin(radians), x*sin(radians) + y*cos(radians));
}
VECTOR VECTOR::clockwisePerp(){
    VECTOR returnthis;
    returnthis.set(y,-x);
    return returnthis;
}
void VECTOR::rotateTo(VECTOR toVector, double coef){
    x += (toVector.x - x)/coef;
    y += (toVector.y - y)/coef;
}
VECTOR VECTOR::perp(){
    VECTOR returnthis;
    returnthis.set(-y,x);
    return returnthis.unit();
}
double VECTOR::dot(VECTOR v){
    return x*v.x + y*v.y;
}


/* Not sure if this should be used...
void QUAD::set(VECTOR _b, VECTOR _e, double _p, double _w){
    b = _b;
    e = _e;
    p = _p;
    w = _w;
    setArea();
}
void QUAD::operator=(QUAD q){
    b = q.b;
    e = q.e;

    w = q.w;
    h = q.h;

    flex = q.flex;

    a = q.a;

    p = q.p;
}
void QUAD::set(VECTOR _b, VECTOR _e, double _p, double _w, double _h){
    h = _h;
    set(_b, _e, _p, _w);
}
void QUAD::setE(VECTOR _e){
    b += (_e - e);
    e += (_e - e);
}
void QUAD::operator+(VECTOR v){
    b += v;
}
void QUAD::operator+=(VECTOR v){
    b += v;
    e += v;
}
void QUAD::setArea(){
    VECTOR up; up.set(0,1);
    if (h){
        flex = false;
    }
    if ((e-b).isZero()){
        flex = false;
        e += up*w*.5;
        b -= up*w*.5;
        h = w;
    }
    else{
        flex = true;
        h = ((e - b).magn());
    }
    a = w*h;
}
bool QUAD::in(VECTOR p){
    return (c() - p).magn() < w*.5 || (c() - p).magn() < h*.5;
}

VECTOR QUAD::c(){
    if (e.isZero()){ return b; }
    return (b + e) / 2;
}

void QUAD::tick(){
    if (!e.isZero()){
        e.rotateTo(b + (e - b).unit()*h, 1);
    }
}
void QUAD::render(){
    VECTOR len = (((e - b) * p) - (e - b)) / 2;
    //len.set(0,0);
    VECTOR perp = (e - b).perp() / 2;

    double w2 = w;

    if (flex){
        w2 = a / (e - b).magn();
    }

    (e + len + perp*w2).draw();
    (e + len - perp*w2).draw();
    (b - len - perp*w2).draw();
    (b - len + perp*w2).draw();
}
*/

