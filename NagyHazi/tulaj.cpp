/**
 * \file tulaj.cpp
 *
 * Tulaj osztály tagfüggvényinek megvalósítása (definíciója)
 */

#include <iostream>

#include "memtrace.h"
#include "tulaj.h"

Tulaj::Tulaj(const char* nev, const char* cim, const char* tel) {
	if (nev != "" && cim != "" && tel != "") {
		this->tNev = nev;
		this->cim = cim;
		this->tel = tel;
	} else throw "Hibas bemenet";
}

 /// Globális inserter
 /// @param os - output stream referencia
 /// @param t - Tulaj referencia
 /// @return output stream referencia
std::ostream& operator<<(std::ostream& os, const Tulaj& t) {
	return os <<"Nev: " << t.getNev() << "\n\tCim: " << t.getCim() << "\n\tTelefonszam: " << t.getTel();
}
