#pragma once
#include <iostream>

#include <string>

class IntLinkedList;

class Element
{
	friend class IntLinkedList;
public:
	int value;
	Element * next;
	Element();							// bezparametrowy
	Element(int);						// ustawiajacy wartosc	
	Element(Element&);					// kopiujacy
	~Element();							// destruktor
};

class IntLinkedList
{
    Element *head;
	Element *tail;
	std::string name;
public:
    IntLinkedList();
	IntLinkedList(std::string);
	~IntLinkedList();
	int size();
	int isEmpty();
	void print();
	friend void print(IntLinkedList&);
	void append(int);
	void append(Element&);
	void append(IntLinkedList&);
	void addSorted(int, bool = false);
	void addSorted(Element&, bool = false);
	void addSorted(IntLinkedList&);
	void removeFirst();
	void removeLast();
	void removeValue(int);
	bool contains(int);	
};

