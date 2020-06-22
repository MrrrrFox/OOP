#pragma once
#include "FileSystemElement.h"

// klasa reprezentujaca plik
class File : public FileSystemElement
{
public:
// konstrukor ustawiajacy nazwe pliku i destruktor
    File(std::string);
    ~File() = default;
// funkcja kopiujaca plik
    FileSystemElement * copy();
// wypisywanie nazwy pliku
    std::ostream & print(std::ostream &, int) const;
// przeciazenie cout
    friend std::ostream& operator<<(std::ostream &, const File &);
};