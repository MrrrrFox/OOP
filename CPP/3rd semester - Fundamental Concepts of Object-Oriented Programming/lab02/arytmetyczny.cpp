#include "arytmetyczny.h"

int arytmetyczny(int * wektor, int n)
{
	int odstep = *(wektor+1) - *(wektor);
	int l1;
	for(l1=1; l1<n-1; l1++)
	{
		if(odstep != *(wektor+l1+1) - *(wektor+l1))
		{
			return 0;
		}
	}

	return 1;
}
