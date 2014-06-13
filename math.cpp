#include "math.h"

///inline double abso(double x){
//    return sqrt(x*x);
///}

inline bool isBit(unsigned char byte, unsigned char i){
    return (byte&exp2arr[i]);
}

double moveTo(double* fromDbl, double toDbl, double coef){
    *fromDbl += (toDbl - *fromDbl)/coef;
    ///if (toDbl - *fromDbl < .05 && toDbl - *fromDbl > -.05){ *fromDbl = toDbl; }
    return *fromDbl;
}

bool isAdjacent(int x1, int y1, int x2, int y2){
    int dx = x1-x2;
    int dy = y1-y2;

    return ((dx == 0 && (dy == 1 || dy == -1)) || (dy == 0 && (dx == 1 || dx == -1)));
}

inline int randInt(int a, int b){
	if (a == b){ return a; }
	return (rand()%(b-a) + a);
}  //Only works for differences of a and b less than RAND_MAX, usually about 65536...
float randFloatD2(float a, float b){
	return randInt(a*100, b*100)/100.;
}
inline double random(){
    return randInt(0,10000)/10000.;
}
double gaussianPositive(double mu, double sigma){
    return mu + sigma*sqrt(-log(randInt(1,10000)/10000.))/.682018;
}
double gaussian(double mu, double sigma){
    double x = sigma*sqrt(-log(randInt(1,10000)/10000.))/.682018;
    switch (rand()%2){
        case 0: return mu - x;
        case 1: return mu + x;
    }
}
double gaussianAt(double mu, double sigma, double x){
    // To add.
}
int dir(double x1, double x2){
    return (x1 == x2)?(0):( (x1 < x2)?(1):(-1) );
}

