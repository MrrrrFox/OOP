#pragma once
#include <iostream>

class TestClass
{
private:
	char* _nazwa;
public:
	
	TestClass(const char *);
	~TestClass();

	char * name() const;
};

