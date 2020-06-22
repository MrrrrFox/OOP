#pragma once
#include "shape.h"
#include <cmath>
#include <iostream>

// klasa pochodna od Shape reprezentujaca trojkat
class Triangle : public Shape 
{
public:
	Triangle(const double x=0, const double y=0, const double z=0) : _a(x), _b(y), _c(z) {}
	double area() const;
	void print() const;
	void print(std::ostream&) const;
protected:
	double _a, _b, _c;
};
