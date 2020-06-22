#pragma once
#include "osoba.h"
#include <memory>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <string>
#include <utility>

// komparator do sortowania
struct myCompare
{
    bool operator()(const std::unique_ptr<Person>& p1, const std::unique_ptr<Person>& p2)
    {
        if(p1->get_plec() && p2->get_plec()) return false;
        if(p1->get_plec() && !p2->get_plec()) return true;
        return false;
    }
};

// klasa reprezentujaca kolejke
class QKolejka
{
public:
// konstruktor
    QKolejka() = default;
// dodawanie do kolejki
    void add(std::unique_ptr<Person> p)
    {
        _kolejka.push_back(std::move(p));
        std::sort(_kolejka.begin(),_kolejka.end(),myCompare());
    }
// wypisanie kolejki
    void print(std::string title)
    {
        std::cout<< "*** " << title << " ***" << std::endl;
        for(auto const &elem : _kolejka) elem->status();
    }
// lista (w sensie wektor) kobiet
    std::vector<Woman*> getWoman()
    {
        std::vector<Woman*> kobiety;
        for(auto const & elem : _kolejka) if(Woman* woman_ptr = dynamic_cast<Woman*>(elem.get())) kobiety.push_back(woman_ptr);
        return kobiety;
    }
// zliczanie imion
// myslalem nad wktorem par lub innymi sposobami, ale ten pomysł wydaje mi się najprostszy i bez zbędnych udziwnien
    void countNames()
    {
        // spisanie wektora imiona z kolejki i posortowanie
        std::vector<std::string> imiona;
        for(auto & elem : _kolejka) imiona.push_back(elem->name());
        std::sort(imiona.begin(),imiona.end()); // mialem swoj komparator, ale pozniej sie zorientowalem ze stringi posortuja sie z domyslnym
        
        // przejscie po wektorze i wypisanie ilosci (za pomoca inta pomocniczego), jezeli nastepne imie jest inne niz aktualnie rozpatrywane
        int ile = 0;
        for(unsigned int i = 0; i<imiona.size(); ++i)
        {
            ++ile;
            if(imiona[i+1].compare(imiona[i])) 
            {
                std::cout << imiona[i] << " : " << ile << std::endl;
                ile = 0;
            }
        }
    }
// obcinanie wlosow pierwszemu klientowi w kolejce
    void haircut()
    {
        _kolejka[0]->haircut();
        if(_kolejka[0]->done()) _kolejka.erase(_kolejka.begin());
    }
// obcinanie wlosow pierwszym klientowi o danym imieniu w kolejce
    void haircut(std::string nameToHaircut)
    {
        unsigned int i = 0;
        for(auto const & elem : _kolejka)
        {
            if(!elem->name().compare(nameToHaircut))    // jezeli zgadza sie imie
            {
                elem->haircut();
                if(elem->done()) _kolejka.erase(_kolejka.begin()+i);
                break;
            }
            ++i;
        }
    }
// golenie pierwszego mezczyzny o danym imieniu w kolejce
    void shave(std::string nameToShave)
    {
        unsigned int i = 0;
        for(auto const & elem : _kolejka)
        {
            if(!elem->name().compare(nameToShave))      // jezeli zgadza sie imie
            {
                dynamic_cast<Man*>(elem.get())->shave();
                if(elem->done()) _kolejka.erase(_kolejka.begin()+i);
                break;
            }
            ++i;
        }
    }
    
protected:
    std::vector<std::unique_ptr<Person>> _kolejka;
};