#ifndef AVANZAR_H
#define AVANZAR_H
int verlet_pos(double *X, double *v, double *F, double h, int N);
int verlet_vel(double *v, double *F, double *F2, double h, int N);
double fuerzas(double *F, double *F2, double *E_pot, double rc2, int N, double *X, int l, double L, double *LUT_F, double *LUT_V, double r02, double deltar2, double *f_mod, double *delta_X);
int PBC_pos(double *X, double L, int N);
double temp_change(double *v, int N, double *E_cin, double T_final, double dT, int l, int Termalizacion, int Pasos_T);
#endif

