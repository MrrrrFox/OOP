#include "complexNumber.h"

// konstruktor 2-argumentowy
ComplexNumber::ComplexNumber(int re, int im)
{
	std::cout << "Constructing " << re << "+" << im << "i" << std::endl;
	_re = re;
	_im = im;
}

// destruktor
ComplexNumber::~ComplexNumber()
{
	std::cout << "Deleting: " << _re << "+" << _im << "i" << std::endl;
}

// przeciazony operator wyjscia
std::ostream& operator <<(std::ostream& os, const ComplexNumber & myComplex) 
{
	os << myComplex._re << "+" << myComplex._im << "i";

    	return os;
}