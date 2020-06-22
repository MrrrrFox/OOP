/* Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał
   a wynik jego działania był taki sam, jak podany na końcu tego pliku.

   Bazując na zadaniu z poprzednich zajęć (kompletnym i działającym)
   wprowadź następujące modyfikacje:
   * zamień strukturę Element na klasę i dodaj 
     - konstruktor bezparametrowy 
     - konstruktor z parametrem int, ustawiający wartość _value
     - konstruktor kopiujący element 
       (wykorzystaj oba konstruktory parametrowe w metodach klasy IntLinkedList)
     - destruktor

  * jeśli potrafisz, ustaw w klasie Element pola value i next na prywatne 
    i zadeklaruj przyjaźń z klasą IntLinkedList

   * dodaj do klasy IntLinkedList: 
     - pole prywatne _name (obok _head i _tail)
       ustawione w konstruktorze bezparametrowym na "LX"
     - konstruktor parametrowy ustawiający nazwę listy zgodnie z podanym argumentem
     - zmodyfikuj destruktor, aby wypisywał nazwę listy
     - metodę append - dodającą na koniec listy cały Element 
     - metodę removeLast - usuwającą ostatni element z listy
     - zmodyfikuj metodę addSorted, dodając argument bool uniq domyślnie 
       ustawiony na false, który w przypadku uniq=true 
       zapobiega dodawaniu do listy takich samych elementów 
     - dodaj metodę addSorted, dodającą obiekt w porządku rosnącym, analogicznie 
       zawierający argument uniq 
	 - dodaj metodę addSorted, dodającą  w porządku rosnącym do listy  
	   listę podaną jako argument funkcji
	 - dodaj metodę append, dodającą do listy listę podaną jako argument funkcji

  * dodaj funkcję zaprzyjaźnioną print, drukującą listę 
       (modyfikując metodę print)

 * Pliku main.cpp, NIE WOLNO modyfikować bez zgody prowadzącego.
 * Proszę pamietać o dokumentacji kodu.
 * Skonfiguruj plik konfiguracyjny cmake albo napisz Makefile tak, aby:
   - plikiem wynikowym był main
   - program kompilował się z flagami -Wall -g - pedantic.
   - były zdefiniowane cele użytkownika run, clean, check oraz all (main+run)

 * Kody źródłowe powinny znajdować się w katalogu nazwisko_lab8 
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
    IntLinkedList list1("L1");
    cout << "size: " << list1.size() << endl;
    cout << (list1.isEmpty() ? "Lista pusta" : "Lista nie jest pusta") << endl;
    list1.print();
    list1.removeFirst();
    cout << "   --- test append ---" << endl;
    Element a(3),b(5),c(-2);
    list1.append(a);
    list1.append(b);
    list1.append(c);
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

    cout << "   --- test remove first last ---" << endl;
    list1.removeFirst();
    list1.removeLast();
    print(list1);
    cout << "   --- test remove 0,5,-2,-5 ---" << endl;
    list1.removeValue(0);
    list1.removeValue(5);
    list1.removeValue(-2);
    list1.removeValue(-5);
    print(list1);
    cout << "size: " << list1.size() << endl;

    cout << "   --- test SortedList ---" << endl;
    IntLinkedList list2("L2");
    cout << "size: " << list2.size() << endl;
    cout << (list2.isEmpty() ? "Lista pusta" : "Lista nie jest pusta") << endl;
    list2.print();
    Element x(3),y(4),z(-2);
    list2.addSorted(x);
    list2.addSorted(x,true);
    list2.addSorted(1);
    list2.addSorted(z);
    list2.addSorted(y);
    list2.addSorted(4, true);
    list2.addSorted(1, true);
    list2.addSorted(-2);
    list2.print();
    cout << "size: " << list2.size() << endl;

    cout << "   --- test list3.addSorted(list1) ---" << endl;
    IntLinkedList list3("L3");
    list3.addSorted(list1);
    print(list3);
    cout << "   --- test list3.append(list2) ---" << endl;
    list3.append(list2);
    print(list3);
    cout << "   --- test list4.addSorted(list3) ---" << endl;
    IntLinkedList list4("L4"), list5;
    list4.addSorted(list3);
    print(list4);
    list5.addSorted(list3);
    print(list5);
    return 0;
}

/* Oczekiwany wynik: ./main
size: 0
Lista pusta
L1=[]
   --- test append 3,5,-2,8,7,0 ---
L1=[3, 5, -2, 8, 7, 0]
size: 6
-5: Element nieznaleziony
L1=[3, 5, -2, 8, 7, 0, -5]
-5: Element znaleziony
Lista nie jest pusta
   --- test remove first ---
L1=[5, -2, 8, 7, 0]
   --- test remove 0,5,-2,-5 ---
L1=[8, 7]
Size: 2
   --- test SortedList ---
Size: 0
Lista pusta
L2=[]
L2=[-2, -2, 1, 3, 4]
Size: 5
   --- test list3.addSorted(list1) ---
L3=[7, 8]
   --- test list3.append(list2) ---
L3=[7, 8, -2, -2, 1, 3, 4]
   --- test list4.addSorted(list3) ---
L4=[-2, 1, 3, 4, 7, 8]
LX=[-2, 1, 3, 4, 7, 8]
Destruktor LX: Lista pusta
Destruktor L4: Lista pusta
Destruktor L3: Lista pusta
Destruktor L2: Lista pusta
Destruktor L1: Lista pusta
*/
