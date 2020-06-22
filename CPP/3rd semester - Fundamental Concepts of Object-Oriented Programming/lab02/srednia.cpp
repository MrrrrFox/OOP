#include "srednia.h"
#include "suma.h"

float srednia(int * wektor, int n)
{
	int sum = suma(wektor,n);
	float sr = (float)sum/(float)n;

	return sr;
}
