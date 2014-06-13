#include "terrain.h"


void TERRAIN::generate(){
    for (int i = 0; i < WIDTH; i++) {
        h[i] = 5*sin(i*M_PI/64) + 10*sin(i*M_PI/512) + 60;
    }
}
bool TERRAIN::isUnder(VECTOR v){
    return (heightAt(v.x) > v.y);
}
double TERRAIN::heightAt(double x){
    double perc = x - (int)x;
    return (perc*heightAt((int)x) + (1 - perc)*heightAt((int)x + 1));
}
VECTOR TERRAIN::normalAt(double x){
    VECTOR toReturn;
    toReturn.set(2, (heightAt(x-1) + heightAt(x+1))/2);
    return toReturn.perp().unit();
}
void TERRAIN::explode(VECTOR v, short kind){
    
}
void TERRAIN::tick(){
    
}
void TERRAIN::render(){
    glBegin(GL_POLYGON);
    
    glVertex2d(1,0);
    for (int i = 0; i < WIDTH; i++) {
        glVertex2d(i+1,h[i]);
    }
    glVertex2d(WIDTH,0);
    
    glEnd();
}