#pragma once
#include <iostream>
#include <exception>

// klasa reprezentujaca tablice (typ T)
template<int size, typename T> class Array
{
public:
// konstruktor
    Array()
    {
        std::cout << "---Tworze wersje T" << std::endl;
    }
// destruktor
    ~Array() = default;
// przeciazenie operatora []
    T& operator[](unsigned int index);
// przeciazenie operatora <<
    friend std::ostream& operator<<(std::ostream& out, const Array<size,T> & myArray) 
    {
        for(int i=0; i<myArray.getSize(); ++i) out << myArray.getValue(i) << " ";
        return out;
    }

protected:
// getter wartosci tablicy
    T getValue(int index) const
    {
        return _tab[index];
    }
// getter rozmiaru
    int getSize() const
    {
        return _rozm;
    }
// rozmiar tablicy
    unsigned int _rozm = size;
// wskaznik na okreslony typ (pod tablice)
    T _tab[size] = {T()};
};

// przeciazenie operatora []
template <int size,typename T> T& Array<size,T>::operator[](unsigned int index)
{
    if(index>=_rozm) throw std::invalid_argument("Indeks poza zakresem");
    return _tab[index];
}






// klasa reprezentujaca tablice (typ T*)
template<int size, typename T> class Array<size,T*>
{
public:
// konstruktor
    Array()
    {
        std::cout << "---Tworze wersje T*" << std::endl;
    }
// destruktor
    ~Array()
    {
        for(const T* elem : _tab) delete elem;
        std::cout << "---Usuwam wersje T*" << std::endl;
    }
// przeciazenie operatora []
    T*& operator[](unsigned int index);
// przeciazenie operatora <<
    friend std::ostream& operator<<(std::ostream& out, const Array<size,T*> & myArray) 
    {
        for(const auto& elem : myArray._tab)
        {
            if(elem != nullptr) out << *elem << " ";
        }
        return out;
    }

protected:
// rozmiar tablicy
    unsigned int _rozm = size;
// wskaznik na okreslony typ (pod tablice)
    T* _tab[size] = {nullptr};
};

// przeciazenie operatora []
template <int size,typename T> T*& Array<size,T*>::operator[](unsigned int index)
{
    if(index>=_rozm) throw std::invalid_argument("Indeks poza zakresem");
    return _tab[index];
}