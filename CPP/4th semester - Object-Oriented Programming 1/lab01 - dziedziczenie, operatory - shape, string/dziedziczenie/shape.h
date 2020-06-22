#pragma once
#include <iostream>

// klasa bazowa Shape reprezentujaca ksztalt
class Shape 
{
public:
	virtual double area() const;			// wypisanie pola figury
	virtual void print() const;			// wypisanie cech figury
	virtual void print(std::ostream&) const;	// jak wyzej, ale z przekierowaniem strumienia
	virtual ~Shape() = default;			// destruktor wirtualny - bo byly warningi przy "delete b" w main
};

//funkcja wypisujaca cechy (dlugosc boku itp) figury, lub klas pochodnych
void print(const Shape&);

