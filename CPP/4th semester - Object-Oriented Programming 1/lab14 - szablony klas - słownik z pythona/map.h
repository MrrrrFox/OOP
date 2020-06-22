#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

// klasa reprezentujaca slownik
template <typename T1, typename T2> class Map
{
public:
// dodawanie elementu do slownika
    void insert(T1 first, T2 second);
// wypisywanie slownika
    void print(std::string preStr) const;
// przeciazenie operatora [] - normalne
    T2& operator[](const T1& first);
// przeciazenie operatora [] - const
    const T2& operator[](const T1& first) const;
// czy podany element jest w slowniku
    bool contains(const T1& first) const;
protected:
// slownik jako wektor par
    std::vector<std::pair<T1,T2>> _tab;
};

// dodawanie elementu do slownika
template<typename T1, typename T2> void Map<T1,T2>::insert(T1 first, T2 second)
{
    _tab.push_back(std::make_pair(first,second));
}

// wypisywanie slownika
template<typename T1, typename T2> void Map<T1,T2>::print(std::string preStr) const
{
    for(const auto& elem : _tab) std::cout << "---" << preStr << "--- klucz: " << elem.first << " wartosc: " << elem.second << std::endl;
}

// przeciazenie operatora [] - normalne 
template<typename T1, typename T2> T2& Map<T1,T2>::operator[](const T1& first)
{
    auto iter = std::find_if(std::begin(_tab), std::end(_tab), [&first](auto& elem){return elem.first == first;});
    if(iter == std::end(_tab))
    {
        insert(first, T2());
        return _tab[(_tab.size())-1].second;
    }
    else return (*iter).second;
}

// przeciazenie operatora [] - const
template<typename T1, typename T2> const T2& Map<T1,T2>::operator[](const T1& first) const
{
    auto iter = std::find_if(std::begin(_tab), std::end(_tab), [&first](auto& elem){return elem.first == first;});
    if(iter == std::end(_tab)) throw std::invalid_argument("Niewlasciwy klucz");
    else return (*iter).second;
}

// czy podany element jest w slowniku
template<typename T1, typename T2> bool Map<T1,T2>::contains(const T1& first) const
{
    auto iter = std::find_if(std::begin(_tab), std::end(_tab), [&first](auto& elem){return elem.first == first;});
    return iter == std::end(_tab) ? false : true;
}