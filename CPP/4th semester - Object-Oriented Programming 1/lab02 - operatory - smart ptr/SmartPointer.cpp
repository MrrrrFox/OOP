#include "SmartPointer.h"
#include <cstring>

SmartPointer::SmartPointer(TestClass * test)
{
	_ile = new int;
	*_ile = 1;
	_wsk = test;
}

SmartPointer& SmartPointer::operator=(SmartPointer& second)
{
	lower();
	
	_wsk = second._wsk;
	_ile = second._ile;
	(*_ile)++;
	
	return *this;
}

SmartPointer::~SmartPointer()
{
	lower();
}

TestClass* SmartPointer::operator-> ()
{
	return _wsk;
}

TestClass & SmartPointer::operator *() 
{
	return *_wsk;
}

void SmartPointer::lower()
{	
	(*_ile)--;
	if(*_ile == 0) 
	{	
		if(_wsk != nullptr) delete _wsk;
		delete _ile;
	}
}

TestClass * SmartPointer::get()
{
	return _wsk;
}

void print(SmartPointer * ptr)
{
	std::cout << ptr->get()->name() << std::endl;
}

