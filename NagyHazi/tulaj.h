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
	String tNev;
	String cim;
	String tel;
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

	/// Nev beállítása
	/// @param p - karaktersorozat
	void settNev(const char* p) {
		if (String(p) != String())
			this->tNev = p;
		else throw "Rossz bemenet";
	}

	/// Cím lekérdezése
	/// @return - cím
	String getCim() const { return cim; }

	/// Cim beállítása
	/// @param p - karaktersorozat
	void setCim(const char* p) {
		if (String(p) != String())
			this->cim = p;
		else throw "Rossz bemenet";
	}

	/// Telefonszám lekérdezése
	/// @return - telefonszám
	String getTel() const { return tel; }

	/// Telefonszám beállítása
	/// @param p - karaktersorozat
	void setTel(const char* p) {
		if (String(p) != String())
			this->tel = p;
		else throw "Rossz bemenet";
	}

	/// Destruktor
	~Tulaj() {}
};

/// Globális inserter
/// @param os - output stream referencia
/// @param s - Tulaj referencia
/// @return output stream referencia
std::ostream& operator<<(std::ostream& os, const Tulaj& t);

#endif // TULAJ_H