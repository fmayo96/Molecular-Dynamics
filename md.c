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
// Defino las variables.
srand(time(NULL));
int N = 512;
int N_frames = 120000, N_skip = 10i, N_T = 100,  Pasos_T = 1000;
double rho = 0.8442, L = cbrt(N / rho), T = 2.0;
double *X = (double*) malloc (3 * N * sizeof(double));
double *v = (double*) malloc (3 * N * sizeof(double));
double *F = (double*) malloc (3 * N * sizeof(double));
double *F2 = (double*) malloc (3 * N * sizeof(double));
double *E_pot = 0, *E_cin, *E_tot;
E_pot = (double*) malloc(N_frames * sizeof(double));
E_cin = (double*) malloc(N_frames * sizeof(double));
E_tot = (double*) malloc(N_frames * sizeof(double));
double h = 0.001;
int l = 0, size_lut= 500000;
double r02 = 0.00000025;
double rc2 = 6.25;
double *delta_X;
delta_X = malloc(3 * sizeof(double));
double T_final = 0.728;
double dT = (double) (T - T_final) / (double) Pasos_T;
// Creo los programas para VMD y printear.
char filename[255];
sprintf(filename, "testinteraccion.lammpstrj");

char filename2[255];
sprintf(filename2, "test_Energia.txt");
FILE *fp2=fopen(filename2, "w");
// Creo las tablas de F y V.
double *LUT_F, *LUT_V, *f_mod;
f_mod = (double*) malloc(sizeof(double));
LUT_F = (double*) malloc(size_lut * sizeof(double));
LUT_V = (double*) malloc(size_lut * sizeof(double));
double deltar2 = build_LUT(LUT_F, LUT_V, rc2, r02, size_lut);
// Pongo las condiciones iniciales.
set_box(X, N, L);
*E_cin = set_v(v, N, T);
save_lammpstrj(filename, X, v, N, L, 0);
fuerzas(F, F2, E_pot, rc2, N, X, l, L, LUT_F, LUT_V, r02, deltar2, f_mod, delta_X);

// Evolucion temporal.
for(l = 1; l < N_frames ; l++)
	{printf("Progreso %lf %% \r",(double) l * 100 / N_frames);
	*(E_cin + l) = 0;
	*(E_pot + l) = 0;
	verlet_pos(X, v, F, h, N);
	PBC_pos(X, L, N);
	fuerzas(F, F2, E_pot, rc2, N, X, l, L, LUT_F, LUT_V, r02, deltar2, f_mod, delta_X);
	verlet_vel(v, F, F2, h, N);
	*(E_cin + l) = Ecin(v, N);
	if(l % N_skip == 0)
		save_lammpstrj(filename, X, v, N, L, l); 
	if(l % N_T == 0)
		temp_change(v, N, E_cin, dT, l);
	}

for(l = 0; l < N_frames; l++)
	{
	fprintf(fp2, "%lf %lf \n",*(E_cin + l), *(E_pot + l) /(double)N);
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

