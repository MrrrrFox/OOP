#include "mediana.h"

float mediana(int * wektor, int n)
{
	if(n%2==1)
	{
		return *(wektor+n/2);
	}
	// przy parzystej liczbie wyrazow zwracam srednia arytmetyczna dwoch srodkowych wyrazow
	return ( (float)(*(wektor-1+n/2) + *(wektor+n/2)) ) / 2;

}
