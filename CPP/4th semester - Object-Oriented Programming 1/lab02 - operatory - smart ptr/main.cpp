/* Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał
   a wynik jego działania był taki sam, jak podany na końcu tego pliku.

   Celem zadania jest napisanie klasy sprytnego wskaźnika, 
   w którym liczona jest ilość referencji do tego wskaźnika. 
   Podczas konstruowania takiego sprytnego wskaźnika przekazujemy do niego
   wskaźnik do obiektu stworzonego operatorem new i startujemy licznik.
   Każdy następny sprytny wskaźnik pokazujący na ten obiekt (stworzony 
   z innego sprytnego wskaźnika) zwiększa ten licznik, a każde zniszczenie 
   sprytnego wskaźnika (np przez wyjście poza zakres) zmniejsza licznik. 
   Gdy licznik dochodzi do zera, należy zwolnić pamięć. 
  
   Kluczową sprawą jest zapewnienie współdzielenia licznika pomiędzy różnymi
   instancjami klasy sprytnego licznika (static nie jest rozwiązaniem).
 
   Sprytny wskaźnik ma obsługiwać trywialną klasę TestClass, 
   która posiada jedynie konstruktory i destruktory 
   wypisujące informacje o swoim wywołaniu (patrz oczekiwany wynik)
   oraz metodę nazwa().
  
 * Można korzystać z biblioteki standardowej std::string.
   Zamiana liczby na std::string: std::to_string(int).
  
* Proszę pamiętać o dokumentacji kodu.
 * Napisz Makefile albo skonfiguruj plik konfiguracyjny cmake tak, aby:
   - plikiem wynikowym był main
   - program kompilował się z flagami -Wall - pedantic.
   - były zdefiniowane cele użytkownika run, clean, check oraz all (main+run)

 * Kody źródłowe powinny znajdować się w katalogu nazwisko_lab2 
 * do którego nikt oprócz właściciela nie ma praw dostępu.
 * UWAGA! Wysyłamy spakowany katalog, nie oddzielne pliki!!!!!!
 * Wcześniej KASUJEMY niepotrzebne pliki.
 
 * Podczas wykonywania zadania nie wolno korzystać z internetu, notatek,
 * ani żadnych innych materiałów. 
 */
 
#include <iostream>

#include "SmartPointer.h"
#include "TestClass.h"

void print(const TestClass& t) {
    std::cout <<"..... TestClass nazwa: " << t.name() << std::endl;
}

int main() {
  using namespace std;
  {
    TestClass a("test_A0");
    print(a);
  }
  cout << endl;
  SmartPointer smart1(new TestClass("test_A1"));
  SmartPointer smart2(new TestClass("test_A2"));
  smart2 = smart1; // kasujemy  A2 bo zaden wskaznik na niego nie wskazuje
  {
    SmartPointer smart3 = smart2; // juz trzy wskazniki pokazuja na obiekt A1
    print(*smart3);
    std::cout << "-- " << smart3->name() << std::endl;
  }
  std::cout << "== " << smart2->name() << std::endl;
}
/* oczekiwany wynik
.. Konstruuje TestClass test_A0
..... TestClass nazwa: test_A0
.. Usuwam  TestClass test_A0

.. Konstruuje TestClass test_A1
.. Konstruuje TestClass test_A2
.. Usuwam  TestClassA test_A2 
..... TestClass nazwa: test_A1
-- test_A1
== test_A1
.. Usuwam  TestClassA test_A1

 */
