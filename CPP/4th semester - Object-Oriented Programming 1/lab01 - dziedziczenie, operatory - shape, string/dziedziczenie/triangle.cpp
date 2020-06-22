#include "triangle.h"

void Triangle::print() const
{
	std::cout<<"Trojkat o bokach: "<< _a << " " << _b << " " << _c << std::endl; 
}

void Triangle::print(std::ostream& os) const
{
	os << "Trojkat o bokach: "<< _a << " "<< _b << " "<< _c << std::endl; 
}

double Triangle::area() const
{
	double x = (_a + _b + _c)/2;
	return sqrt(x*(x-this->_a)*(x-this->_b)*(x-this->_c));
}
