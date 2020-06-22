#pragma once
#include <iostream>

#include "person.h"
#include <functional>

// komparator srednich ocen studentow
bool greaterAverage(const Person & stud1, const Person & stud2)
{
    return averageScore(stud1) > averageScore(stud2);
}

// komparator ocen studenctow z konkrenej kolumny 
bool columnSort(const Person & stud1, const Person & stud2, int col_index)
{
    return stud1.get_oceny()[col_index] > stud2.get_oceny()[col_index];
}

// funkcja pomocnicza do full printa
void printFullStudent(const Person & student)
{
    std::cout<< student.get_nazwa() << " srednia: " << std::setw(5) << averageScore(student) << " suma:" << std::setw(5) << student.getSum() << " oceny:" << std::setw(5);
    for(auto const &elem: student.get_oceny())
    {
        std::cout << elem << std::setw(5);
    }
    std::cout<<std::endl;
}

// funkcja pomocnicza do printa
void printStudent(const Person & student)
{
    std::cout<< student.get_nazwa() << " oceny:" << std::setw(5);
    for(auto const &elem: student.get_oceny())
    {
        std::cout << elem << std::setw(5);
    }
    std::cout<<std::endl;
}

// klasa reprezentujaca katalog studentow
class Data
{
protected:
// lista (wektor) studentow
    std::vector<Person> _studenci;
public:

// wypisywanie
    void fullprint()
    {
        std::for_each(_studenci.begin(), _studenci.end(), printFullStudent);
    }
// print do wypisywania tylko ocen
    void print()
    {
        std::for_each(_studenci.begin(), _studenci.end(), printStudent);
    }
// przeciazony operator +=
    void operator+=(const Person & newPerson)
    {
        _studenci.push_back(newPerson);
    }
// przeciaony operator []
    Person& operator[](int i)
    {
        return _studenci[i];
    }
// sortowanie po kolumnie
    Data& sort(int column)
    {
        auto f = std::bind(columnSort, std::placeholders::_1, std::placeholders::_2,column);
        std::sort(_studenci.begin(), _studenci.end(), f);
        return *this;
    }
// sortowanie wg sredniej
    Data& sortBy(bool (*compare)(const Person &, const Person &))
    {
        std::sort(_studenci.begin(),_studenci.end(), compare);
        return *this;
    }
};