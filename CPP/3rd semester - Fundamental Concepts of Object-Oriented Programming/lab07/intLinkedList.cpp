#include "intLinkedList.h"
#include <iostream>

using namespace std;

IntLinkedList::IntLinkedList()		// ustawia head i tail na null
{
	head = NULL;
	tail = NULL;
}

IntLinkedList::~IntLinkedList()		// zwalnia pierwszy dopoki jest cos w liscie
{
	while(head!=NULL)
	{
		removeFirst();
	}
	cout<<"Destruktor: Lista pusta"<<endl;
}

int IntLinkedList::size()		// przechodzi po kazdym elemencie listy zwiekszajac wskaznik o 1 z kazdym przejciem
{
	el_listy1 *pom;
	pom = head;
	int i = 0;
	while(pom!=NULL)
	{
		i++;
		pom=pom->nastepny;
	}
	return i;
}

int IntLinkedList::isEmpty()		// jest pusta jezeli head jest nullem
{
	if(head == NULL) 
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

void IntLinkedList::print()		// przechodzi po liscie wypisujac kolejne wartosci wg formatu zadanego w main
{
	el_listy1 *pom;
	pom = head;
	cout<<"[";
	while(pom!=NULL)
	{
		cout<<pom->klucz;
		if(pom->nastepny != NULL)
		{
			cout<<", ";
		}
		pom=pom->nastepny;
	}
	cout<<"]";
	//if(head!=NULL) cout<<" head="<<head->klucz;
	//if(tail!=NULL) cout<<" tail="<<tail->klucz;
	cout<<endl;
}

void IntLinkedList::append(int x)		// dodaje na koniec
{
	el_listy1 *pom;
    pom = new el_listy1;
    if(pom != NULL)
    {
    	pom->klucz=x;
		pom->nastepny = NULL;
		if(head == NULL)				// pusta lista
		{
			pom->nastepny = head;
			head = pom;
			tail = pom;
		}
		else							// pozostale przypadki
		{
			tail->nastepny = pom;
			tail = pom;
		}
	}
//print();
}

void IntLinkedList::addSorted(int x) 		// dodaje w sposob posortowany
{
	el_listy1 *pom;
   	pom = new el_listy1;
    	if(pom != NULL)
    	{
    		pom->klucz=x;
    		if(head == NULL) // pusta lista
    		{
			pom->nastepny = head;
			head = pom;
			tail = pom;
		}
		else			
		{
			if(head->klucz >= x)			// dodaje na poczatek niepustej
			{
				pom->nastepny = head;
				head = pom;
			}
			else					
			{
				el_listy1 *pom2;
				pom2 = head;
				while(pom2->nastepny && (pom2->nastepny)->klucz < x)
				{
					pom2 = pom2->nastepny;
				}
				pom->nastepny = pom2->nastepny;
				pom2->nastepny = pom;
				if(pom2 == tail)
				{
					tail = pom;
				}
			}
		}
    	}
//print();
}

void IntLinkedList::removeFirst()		// usuwa 1 element przepinajac head
{
	if(head!=NULL)
	{
		el_listy1 *pom;
		pom = head;
		if(head == tail)
		{
			tail = NULL;
		}
		head = head->nastepny;
		delete pom;
	}
//print();
}

void IntLinkedList::removeValue(int x)	
{
	if(head!=NULL)
	{
		if(head->klucz == x)
		{
			removeFirst();
		}
		else
		{
			el_listy1 *pom;
			pom = head;
			while(pom!=NULL)
			{
				if(pom->nastepny && (pom->nastepny)->klucz == x)
				{
					el_listy1 *pom2;
					pom2 = pom->nastepny;
					pom->nastepny = pom2->nastepny;
					if(pom2 == tail)
					{
						tail = pom;
					}
					delete pom2;
					break;
				}
				pom = pom->nastepny;
			}
		}
	}
//print();
}

bool IntLinkedList::contains(int x)
{
	el_listy1 *pom;
	pom = head;
	while(pom!=NULL)
	{
		if(pom->klucz == x)
		{
			return 1;
		}
		pom=pom->nastepny;
	}
	return 0;
}

