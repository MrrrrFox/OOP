#pragma once
#include <iostream>

// klasa obslugujaca wyjatek zadeklarowania liczby spoza zakresu
class OutOfRange
{
public:
// zmienne liczby do wypisywania
    std::string _nazwa;
    double _liczba;
    double _zakres_min;
    double _zakres_max;
// konstruktor - lista inicjalizacyjna
    OutOfRange(std::string name, double num, double min, double max) : _nazwa(name), _liczba(num), _zakres_min(min), _zakres_max(max) 
    {
        std::cout << "Kontrola zakresu" << std::endl;
    }
// destruktor
    ~OutOfRange() = default;
// przeciazony operator wyjscia
    friend std::ostream& operator<<(std::ostream&, OutOfRange&);
};

// przeciazony operator wyjscia dla klasy OutOfRange
std::ostream& operator<<(std::ostream& out, const OutOfRange& myOutOfRange)
{
    out << "UPS! Mamy problem z zakresem" << std::endl;
    out << "Liczba " << myOutOfRange._nazwa << " ma wartosc " << myOutOfRange._liczba << " spoza dopuszczalnego zakresu: [" << myOutOfRange._zakres_min << ", " << myOutOfRange._zakres_max << "]"; 
    return out;
}

// klasa obslugujaca wyjatek wyjscia poza tablice w NumArray
class OutOfSize
{
public:
// konstruktor
    OutOfSize()
    {
        std::cout << "Kontrola rozmiaru" << std::endl;
        // usuwanie
        std::cout << "UPS! Tablica pelna, koniec zabawy" << std::endl;
    }
};