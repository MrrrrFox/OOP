#pragma once
#include <iostream>

class Tablica
{
private:
	int* _tab;
	int _rozm;
public:
	typedef int* IteratorStaly;
	typedef int* Iterator;
	Tablica();
	Tablica(int*, int);
	~Tablica();
	int* poczatek() const;
	int* koniec() const;

    	friend std::ostream& operator <<(std::ostream&, const Tablica&);

	Tablica& operator=(const Tablica&);
	Tablica operator+(int) const;
	int& operator()(int) const;
	Tablica operator-(int) const;
	Tablica operator-=(int);
	Tablica operator+(const Tablica&) const;
	Tablica tylkoPierwszeWystapienia();
};



