#pragma once
#include <iostream>
#include <string>

// klasa testowa X
class X
{
public:
// konstuktor
    X() = default;
    X(std::string name) : _nazwa(name) {std::cout << "Tworze X " << _nazwa << std::endl;}
// wirtualny destruktor (pod wypisywanie w main)
    virtual ~X()
    {
        std::cout << "Usuwam X " << _nazwa << std::endl;
    }
// przeciazony operator <<
    friend std::ostream& operator<<(std::ostream& out, const X& myX);

protected:
// nazwa
    std::string _nazwa;
};

// przeciazony operator <<
std::ostream& operator<<(std::ostream& out, const X& myX)
{
    out << myX._nazwa;
    return out;
}

// klasa testowa Y dziedziczaca po X
class Y : public X
{
public:
// konstruktor
    Y(std::string name) : X(name) { std::cout << "Tworze Y " << _nazwa << std::endl;}
// destruktor
    ~Y() override
    {
        std::cout << "Usuwam Y " << _nazwa << std::endl;
    }
};