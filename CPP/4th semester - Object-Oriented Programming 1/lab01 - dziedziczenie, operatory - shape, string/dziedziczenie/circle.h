#pragma once
#include "shape.h"
#include <cmath>
#include <iostream>

// klasa pochodna od Shape reprezentujaca kolo
class Circle : public Shape 
{
public:
	Circle(const double x=0): _a(x) {}
	double area() const;
	void print() const;
	void print(std::ostream&) const;
protected:
	double _a;
};
