#pragma once
#include <iostream>
#include "exceptions.h"
#include <vector>

// klasa reprezentujaca liczbe
class Number
{
public:
// glosny konstruktor
    Number(std::string name, double num)
    {
        std::cout << "Tworzymy liczbe " << num << std::endl;
        _nazwa = name;
        if(_min==_max || (num<=_max && num>=_min)) _liczba = num;
        else
        {
            throw OutOfRange(name,num,_min,_max);
        }
    }
// glosny destruktor
    ~Number()
    {
        std::cout << "Usuwamy liczbe " << _liczba << std::endl;
    }
// print
    void print() const
    {
        std::cout << _nazwa << " = " << _liczba << std::endl;
    }
// funkcja skipujaca wypisywanie tekstu w main poprzez wyrzucenie wyjatku
    double Skip()
    {
        throw _liczba;
    }
// ustawianie przedzialu liczb
    static void setRange(double min, double max)
    {
        _min = min;
        _max = max;
    }
// obsluga zbioru liczb
    static Number* set(std::string numName, double numValue)
    {
        Number * tmp = new Number(numName,numValue);
        setNum.push_back(tmp);
        return tmp;
    }
// zmienne zakresu - jezeli sa rowne, to zakres jest dowolny 
//(bez sensu deklarowac liczby z pustego zakresu, wiec wykorzystuje ten przypadek)
    static double _min;
    static double _max;
    static std::vector<Number*> setNum;
private:
    std::string _nazwa;     // nazwa liczby
    double _liczba;         // wartosc liczby
};

// obsługa zmiennych statycznych
double Number::_min = 0.0;
double Number::_max = 0.0;
std::vector<Number*> Number::setNum = {};
