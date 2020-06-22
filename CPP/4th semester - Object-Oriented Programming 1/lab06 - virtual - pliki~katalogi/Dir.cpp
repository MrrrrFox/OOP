#include <iostream>
#include "Dir.h"

// konstruktor na podstawie klasy bazowej
Dir::Dir(std::string dir_name) : FileSystemElement(dir_name) {}

// destruktor - usuwa pliki ktore sie w nim znajduja
Dir::~Dir()
{
    for(int i = 0; i<_rozm; ++i)
    {
        delete _pliki[i];
    }
}

// funkcja zwracajaca plik w katalogu o podanej nazwie
FileSystemElement * Dir::get(std::string name_to_find) const
{
    for(int i = 0; i<_rozm; ++i)
    {
        if(_pliki[i]->get_nazwa() == name_to_find)
        {
            return _pliki[i];
        }
    }
    return nullptr;
}

// dodanie skladnika systemu do katalogu
void Dir::operator+=(FileSystemElement* file_to_add)
{
    _pliki[_rozm++] = file_to_add;
}

// usuniecie skladnika systemu z katalogu (i przepiecie pozostalych w tablicy)
void Dir::operator-=(std::string file_to_remove)
{
    int flaga = 0;
    for(int i = 0; i<_rozm; ++i)
    {
        if(flaga == 1)
        {
            _pliki[i-1]=_pliki[i];
        }
        if(_pliki[i]->get_nazwa() == file_to_remove && flaga == 0)
        {
            delete _pliki[i];
            flaga = 1;
        }
    }
    --_rozm;
}

// funkcja kopiujaca podany składnik do aktualnego folderu
void Dir::copy(FileSystemElement * to_copy)
{
    _pliki[_rozm++] = to_copy->copy();
}

// funkcja kopiujaca aktualny folder
FileSystemElement * Dir::copy()
{
    Dir * new_dir = new Dir(get_nazwa());
    for(int i = 0; i<_rozm; ++i)
    {
        *new_dir += _pliki[i]->copy();
    }
    
    return new_dir;
}

// wypisanie zawartosci katalogu
std::ostream & Dir::print(std::ostream & out, int how_many) const
{
    for(int i = 0; i<how_many; ++i)
    {
        out << "  ";
    }
    
    out << get_nazwa() << std::endl;
    for(int i = 0; i<_rozm; ++i)
    {
        _pliki[i]->print(out, how_many+1);
    }
    return out;
}

// przeciazony cout
std::ostream & operator<<(std::ostream & out, const Dir & dir)
{
    return dir.print(out,0);
}