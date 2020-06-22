#include "MapPoint.h"
#include <iostream>
#include <cstring>

using namespace std;

MapPoint * construct(char const *nazwa, const double dlugosc, const double szerokosc)
{
 	MapPoint * miasto = new MapPoint;
	
	// miasto->name = new char[strlen(nazwa) + 1];		niepotrzebne przy deklarowaniu struktury
	miasto->name = nazwa;

	miasto->longitude = dlugosc;
	miasto->latitude = szerokosc;
	
	return miasto;
}

void print(MapPoint * miasto)
{
	cout << "Współrzędne dla " << miasto->name << ". Długość: " << miasto->longitude << ". Szerokość: " << miasto->latitude << endl;
}

void print(const MapPoint *)
{
	cout << "Współrzędne dla " << miasto->name << ". Długość: " << miasto->longitude << ". Szerokość: " << miasto->latitude << endl;
}

void clear(MapPoint * miasto)
{
	delete[] miasto->name;
	delete miasto;
}

void clear(MapPoint * miasto1, MapPoint * miasto2, MapPoint * miasto3)
{
	clear(miasto1);
	clear(miasto2);
	clear(miasto3);
}

MapPoint inTheMiddle(MapPoint * miasto1, const MapPoint * miasto2, char const * nazwa)
{
	MapPoint * noweMiasto = new MapPoint;
	double x, y;
	x = (miasto1->longitude + miasto2->longitude)/2;
	y = (miasto1->latitude + miasto2->latitude)/2;
	noweMiasto->name = nazwa;

	return noweMiasto;	
}

void movePoint(MapPoint * miasto, const double xshift, const double yshift)
{
	miasto->longitude = miasto->longitude + xshift;
	miasto->latitude = miasto->latitude + yshift;
}
