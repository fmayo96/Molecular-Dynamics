#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "general.h"
#include "inicializar.h"
#include "visualizacion.h"

int main()
{
int N = 125;
float L = 10,T = 1;
float *X = (float*)malloc(3*N*sizeof(float));
float *v = (float*)malloc(3*N*sizeof(float));
float t = 0, dt = 0.1;

char filename[255];
sprintf(filename, "testinicializar.lammpstrj");
int N_frames = 100;

float dl = set_box(X,N,L);
float Ecin = set_v(v,N,T);
for(int l = 0; l < N_frames; l++)
	{
	for(int i = 0; i < 3* N; i++)
		{
		*(X+i) += *(v+i)*t;
		}
	t += dt;
	save_lammpstrj(filename, X, v, N, L, l);
	}
return 0;
}

#include "general.c"
#include "inicializar.c"
#include "visualizacion.c"

