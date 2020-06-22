/* Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał
   a wynik jego działania był taki sam jak podany na końcu tego pliku.

   Proszę zdefiniować klasy reprezentujące żelazka marki Philips i Tefal. 
   Każde żelazko ma nazwę, cenę i aktualną temperaturę oraz maksymalny zakres temperatur 
   (temperatura to liczba całkowita od 0 do 9, przy czym każdy model żelazka może mieć inny zakres - mniejszy).
   Tefal ma zakres do 7, natomiast Philips ma zakres temperatur do 5.

   Proszę zdefiniować również klasy reprezentujace różne rodzaje ubrań. 
   Każde ubranie:
   * ma swoją nazwę i cenę oraz maksymalny zakres temperatury do prasowania, 
     ustawiony domyślnie na 9,
   * może być pogniecione lub wyprasowane,
   * można prasować lub gnieść.
   Dodatkowo koszule mogą mieć pogniecione lub wyprasowane rękawy, 
   a spodnie mogą mieć pogniecione lub wyprasowane kanty na nogawkach. 

   UWAGA!
   * Koszula nie ma kantów na nogawkach, a spodnie nie mają rękawów.
   * Ubrania wyprasowanego nie prasujemy ponownie.
   * Stan i prasowanie rękawów lub kantów na nogawkach nie ma nic wspólnego z ogólnym stanem lub prasowaniem.
   * Nowe ubranie zawsze wymaga prasowania.
   * Nie należy definiować każdej klasy w osobnym pliku, raczej je pogrupować.
   * Proszę jak najoptymalniej zdefiniować strukturę klas, wyłaniając części wspólne.

  W zadaniu zaleca się korzystanie z elementów bilbioteki standardowej (std::string)
*/

#include "main.h"

int main ()
{
  const float cenaZelazka = 135;
  ZelazkoPhilips zelazko1 (cenaZelazka);
  zelazko1.UstawTemperature (6);
  zelazko1.WypiszWlasciwosci(); 
  zelazko1.UstawTemperature (5);
  zelazko1.WypiszWlasciwosci();    // Philips cena: 135. temperatura: 5

  const float cenaKoszuli = 200;
  KoszulaBawelniana koszula1 (cenaKoszuli);
  koszula1.WypiszWlasciwosci();    // Koszula bawelniana cena: 200. Stan ubrania: pogniecione. Stan rekawow: pogniecione.
  koszula1.Prasuj(zelazko1);       // Prasuje Koszula bawelniana zelazkiem o temp. 5.
  koszula1.WypiszWlasciwosci();	   // Koszula bawelniana cena: 200. Stan ubrania: wyprasowane. Stan rekawow: pogniecione.

  KoszulaJedwabna koszula2 (300); 
  koszula2.WypiszWlasciwosci();    // Koszula jedwabna cena: 300. Stan ubrania: pogniecione. Stan rekawow: pogniecione.
  koszula2.PrasujRekawy(zelazko1); // Temperatura zelaska za wysoka.
  zelazko1.UstawTemperature (3);
  zelazko1.WypiszWlasciwosci();    // Philips cena: 135. temperatura: 3
  koszula2.PrasujRekawy(zelazko1); // Prasuje rekawy Koszula jedwabna zelazkiem o temp. 3.
  koszula2.WypiszWlasciwosci();	   // Koszula jedwabna cena: 300. Stan ubrania: pogniecione. Stan rekawow: wyprasowane.
  koszula2.PrasujRekawy(zelazko1); // Ubranie nie wymaga prasowania rekawow.

  SpodnieBawelniane spodnie1 (55);
  spodnie1.WypiszWlasciwosci();    // Spodnie bawelniane cena: 55. Stan ubrania: pogniecione. Stan nogawek: pogniecione.
  spodnie1.Prasuj(zelazko1);       // Prasuje Spodnie bawelniane zelazkiem o temp. 3.
  spodnie1.WypiszWlasciwosci();	   // Spodnie bawelniane cena: 55. Stan ubrania: wyprasowane. Stan nogawek: pogniecione.
  spodnie1.Prasuj(zelazko1);       // Ubranie nie wymaga prasowania.

  SpodnieJedwabne spodnie2 (234);
  spodnie2.WypiszWlasciwosci();     // Spodnie jedwabne cena: 234. Stan ubrania: pogniecione. Stan nogawek: pogniecione.
  spodnie2.PrasujNogawki(zelazko1); // Prasuje nogawki Spodnie jedwabne zelazkiem o temp.3
  spodnie2.WypiszWlasciwosci();		  // Spodnie jedwabne cena: 234. Stan ubrania: pogniecione. Stan nogawek: wyprasowane.
  spodnie2.PrasujNogawki(zelazko1); // Ubranie nie wymaga prasowania nogawek.

  Ubranie* koszUbran [4];
  koszUbran[0] = &koszula1;
  koszUbran[1] = &koszula2;
  koszUbran[2] = &spodnie1;
  koszUbran[3] = &spodnie2;

  std::cout<<"\n";
  std::cout<<"===== GNIECIEMY =====\n";
  Ubranie** koniecKosza = koszUbran + 4;
  for (Ubranie** ciuch = koszUbran; ciuch != koniecKosza; ++ciuch) {
    (*ciuch) -> Pogniec();
    (*ciuch) -> WypiszWlasciwosci();
    std::cout<<"\n";
  }
  std::cout<<"\n";

  ZelazkoTefal zelazko2 (333);
  zelazko2.UstawTemperature (7);
  zelazko2.WypiszWlasciwosci();    // Tefal cena: 333. temperatura: 7
  zelazko2.UstawTemperature (1);

  std::cout<<"\n";
  std::cout<<"===== PRASUJEMY =====\n";
  for (Ubranie** ciuch = koszUbran; ciuch != koniecKosza; ++ciuch) {
    (*ciuch) -> Prasuj(zelazko2);
    (*ciuch) -> WypiszWlasciwosci();
    std::cout<<"\n";
  }
  
  return 0;
}
/*
Ten model nie obsluguje takiego zakresu temperatur.
Philips cena: 135. temperatura: 0
Philips cena: 135. temperatura: 5
Koszula bawelniana cena: 200. Stan ubrania: pogniecione. Stan rekawow: pogniecione.
Prasuje Koszula bawelniana zelazkiem o temp. 5.
Koszula bawelniana cena: 200. Stan ubrania: wyprasowane. Stan rekawow: pogniecione.
Koszula jedwabna cena: 300. Stan ubrania: pogniecione. Stan rekawow: pogniecione.
Zelazko za gorace.
Philips cena: 135. temperatura: 3
Prasuje rekawy Koszula jedwabna zelazkiem o temp.3.
Koszula jedwabna cena: 300. Stan ubrania: pogniecione. Stan rekawow: wyprasowane.
Ubranie nie wymaga prasowania rekawow.
Spodnie bawelniane cena: 55. Stan ubrania: pogniecione. Stan nogawek: pogniecione.
Prasuje Spodnie bawelniane zelazkiem o temp. 3.
Spodnie bawelniane cena: 55. Stan ubrania: wyprasowane. Stan nogawek: pogniecione.
Ubranie nie wymaga prasowania.
Spodnie jedwabne cena: 234. Stan ubrania: pogniecione. Stan nogawek: pogniecione.
Prasuje nogawki Spodnie jedwabne zelazkiem o temp.3
Spodnie jedwabne cena: 234. Stan ubrania: pogniecione. Stan nogawek: wyprasowane.
Ubranie nie wymaga prasowania nogawek.

===== GNIECIEMY =====
Koszula bawelniana cena: 200. Stan ubrania: pogniecione.
Koszula jedwabna cena: 300. Stan ubrania: pogniecione.
Spodnie bawelniane cena: 55. Stan ubrania: pogniecione.
Spodnie jedwabne cena: 234. Stan ubrania: pogniecione.

Tefal cena: 333. temperatura: 7

===== PRASUJEMY =====
Prasuje Koszula bawelniana zelazkiem o temp. 1.
Koszula bawelniana cena: 200. Stan ubrania: wyprasowane.
Prasuje Koszula jedwabna zelazkiem o temp. 1.
Koszula jedwabna cena: 300. Stan ubrania: wyprasowane.
Prasuje Spodnie bawelniane zelazkiem o temp. 1.
Spodnie bawelniane cena: 55. Stan ubrania: wyprasowane.
Prasuje Spodnie jedwabne zelazkiem o temp. 1.
Spodnie jedwabne cena: 234. Stan ubrania: wyprasowane.
*/
