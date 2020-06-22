/*
  Celem zadania jest napisanie hierarchii klas opisującej składniki systemu plików.
  Składnikami tymi sa katalog (klasa Dir) i plik (klasa File).
   
  UWAGA:
  * Aby zapewnić wypisywanie z wcięciami, klasy te powinny posiadać metodę print 
    z argumentem informującym, ile spacji potrzeba wypisać przed nazwą (w wyniku końcowym są dwie na każde wcięcie).
  * Podczas kopiowania przydana będzie polimorficzna metoda kopiująca.
  * Implementacja klasy Dir może być trywialna, np. zakładać że będzie ona posiadać maksymalnie 20 składników.

   Po uzyskaniu prawidłowego rezultatu działania należy całkowicie przerobić main.cpp tak, 
   aby zamiast tradycyjnych wskaźników użyć sprytnych. Niepowtarzalna okazja, aby zamieszać w main.cpp! 
   
   Po skończeniu zadania proszę o dodanie do niniejszego laboratorium napisanych przez siebie plików. 
   Proszę o skompilowanie i uruchomienie oceny programu w VPL.
 */
 
#include <iostream>
#include <memory>  //do sprytnych wskaźników
#include "FileSystemElement.h"
#include "Dir.h"
#include "File.h"

int main() 
{
    std::unique_ptr<Dir> top(new Dir("."));
    //Dir *top = new Dir("."); // teraz top tworzymy inaczej - sprytnym wskaznikiem (unique_ptr z memory)
    Dir *home = new Dir("home");
    *top += home; // dodajemy do kat TOP podkatalog
    Dir *ewa = new Dir("ewa");
    *home += ewa;
    Dir *adam = new Dir("adam");
    *home += adam;  
  
    std::cout << (const Dir&)*top << std::endl;

    *ewa += new Dir("Desk");
    *ewa += new File("auto1.jpg");
    *ewa += new File("auto2.jpg");
    *ewa += new File("auto3.jpg");
    Dir* wd = new Dir("work");
    *wd += new File("proj.descr");
    *wd += new File("proj.files.repo");
    *ewa += wd;
  
    std::cout << *top;
    std::cout << "--------------" << std::endl;
    std::cout << *(ewa->get("work"));

    adam->copy(ewa->get("work")); // trzeba koniecznie zrobic kopie

    *wd -= "proj.descr";
    *wd += new File("proj.txt"); // w kat: home/ewa/work pojawi sie nowy plik proj.txt, ktorego brak w kat home/adam/work 
  
    std::cout << "--------------" << std::endl;
    std::cout << *top;

    //delete top; // przy sprytnym wskazniku nie trzeba zwalniac
  
}
/* oczekiwany wynik 
.
  home
    ewa
    adam

.
  home
    ewa
      Desk
      auto1.jpg
      auto2.jpg
      auto3.jpg
      work
        proj.descr
        proj.files.repo
    adam
--------------
work
  proj.descr
  proj.files.repo
--------------
.
  home
    ewa
      Desk
      auto1.jpg
      auto2.jpg
      auto3.jpg
      work
        proj.files.repo
        proj.txt
    adam
      work
        proj.descr
        proj.files.repo

 */ 