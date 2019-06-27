#ifndef GENERAL_H
#define GENERAL_H
#include <math.h>
#include <time.h>
double Random();
double Gaussiana(double mu, double sigma);
double Norma2(double *v);
double Distance2(double *v1,double *v2);
int delta(double *delta_X, double *v1, double *v2);
double Ecin(double *v, int N);
#endif

