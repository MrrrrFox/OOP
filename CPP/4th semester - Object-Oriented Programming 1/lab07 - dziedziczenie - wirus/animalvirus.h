#pragma once
#include "virus.h"

// klasa reprezentujaca wirusa od zwierzecia
class AnimalVirus : public Virus
{
private:
// nazwa nosiciela
    std::string _nosiciel;
public:
// konstruktory
    AnimalVirus() = default;
    AnimalVirus(std::string, std::string, const std::vector<Nukleotyp>);
    AnimalVirus(AnimalVirus &);
    AnimalVirus(AnimalVirus &&);
// przeciazone operatory
    AnimalVirus operator=(AnimalVirus &);
    AnimalVirus operator=(AnimalVirus &&);
// getter nosiciela
    std::string get_animal_host();
};