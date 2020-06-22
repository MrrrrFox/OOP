/* 
  Tu mozesz dodać własny komentarz do zadania.
////////////////////////////////////////////////////////////////////////////////////////////////////
31.03.2020
  Zadanie bylo ciekawe, pokazywalo z czym je sie polimorfizm.
  
  Nadal jednak nie do konca rozumiem jak mozna to sprytnie wykorzystywac, poniewaz gdy cos mi nie wychodzilo,
  to po prostu tworzylem kolejna funkcje wirtualna w File (moze tak trzeba bylo, ale jeszcze nie czuje tego w pelni)
  
  Na szczescie program sie skompilowal z poprawnym outputem.
  
  Najwieksza trudnosc sprawila mi funkcja copy. Probowalem ja napisac na podstawie sizeof(File) ale nie bylo to dobre
  rozwiazanie. Koncowo zdecydowalem sie na dolozenie funkcji wirtualnych dzieki ktorym moglem rozroznic File i Dir.
  (jak wspomnialem wczesniej, nie mam pojecia czy to dobre rozwiazanie, ale zadzialalo). 
  
  Jak wrocilem na koniec do polecenia to doczytalem, ze copy moglo byc polimorficzne - nie wpadlem na to
  analizujac main (myslalem ze kopiujemy tylko do folderu), i chociaż mój sposob jest przekombinowany, 
  to jednak dziala.
  
  Niestety zabraklo mi juz czasu (i trochę sily oraz cierpliwosci...) na smart pointer. W ramach mozliwosci postaram sie to dokonczyc we
  wlasnym zakresie.
*/

#pragma once
#include <iostream>
#include <string>

// klasa odpowiedzialna za reprezentacja skladnikow systemu plikow
class FileSystemElement
{
protected:
    std::string _nazwa;
public:
// konstruktor i wirtualny destruktor
    FileSystemElement(std::string);
    virtual ~FileSystemElement() = default;
// getter nazwy
    std::string get_nazwa() const;
// wirtualna funkcja kopiujaca
    virtual FileSystemElement * copy() = 0;
    
// wirtualna funkcja wypisujaca skladnik systemu
    virtual std::ostream& print(std::ostream &, int) const = 0;
// przeciazony cout
    friend std::ostream& operator<<(std::ostream &, const FileSystemElement &);
};

