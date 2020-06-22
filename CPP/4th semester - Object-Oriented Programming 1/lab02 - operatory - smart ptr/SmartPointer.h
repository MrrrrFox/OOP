#pragma once
#include <iostream>
#include "TestClass.h"

class SmartPointer
{
private:
	TestClass * _wsk; 
public:

	int *_ile;
	SmartPointer(TestClass *);
	~SmartPointer();
	SmartPointer & operator=(SmartPointer&);
	TestClass & operator *(); 
	TestClass* operator-> ();

	TestClass * get();

	void lower();
};

void print(SmartPointer *);
