#pragma once
#include "MapPoint.h"

struct MapDist
{
float longitude;			//długość
float latitude;			//szerokosc
};

const MapDist distance(MapPoint, MapPoint);																//delty odleglosci
double angularDistance(const MapDist);														//pitagoras
const MapPoint& closestFrom(MapPoint *, MapPoint *, MapPoint *);			//do ktorego z P2 i P3 jest blizej do P1
