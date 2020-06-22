#include "circle.h"

void Circle::print() const
{
	std::cout<<"Kolo o promieniu: "<< _a << std::endl; 
}

void Circle::print(std::ostream& os) const
{
	os <<"Kolo o promieniu: "<< _a << std::endl; 
}

double Circle::area() const
{
	return M_PI * _a * _a;
}
