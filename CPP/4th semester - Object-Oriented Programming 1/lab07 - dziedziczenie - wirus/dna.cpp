#include "dna.h"

// konstruktor - ustawia podane lancuchy
DNA::DNA(const RNA& chain1, const RNA& chain2)
{
    _lancuchy[0] = chain1;
    _lancuchy[1] = chain2;
}

// przeciazony cout
std::ostream& operator<<(std::ostream& out, const DNA& myDNA)
{
    out << myDNA._lancuchy[0];
    
    int rozmiar = myDNA._lancuchy[0].get_RNA().size();
    for(int i = 0; i<rozmiar; ++i)
    {
        out << "| ";
    }
    out << std::endl;
    
    out << myDNA._lancuchy[1];
    
    return out;
}