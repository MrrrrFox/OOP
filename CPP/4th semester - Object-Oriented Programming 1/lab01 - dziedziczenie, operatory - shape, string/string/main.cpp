/* Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał
   a wynik jego działania był taki sam, jak podany na końcu tego pliku.

   Proszę zdefiniować klasę MyString, która odpowiada klasie std::string.
   Należy zdefiniować wszystkie potrzebne kondtruktory alokujące pamięć
   oraz destruktor ją zwalniający.
   Należy przeciążyć podstawowe operatory do obsługi łancucha znaków: 
   ==, =, +, *, << w różnych konfiguracjach parametrycznych.
   Dodatkowo należy też zdefiniować funkcję print (dodaje na końcu "\n"),
   str (zwraca wskaźnik do napisu) oraz operator [], który pobiera element napisu.

   !!! UWAGA !!! 
   * Zewnętrzne funkcje operatorowe proszę zdefiniować jako funkcje niezaprzyjaźnione
     jedynie cout można zaprzyjaźnić.
   * Zadanie wykonujemy na tablicy znaków, nie wolno korzystać z std::string.
   * Przy wykonaniu tego zadania *** NIE WOLNO *** korzystać z kodów wcześniejszych zadań.
   * Pliku main.cpp, NIE WOLNO modyfikować bez zgody prowadzącego. \
     Zaliczone zadanie powinno się kompilować bez żadnych zakomentowanych linii.
   * Kody źródłowe powinny znajdować się w katalogu nazwisko_poprawa.
     Wcześniej kasujemy niepotrzebne pliki.
 
 * Proszę pamietać o dokumentacji kodu.
 * Skonfiguruj plik konfiguracyjny cmake albo napisz Makefile tak, aby:
   - plikiem wynikowym był main
   - program kompilował się z flagami -Wall -g - pedantic.
   - były zdefiniowane cele użytkownika run, clean, check oraz all (main+run)
 
 * Podczas wykonywania zadania nie wolno korzystać z internetu, notatek,
 * ani żadnych innych materiałów, w tym również swoich zadań. 

*/

#include "myString.h"
#include <iostream>

using namespace std;

int main() {
	MyString s0("Powodzenia na Kolokwium");  
	MyString s1("Powodzenia na kolokwium");
	const MyString s2(s1);  

	s0.print(); s1.print(); s2.print(); 
	cout << "\n*** Porownywanie napisow ***" << endl;
	cout << "Napisy s0 i s1 " << (s0 == s1 ? "sa identyczne" :"nie sa identyczne") <<endl;
	cout << "Napisy s1 i s2 " << (s1 == s2 ? "sa identyczne" :"nie sa identyczne") <<endl;
	cout << "Napisy s0 i s1 " << (s2 == s1 ? "sa identyczne" :"nie sa identyczne") <<endl;
	cout << "Napisy s2 i \"Powodzenia na kolokwium\" " << (s2 == "Powodzenia na kolokwium" ? "sa identyczne" :"nie sa identyczne") <<endl;
	
	cout << "\n*** Dodawanie i przypisywanie napisow ***" << endl;
	cout << s1 << endl; //s1.print();
	s1 = "Samych sukcesow!!!";
	cout << s1 << endl;
	MyString s3 = s2 + " tu i teraz...";
	cout << s3 << endl; //s3.print();
	MyString s4 = s2 + ": " + s1 + " - " + s2 + '!'; // uwaga na typ char
	cout << s4 << endl; //s4.print();
	
	cout << "\n*** Powielanie napisow ***" << endl;
	/*MyString s5 = 2 * MyString(":-)");
	MyString s6 = ":-D " + (const MyString&)s5*4;
	s6.print();
	*/
	MyString s6 = s1;
	cout << s6 << endl;
	cout << "Siodmy znak: " << s6[7] << endl;;
// Zadanie dodatkowe (do odkomentowania po zrobieniu)
//	s6[7] = 'S';
//	cout << s6 << endl;
}

/* Oczekiwany wynik ./main
Powodzenia na Kolokwium
Powodzenia na kolokwium
Powodzenia na kolokwium

*** Porownywanie napisow ***
Napisy s0 i s1 nie sa identyczne
Napisy s1 i s2 sa identyczne
Napisy s0 i s1 sa identyczne
Napisy s2 i "Powodzenia na kolokwium" sa identyczne

*** Dodawanie i przypisywanie napisow ***
Powodzenia na kolokwium
Samych sukcesow!!!
Powodzenia na kolokwium tu i teraz...
Powodzenia na kolokwium. Samych sukcesow!!! - Powodzenia na kolokwium!

*** Powielanie napisow ***
:-D :-):-):-):-):-):-):-):-)
Samych sukcesow!!!
*/
