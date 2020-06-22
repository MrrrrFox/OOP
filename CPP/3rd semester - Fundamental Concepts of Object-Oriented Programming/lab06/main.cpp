/* Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał
 * a wynik jego działania był taki sam, jak podany na końcu tego pliku.

 * Zdefiniuj klasę IntArrayList - listę zaimplementowaną na tablicy statycznej,
 * której maksymalny rozmiar jest przechowywany w stałej globalnej MaxTab,
 * zawierającą pola: tab[MaxTab] - tablicę statyczną oraz size - aktualny rozmiar zajętości
 * UWAGA!!! USTAW MaxTab na 10, bo w przeciwnym razie program nie będzie poprawnie działał.
 
 * Zdefiniuj konstruktor i destruktor (ustawiający size na 0) oraz metody:
  * print - drukującą tablicę w postaci [w1,w2,w3]
  * find - zwracającą indeks pierwszego znalezionego elementu o podanej wartości
         - jeśli nie znaleziono, zwraca wartość ujemną
  * printFind - obsługującą wyświetlanie funkcji find
  * add - 4 wersje funkcji:
   - wstawiająca element na koniec, jeśli jest miejsce
   - wstawiająca na koniec tablicę elementów podaną jako parametr (wskaźnik tablicy + liczba elementów)
     jeśli nie da się dodać całego wektora, nic nie dodaje
   - wstawiająca element pod określony indeks, przesuwający resztę elementów w prawo
   - wstawiająca element zachowując porządek rosnący (parametr typu bool ma wartość true)
 * remove - 2 wersje:
   - usuwającą element pod wskazanym indeksem, przesuwając wszystkie elementy w lewo
   - usuwającą fragment tablicy od wskazanego indeksu podaną liczbę elementów.

 * Pliku main.cpp, nie wolno modyfikować.
 * Skonfiguruj plik konfiguracyjny cmake albo napisz Makefile tak, aby:
   - plikiem wynikowym był main
   - program kompilował się z flagami -Wall -g - pedantic.
   - były zdefiniowane cele użytkownika run i clean oraz all (main+run)

 * Kody źródłowe powinny znajdować się w katalogu nazwisko_lab6 
 * do którego nikt oprócz właściciela nie ma praw dostępu.
 * UWAGA! Wysyłamy spakowany katalog, nie oddzielne pliki!!!!!!
 * Wcześniej kasujemy niepotrzebne pliki.
 
 * Podczas wykonywania zadania nie wolno korzystać z internetu, notatek,
 * ani żadnych innych materiałów. 
*/

#include <iostream>
#include "intArrayList.h"

int main() {
    IntArrayList list1, list2;
    std::cout << "************* LIST1 *************\n";
    std::cout << "------- ADD 7,-2,37 -------\n";
    list1.add(7);
    list1.add(-2);
    list1.add(37);
    list1.print(); 
    int tab[]={3,6,9};
    std::cout << "------- ADD [3,6,9] -------\n";
    list1.add(tab,3);
    list1.add(tab,3);
    list1.add(tab,3);
    list1.print(); 
    list1.printFind(37);
    std::cout << "------- REMOVE IND=2 -------\n";
    list1.remove(2);
    list1.print(); 
    list1.printFind(37);
    std::cout << "------- ADD -50 IND=2 -------\n";
    list1.add(2, -50);
    list1.print(); 
    std::cout << "------- REMOVE IND=2 n=3 -------\n";
    list1.remove(2,3);
    list1.print(); 
    std::cout << "------- ADD [3,6,9] -------\n";
    list1.add(tab,3);
    list1.print();
    std::cout << "\n************* LIST2 *************\n";
    std::cout << "------- ADD SORT -2,-4,10,5 -------\n";   
	list2.add(-2);
    list2.add(-4, true);
    list2.add(10, true);
    list2.add(5,true);
    list2.print();
    std::cout << "------- ADD SORT 7,0,3,2 -------\n";
    list2.add(7,true);
    list2.add(0,true);
    list2.add(3,true);
    list2.add(2,true);
    list2.print();
    std::cout << "------- ADD SORT -8,6,13 -------\n";
    list2.add(-8,true);
    list2.add(6,true);
    list2.add(13,true);
    list2.print();
    return 0;
}

/* Wynik działania programu (make run lub ./main)
************* LIST1 *************
------- ADD 7,-2,37 -------
[7, -2, 37]
------- ADD [3,6,9] -------
[7, -2, 37, 3, 6, 9, 3, 6, 9]
Wartość=37  Indeks=2
------- REMOVE IND=2 -------
[7, -2, 3, 6, 9, 3, 6, 9]
Wartość=37  Element nieznaleziony
------- ADD -50 IND=2 -------
[7, -2, -50, 3, 6, 9, 3, 6, 9]
------- REMOVE IND=2 n=3 -------
[7, -2, 9, 3, 6, 9]
------- ADD [3,6,9] -------
[7, -2, 9, 3, 6, 9, 3, 6, 9]

************* LIST2 *************
------- ADD SORT -2,-4,10,5 -------
[-4, -2, 5, 10]
------- ADD SORT 7,0,3,2 -------
[-4, -2, 0, 2, 3, 5, 7, 10]
------- ADD SORT -8,6,13 -------
[-8, -4, -2, 0, 2, 3, 5, 6, 7, 10]

*/
