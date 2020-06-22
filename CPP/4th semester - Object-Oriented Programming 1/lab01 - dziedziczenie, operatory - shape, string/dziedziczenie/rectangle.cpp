#include "rectangle.h"

void Rectangle::print() const
{
	std::cout<<"Prostokat o bokach: "<< _a <<" "<< _b << std::endl; 
}

void Rectangle::print(std::ostream& os) const
{
	os << "Prostokat o bokach: "<< _a <<" "<< _b << std::endl; 
}

double Rectangle::area() const
{
	return _a * _b;
}

