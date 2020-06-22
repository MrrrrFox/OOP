#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <iomanip>
#include <numeric>

// funkcja pomocnicza do NotInt
bool NotInt(double i)
{
   double rd = round(i), eps = 1e-9;
   return !(i<=rd+eps && i>=rd-eps); 
}
//  struktura odpowiedzialna za zliczanie zlych ocen
struct badScores
{
    bool operator()(double mark)
    {
        if(mark<3) return true;
        return false;
    }
};

// klasa reprezentujaca osobe (studenta )
class Person
{
protected:
// nazwa studenta
    std::string _nazwa;
// oceny studenta
    std::vector<double> _oceny;
public:
// konstruktor
    Person(std::string name, std::vector<double> marks) : _nazwa(name), _oceny(marks) {}
// wypisywanie
    void print() const
    {
        std::cout << _nazwa << ":" << std::setw(5);
        for(auto const &elem: _oceny)
        {
            std::cout << elem << std::setw(5);
        }
        std::cout<<std::endl;
    }
// suma
    double getSum() const
    {
        return accumulate(_oceny.begin(), _oceny.end(), 0.0);
    }
// getter ocen
    std::vector<double> get_oceny() const
    {
        return _oceny;
    }
// getter nazwy
    std::string get_nazwa() const
    {
        return _nazwa;
    }    
// pierwsza ocena z polowka
    auto notIntScores() const
    {
        std::vector<double>::const_iterator tmp = std::find_if(_oceny.begin(), _oceny.end(), NotInt); 
        return tmp;
    }
// zliczanie dobrych ocen (jako roznica wszystkich i zlych)
    int countGoodScores() const
    {
        int neg = count_if(_oceny.begin(), _oceny.end(), badScores());
        return _oceny.size() - neg;
    }
// zaprzyjaznienie NotInt
    friend bool NotInt(double i);
// dodanie oceny
    void addScore(double newMark)
    {
        _oceny.push_back(newMark);
    }
// usuniecie oceny
    void removeScore(double newMark)
    {
        auto iter = _oceny.begin();
        while(iter != _oceny.end())
        {
            if(*iter==newMark)
            {
                iter = _oceny.erase(iter);
                break;
            }
            else
            {
                ++iter;
            }
        }
    }
};

// funckja do obliczania sredniej oceny
double averageScore(const Person & myPerson)
{
    return myPerson.getSum()/myPerson.get_oceny().size();
}