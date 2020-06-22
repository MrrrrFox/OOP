#pragma once

#include <iostream>

#define MaxTab 10

class IntArrayList
{
    int tab[MaxTab];
	int size;
public:
    IntArrayList();
	~IntArrayList();
    void print();
	int find(int);
	void printFind(int);
	void add(int);
	void add(int*, int);
	void add(int, int);
	void add(int, bool);
	void remove(int);
	void remove(int, int);
};

