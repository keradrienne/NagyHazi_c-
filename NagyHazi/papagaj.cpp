/**
 *
 * \file papagaj.cpp
 *
 * Papagaj osztály tagfüggvényinek megvalósítása (definíciója)
*/
#include <iostream>

#include "memtrace.h"
#include"papagaj.h"

/// Paraméteres konstruktor
Papagaj::Papagaj(const char* faj, const char* nev, const Datum& szul,
	const Tulaj& gazdi, const char* tollazat, bool nem) :Allat(faj, nev, szul), gazdi(gazdi) {
	if (tollazat != "") {
		this->tollazat = tollazat;
		this->nem = nem;
	} else throw "Hibas bemenet";
}

/// operátor==
bool Papagaj::operator==(const Papagaj& p) const {
	return faj == p.faj && nev == p.nev && szul == p.szul &&
		gazdi == p.gazdi && tollazat == p.tollazat && nem == p.nem;
}

/// operátor!=
bool Papagaj::operator!=(const Papagaj& p) const {
	return faj != p.faj || nev != p.nev || szul != p.szul ||
		gazdi != p.gazdi || tollazat != p.tollazat || nem != p.nem;
}

/// Globális inserter
std::ostream& operator<<(std::ostream& os, Papagaj& p) {
	return os << "\nPapagaj adatai:\n\tFaj: " << p.getFaj() << "\n\tNev: " << p.getNev() << "\n\tSzuletesi ido: " << p.getSzul() 
		<< "\n\Tollazat: " << p.getTollazat() << "\n\tNem: " << (p.getNem() ? "Nosteny" : "Him") <<	"\nTulaj adatai:\n\t" << p.getTulaj();
}

/// Globális inserter
std::ofstream& operator<<(std::ofstream& of, Papagaj& p) {
	of << p.getFaj() << ";" << p.getNev() << ";" << p.getSzul().getEv() << ";" << p.getSzul().getHo() << ";" << p.getSzul().getNap() 
		<< ";" << p.getTollazat() << ";" <<	p.getNem() << ";" << p.getTulaj().getNev() << ";" << p.getTulaj().getCim() << ";" << p.getTulaj().getTel() << std::endl;
	return of;
}