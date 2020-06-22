#include "animalvirus.h"

// konstruktor ustawiajacy podane parametry
AnimalVirus::AnimalVirus(std::string name, std::string host, const std::vector<Nukleotyp> myVirus)
{
    _nazwa = name;
    _nosiciel = host;
    set_RNA(myVirus);
}

// konstruktor kopiujacy
AnimalVirus::AnimalVirus(AnimalVirus & myVirus)
{
    _nazwa = myVirus.get_name();
    ++myVirus._wiek;
    _wiek = 0;
    set_RNA(myVirus._lancuch->get_RNA());
    
    _nosiciel = myVirus.get_animal_host();
}

// konstruktor przenoszacy (chyba mutuje)
AnimalVirus::AnimalVirus(AnimalVirus && myVirus)
{
    _nazwa = std::move(myVirus._nazwa);
    _lancuch = std::move(myVirus._lancuch);
    myVirus._lancuch = nullptr;
    _wiek = myVirus._wiek;
    mutate();
    
    _nosiciel = myVirus.get_animal_host();
}

// przeciazony operator = (kopiowanie - użycie rzeczy z Virus)
AnimalVirus AnimalVirus::operator=(AnimalVirus & myVirus)
{
    _nazwa = myVirus._nazwa;
    set_RNA(myVirus._lancuch->get_RNA());
    _wiek = myVirus._wiek;
    
    _nosiciel = myVirus.get_animal_host();
    
    return *this;
}

// przeciazony operator = (przenoszenie - użycie rzeczy z Virus, chyba nie mutuje)
AnimalVirus AnimalVirus::operator=(AnimalVirus && myVirus)
{
    _nazwa = std::move(myVirus._nazwa);
    _lancuch = std::move(myVirus._lancuch);
    myVirus._lancuch = nullptr;
    _wiek = myVirus._wiek;

    _nosiciel = myVirus.get_animal_host();
    
    return *this;
}

// getter nosiciela
std::string AnimalVirus::get_animal_host()
{
    return _nosiciel;
}