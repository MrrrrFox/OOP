// załącz potrzebne pliki i opisz tutaj strukturę klas

#pragma once

#include "wirtualne.h"
#include <iostream>
#include <cmath>

// klasa reprezentujaca punkt - osobna klasa zawierana w ksztaltach
class Point
{
public:
// wspolrzedne punktu
    double _x;
    double _y;
// konstruktory i destruktor
    Point() = default;
    Point(double x, double y) : _x(x), _y(y) {}
    Point(const Point & myPoint)
    {
        _x = myPoint._x;
        _y = myPoint._y;
    }
// zaprzyjazniony operator wyjscia
    friend std::ostream & operator <<(std::ostream& out, const Point& myPoint)
    {
        out << "(" << myPoint._x << ", " << myPoint._y << ")";
        return out;
    }
};

// klasa reprezentuajaca kolo
class Circle : public Drawable, public ClosedShape, public Transformable
{
protected:
    // wlasciwosci kola
    Point _srodek;
    double _promien;
public:
// konstruktor
    Circle(const Point & myPoint, double r) : _srodek(myPoint), _promien(r) {}
// dlugosc
    double length() override
    {
        return 2*M_PI*_promien;
    }
// pole
    double area() const override
    {
        return M_PI*pow(_promien,2);
    }
// przesuniecie
    void shift(double trans_x, double trans_y) override
    {
        _srodek._x += trans_x;
        _srodek._y += trans_y;
    }
// rysowanie
    void draw() override
    {
        std::cout << "Rysujemy kolo o srodku " << _srodek << "i promieniu " << _promien << std::endl;
    }
};

// klasa reprezentuajaca odcinek
class Section : public Drawable, public Transformable
{
public:
// wlasciwosci kola
    Point _punkt1;
    Point _punkt2;
// konstruktor
    Section(const Point & myPoint1, const Point & myPoint2) : _punkt1(myPoint1), _punkt2(myPoint2) {}
// dlugosc
    double length() override
    {
        return sqrt(pow(_punkt1._x-_punkt2._x,2) + pow(_punkt1._y-_punkt2._y,2));
    }
// przesuniecie
    void shift(double trans_x, double trans_y) override
    {
        _punkt1._x += trans_x;
        _punkt1._y += trans_y;
        _punkt2._x += trans_x;
        _punkt2._y += trans_y;
    }
// rysowanie
    void draw() override
    {
        std::cout << "Rysujemy odcinek od " << _punkt1 << " do " << _punkt2 << std::endl;
    }
};

// klasa reprezentuajaca deltoid
class Deltoid : public Drawable, public ClosedShape, public Transformable
{
protected:
    // wlasciwosci kola
    Point _punkt1;
    Point _punkt2;
    Point _punkt3;
    Point _punkt4;
public:
// konstruktor
    Deltoid(const Point & myPoint1, const Point & myPoint2, const Point & myPoint3, const Point & myPoint4) : _punkt1(myPoint1), _punkt2(myPoint2), _punkt3(myPoint3), _punkt4(myPoint4) {}
    Deltoid(const Section & myDiag1, const Section & myDiag2) : _punkt1(myDiag1._punkt1), _punkt2(myDiag2._punkt1), _punkt3(myDiag1._punkt2), _punkt4(myDiag2._punkt2) {}
// dlugosc
    double length() override
    {
        Section sec1(_punkt1, _punkt2);
        Section sec2(_punkt2, _punkt3);
        Section sec3(_punkt3, _punkt4);
        Section sec4(_punkt4, _punkt1);
        
        return sec1.length()+sec2.length()+sec3.length()+sec4.length();
    }
// pole - output jest zly, nie chyba nie dzieli Pani przez 2
    double area() const override
    {
        Section diag1(_punkt1, _punkt3);
        Section diag2(_punkt2, _punkt4);
        
        return diag1.length()*diag2.length();
    }
// przesuniecie
    void shift(double trans_x, double trans_y) override
    {
        _punkt1._x += trans_x;
        _punkt1._y += trans_y;
        _punkt2._x += trans_x;
        _punkt2._y += trans_y;
        _punkt3._x += trans_x;
        _punkt3._y += trans_y;
        _punkt4._x += trans_x;
        _punkt4._y += trans_y;
    }
// rysowanie
    void draw() override
    {
        std::cout << "Rysujemy deltoid o wierzcholkach " << _punkt1 << ", " << _punkt2 << ", " << _punkt3 << ", " << _punkt4 << std::endl;
    }
};

