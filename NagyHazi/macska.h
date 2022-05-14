#ifndef MACSKA_H
#define MACSKA_H

/**
 * \file macska.h
 *
 * Macska osztály deklarációja és függvényei
 */

#include <iostream>
#include <fstream>

#include "memtrace.h"
#include "allat.h"
#include "tulaj.h"
class Macska : public Allat{
private:
	Tulaj gazdi;
	String chip;
	String bunda;
	bool nem;
public:
	///Default konstruktor
	Macska() :nem(false) {}

	/// Konstruktor beállítja az attribútumokat
	/// @param faj - faj megnevezése
	/// @param nev - név megadása
	/// @param szul - születési év megadása
	/// @param gazdi - tulaj megadása
	/// @param chip - chipszám megadása
	/// @param bunda - bunda jellege, színe megadása
	/// @param nem - nem megadása
	Macska(const char* faj, const char* nev, const Datum& szul,
		const Tulaj& gazdi, const char* chip, const char* bunda, bool nem);

	/// Két macska egyezõségét vizsgálja
	/// @param m - jobb oldali operandus
	/// @return true, ha egyezik a két macska
	bool operator==(const Macska&) const;

	/// Két macska nem egyezõségét vizsgálja
	/// @param m - jobb oldali operandus
	/// @return true, ha nem egyezik a két macska
	bool operator!=(const Macska&) const;

	/// Tulaj lekérdezése
	/// @return - gazdi
	Tulaj getTulaj() { return gazdi; }

	/// Tulaj beállítása
	/// @param t - Tulaj referencia
	void setTulaj(Tulaj& t) { this->gazdi = t; }

	/// Chipszám lekérdezése
	/// @return - chip
	String getChip() { return chip; }

	/// Chipszám beállítása
	/// @param p - karaktersorozat
	void setChip(const char* p) {
		if (String(p) != String())
			this->chip = p;
		else throw "Rossz bemenet";
	}

	/// Bunda lekérdezése
	/// @return - bunda
	String getBunda() { return bunda; }

	/// Bundázat beállítása
	/// @param p - karaktersorozat
	void setBunda(const char* p) {
		if (String(p) != String())
			this->bunda = p;
		else throw "Rossz bemenet";
	}

	/// Nem lekérdezése
	/// True - nõstény, False - hím
	/// @return - nem
	bool getNem() { return nem; }

	/// Nem beállítása
	/// @param b - true/false
	void setNem(bool b) { this->nem = b; }

	/// Destruktor
	~Macska() {}
};

/// Globális inserter
/// @param os - output stream referencia
/// @param m - Macska referencia
/// @return output stream referencia
std::ostream& operator<<(std::ostream& os, Macska& m);

/// Globális inserter
/// @param of - output stream referencia
/// @param m - Macska referencia
/// @return output stream referencia
std::ofstream& operator<<(std::ofstream& of, Macska& m);

#endif // MACSKA_H