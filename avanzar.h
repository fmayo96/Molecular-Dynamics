#ifndef AVANZAR_H
#define AVANZAR_H
int verlet_pos(double *X, double *v, double *F, double h, int N);
int verlet_vel(double *v, double *F, double *F2, double h, int N);
double fuerzas(double *F, double *F2, double *E_pot, double rc2, int N, double *X, int l, int L, double *LUT_F, double *LUT_V, double r02, double deltar2, double *f_mod);
int PBC_pos(double *X, double L, int N);
#endif

