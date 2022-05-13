#ifndef PAPAGAJ_H
#define PAPAGAJ_H

/**
 * \file papagaj.h
 *
 * Papagaj osztály deklarációja és függvényei
 */

#include <iostream>
#include <fstream>

#include "memtrace.h"
#include "allat.h"
#include "tulaj.h"

class Papagaj : public Allat{
private:
	Tulaj gazdi;		///< tulajdonos
	String tollazat;	///< tollazat jellege, színe
	bool nem;			///< állat neme
public:
	///Default konstruktor
	Papagaj() :nem(false) {}

	/// Konstruktor beállítja az attribútumokat
	/// @param faj - faj megnevezése
	/// @param nev - név megadása
	/// @param szul - születési év megadása
	/// @param gazdi - tulaj megadása
	/// @param tollazat - tollazat jellege, színe megadása
	/// @param nem - nem megadása
	Papagaj(const char* faj, const char* nev, const Datum& szul,
		const Tulaj& gazdi, const char* tollazat, bool nem);

	/// Két papagáj egyezõségét vizsgálja
	/// @param p - jobb oldali operandus
	/// @return true, ha egyezik a két papagáj
	bool operator==(const Papagaj&) const;

	/// Két papagáj nem egyezõségét vizsgálja
	/// @param p - jobb oldali operandus
	/// @return true, ha nem egyezik a két papagáj
	bool operator!=(const Papagaj&) const;

	/// Tulaj lekérdezése
	/// @return - gazdi
	Tulaj getTulaj() { return gazdi; }

	/// Tollazat lekérdezése
	/// @return - bunda
	String getTollazat() { return tollazat; }

	/// Nem lekérdezése
	/// True - nõstény, False - hím
	/// @return - nem
	bool getNem() { return nem; }

	/// Destruktor
	~Papagaj() {}
};

/// Globális inserter
/// @param os - output stream referencia
/// @param p - Papagaj referencia
/// @return output stream referencia
std::ostream& operator<<(std::ostream& os, Papagaj& p);

/// Globális inserter
/// @param of - output stream referencia
/// @param p - Papagaj referencia
/// @return output stream referencia
std::ofstream& operator<<(std::ofstream& of, Papagaj& p);

#endif // PAPAGAJ_H