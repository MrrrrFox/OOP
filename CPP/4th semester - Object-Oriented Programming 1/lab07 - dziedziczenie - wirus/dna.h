#pragma once
#include "rna.h"

// klasa reprezentujaca DNA
class DNA : public RNA
{
private:
// dwa lancuchy dna
    RNA _lancuchy[2];
public:
// konstruktor
    DNA(const RNA&, const RNA&);
// przeciazony cout
    friend std::ostream& operator<<(std::ostream&, const DNA&);
};