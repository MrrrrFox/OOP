#include "intArrayList.h"
#include <iostream>

#define MaxTab 10

using namespace std;

IntArrayList::IntArrayList()
{
	size = 0;
}

IntArrayList::~IntArrayList()
{
	size = 0;
}

void IntArrayList::print()		
{
	cout << "[";
	for(int i = 0;i<size;i++)				// wypisuje po kolei wszystkie elementy tablicy
	{
		cout << tab[i];
		if(i<size-1)
		{
			 cout << ", ";
		}
	}
	cout << "]" << endl;
}

int IntArrayList::find(int x)				
{
	int pozycja = -1;						// jezeli ni znajdzie to zwraca ujemna

	for(int i = 0; i < size; i++)			// szukam pozycji
	{
		if(tab[i] == x)
		{
			pozycja = i;
			break;							// jak znajde to wychodze
		}
	}
	
	return pozycja;
}

void IntArrayList::printFind(int x)			// printuje find()
{
	int pozycja = find(x);
	if(pozycja >= 0)
	{
		cout << "Wartosc " << x << " Indeks=" << pozycja << endl;
	}
	else
	{
		cout << "Wartosc " << x << " Element nieznaleziony" << endl;
	}
}

void IntArrayList::add(int x)
{
	if(size < MaxTab)
	{
		tab[size] = x;
		size++;
	}
}

void IntArrayList::add(int* a, int rozm)
{
	if(size <= MaxTab - rozm)
	{
		for(int i = 0; i<rozm; i++)
		{
			add(*(a+i));
		}
	}
}

void IntArrayList::add(int miejsce, int wartosc)
{
	if(size < MaxTab)
	{
		for(int indeks = size; indeks>miejsce; indeks--)
		{
			tab[indeks] = tab[indeks-1];
		}
		tab[miejsce] = wartosc;

		size++;
	}
}

void IntArrayList::add(int x, bool a)	
{
	if(size < MaxTab)
	{
		if(a == 1)
		{
			int i = 0;
			while(i<size)				// szukam indeks by wlozyc w porzadku posortowanym
			{
				if(tab[i]<x)
				{
					i++;
				}
				else
				{
					break;
				}
			}
			add(i,x);					// dodaje do tablicy
		}
	}
}

void IntArrayList::remove(int miejsce)
{
	for(int i = miejsce; i<size;i++)
	{
		tab[i] = tab[i+1];
	}

	size--;
}

void IntArrayList::remove(int ostatniaZachowanaPozycja, int ileUsunac)
{
	int i = ileUsunac;
	while(i>0)
	{
		remove(ostatniaZachowanaPozycja+1);
		i--;
	}
}


