#include "general.h"
#include "inicializar.h"
#include "interaccion.h"
#include "avanzar.h"
int verlet_pos(double *X, double *v, double *F, double h, int N)
{
int i, k;
for(i = 0; i < N; i++)
	{
	for(k = 0; k < 3; k++)
		{
		*(X + 3*i + k) += *(v + 3*i + k) * h + *(F + 3*i + k) * h * h / 2.0;
		}
	}	
return 0;
}
int verlet_vel(double *v, double *F, double *F2, double h, int N)
{
int i;
for(i = 0; i <  N; i++)
	{
	for(k = 0; k < 3; k++)
		{
		*(v + 3*i + k) += (*(F + 3*i + k) + *(F2 + 3*i +k) )* h / 2.0;
		}
	}
return 0;
}
double fuerzas(double *F, double *F2, double *E_pot, double rc2, int N, double *X, int l, int L, double *LUT_F, double *LUT_V, double r02, double deltar2, double *f_mod, double *delta_X)
{
double rij2;
int i, j, k;
for(i = 0; i < 3 * N; i++)
	{
	*(F2 + i) = *(F + i);
	*(F + i) = 0;
	}
for(i = 1; i <  N; i++)
	{
	for(j = 0; j < i; j++)
		{
		for(k = 0; k < 3; k++)
			{
			*(delta_X + k) = *(X + 3*i + k) - *(X + 3*j + k);
			}   	
		PBC_force(delta_X, L);
		rij2 = Norma2(delta_X);
		if(rij2 < rc2)
			{
			 pair_force(LUT_F, LUT_V, rij2, r02, deltar2, f_mod) / (double)N;
			for(k = 0; k < 3; k++)
				{
				*(F + 3*i + k) += *f_mod * (*(delta_X + k));
				*(F + 3*j + k) -= *f_mod * (*(delta_X + k)); 
				}
			}
		}
	}

return 0;
}
int PBC_pos(double *X, double L,int N)
{
for(int i = 0; i < 3 * N; i++)
	{
	if(*( X + i) >= L)
		{
		*(X + i) -= L;
		}
	else if(*(X + i) < 0) 
		{
		*(X + i) += L;
		}
	}
return 0;
}

