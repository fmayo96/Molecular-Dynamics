#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "general.h"
#include "inicializar.h"
#include "interaccion.h"

int main()
{
int size_lut = 100000, N = 125;
double L = 10, T = 1;
double *LUT_F;
double *LUT_V;
LUT_F = (double*) malloc(size_lut * sizeof(double));
LUT_V = (double*) malloc(size_lut * sizeof(double));
double *X, *v, *F;
X = (double*) malloc(3 * N * sizeof(double));
v = (double*) malloc(3 * N * sizeof(double));
F = (double*) malloc(N * sizeof(double));
double rc = 2.5, rc2 = rc * rc;
double r0 = 1, r02 = r0 * r0, deltar, deltar2;
double *delta_X, *f_mod;
delta_X = (double*) malloc (3 * sizeof(double));
f_mod = (double*) malloc (sizeof(double));
double rij2;
int i, j, k;
set_box(X, N, L);
set_v(v, N, T);
deltar = build_LUT(LUT_F, LUT_V, rc, r0, size_lut);
deltar2 = deltar * deltar;
for(i = 0; i < N; i++)
	{
	*(F + i) = 0;
	}
for(i = 1; i < N; i++)
	{
	for(j = 0; j < i; j++)
		{for(k = 0; k < 3; k++)
			{
			*(delta_X + k) = *(X + 3*i + k) - *(X + 3*j + k);
			}
		PBC_force(delta_X, L);
		rij2 = Norma2(delta_X);
		printf("%lf \n", rij2);

		if(rij2 < rc2)
			{
			pair_force(LUT_F, LUT_V, rij2, r02, deltar2, f_mod);
			*(F + i) += *f_mod;
			*(F + j) -= *f_mod; 
			}	
		}
	}
char filename[255];
sprintf(filename, "testinteraccion.txt");
FILE *fp = fopen(filename, "w");
for(i = 0; i < N; i++)
	{
	fprintf(fp, "%lf", *(F + i));
	}
fclose(fp);
return 0;
}

#include "general.c"
#include "inicializar.c"
#include "interaccion.c"


