#ifndef ALLAT_H
#define ALLAT_H
/*
* \file allat.h
* 
* Allat osztály deklarációja és függvényei
*/

#include "string.h"
#include "datum.h"
#include "memtrace.h"

class Allat {
protected:
	String faj;		///< faj
	String nev;		///< név
	Datum szul;		///< szuletés dátuma
public:
	///Default konstruktor
	Allat() {}

	/// Konstruktor beállítja az attribútumokat
	/// @param faj - faj megnevezése
	/// @param nev - név megadása
	/// @param szul - születési év megadása
	Allat(const char* faj, const char* nev, const Datum& szul) :szul(szul) {
		if(faj == "" || nev == "") throw "Hibas bemenet";
		else {
			this->faj = faj;
			this->nev = nev;
		}
	}

	/// Faj lekérdezése
	/// @return - faj
	String getFaj() const { return faj; }

	/// Név lekérdezése
	/// @return - név
	String getNev() const { return nev; }

	/// Születési dátum lekérdezése
	/// @return - dátum
	Datum getSzul() const { return szul; }

	/// Virtuális destruktor
	virtual ~Allat() {}
};

/// Globális inserter
/// @param os - output stream referencia
/// @param k - Tulaj referencia
/// @return output stream referencia
std::ostream& operator<<(std::ostream& os, Kutya& k);

#endif // ALLAT_H