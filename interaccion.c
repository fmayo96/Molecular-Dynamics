#include "general.h"
#include "inicializar.h"
#include <math.h>

double build_LUT(double *LUT_F, double *LUT_V, double rc2, double r02, int size_lut)
{  //Armo las tablas de Fuerza y potencial.
double deltar2, rij2, r6, r12, rc6, rc12; 
deltar2 = (double)(rc2-r02)/(double)size_lut;
for(int i = 0; i < size_lut; i++)
	{rij2 = r02 + i * deltar2; 
	r6 = rij2 * rij2 * rij2;
	rc6 = rc2 * rc2 * rc2;
	r12 = r6 * r6;
	rc12 = rc6 * rc6;  
	*(LUT_F + i) = 24 * (1/rij2) * (2 /r12 - (1 / r6));
	*(LUT_V + i) = 4 * (1/r12 - 1/r6) - 4 * (1/rc12 - 1/rc6) ;
	}
return deltar2;
}
double pair_force(double *LUT_F, double *LUT_V, double rij2 , double r02, double deltar2, double *f_mod)
{ // Calcula pares de interaccion.
int k = (int) ((rij2 - r02) / (deltar2));
if(k < 0)
	{
	k = 0;
	}
*f_mod = ((rij2 - k * deltar2)/ deltar2) * (*(LUT_F + k + 1)-*(LUT_F + k)) + *(LUT_F + k);
double Vij = ((rij2 - k * deltar2)/ deltar2) * (*(LUT_V + k +1)-*(LUT_V + k)) + *(LUT_V + k);

return Vij;
}
int PBC_force(double *delta_X, double L)
{
int i;
for(i = 0; i < 3; i++)
	{
	if(*(delta_X + i) > L/2.0)
		{
		*(delta_X + i) -= L;
		}
	else if(*(delta_X + i) <= -L/2.0)
		{
		*(delta_X + i) += L;
		}
	}
return 0;
}

