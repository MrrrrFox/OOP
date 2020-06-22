#pragma once

// *** Nie modyfikować tego pliku ***

#include <vector>
#include <ostream>

//-------------------------------------------------------------
// Implementacja nukleotydów
enum Nukleotyp { 
	A='A', // adeine 
	G='G', // guanine
	C='C', // citozine
	T='T', // thymine
	U='U'  // uracil
};

//-------------------------------------------------------------
// Implementacja sekwencji nukleotydów danych typem Nukleotyp
class RNA {

	// operator drukujący sekwencję genów na wyjście ostream.
	friend std::ostream& operator<< (std::ostream &, const RNA &);

 public:	
	// zwraca sekwencję genów (nukleotydów) w postaci wektora
	std::vector <Nukleotyp> get_RNA() const { return chain; }
	RNA() = default;

    // konstruktor inicjalizujący łańcuch RNA
	RNA (const std::vector< Nukleotyp > seq) : chain(seq) { }
	
	// mutuje łańcuch RNA poprzez cykliczne przesunięcie w lewo
	RNA & mute ();

 protected:
	// ciąg nukleotydów zaimplementowany jako wektor	
	std::vector< Nukleotyp > chain;

};