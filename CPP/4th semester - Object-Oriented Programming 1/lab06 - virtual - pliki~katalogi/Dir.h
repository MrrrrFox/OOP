# pragma once
#include "FileSystemElement.h"

// klasa reprezentujaca katalog
class Dir : public FileSystemElement
{
private:
// tablica plikow w katalogu i rozmiar
    FileSystemElement * _pliki[20];
    int _rozm = 0;
public:
// konstruktor ustawiajacy nazwe folderu i destruktor
    Dir(std::string);
    ~Dir();
// funkcja zwracajaca plik o podanej nazwie
    FileSystemElement * get(std::string) const;
// przeciazone operatory dodawania i usuwania skladnika systemu
    void operator+=(FileSystemElement *);
    void operator-=(std::string);
// funkcje kopiujace - folder i do folderu 
    FileSystemElement * copy();
    void copy(FileSystemElement *);
// wypisywanie folderu
    std::ostream & print(std::ostream &, int) const;
// przeciazenie cout
    friend std::ostream & operator<<(std::ostream &, const Dir &);
};