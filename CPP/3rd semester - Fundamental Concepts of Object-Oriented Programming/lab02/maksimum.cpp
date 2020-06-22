#include "maksimum.h"

int maksimum(int * wektor, int n)
{
	int max = *wektor;
	int l1;
	for(l1=1; l1<n; l1++)
	{
		if(max < *(wektor+l1))
		{
			max = *(wektor+l1);
		}
	}
	
	return max;
}
