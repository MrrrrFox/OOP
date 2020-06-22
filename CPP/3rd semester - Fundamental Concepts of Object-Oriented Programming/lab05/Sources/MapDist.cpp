#include "MapDist.h"
#include <cmath>

using namespace std;

const MapDist distance(MapPoint miasto1, MapPoint miasto2)
{
	const MapDist dystans = new MapDist;
	// dystans->longitude = 
return 0;
}

double angularDistance(const MapDist delty)
{

return 0;
}

const MapPoint& closestFrom(MapPoint * miastoRef, MapPoint * miasto1, MapPoint * miasto2)
{
	if(angularDistance(distance(maistoRef, miasto1)) > angularDistance(distance(maistoRef, miasto2)) )
	{
		return miasto2;
	}
	else
	{
		return miasto1;
	}
}

