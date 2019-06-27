#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "general.h"
#include "inicializar.h"
#include "interaccion.h"

int main()
{
int size_lut = 100000;
double *LUT_F;
double *LUT_V;
LUT_F = (double*) malloc(size_lut * sizeof(double));
LUT_V = (double*) malloc(size_lut * sizeof(double));
double rc = 2.5;
double r0 = 1;
double deltar;

char filename[255];
sprintf(filename, "test_LUT.txt");
FILE *fp = fopen(filename, "w");
deltar = build_LUT(LUT_F, LUT_V, rc, r0, size_lut);
double *r;
r = (double*) malloc(size_lut *sizeof(double));
for(int i = 0; i < size_lut; i++ )
	{ *(r + i) = r0 + i * deltar;
	fprintf(fp," %lf  %lf %lf \n",*(r + i) ,*(LUT_F + i), *(LUT_V + i));
	}
fclose(fp);
return 0;
}

#include "general.c"
#include "inicializar.c"
#include "interaccion.c"

