#include "shape.h"

double Shape::area() const
{
	return 0.0;
}

void Shape::print() const
{
	std::cout<<"Brak danych by wypisac Shape!"<<std::endl;
}

void print(const Shape & shape)
{
	shape.print();
}

void Shape::print(std::ostream& os) const
{
	os << "Brak danych by wypisac Shape!"<<std::endl;
}