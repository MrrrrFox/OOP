#pragma once
#include <iostream>
//////////////////////////////////////////////////////////////////////////////////////////////////// ZELAZKO
// klasa bazowa dla zelazek
class Zelazko
{
protected:
    std::string _nazwa;
    float _cena;
    int _akt_temp;
    int _max_temp;
public:
// konstruktory
    Zelazko() = default;
    Zelazko(const float price)
    {
        _nazwa = "";
        _cena = price;
        _akt_temp = 0;
    }
// funkcja ustawiajaca temperature
    void UstawTemperature(int temp)
    {
        if(temp<=_max_temp)
        {
            _akt_temp = temp;
        }
        else
        {
            std::cout << "Ten model nie obsluguje takiego zakresu temperatur." << std::endl;
        }
    }
// funkcja wypisujaca wlasciwosci zelazka
    void WypiszWlasciwosci()
    {
        std::cout << _nazwa << " cena: " << _cena << ". temperatura: " << _akt_temp << std::endl;
    }
// getter aktualnej temperatury
    int get_akt_temp()
    {
        return _akt_temp;
    }
};

// klasa reprezentujaca zelazka marki Philips (zmienia się tylko konstruktor - reszte dziedzicy po Zelazku)
class ZelazkoPhilips : public Zelazko
{
public:
    ZelazkoPhilips(const float price)
    {
        _nazwa = "Philips";
        _cena = price;
        _akt_temp = 0;
        _max_temp = 5;
    }
};

// klasa reprezentujaca zelazka marki Tefal (zmienia się tylko konstruktor - reszte dziedzicy po Zelazku)
class ZelazkoTefal : public Zelazko
{
public:
    ZelazkoTefal(const float price)
    {
        _nazwa = "Tefal";
        _cena = price;
        _akt_temp = 0;
        _max_temp = 7;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////// UBRANIE
// klasa bazowa dla ubran
class Ubranie
{
protected:
// wlasciwosci kazdego ubrania
    std::string _nazwa;
    float _cena;
    int _zakres_temp = 9;
    bool _wyprasowane = false;
public:
    Ubranie() = default;
// prasowanie koszuli
    void Prasuj(Zelazko& iron)
    {
        if(iron.get_akt_temp() <= _zakres_temp)
        {
            if(_wyprasowane == true)
            {
                std::cout << "Ubranie nie wymaga prasowania." << std::endl;
            }
            else
            {
                std::cout << "Prasuje " << _nazwa << " zelazkiem o temp. "<< iron.get_akt_temp() <<"." << std::endl;
                _wyprasowane = true;
            }
        }
        else
        {
            std::cout << "Zelazko za gorace." << std::endl;
        }
    }
// wypisanie wlasciwosi
    void WypiszWlasciwosci()
    {
        std::cout << _nazwa << " cena: " << _cena << ". Stan ubrania: " << (_wyprasowane==0 ? "pogniecione." : "wyprasowane.");
    }
// gniecenie ubrania
    virtual void Pogniec()
    {
        _wyprasowane = false;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////// KOSZULE
// klasa bazowa dla koszul
class Koszula : public Ubranie
{
protected:
    bool _wyprasowane_rekawy = false;
public:
// konstruktory
    Koszula() = default;
    Koszula(const float price)
    {
        _cena = price;
    }
// wypisanie wlasciwosci
    void WypiszWlasciwosci()
    {
        std::cout << _nazwa << " cena: " << _cena << ". Stan ubrania: " << (_wyprasowane==0 ? "pogniecione. " : "wyprasowane. ") << "Stan rekawow: " << (_wyprasowane_rekawy==0 ? "pogniecione." : "wyprasowane.") << std::endl;
    }
// prasowanie rekawow
    void PrasujRekawy(Zelazko& iron)
    {
        if(iron.get_akt_temp() <= _zakres_temp)
        {
            if(_wyprasowane_rekawy == true)
            {
                std::cout << "Ubranie nie wymaga prasowania rekawow." << std::endl;
            }
            else
            {
                std::cout << "Prasuje rekawy " << _nazwa << " zelazkiem o temp. "<< iron.get_akt_temp() <<"." << std::endl;
                _wyprasowane_rekawy = true;
            }
        }
        else
        {
            std::cout << "Zelazko za gorace." << std::endl;
        }
    }
// gniecenie koszuli
    void Pogniec()
    {
        _wyprasowane = false;
        _wyprasowane_rekawy = false;
    }
};

// klasa reprezentujaca koszule bawelniane (zmienia się tylko konstruktor - reszte dziedzicy po Koszuli i Ubraniu)
class KoszulaBawelniana : public Koszula
{
public:
    KoszulaBawelniana(const float price)
    {
        _nazwa = "Koszula bawelniana";
        _cena = price;
        _zakres_temp = 7;
    }
};

// klasa reprezentujaca koszule jedwabne (zmienia się tylko konstruktor - reszte dziedzicy po Koszuli i Ubraniu)
class KoszulaJedwabna : public Koszula
{
public:
    KoszulaJedwabna(const float price)
    {
        _nazwa = "Koszula jedwabna";
        _cena = price;
        _zakres_temp = 3;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////// SPODNIE
// klasa bazowa dla spodni
class Spodnie : public Ubranie
{
protected:
    bool _wyprasowane_nogawki = false;
public:
// konstruktory
    Spodnie() = default;
    Spodnie(const float price)
    {
        _cena = price;
    }
// wypisanie wlasciwosci
    void WypiszWlasciwosci()
    {
        std::cout << _nazwa << " cena: " << _cena << ". Stan ubrania: " << (_wyprasowane==0 ? "pogniecione. " : "wyprasowane. ") << "Stan nogawek: " << (_wyprasowane_nogawki==0 ? "pogniecione." : "wyprasowane.") << std::endl;
    }
// prasowanie nogawek
    void PrasujNogawki(Zelazko& iron)
    {
        if(iron.get_akt_temp() <= _zakres_temp)
        {
            if(_wyprasowane_nogawki == true)
            {
                std::cout << "Ubranie nie wymaga prasowania nogawek." << std::endl;
            }
            else
            {
                std::cout << "Prasuje nogawki " << _nazwa << " zelazkiem o temp."<< iron.get_akt_temp() << std::endl;
                _wyprasowane_nogawki = true;
            }
        }
        else
        {
            std::cout << "Zelazko za gorace." << std::endl;
        }
    }
// gniecenie spodni
    void Pogniec()
    {
        _wyprasowane = false;
        _wyprasowane_nogawki = false;
    }
};

// klasa reprezentujaca spodnie bawelniane (zmienia się tylko konstruktor - reszte dziedzicy po Spodniach i Ubraniu)
class SpodnieBawelniane : public Spodnie
{
public:
    SpodnieBawelniane(const float price)
    {
        _nazwa = "Spodnie bawelniane";
        _cena = price;
        _zakres_temp = 7;
    }
};

// klasa reprezentujaca spodnie jedwabne (zmienia się tylko konstruktor - reszte dziedzicy po Spodniach i Ubraniu)
class SpodnieJedwabne : public Spodnie
{
public:
    SpodnieJedwabne(const float price)
    {
        _nazwa = "Spodnie jedwabne";
        _cena = price;
        _zakres_temp = 3;
    }
};