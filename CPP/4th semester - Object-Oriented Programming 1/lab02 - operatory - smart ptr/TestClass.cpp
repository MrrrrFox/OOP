#include "TestClass.h"
#include <cstring>

TestClass::TestClass(const char * wyraz)
{
	std::cout << ".. Konstruuje TestClass " << wyraz << std::endl;
	_nazwa = new char[strlen(wyraz)];
	strcpy(_nazwa, wyraz);
}

TestClass::~TestClass()
{
	std::cout << ".. Usuwam TestClass " << _nazwa << std::endl;
	delete[] _nazwa;
}

char * TestClass::name() const
{
	return _nazwa;
}
