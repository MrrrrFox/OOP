#pragma once
#include <iostream>
#include <cstring>

class Point
{
	double _x;
	double _y;
	char * _name;
	Point * next;
	
public:
	Point();							// domyslny
	Point(double, double);				// ustawia wartosc _x i _y
	Point(char const *, double, double);	// ustawiajacy wartosc _name, _x, _y
	Point(Point&);						// kopiujacy
	Point(Point&&);						// przenoszacy
	~Point();							// destruktor

	double getX();
	double getY();
	char* getName();
	void changeName(char const *);
	void fullPrint();
	void move(double, double);
	int compareX(Point&, Point&);
	int compareY(Point&, Point&);
	int compareXY(Point&, Point&);
	
};


