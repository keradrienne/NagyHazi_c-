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

std::ostream& operator<<(std::ostream& os, const Tulaj& t) {
	return os <<"\tNev: " << t.getNev() << "\n\t\tCim: " << t.getCim() << "\n\t\tTelefonszam: " << t.getTel();
}
