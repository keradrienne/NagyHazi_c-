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
	String faj;
	String nev;
	Datum szul;
public:
	///Default konstruktor
	Allat() {}

	/// Konstruktor beállítja az attribútumokat
	/// @param faj - faj megnevezése
	/// @param nev - név megadása
	/// @param szul - születési év megadása
	Allat(const char* faj, const char* nev, const Datum& szul) :szul(szul) {
		if (String(faj) == String() || String(nev) == String()) throw "Hibas bemenet";
		else {
			this->faj = faj;
			this->nev = nev;
		}
	}

	/// Faj lekérdezése
	/// @return - faj
	String getFaj() const { return faj; }

	/// Faj beállítása
	/// @param p - karaktersorozat
	void setFaj(const char* p) {
		if (String(p) != String())
			this->faj = p;
		else throw "Rossz bemenet";
	}

	/// Név lekérdezése
	/// @return - név
	String getNev() const { return nev; }

	/// Nev beállítása
	/// @param p - karaktersorozat
	void setNev(const char* p) {
		if (String(p) != String())
			this->nev = p;
		else throw "Rossz bemenet";
	}

	/// Születési dátum lekérdezése
	/// @return - dátum
	Datum getSzul() const { return szul; }

	/// Szuletési dátum beállítása
	/// @param d - dátum referencia
	void setSzul(Datum& d) { this->szul = d; }

	/// Virtuális destruktor
	virtual ~Allat() {}
};

#endif // ALLAT_H