double Random() //devuelve un float aleatorio entre 0 y 1.
{srand(time(NULL));
return((double)rand()/(double)RAND_MAX);
}

double Gaussiana(double mu, double sigma) // devuelve un float con proba gaussiana.
{srand(time(NULL));
int n = 15, i;
double z = 0;

for(i = 0; i < n; i++)
	{
	z  += Random();
	}

z = sqrt(12)*(z/n-0.5); //normal estándar.

return z*sigma + mu;
}

double Norma2(double *v)
{
return *v*(*v) + *(v+1)*(*(v+1)) + *(v+2)*(*(v+2));
}


double Distance2(double *v1, double *v2)
{
return ((*v1-*v2)*(*v1-*v2) + (*(v1+1)-*(v2+1))*(*(v1+1)-*(v2+1)) + (*(v1+2)-*(v2+2))*(*(v1+2)-*(v2+2)));
}
int delta(double *delta_X, double *v1, double *v2)
{
for(int i = 0; i < 3; i++)
	{
	*(delta_X + i) = *(v1 + i) - *(v2 - i);
	}
return 0;
}
double Ecin(double *v, int N)
{double E_cin = 0;
for(int i = 0; i < 3 * N; i++)
	{
	E_cin += *(v + i) * (*(v+i)) / 2.0; 
	}
return E_cin /(double) N;
}


