#ifndef __INCLUDEGUARD__math_h
#define __INCLUDEGUARD__math_h

#include "include.h"

//inline double abs(double x);

const unsigned short exp2arr[16] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};

double moveTo(double* fromDbl, double toDbl, double coef);

bool isAdjacent(int x1, int y1, int x2, int y2);

inline int randInt(int a, int b);
float randFloatD2(float a, float b);
inline double random();
double gaussianPositive(double mu, double sigma);
double gaussian(double mu, double sigma);
double gaussianAt(double mu, double sigma, double x);
int dir(double x1, double x2);

#endif
