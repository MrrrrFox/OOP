#include "FileSystemElement.h"

// konstruktor - ustawia nazwe skladnika
FileSystemElement::FileSystemElement(std::string name)
{
    _nazwa = name;
}

// getter nazwy
std::string FileSystemElement::get_nazwa() const
{
    return _nazwa;
}

// przeciazony cout
std::ostream & operator<<(std::ostream & out, const FileSystemElement & file_system_elem)
{
    return file_system_elem.print(out, 0);
}