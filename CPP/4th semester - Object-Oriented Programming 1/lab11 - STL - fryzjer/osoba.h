#pragma once
#include <iostream>

// klasa reprezentujaca osobe
class Person
{
public:
// konstroktor - lista inicjalizacyjna
    Person(std::string name, bool strzyzenie = false, bool plec = true) : _nazwa(name), _ostrzyzony(strzyzenie), _plec(plec) {}
// destruktor wirtualny
    virtual ~Person() = default;
// getter nazwy
    std::string name() const
    {
        return _nazwa;
    }
// strzyzenie
    void haircut()
    {
        if(!_ostrzyzony) _ostrzyzony = true;
        else std::cout << std::endl << "!!! Klient juz ostrzyzony !!!";
    }
// getter plci
    bool get_plec() const
    {
        return _plec;
    }
// funckje wirtualne - aktualny status i czy osoba jest już gotowe
    virtual void status() const {};
    virtual bool done() const = 0;
protected: // zmienne
    std::string _nazwa;
    bool _ostrzyzony;
    bool _plec; // kobiety -> true, mezczyzni -> false
};






// klasa reprezentuajaca kobiete
class Woman : public Person
{
public:
// konstruktor - lista inicjalizacyjna
    Woman(std::string name, bool strzyzenie = true, bool malowanie = true) : Person(name,!strzyzenie,true), _pomalowana(!malowanie) {}
// destruktor - komunikat
    ~Woman()
    {
        std::cout << std::endl << _nazwa << (_ostrzyzony==false ? " nieobcieta " : " obcieta ") << (_pomalowana==false ? "i niepomalowana" : "i pomalowana") << " idzie na zakupy";
    }
// wypisywanie statusu klienta
    void status() const
    {
        std::cout<< _nazwa << (_ostrzyzony==false ? " nieobcieta " : " obcieta ") << (_pomalowana==false ? "i niepomalowana" : "i pomalowana") << std::endl;
    }
// czy klient jest gotowy (true) czy cos jeszcze chce (false)
    bool done() const
    {
        if(_ostrzyzony && _pomalowana) return true;
        return false;
    }
// make-up
    void makeup()
    {
        if(!_pomalowana) _pomalowana = true;
        else std::cout << std::endl << "!!! Juz pomalowana !!!";
    }
protected: // zmienne
    bool _pomalowana;
};






// klasa reprezentuajaca mezczyzne
class Man : public Person
{
public:
// konstruktor - lista inicjalizacyjna
    Man(std::string name, bool strzyzenie = true, bool golenie = true) : Person(name,!strzyzenie,false), _ogolony(!golenie) {}
// destruktor - komunikat
    ~Man()
    {
        std::cout << std::endl << _nazwa << (_ostrzyzony==false ? " nieobciety " : " obciety ") << (_ogolony==false ? "i nieogolony" : "i ogolony") << " idzie na piwko";
    }
// wypisywanie statusu klienta
    void status() const
    {
        std::cout << _nazwa << (_ostrzyzony==false ? " nieobciety " : " obciety ") << (_ogolony==false ? "i nieogolony" : "i ogolony") << std::endl;
    }
// czy klient jest gotowy (true) czy cos jeszcze chce (false)
    bool done() const
    {
        if(_ostrzyzony && _ogolony) return true;
        return false;
    }
// golenie
    void shave()
    {
        if(!_ogolony) _ogolony = true;
        else std::cout << std::endl << "!!! Juz ogolony !!!";
    }
protected: // zmienne
    bool _ogolony;
};