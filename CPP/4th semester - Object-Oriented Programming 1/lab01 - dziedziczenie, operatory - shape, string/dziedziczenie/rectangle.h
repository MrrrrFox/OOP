#pragma once
#include "shape.h"
#include <iostream>

// klasa pochodna od Shape reprezentujaca prostokat
class Rectangle : public Shape 
{	
public:
	Rectangle(const double x=0, const double y=0) : _a(x), _b(y) {}
	double area() const;
	void print() const;
	void print(std::ostream&) const;
protected:
	double _a, _b;
};

