#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "general.h"

int main()
{
//Test de Random y Gaussiana. Devuelve vectores para hacer un histograma y verificar las distribuciones.
int i;
int N = 10000000;
float *xrand, *xgauss;
xrand=(float*)malloc(N*sizeof(float));
xgauss=(float*)malloc(N*sizeof(float));

char filename[255];
sprintf(filename, "testgeneral.txt");
srand(time(NULL));		
FILE *fp=fopen(filename,"w");

for(i = 0; i < N; i++)
	{
	*(xgauss + i) = Gaussiana(0,1);
	*(xrand + i) = Random();
	}
for(i = 0; i < N; i++)
	{
	fprintf(fp,"%f %f \n",*(xrand+i),*(xgauss+i));
	}

// Test de la Norma. Calcula la norma del vector v que se inserte.
float *v;
v=(float*)malloc(3*sizeof(float));
*v = 1;
*(v + 1) = 2;
*(v + 2) = 2;

printf("Norma2= %f\n",Norma2(v));

// Test de Distance. Calcula la distancia entre v1 y v2.

float *v1;
v1=(float*)malloc(3*sizeof(float));
*v1 = 1;
*(v1 + 1) = 2;
*(v1 + 2) = 1;

float *v2;
v2=(float*)malloc(3*sizeof(float));
*v2 = 0;
*(v2 + 1) = 1;
*(v2 + 2) = 0;

printf("%f\n",Distance2(v1,v2));

return 0;
}

#include "general.c"
