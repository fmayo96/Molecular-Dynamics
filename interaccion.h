#ifndef INTERACCION_H
#define INTERACCION_H
double build_LUT(double *LUT_F, double *LUT_V, double rc, double r0, int size_lut);
double pair_force(double *LUT_F, double *LUT_V, double rij2, double r02, double deltar2, double *f_mod);
int PBC_force(double *delta_X, double L);
#endif

