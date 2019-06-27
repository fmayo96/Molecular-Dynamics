#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include "general.h"
#include "inicializar.h"
#include "interaccion.h"
#include "avanzar.h"
#include "visualizacion.h"

int main()
{
int N=125;
int N_frames = 100;
double L = 10, T = 1;
double *X = (double*) malloc (3 * N * sizeof(double));
double *v = (double*) malloc (3 * N * sizeof(double));
double *F = (double*) malloc (3 * N * sizeof(double));
double *E_pot, *E_cin, *E_tot;
E_pot = (double*) malloc(N_frames * sizeof(double));
E_cin = (double*) malloc(N_frames * sizeof(double));
E_tot = (double*) malloc(N_frames * sizeof(double));
double dt = 0.1;
int i, l, size_lut= 100000;
double r0 = 0.000025;
double r02 = r0 * r0;
double rc = 2.5;


char filename[255];
sprintf(filename, "testinteraccion.lammpstrj");

char filename2[255];
sprintf(filename2, "test_Energia.txt");
FILE *fp2=fopen(filename2, "w");

double *LUT_F, *LUT_V, *f_mod;
f_mod = (double*) malloc(sizeof(double));
LUT_F = (double*) malloc(size_lut * sizeof(double));
LUT_V = (double*) malloc(size_lut * sizeof(double));
double deltar = build_LUT(LUT_F, LUT_V, rc, r0, size_lut);
double deltar2 = deltar * deltar;
set_box(X, N, L);
*E_cin = set_v(v, N, T);
save_lammpstrj(filename, X, v, N, L, 0);
for(i = 0; i < 3 * N; i++)
	{
	*(F + i) = 0;
	}
for(l = 1; l < N_frames; l++)
	{
	verlet_vel( v, F, dt, N);
	fuerzas(F, E_pot, rc, N, X, l, L, LUT_F, LUT_V, r02, deltar2, f_mod);
	verlet_vel(v, F, dt, N);
	*(E_cin + l) = Ecin(v, N);
	verlet_pos(X, v, F, dt, N);
	PBC_pos(X, L, N);
	save_lammpstrj(filename, X, v, N, L, l); 
	fprintf(fp2, "%lf %lf \n",*(E_cin + l), *(E_pot + l));
	}

free(X);
free(v);
free(E_pot);
free(E_cin);
free(E_tot);
free(LUT_F);
free(LUT_V);
free(F);


return 0;
}



#include "general.c"
#include "inicializar.c"
#include "interaccion.c"
#include "avanzar.c"
#include "visualizacion.c"

