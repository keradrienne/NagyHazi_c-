#ifndef KUTYA_H
#define KUTYA_H

/**
 * \file kutya.h
 *
 * Kutya osztály deklarációja és függvényei
 */

#include <iostream>
#include <fstream>

#include "memtrace.h"
#include "allat.h"
#include "tulaj.h"

class Kutya : public Allat {
private:
	Tulaj gazdi;
	String chip;
	String bunda;
	bool nem;
public:
	///Default konstruktor
	Kutya() :nem(false) {}

	/// Konstruktor beállítja az attribútumokat
	/// @param faj - faj megnevezése
	/// @param nev - név megadása
	/// @param szul - születési év megadása
	/// @param gazdi - tulaj megadása
	/// @param chip - chipszám megadása
	/// @param bunda - bunda jellege, színe megadása
	/// @param nem - nem megadása
	Kutya(const char* faj, const char* nev, const Datum& szul,
		const Tulaj& gazdi, const char* chip, const char* bunda, bool nem);

	/// Két kutya egyezõségét vizsgálja
	/// @param k - jobb oldali operandus
	/// @return true, ha egyezik a két kutya
	bool operator==(const Kutya&) const;

	/// Két kutya nem egyezõségét vizsgálja
	/// @param k - jobb oldali operandus
	/// @return true, ha nem egyezik a két kutya
	bool operator!=(const Kutya&) const;

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
	~Kutya() {}
};

/// Globális inserter
/// @param os - output stream referencia
/// @param k - Kutya referencia
/// @return output stream referencia
std::ostream& operator<<(std::ostream& os, Kutya& k);

/// Globális inserter
/// @param of - output stream referencia
/// @param k - Kutya referencia
/// @return output stream referencia
std::ofstream& operator<<(std::ofstream& of, Kutya& k);

#endif // KUTYA_H