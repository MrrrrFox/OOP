#pragma once

#include <iostream>

struct el_listy1
{
    int klucz;
    el_listy1 *nastepny;
};

class IntLinkedList
{
    el_listy1 *head;
	el_listy1 *tail;
public:
    IntLinkedList();
	~IntLinkedList();
	int size();
	int isEmpty();
	void print();
	void append(int);
	void addSorted(int);
	void removeFirst();
	void removeValue(int);
	bool contains(int);	
};

