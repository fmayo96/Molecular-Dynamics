#include "inicializar.h"
#include "general.h"

double set_box(double *X, int N, double L)
{ // Ordena las partículas en una red cúbica. Coición inicial.
int n=cbrt(N),i=0;
double dl=L/n;
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

double set_v(double *v, int N, double T)
{ // Le da velocidad inicial a cada partículasiguiendo una distribución de probabilidad Gaussiana.
double sigma=sqrt(T);
for(int i = 0; i < 3*N; i++)
	{
	*(v+i)=Gaussiana(0.0, sigma);
	}
double *Vcm;
Vcm = (double*)malloc(3*sizeof(double)); //Calculo la velocidad del 
*Vcm = 0; // Centro de masa.
*(Vcm+1) = 0;
*(Vcm+2) = 0;
for(int i = 0; i < N; i++)
	{
	for(int k = 0; k < 3; k++)
		{
		*(Vcm+k) += (double)*(v+3*i+k);  
		}	
	}
for(int i = 0; i < N; i++)
	{
	for(int k = 0; k < 3; k++)
		{ // Resto la Vcm para que no haya flujo de partíclas.
		*(v+3*i+k) -= (double)*(Vcm+k)/(double)N;
		}
	}
double Ecin = 0;
for(int i = 0; i < 3*N; i++)
	{
	Ecin += *(v+i)*(*(v+i));
	} 
Ecin = (double)Ecin/(double)2;
return Ecin;
}


