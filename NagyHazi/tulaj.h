#ifndef TULAJ_H
#define TULAJ_H
/*
* \file tualj.h
*
* Tulaj osztály deklarációja és függvényei
*/

#include "string.h"
#include "memtrace.h"

class Tulaj {
private:
	String tNev;		///< név
	String cim;		///< cím
	String tel;		///< telefonszám
public:
	///Default konstruktor
	Tulaj() {}

	/// Konstruktor beállítja az attribútumokat
	/// @param nev - név megadása
	/// @param cim - cím megadása
	/// @param tel - telefonszám megadása
	Tulaj(const char* nev, const char* cim, const char* tel);

	/// Két tulaj egyezõségét vizsgálja
	/// @param d - jobb oldali operandus
	/// @return true, ha egyezik a két tulaj
	bool operator==(const Tulaj& t) const {
		return tNev == t.tNev && cim == t.cim && tel == t.tel;
	}

	/// Két tulaj nem egyezõségét vizsgálja
	/// @param d - jobb oldali operandus
	/// @return true, ha nem egyezik a két tulaj
	bool operator!=(const Tulaj& t) const {
		return tNev != t.tNev || cim != t.cim || tel != t.tel;
	}

	/// Név lekérdezése
	/// @return - név
	String getNev() const { return tNev; }

	/// Cím lekérdezése
	/// @return - cím
	String getCim() const { return cim; }

	/// Telefonszám lekérdezése
	/// @return - telefonszám
	String getTel() const { return tel; }

	/// Destruktor
	~Tulaj() {}
};

/// Globális inserter
/// @param os - output stream referencia
/// @param s - Tulaj referencia
/// @return output stream referencia
std::ostream& operator<<(std::ostream& os, const Tulaj& t);

#endif // TULAJ_H