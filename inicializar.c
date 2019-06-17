#include "inicializar.h"
#include "general.h"

float set_box(float *X, int N, float L)
{
int n=cbrt(N),i=0;
float dl=L/n;
for(int x = 0; x < n; x++)
	{
	for(int y = 0; y < n; y++)
		{
		for(int z = 0; z < n; z++)
			{
			*(X+3*i) = (x+0.5)*dl;
			*(X+3*i+1) = (y+0.5)*dl;
			*(X+3*i+2) = (z+0.5)*dl;
			i++;
			}
		}
	}
return dl;
}

float set_v(float *v, int N, float T)
{
float sigma=sqrt(T);
for(int i = 0; i < 3*N; i++)
	{
	*(v+i)=Gaussiana(0.0, sigma);
	}
float *Vcm;
Vcm = (float*)malloc(3*sizeof(float));
*Vcm = 0;
*(Vcm+1) = 0;
*(Vcm+2) = 0;
for(int i = 0; i < N; i++)
	{
	for(int k = 0; k < 3; k++)
		{
		*(Vcm+k) += (float)*(v+3*i+k)/(float)N;  
		}	
	}
for(int i = 0; i < N; i++)
	{
	for(int k = 0; k < 3; k++)
		{
		*(v+3*i+k) -= (float)*(Vcm+k);
		}
	}
float Ecin = 0;
for(int i = 0; i < 3*N; i++)
	{
	Ecin += *(v+i)*(*(v+i));
	} 
Ecin = (float)Ecin/(float)2;
return Ecin;
}


