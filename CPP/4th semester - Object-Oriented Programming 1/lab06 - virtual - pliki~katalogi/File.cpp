#include "File.h"

// konstruktor na podstawie klasy bazowej
File::File(std::string file_name) : FileSystemElement(file_name) {}

// funkcja kopiujaca plik
FileSystemElement * File::copy()
{
    return new File(_nazwa);
}

// funkcja wypisuja spacje (zaleznie od zagniezdzenia pliku) i nazwe pliku
std::ostream & File::print(std::ostream & out, int how_many) const
{
    for(int i = 0; i<how_many; ++i)
    {
        out << "  ";
    }
    out<<_nazwa << std::endl;
    return out;
}

// przeciazony cout - wystarczy skorzystac z printa
std::ostream& operator<<(std::ostream & out, const File & file)
{
    return file.print(out,0);
}