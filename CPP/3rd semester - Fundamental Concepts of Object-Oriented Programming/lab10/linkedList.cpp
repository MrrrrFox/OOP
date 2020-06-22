#include "linkedList.h"

LinkedList::LinkedList() {

    _head = nullptr;
    _tail = nullptr;
    _name = "LX";

}

LinkedList::LinkedList(std::string name) {

    _head = nullptr;
    _tail = nullptr;
    _name = name;

}

LinkedList::~LinkedList() {

    // usuwamy pierwszy element az lista nie jest pusta
    while (!isEmpty()) {
        removeFirst();
    }

    std::cout << "Destruktor " << _name << ": Lista pusta\n";

}

void LinkedList::append(const Point& point) {

        // przygotowujemy nowy element listy
    Point* tmp = new Point(point);

    if (isEmpty()) {
        // jesli lista jest pusta, po prostu ustawiamy head i tail na nowy element
        _head = tmp;
        _tail = tmp;
    }

    else {
        // "stary" ostatni element wskazuje teraz na element, ktory chcemy dodac, tak samo jak tail
        _tail->_next = tmp;
        _tail = tmp;
    }
}

bool LinkedList::isEmpty() {

    // lista jest pusta jesli head (albo tail) wskazuje na null
    return _head == nullptr;

}

void LinkedList::removeFirst() {

    if (!isEmpty()) {

        // jesli lista ma tylko jeden element
        if (size() == 1) {
            // usuwamy ten element i ustawiamy head i tail na null
            delete _head;
            _head = nullptr;
            _tail = nullptr;
        }

        // jesli lista ma wiecej niz jeden
        else {
            // zapamietujemy drugi element
            Point* tmp = _head->_next;
            // usuwamy pierwszy
            delete _head;
            // head ustawiamy na "stary" drugi
            _head = tmp;
        }

    }

}

int LinkedList::size() {

    // jesli lista jest pusta, od razu zwracamy 0
    if (isEmpty())
        return 0;

    // przechodzimy po liscie i zliczamy elementy
    int count = 1;
    Point* tmp = _head;
    while (_tail != tmp) {
        tmp = tmp->_next;
        count++;
    }
    return count;

}

void print(LinkedList& list) {

    std::cout << list._name << "=[";

    // wypisujemy elementy tylko jesli lista nie jest pusta
    if (!list.isEmpty()) {
        // przechodzimy po liscie do konca i wypisujemy kolejne elementy
        Point* tmp = list._head;
        while (list._tail != tmp) {
            std::cout << *tmp << ", ";
            tmp = tmp->_next;
        }
        // petla while nie wypisuje ostatniego elementu, wiec trzeba to zrobic poza nia
        std::cout << *tmp;
    }

    std::cout << "]\n";

}

void LinkedList::addSorted(const Point& point) {

    // jesli n jest wieksze od ostatniego elementu w tablicy, albo lista jest pusta, po prostu dodajemy ten element
    if (isEmpty() || *_tail < point) {
        append(point);
    }

    // jesli n jest mniejsze od pierwszego elementu w tablicy, dodajemy n na poczatek
    else if (*_head > point) {
        Point* tmp = new Point(point);
        tmp->_next = _head;
        _head = tmp;
    }

    else {
        // szukamy takich dwoch elementow ze: prv->value < n < nxt->value i wstawiamy meidzy nie nowy element
        Point* prv = _head;
        Point* nxt = prv->_next;
        while (*nxt < point) {
            prv = nxt;
            nxt = nxt->_next;
        }
        prv->_next = new Point(point);
        prv->_next->_next = nxt;

    }

}

bool LinkedList::contains(const Point& point) {

    // jesli lista jest pusta na pewno nie ma tam n
    if (isEmpty())
        return false;

    // sprawdzamy czy n jest na poczatku, albo na koncu
    else if (*_head == point)
        return true;
    else if (*_tail == point)
        return true;

    // sprawdzamy czy n jest w srodku listy
    else {
        Point* tmp = _head;
        while (_tail != tmp) {
            if (*tmp == point)
                return true;
            tmp = tmp->_next;
        }
        // petla while prawidlowo nie sprawdza ostatniego elementu, bo zrobilismy to juz wczesniej
        // jesli petla while sie skonczy, a my nie zwrocilismy jeszcze true, to znaczy, ze w liscie nie ma n
        return false;
    }

}

std::ostream& operator <<(std::ostream& os, LinkedList& list) {

    os << list._name << "=[";

    // wypisujemy elementy tylko jesli lista nie jest pusta
    if (!list.isEmpty()) {
        // przechodzimy po liscie do konca i wypisujemy kolejne elementy
        Point* tmp = list._head;
        while (list._tail != tmp) {
            std::cout << *tmp << ", ";
            tmp = tmp->_next;
        }
        // petla while nie wypisuje ostatniego elementu, wiec trzeba to zrobic poza nia
        std::cout << *tmp;
    }

    std::cout << "]\n";

    return os;
}

LinkedList& operator+=(LinkedList& list, Point& point) {

    // przygotowujemy nowy element listy
    Point* tmp = new Point(point);

    if (list.isEmpty()) {
        // jesli lista jest pusta, po prostu ustawiamy head i tail na nowy element
        list._head = tmp;
        list._tail = tmp;
    }

    else {
        // "stary" ostatni element wskazuje teraz na element, ktory chcemy dodac, tak samo jak tail
        list._tail->_next = tmp;
        list._tail = tmp;
    }

    return list;

}

LinkedList& operator--(LinkedList& list) {

    if (!(list.isEmpty())) {

        // jesli lista ma tylko jeden element
        if (list.size() == 1) {
            // usuwamy ten element i ustawiamy head i tail na null
            delete list._head;
            list._head = nullptr;
            list._tail = nullptr;
        }

        // jesli lista ma wiecej niz jeden
        else {
            // zapamietujemy drugi element
            Point* tmp = list._head->_next;
            // usuwamy pierwszy
            delete list._head;
            // head ustawiamy na "stary" drugi
            list._head = tmp;
        }

    }
    return list;

}

LinkedList& operator+=(LinkedList& l1, LinkedList& l2) {
    
    // dodajemy tylko jesli list nie jest puste
    if (!(l2.isEmpty())) {

        // po kolei dodajemy wszystkie elementy list
        Point* tmp = l2._head;
        while (tmp != nullptr) {
            	Point* newPoint = new Point(*tmp);
		// pierwsza lista jest pusta
		if(l1._head == nullptr){
			l1._head = newPoint;
			l1._tail = newPoint;
		}
		else{
			l1._tail->_next = newPoint;
			l1._tail = newPoint;
		}
		tmp = tmp->_next;
        }
    }
    return l1;

}

LinkedList::LinkedList(LinkedList&& list) {

    _head = list._head;
    _tail = list._tail;
    _name = list._name;

    list._head = nullptr;
    list._tail = nullptr;
    list._name = "LX";

}

LinkedList& LinkedList::operator=(LinkedList& l) {
	//usuwanie tego co jest w liscie
	while(this->_head != nullptr){
		--(*this);
	}
	// dodawanie zawartosci listy l do listy
	*this += l;
	
	return *this;

}

LinkedList& operator+(LinkedList& l1, LinkedList& l2) {

    l1 += l2;

    return l1;
}