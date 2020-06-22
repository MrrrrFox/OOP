#pragma once

#include "point.h"

class LinkedList {

private:
    Point* _head;
    Point* _tail;
    std::string _name;

public:
    LinkedList();
    LinkedList(std::string);
    LinkedList(LinkedList&&);
    ~LinkedList();
    int size();
    bool isEmpty();
    void append(const Point&);
    void addSorted(const Point&);
    void removeFirst();
    bool contains(const Point&);
    friend void print(LinkedList&);
    LinkedList& operator=(LinkedList&);
    friend LinkedList& operator+(LinkedList&, LinkedList&);
    friend std::ostream& operator <<(std::ostream&, LinkedList&);
    friend LinkedList& operator+=(LinkedList&, Point&);
    friend LinkedList& operator--(LinkedList&);
    friend LinkedList& operator+=(LinkedList&, LinkedList&);

};