#include "Arr2D.h"

Arr2D::Arr2D()
{
	_tab = nullptr;
	ile_wierszy = 0;
	ile_kolumn = 0;
}

Arr2D::Arr2D(int i, int j)
{
	ile_wierszy = j;
	ile_kolumn = i;
	_tab = new int[ile_wierszy*ile_kolumn];
	allocated = true;
}

Arr2D::Arr2D(const Arr2D & myArr)
{
	ile_kolumn = myArr.ile_kolumn;
	ile_wierszy = myArr.ile_kolumn;
	_tab = new int[ile_kolumn*ile_wierszy];
	allocated = true;
	for(int i = 0; i < ile_kolumn*ile_wierszy; ++i)
	{
		_tab[i] = myArr._tab[i];
	}
}
Arr2D::Arr2D(int * tab, int kol, int wier)
{
	_tab = tab;
	ile_wierszy = wier;
	ile_kolumn = kol;
}

Arr2D::~Arr2D()
{
	if(allocated == true) delete _tab;
}

Arr2D Arr2D::adopt(int *dane, int kolumny, int wiersze)
{
	Arr2D myArr = Arr2D(dane, kolumny, wiersze);
	return myArr;
}

std::ostream& operator <<(std::ostream& os, const Arr2D & myArr) 
{
	os << "[ ";

	for(int i = 0; i < myArr.ile_wierszy ; ++i)
	{
		os << "[";
		for(int j = 0; j < myArr.ile_kolumn; ++j)
		{
			os << myArr._tab[j + myArr.ile_kolumn*i];
			if(j != myArr.ile_kolumn-1) os << ",";
		}
		os<< "] ";
	}

	os << "]";
	
    return os;
}

Arr2D& Arr2D::operator=(const Arr2D& myArr)
{
	delete [] _tab;
	ile_wierszy = myArr.ile_wierszy;
	ile_kolumn = myArr.ile_kolumn;
	_tab = new int[ile_wierszy*ile_kolumn];
	allocated = true;
	for(int i = 0; i<ile_wierszy; ++i)
	{
		for(int j = 0; j<ile_kolumn; ++j)
		{
			_tab[j + ile_kolumn*i] = myArr._tab[j + ile_kolumn*i];  
		}
	}

	return *this;
}

Arr2D Arr2D::operator-() const
{	
	Arr2D myArr = Arr2D(ile_wierszy, ile_kolumn);
	for(int i = 0; i<ile_wierszy; ++i)
	{
		for(int j = 0; j<ile_kolumn; ++j)
		{
			myArr._tab[i + ile_wierszy*j] = _tab[j + ile_kolumn*i];  
		}
	}
	return myArr;
}

int * Arr2D::operator[](int gdzie) const
{
	return _tab + (gdzie*ile_kolumn);
}

void operator <<=(const char * napis, const Arr2D& myArr)
{
	std::cout << napis << std::endl;
	for(int i = 0; i< myArr.ile_wierszy; ++i)
	{
		for(int j=0; j<myArr.ile_kolumn;++j)
		{
			std::cout << myArr._tab[j + myArr.ile_kolumn*i] << " ";	
		}
		std::cout << std::endl;
	}
	std::cout << napis << std::endl;
}
