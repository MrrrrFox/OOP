#pragma once
#include "rna.h"

// klasa reprezentujaca wirusa
class Virus
{
protected:
    std::string _nazwa;
    RNA * _lancuch;
    int _wiek;
public:
// konstruktory i destruktor
    Virus();
    Virus(std::string);
    Virus(Virus &);
    Virus(Virus &&);
    ~Virus();
// gettery
    std::string get_name();
    RNA* get_RNA();
    int get_age() const;
// settery
    void set_RNA(const std::vector<Nukleotyp>);
// przeciazone operatory
    Virus operator=(Virus &);
    Virus operator=(Virus &&);
// funkcja mutujaca - korzysta z mute() z RNA
    void mutate();
};