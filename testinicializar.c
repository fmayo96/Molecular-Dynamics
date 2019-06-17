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
int N = 100;
float L = 10,T = 1;
float *x = (float*)malloc(3*N*sizeof(float));
float *v = (float*)malloc(3*N*sizeof(float));

char filename[255];
sprintf(filename, "testinicializar.lammpstrj");
int N_frames = 1;

float dl = set_box(x,N,L);
float Ecin = set_v(v,N,T);

save_lammpstrj(filename, x, v, N, L, 0);

return 0;
}

#include "general.c"
#include "inicializar.c"
#include "visualizacion.c"

