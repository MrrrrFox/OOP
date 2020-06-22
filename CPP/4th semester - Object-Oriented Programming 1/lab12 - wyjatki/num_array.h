#pragma once
#include "number.h"
#include <vector>
#include "exceptions.h"

// klasa reprezentujaca tablice liczb
class NumArray
{
public:
// konstruktor
    NumArray(int num) : _zakres(num) {}
// obsluga zbioru liczb
    void set(int position, Number* myNumber)
    {
        if(numberSet.size()>=_zakres) throw OutOfSize();
        else numberSet.insert(numberSet.begin()+position,myNumber);
    }
// destruktor
    ~NumArray()
    {
        for(auto const &elem : numberSet)
        {
            delete elem;
        }
        numberSet.clear();
    }
private:
    unsigned int _zakres;           // zakres tablicy
    std::vector<Number*> numberSet; // tablica (wektor) liczb
};

