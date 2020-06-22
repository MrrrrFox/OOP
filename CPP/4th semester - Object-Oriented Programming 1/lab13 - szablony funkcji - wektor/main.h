#pragma once
#include <iostream>

// klasa testowa
class TestObject
{
public:
// konstruktor domyslny
    TestObject() = default;
// konstruktor 1-parametrowy ustawiajacy ID (lista inicjalizacyjna) 
    TestObject(int myID) : ID(myID) {}
// wypisywanie informacji o obiekcie
    void print() const
    {
        std::cout << "Obiekt o identyfikatorze ID=" << ID << std::endl;
    }
// setter ID
    void set(int newID)
    {
        ID = newID;
    }
protected:
// zmienne
    int ID;
};

// klasa reprezentujaca wektor
class Vector
{
public:
// szablon funkcji inicjalizujacej wektor (rozmiar + sama tablica)
    template<typename T1> static void initialise(T1 newSize)
    {
        _rozmiar = newSize;
        _tablica = new T1[_rozmiar];
    }
// szablon funkcji inicjalizujacej wektor podanym obiektem (rozmiar + sama tablica)
    //template<typename T1, typename T2> static void initialise(T1 newSize, T2& myTestObj)
    template<typename T2> static void initialise(const int size, T2 myTestObj)
    {
        _rozmiar = newSize;
        _tablica = new T2[_rozmiar];
        // wypelnianie wektora obiektem
        for(int i=0; i<_rozmiar; ++i) static_cast<T2*>(_tablica)[i] = myTestObj;
    }
// szablon funkcji zwracajacej referencje do elementu wektora na wskazanej pozycji
    template<typename T1> static T1& at(int pos)
    {
        return static_cast<T1*>(_tablica)[pos];
    }
// szablon funkcji resetujacej (usuwajacej) wektor
    template<typename T1> static void reset()
    {
        if(_tablica!=nullptr)   // jezeli nie jest nullptr
        {
            delete[] static_cast<T1*>(_tablica);
            _tablica = nullptr; 
        }
    }
// funkcja zwracajaca rozmiar
    static int size()
    {
        return _rozmiar;
    }
protected:
// zmienne
    static int _rozmiar;
    static void * _tablica;
};

// obsluga zmiennych statycznych
int Vector::_rozmiar = 0;
void * Vector::_tablica = nullptr;
