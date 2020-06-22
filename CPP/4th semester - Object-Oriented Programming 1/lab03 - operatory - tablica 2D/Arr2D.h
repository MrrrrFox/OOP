#pragma once
#include <iostream>

class Arr2D
{
private:
	bool allocated = false;
	int * _tab;
	int ile_kolumn;
	int ile_wierszy;
public:
	Arr2D();
	Arr2D(int, int);
	Arr2D(const Arr2D &);
	Arr2D(int*, int, int);
	~Arr2D();

	Arr2D& operator=(const Arr2D&);
	Arr2D operator-() const;
	int* operator[](int) const;
	static Arr2D adopt(int *, int, int);	
    friend std::ostream& operator <<(std::ostream&, const Arr2D&);
    friend void operator <<=(const char *, const Arr2D&);


};


