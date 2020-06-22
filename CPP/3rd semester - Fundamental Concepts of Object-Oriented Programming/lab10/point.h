#pragma once

#include <iostream>
#include <cstring>

class Point {

private:
    double _x, _y;
    char* _name;
    

public:
	Point* _next;
    Point();
    Point(double, double);
    Point(const char*, double, double);
    Point(const Point&);
    Point(Point&&);
    ~Point();

    double getX() const;
    double getY() const;
    char* getName() const;

    friend bool operator==(const Point&, const Point&);
    friend bool operator>(const Point&, const Point&);
    friend bool operator<(const Point&, const Point&);
    friend std::ostream& operator <<(std::ostream&, const Point&);

};