#include "point.h"
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;	

Point::Point()					// konstruktor domyslny
{
	_x = 0;
	_y = 0;
	_name = nullptr;
}
			
Point::Point(double x, double y)				// konstruktor ustawiajacy _x i _y oraz nazwe na "Miejsce nieznane"
{
	_x = x;
	_y = y;
	_name = new char[17];
	strcpy(_name, "Miejsce nieznane");
}
							
Point::Point(char const * nazwa, double x, double y)		// konstruktor ustawiajacy _name oraz _x i _y
{
	_x = x;
	_y = y;
	_name = new char[strlen(nazwa)+1];
	strcpy(_name, nazwa);
}

Point::Point(Point & punkt)		// konstruktor kopiujacy
{
	_x = punkt._x;
	_y = punkt._y;
	_name = new char[strlen(punkt._name)+1];
	strcpy(_name, punkt._name);
}

Point::Point(Point && inny)	//konstruktor przenoszacy
{
	_x = inny._x;
	_y = inny._y;
	_name = new char[strlen(inny._name)+1];
	strcpy(_name, inny._name);
	
	inny._name = nullptr;
	inny._x = 0.0;
	inny._y = 0.0;
	
}



Point::~Point()						// destruktor
{
	delete[] _name;
}

double Point::getX()			// zwraca _x
{
	return _x;
}

double Point::getY()			// zwraca _y
{
	return _y;
}

char * Point::getName()			// zwraca _name
{
	return _name;
}
void Point::changeName(char const * nowaNazwa)		// zmienia _name
{
	delete _name;
	_name = new char[strlen(nowaNazwa)+1];
	strcpy(_name, nowaNazwa);
}
void Point::fullPrint()							// wypisuje w zadanym formacie
{
	cout<< ( _name!= nullptr ? _name : "NULL") << " (" << _x << "," << _y << ")" << endl; 
}

void Point::move(double x, double y)
{
	_x+=x;
	_y+=y;
}

int Point::compareX(Point& p1, Point& p2)		// porownuje _x
{
	int wart = p2._x - p1._x;
	if(wart>0)
	{
		return 1;
	}
	else
	{
		if(wart<0)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
}

int Point::compareY(Point& p1, Point& p2)			// porownuje _y
{
	int wart = p2._y - p1._y;
	if(wart>0)
	{
		return 1;
	}
	else
	{
		if(wart<0)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
}

int Point::compareXY(Point& p1, Point& p2)		
{
	int wartx, warty;
	wartx = compareX(p1,p2);
	warty = compareY(p1,p2);
	return 10*wartx+warty; 
}


