#include "virus.h"

// konstruktor bezparametrowy
Virus::Virus()
{
    _lancuch = nullptr;
    _wiek = 0;
}

// konstruktor ustawiajacy nazwe
Virus::Virus(std::string name)
{
    _nazwa = name;
    _lancuch = nullptr;
    _wiek = 0;
}

// konstruktor kopiujacy
Virus::Virus(Virus & myVirus)
{
    _nazwa = myVirus.get_name();
    ++myVirus._wiek;
    _wiek = 0;
    set_RNA(myVirus._lancuch->get_RNA());
}

// konstruktor przenoszacy (mutuje)
Virus::Virus(Virus && myVirus)
{
    _nazwa = std::move(myVirus._nazwa);
    _lancuch = std::move(myVirus._lancuch);
    myVirus._lancuch = nullptr;
    _wiek = myVirus._wiek;
    mutate();
}

// destruktor
Virus::~Virus()
{
    delete _lancuch;
    _lancuch = nullptr;
}

// getter nazwy
std::string Virus::get_name()
{
    return _nazwa;
}

// getter lancucha
RNA* Virus::get_RNA()
{
    return _lancuch;
}

// getter wieku
int Virus::get_age() const
{
    return _wiek;
}

// setter lancucha
void Virus::set_RNA(const std::vector<Nukleotyp> myChain)
{
    _lancuch = new RNA(myChain);
}

// przeciazony operator = (kopiowanie, ale wg instrukcji nie zwieksza wieku)
Virus Virus::operator=(Virus & myVirus)
{
    _nazwa = myVirus._nazwa;
    set_RNA(myVirus._lancuch->get_RNA());
    _wiek = myVirus._wiek;
    return *this;
}

// przeciazony operator = (przenoszenie, mutuje)
Virus Virus::operator=(Virus && myVirus)
{
    _nazwa = std::move(myVirus._nazwa);
    _lancuch = std::move(myVirus._lancuch);
    myVirus._lancuch = nullptr;
    _wiek = myVirus._wiek;
    mutate();
    return *this;
}

// funkcja mutujaca wirusa
void Virus::mutate()
{
    _lancuch->mute();
}