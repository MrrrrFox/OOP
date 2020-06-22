#include "suma.h"

int suma(int * wektor, int n)
{
	int sum = 0;
	int l1;
	for(l1=0;l1<n;l1++)
	{
		sum+=*(wektor+l1);
	}
	return sum;
}
