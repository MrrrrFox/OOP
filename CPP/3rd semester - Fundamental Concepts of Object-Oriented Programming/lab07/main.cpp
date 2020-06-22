/* Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał
 * a wynik jego działania był taki sam, jak podany na końcu tego pliku.

 * Struktura (albo klasa) Element reprezentuje element listy jednokierunkowej
   i posiada pole value typu int oraz wskaźnik na następny element
 * Klasa IntLinkedList zawiera prywatne pola: 
   wskaźniki na head i tail typu struktury/klasy Element
   oraz publiczne metody:
  * konstruktor ustawiający wskaźniki na NULL
  * destruktor usuwający wszystkie elementy listy i kontrolnie wywołujący isEmpty()
  * metody pomocnicze size i isEmpty
  * print - drukuje listę w postaci [w1, w2, w3]
  * append - wstawia wartość na koniec listy
  * addSorted - wstawia wartość w porządku rosnącym
  * removeFirst - usuwa pierwszy element z listy
  * removeValue - usuwa pierwszy znaleziony element o wartości value
  * contains - szuka elementu na liście i zwraca wartość typu bool


 * Pliku main.cpp, NIE WOLNO modyfikować bez zgody prowadzącego.
 * Proszę pamietać o dokumentacji kodu.
 * Skonfiguruj plik konfiguracyjny cmake albo napisz Makefile tak, aby:
   - plikiem wynikowym był main
   - program kompilował się z flagami -Wall -g - pedantic.
   - były zdefiniowane cele użytkownika run, clean, check oraz all (main+run)

 * Kody źródłowe powinny znajdować się w katalogu nazwisko_lab7 
 * do którego nikt oprócz właściciela nie ma praw dostępu.
 * UWAGA! Wysyłamy spakowany katalog, nie oddzielne pliki!!!!!!
 * Wcześniej kasujemy niepotrzebne pliki.
 
 * Podczas wykonywania zadania nie wolno korzystać z internetu, notatek,
 * ani żadnych innych materiałów. 
*/

#include "intLinkedList.h"
#include <iostream>

using namespace std;

int main() {
    IntLinkedList list1;
    cout << "size: " << list1.size() << endl;
    cout << (list1.isEmpty() ? "Lista pusta" : "Lista nie jest pusta") << endl;
    list1.print();
    list1.removeFirst();
    cout << "   --- test append 3,5,-2,8,7,0 ---" << endl;
    list1.append(3);
    list1.append(5);
    list1.append(-2);
    list1.append(8);
    list1.append(7);
    list1.append(0);
    list1.print();
    cout << "size: " << list1.size() << endl;
    cout << (list1.contains(-5) ? "-5: Element znaleziony" : "-5: Element nieznaleziony")<< endl;
    list1.append(-5);
    list1.print();
    cout << (list1.contains(-5) ? "-5: Element znaleziony" : "-5: Element nieznaleziony")<< endl;
    cout << (list1.isEmpty() ? "Lista pusta" : "Lista nie jest pusta") << endl;

    cout << "   --- test remove first 0,5,-2,-5 ---" << endl;
    list1.removeFirst();
    list1.print();
    list1.removeValue(0);
    list1.removeValue(5);
    list1.removeValue(-2);
    list1.removeValue(-5);
    list1.print();
    cout << "size: " << list1.size() << endl;

    cout << "   --- test SortedList ---" << endl;
    IntLinkedList list2;
    cout << "size: " << list2.size() << endl;
    cout << (list2.isEmpty() ? "Lista pusta" : "Lista nie jest pusta") << endl;
    list2.print();
    list2.addSorted(3);
    list2.addSorted(1);
    list2.addSorted(-1);
    list2.addSorted(4);
    list2.print();
    list2.removeFirst();
    list2.print();
    cout << "size: " << list2.size() << endl;
    return 0;
}

/* Oczekiwany wynik: ./main
size: 0
Lista pusta
[]
   --- test append 3,5,-2,8,7,0 ---
[3, 5, -2, 8, 7, 0]
size: 6
-5: Element nieznaleziony
[3, 5, -2, 8, 7, 0, -5]
-5: Element znaleziony
Lista nie jest pusta
   --- test remove first 0,5,-2,-5 ---
[5, -2, 8, 7, 0, -5]
[8, 7]
size: 2
   --- test SortedList ---
size: 0
Lista pusta
[]
[-1, 1, 3, 4]
[1, 3, 4]
size: 3
Destruktor: Lista pusta
Destruktor: Lista pusta
*/
