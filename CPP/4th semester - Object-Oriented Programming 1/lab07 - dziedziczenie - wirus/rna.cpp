#include "rna.h"

// przeciazony operator cout
std::ostream& operator<<(std::ostream& out, const RNA& myRNA)
{
    for(auto& data : myRNA.get_RNA())
    {
        switch(data)
        {
            case A:
                out << "A ";
                break;
            case G:
                out << "G ";
                break;
            case C:
                out << "C ";
                break;
            case T:
                out << "T ";
                break;
            case U:
                out << "U ";
                break;
        }
    }
    out << std::endl;
    return out;
}

// funkcja mutujaca - cykliczne przesuniecie nukleotydow w lewo
RNA & RNA::mute()
{
    Nukleotyp first = chain.front();
    int rozmiar = chain.size();
    for(int i = 0; i<rozmiar-1; ++i)
    {
        chain[i] = chain[i+1];
    }
    chain[rozmiar-1] = first;
    return *this;
}