#include "tablica.h"

Tablica::Tablica()
{
	_tab = nullptr;
	_rozm = 0;
}

// konstruktor 2-argumentowy
Tablica::Tablica(int* tab, int rozm)
{
	_rozm = rozm;
	_tab = new int[_rozm];
	for(int i=0; i<_rozm; ++i)
	{
		_tab[i] = tab[i];
	}
}

// destruktor
Tablica::~Tablica()
{
    delete [] _tab;
}

int* Tablica::poczatek() const
{
	return _tab;
}
       
int* Tablica::koniec() const
{
	return _tab+_rozm-1;
}

// przeciazony operator wyjscia
std::ostream& operator <<(std::ostream& os, const Tablica & myTab) 
{
    for(int i = 0; i<myTab._rozm; ++i)
    {
        os << myTab._tab[i];
        if(i<myTab._rozm-1)
        {
            os << ", ";
        }
    }
	return os;
}

Tablica& Tablica::operator=(const Tablica& myTab)
{
	if(&myTab == this) return *this;
	delete [] _tab;
	_tab = new int[myTab._rozm];
	for(int i=0; i<myTab._rozm; ++i)
	{
		_tab[i] = myTab._tab[i];
	}
	_rozm = myTab._rozm;
	return *this;
}

Tablica Tablica::operator+(int newData) const
{
	int* newTab = new int[_rozm+1];
	for(int i=0; i<_rozm; ++i)
	{
		newTab[i] = _tab[i];
	}
	newTab[_rozm] = newData;
	
	Tablica tabtab(newTab, _rozm+1);
	delete [] newTab;

	return tabtab;
}

int& Tablica::operator()(int indeks) const
{
	return _tab[indeks];
}

Tablica Tablica::operator-(int dataMinus) const
{
	int* newTab = new int[_rozm-1];
	int j = 0;
	for(int i=0; i<_rozm; ++i)
	{
		if(_tab[i]!=dataMinus)
		{
			newTab[j] = _tab[i];
			j++;
		}
	}
	Tablica tabtab(newTab, _rozm-1);
	delete [] newTab;

	return tabtab;
}

Tablica Tablica::operator-=(int dataMinus)
{
	
	int ile=0;
	for(int i=0; i<_rozm; ++i)
	{
		if(_tab[i]==dataMinus)
		{
			ile++;
		}
	}
	int* newTab = new int[_rozm-ile];
	int j = 0;
	for(int i=0; i<_rozm; ++i)
	{
		if(_tab[i]!=dataMinus)
		{
			newTab[j] = _tab[i];
			j++;
		}
	}
	delete [] _tab;
	_tab = newTab;
	_rozm = _rozm-ile;

	Tablica tabtab(newTab, _rozm);

	return tabtab;
}

Tablica Tablica::operator+(const Tablica& myTab) const
{
	int* newTab = new int[_rozm+myTab._rozm];
	int j = 0;
	for(int i=0; i<_rozm; ++i)
	{
		newTab[j] = _tab[i];
		j++;
	}
	for(int i=0; i<myTab._rozm; ++i)
	{
		newTab[j] = myTab._tab[i];
		j++;
	}

	Tablica tabtab(newTab, _rozm+myTab._rozm);
	delete [] newTab;

	return tabtab;	
}

Tablica Tablica::tylkoPierwszeWystapienia()
{
	int ile = 0;
	int flaga;
	int* dowpisania = new int[_rozm];
	for(int i=0; i<_rozm; ++i)
	{
		dowpisania[i] = 0;
		flaga = 0;
		for(int j=0; j<i; ++j)
		{
			if(_tab[i]==_tab[j]) 
			{
				flaga = 1;
				break;
			}
		}
		if(flaga == 0) 
		{
			ile++;
			dowpisania[i] = 1;
		}
	}

	int* newTab = new int[ile];
	int j = 0;
	for(int i=0; i<_rozm; ++i)
	{
		if(dowpisania[i] == 1)	
		{
			newTab[j] = _tab[i];
			j++;
		}
	}


	Tablica tabtab(newTab, ile);
	delete [] newTab;
	delete [] dowpisania;

	return tabtab;	
}