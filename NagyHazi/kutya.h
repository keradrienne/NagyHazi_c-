#ifndef KUTYA_H
#define KUTYA_H

/**
 * \file kutya.h
 *
 * Kutya oszt�ly deklar�ci�ja �s f�ggv�nyei
 */

#include <iostream>
#include <fstream>

#include "memtrace.h"
#include "allat.h"
#include "tulaj.h"

class Kutya : public Allat {
private:
	Tulaj gazdi;	///< tulajdonos
	String chip;	///< chipsz�m
	String bunda;	///< bunda jellege, sz�ne
	bool nem;		///< �llat neme
public:
	///Default konstruktor
	Kutya() :nem(false) {}

	/// Konstruktor be�ll�tja az attrib�tumokat
	/// @param faj - faj megnevez�se
	/// @param nev - n�v megad�sa
	/// @param szul - sz�let�si �v megad�sa
	/// @param gazdi - tulaj megad�sa
	/// @param chip - chipsz�m megad�sa
	/// @param bunda - bunda jellege, sz�ne megad�sa
	/// @param nem - nem megad�sa
	Kutya(const char* faj, const char* nev, const Datum& szul,
		const Tulaj& gazdi, const char* chip, const char* bunda, bool nem);

	/// K�t kutya egyez�s�g�t vizsg�lja
	/// @param k - jobb oldali operandus
	/// @return true, ha egyezik a k�t kutya
	bool operator==(const Kutya&) const;

	/// K�t kutya nem egyez�s�g�t vizsg�lja
	/// @param k - jobb oldali operandus
	/// @return true, ha nem egyezik a k�t kutya
	bool operator!=(const Kutya&) const;

	/// Tulaj lek�rdez�se
	/// @return - gazdi
	Tulaj getTulaj() { return gazdi; }

	/// Chipsz�m lek�rdez�se
	/// @return - chip
	String getChip() { return chip; }

	/// Bunda lek�rdez�se
	/// @return - bunda
	String getBunda() { return bunda; }

	/// Nem lek�rdez�se
	/// True - n�st�ny, False - h�m
	/// @return - nem
	bool getNem() { return nem; }

	/// Destruktor
	~Kutya() {}
};

/// Glob�lis inserter
/// @param os - output stream referencia
/// @param k - Kutya referencia
/// @return output stream referencia
std::ostream& operator<<(std::ostream& os, Kutya& k);

/// Glob�lis inserter
/// @param of - output stream referencia
/// @param k - Kutya referencia
/// @return output stream referencia
std::ofstream& operator<<(std::ofstream& of, Kutya& k);

#endif // KUTYA_H