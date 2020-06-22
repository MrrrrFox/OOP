#include "point.h"

// konstruktory i destruktor:

Point::Point() {
    _x = _y = 0;
    _name = nullptr;
    _next = nullptr;
}

Point::Point(double x, double y) {
    const char* name = "Miejsce nieznane";
    _x = x;
    _y = y;
    _name = new char[strlen(name) + 1];
    strcpy(_name, name);
    _next = nullptr;
}

Point::Point(const char* name, double x, double y) {
    _x = x;
    _y = y;
    _name = new char[strlen(name) + 1];
    strcpy(_name, name);
    _next = nullptr;
}

Point::Point(const Point& point) {
    _x = point._x;
    _y = point._y;
    _name = new char[strlen(point._name) + 1];
    strcpy(_name, point._name);
    _next = point._next;
}

Point::Point(Point&& point) {
    _x = point._x;
    _y = point._y;
    _name = new char[strlen(point._name) + 1];
    strcpy(_name, point._name);
    _next = point._next;

    point._x = 0;
    point._y = 0;
    point._next = nullptr;
    if (point._name != nullptr)
        delete[] point._name;
}

Point::~Point() {
    if (_name != nullptr)
        delete[] _name;
}


// getX, getY, getName, getNext:

double Point::getX() const {
    return _x;
}

double Point::getY() const {
    return _y;
}

char* Point::getName() const {
    if (_name == nullptr)
        return (char*)"NULL";
    else
        return _name;    
}


// operatory:

bool operator==(const Point& a, const Point& b) {
    if (a.getX() == b.getX())
        return true;
    if (a.getY() == b.getY())
        return true;
    return false;
}

bool operator>(const Point& a, const Point& b) {
    if (a.getX() > b.getX())
        return true;
    else if (a.getX() == b.getX())
        return a.getY() > b.getY();
    return false;
}

bool operator<(const Point& a, const Point& b) {
    if (a.getX() < b.getX())
        return true;
    else if (a.getX() == b.getX())
        return a.getY() < b.getY();
    return false;
}

std::ostream& operator <<(std::ostream& os, const Point& point) {
    os << point.getName() << "(" << point.getX() << "," << point.getY() << ")";
    return os;
}