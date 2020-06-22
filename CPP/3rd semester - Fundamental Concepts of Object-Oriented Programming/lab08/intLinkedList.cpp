#include "intLinkedList.h"
#include <iostream>
#include <string>

using namespace std;	

Element::Element()					// konstruktor domyslny
{

}
			
Element::Element(int x)				// konstruktor ustawiajacy value
{
	value = x;
}
							
Element::Element(Element & element)		// konstruktor kopiujacy
{
	value = element.value;
	next = element.next;
}

Element::~Element()						// destruktor
{

}

IntLinkedList::IntLinkedList()		// konstruktor domyślny - ustawia head i tail na null oraz name na "LX"
{
	head = NULL;
	tail = NULL;
	name = "LX";
}

IntLinkedList::IntLinkedList(string nazwa)	// konstruktor z parametrem string, ktory ustawia name na podana wartosc
{
	head = NULL;
	tail = NULL;
	name = nazwa;
}

IntLinkedList::~IntLinkedList()		// destruktor - zwalnia pierwszy dopoki jest cos w liscie
{
	while(head!=NULL)
	{
		removeFirst();
	}
	cout<<"Destruktor "<< name << ": Lista pusta"<<endl;
}

int IntLinkedList::size()		// zwraca ilosc elementow - przechodzi po kazdym elemencie listy zwiekszajac wskaznik o 1 z kazdym przejciem
{
	Element *pom;
	pom = head;
	int i = 0;
	while(pom!=NULL)
	{
		i++;
		pom=pom->next;
	}
	return i;
}

int IntLinkedList::isEmpty()		// sprawdza, czy lista jest pusta (czy head jest nullem)
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

void IntLinkedList::print()		// wypisuje liste - przechodzi po liscie wypisujac kolejne wartosci wg formatu zadanego w main (nazwa i nawiasy klamrowe)
{
	Element *pom;
	pom = head;
	cout<<name<<"=[";
	while(pom!=NULL)
	{
		cout<<pom->value;
		if(pom->next != NULL)
		{
			cout<<", ";
		}
		pom=pom->next;
	}
	cout<<"]"<<endl;
}

void print(IntLinkedList& lista)		// zaprzyjazniony print, ktory dziala analogicznie jak poprzedni
{
	Element *pom;
	pom = lista.head;
	cout<<lista.name<<"=[";
	while(pom!=NULL)
	{
		cout<<pom->value;
		if(pom->next != NULL)
		{
			cout<<", ";
		}
		pom=pom->next;
	}
	cout<<"]"<<endl;
}

void IntLinkedList::append(int x)		// dodaje wartosc na koniec (tworzy element o zadanej wartosci)
{
	Element *pom;
  	pom = new Element(x);
    	if(pom != NULL)
    	{
		pom->next = NULL;
		if(head == NULL)				// pusta lista
		{
			pom->next = head;
			head = pom;
			tail = pom;
		}
		else							// pozostale przypadki
		{
			tail->next = pom;
			tail = pom;
		}
	}
}

void IntLinkedList::append(Element& a)		// dodaje element na koniec listy (tworzy kopie podanego elementu i wstawia ja na koniec)
{
	Element *pom;
    	pom = new Element(a);
	if(head == NULL)
	{
		pom->next = NULL;
		head = pom;
		tail = pom;
	}
	else
	{
		tail->next = pom;
		tail = pom;
		pom->next = NULL;
	}
}

void IntLinkedList::append(IntLinkedList& list1)	// wstawia liste na koniec (tworzy gleboka kopie podanej listy i dopisuje ja na koniec)
{
	Element * pom;
	pom = list1.head;
	while(pom)
	{
		append(pom->value);
		pom = pom->next;
	}	
}

void IntLinkedList::addSorted(int x, bool uniq) 		// dodaje w sposob posortowany wartosc na koniec (tworzy element o podanej wartosci i wstawia go do listy w sposob posortowany)
{
	Element *pom;
   	pom = new Element(x);
    	if(pom != NULL)
    	{
    		if(head == NULL) // pusta lista
    		{
			pom->next = head;
			head = pom;
			tail = pom;
		}
		else			
		{
			if(head->value >= x)			// dodaje na poczatek niepustej
			{
				if(head->value == x && uniq == true )	// sprawdzenie warunku z bool'em uniq
				{
					delete pom;
				}
				else
				{
					pom->next = head;
					head = pom;							
				}
			}
			else						// pozostale przypadki			
			{
				Element *pom2;
				pom2 = head;
				while(pom2->next && (pom2->next)->value < x)	// znajduje miejsce
				{
					pom2 = pom2->next;
				}
				if(pom2->next)
				{
					if((pom2->next)->value == x && uniq == true) // sprawdzenie warunku z bool'em uniq
					{
						delete pom;
					}
					else
					{
						pom->next = pom2->next;
						pom2->next = pom;
					}
				}
				else
				{
					pom->next = pom2->next;
					pom2->next = pom;
					tail = pom;	
				}						
			}
		}
	}
}

void IntLinkedList::addSorted(Element& a, bool uniq) 		// dodaje w sposob posortowany element na koniec listy (tworzy kopie podanego elementu i wstawia go do listy w sposob posortowany)
{
	Element *pom;
   	pom = new Element(a);
    	if(pom != NULL)
    	{
    		if(head == NULL) // pusta lista
    		{
			pom->next = head;
			head = pom;
			tail = pom;
		}
		else			
		{
			if(head->value >= pom->value)			// dodaje na poczatek niepustej
			{
				if(head->value == pom->value && uniq == true )	// sprawdzenie warunku z bool'em uniq
				{
					delete pom;
				}
				else
				{
					pom->next = head;
					head = pom;							
				}
			}
			else				// pozostale przypadki			
			{
				Element *pom2;
				pom2 = head;
				while(pom2->next && (pom2->next)->value < pom->value)		// szukanie wlasciwego miejca
				{
					pom2 = pom2->next;
				}
				if(pom2->next)
				{
					if((pom2->next)->value == pom->value && uniq == true)	// sprawdzenie warunku z bool'em uniq
					{
						delete pom;
					}
					else
					{
						pom->next = pom2->next;
						pom2->next = pom;
					}
				}
				else
				{
					pom->next = pom2->next;
					pom2->next = pom;
					tail = pom;	
				}						
			}
		}
	}
}

void IntLinkedList::addSorted(IntLinkedList& list1)	// dodaje liste do liste w sposob posortowany (tworzy gleboka kopie zadanej listy za pomoca juz napisanej funckji addSorted i wstawia kolejno elementy do listy)
{
	Element * pom;
	pom = list1.head;
	while(pom)
	{
		addSorted(pom->value,true);
		pom = pom->next;
	}
}

void IntLinkedList::removeFirst()		// usuwa pierwszy element przepinajac head
{
	if(head!=NULL)
	{
		Element *pom;
		pom = head;
		if(head == tail)
		{
			tail = NULL;
		}
		head = head->next;
		delete pom;
	}
}

void IntLinkedList::removeLast()			// usuwanie ostatniego
{
	if(head!=NULL)
	{
		Element *pom;
		pom = head;
		if(head->next == NULL)			// tylko jeden element w liscie
		{
			tail = NULL;
			head = head->next;
			delete pom;
		}
		else					// usuwa ogon
		{
			while(pom->next != tail)
			{
				pom=pom->next;
			}
			tail = pom;
			pom=pom->next;
			tail->next = NULL;
			delete pom;
		}
	}	
}

void IntLinkedList::removeValue(int x)			// usuwa pierwszy znaleziony element o zadanej wartosci z listy
{
	if(head!=NULL)
	{
		if(head->value == x)
		{
			removeFirst();
		}
		else
		{
			Element *pom;
			pom = head;
			while(pom!=NULL)
			{
				if(pom->next && (pom->next)->value == x)
				{
					Element *pom2;
					pom2 = pom->next;
					pom->next = pom2->next;
					if(pom2 == tail)
					{
						tail = pom;
					}
					delete pom2;
					break;
				}
				pom = pom->next;
			}
		}
	}
}

bool IntLinkedList::contains(int x)		// sprawdza, czy w liscie istnieje element o zadanej wartosci 
{
	Element *pom;
	pom = head;
	while(pom!=NULL)
	{
		if(pom->value == x)
		{
			return 1;
		}
		pom=pom->next;
	}
	return 0;
}