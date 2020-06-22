#pragma once
#include <iostream>

class ComplexNumber
{
private:
	int _re;
	int _im;
public:
	ComplexNumber(int, int);
	~ComplexNumber();

    	friend std::ostream& operator <<(std::ostream&, const ComplexNumber&);
};


