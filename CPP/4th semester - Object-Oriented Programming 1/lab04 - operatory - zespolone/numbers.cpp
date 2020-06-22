#include "numbers.h"

// konstruktor 1-argumentowy
polish::polish(int cale)
{
	_cale = cale;
}
	
// przeciazony operator , 
float polish::operator,(int czesc) const
{
	float ulamek = czesc;
	while(ulamek>=1) ulamek = ulamek/10;
	return (float)_cale+ulamek;
}