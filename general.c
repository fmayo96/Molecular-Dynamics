float Random() //devuelve un float aleatorio entre 0 y 1.
{
return((float)rand()/(float)RAND_MAX);
}

float Gaussiana(float mu, float sigma) // devuelve un float con proba gaussiana.
{
int n = 15, i;
float z = 0;

for(i = 0; i < n; i++)
	{
	z  += random();
	}

z = sqrt(12)*(z/n-0.5); //normal estándar.

return z*sigma + mu;
}

float Norma(float *v)
{
return sqrt(*v*(*v) + *(v+1)*(*(v+1)) + *(v+2)*(*(v+2)));
}


float Distance(float *v1,float *v2)
{
return sqrt((*v1-*v2)*(*v1-*v2) + (*(v1+1)-*(v2+1))*(*(v1+1)-*(v2+1)) + (*(v1+2)-*(v2+2))*(*(v1+2)-*(v2+2)));
}



