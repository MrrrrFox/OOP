#pragma once

#include <iostream>

struct MapPoint
{
const char* name;
double longitude;		//długość
double latitude;			//szerokosć

};

MapPoint * construct(char const *, const double, const double);
void print(MapPoint *);
void print(const MapPoint *);
void clear(MapPoint *);
void clear(MapPoint *, MapPoint *, MapPoint *);
MapPoint inTheMiddle(MapPoint *, const MapPoint *, char const *);
void movePoint(MapPoint *, const double, const double);
