#pragma once
#include "map.h"

// czy podany argument jest w slowniku
std::string print(bool isIn)
{
    return isIn==true ? "Znaleziono" : "Nie znaleziono";
}

// przeciazenie operatora * (string-int)
std::string operator*(const std::string str, int ile)
{
    std::string tmp = "";
    for(int i=0; i<ile; ++i) tmp += str;
    return tmp;
}

// przeciazenie operatora * (int-string)
std::string operator*(int ile, const std::string str)
{
    std::string tmp = "";
    for(int i=0; i<ile; ++i) tmp += str;
    return tmp;
}