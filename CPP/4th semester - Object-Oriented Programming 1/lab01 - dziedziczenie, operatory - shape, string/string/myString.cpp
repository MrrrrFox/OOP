#include "myString.h"
#include <cstring>

MyString::MyString(const char * nowyWyraz)
{
	_wyraz = new char[strlen(nowyWyraz)];
	strcpy(_wyraz, nowyWyraz);
}

MyString::MyString(const MyString & mystring)
{
	_wyraz = new char[strlen(mystring._wyraz)];
	strcpy(_wyraz, mystring._wyraz);
}

MyString::~MyString()
{
	delete[] _wyraz;
}

char * MyString::str() const
{
	return this->_wyraz;
}

int MyString::operator==(const MyString& second) const
{
	if( strcmp(_wyraz, second._wyraz) == 0 ) return 1;
	return 0;
}

int MyString::operator==(const char * second) const
{
	if( strcmp(_wyraz, second) == 0 ) return 1;
	return 0;
}

MyString& MyString::operator=(const MyString& second)
{
	delete[] _wyraz;
	_wyraz = new char[strlen(second._wyraz)];
	strcpy(_wyraz, second._wyraz);
	return *this;
}

MyString& MyString::operator=(const char * napis)
{
	delete[] _wyraz;
	_wyraz = new char[strlen(napis)];
	strcpy(_wyraz, napis);
	return *this;
}


MyString MyString::operator+(const MyString& mystring) const
{
	return *this + mystring._wyraz;
}

MyString MyString::operator+(const char * napis) const
{
	int rozmiar = strlen(_wyraz) + strlen(napis);
	char * razem = new char[rozmiar+1];
	strcpy(razem, _wyraz);
	strcat(razem, napis);

	MyString newStr(razem);
	delete[] razem;
	return newStr;
}

MyString MyString::operator+(const char litera) const
{
	const char tabela[2] = {litera, '\0'}; 
	return *this + tabela;
}

MyString MyString::operator*(int skala) const
{
	
}

char & MyString::operator[](int i) const
{
	return _wyraz[i];
}

std::ostream& operator <<(std::ostream& os, const MyString& mystring) 
{
	os << mystring._wyraz;
	
    return os;
}

void MyString::print() const
{
	std::cout<< _wyraz << std::endl; 
}


MyString operator*(int skala, const MyString& )
{
	
}
