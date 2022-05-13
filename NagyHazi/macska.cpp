/**
 *
 * \file macska.cpp
 *
 * Macska osztály tagfüggvényinek megvalósítása (definíciója)
*/
#include <iostream>

#include "memtrace.h"
#include"macska.h"

/// Paraméteres konstruktor
Macska::Macska(const char* faj, const char* nev, const Datum& szul,
	const Tulaj& gazdi, const char* chip, const char* bunda, bool nem) :Allat(faj, nev, szul), gazdi(gazdi) {
	if (chip != "" && bunda != "") {
		this->chip = chip;
		this->bunda = bunda;
		this->nem = nem;
	}
	else throw "Hibas bemenet";
}

/// operátor==
bool Macska::operator==(const Macska& m) const {
	return faj == m.faj && nev == m.nev && szul == m.szul &&
		gazdi == m.gazdi && chip == m.chip && bunda == m.bunda && nem == m.nem;
}

/// operátor!=
bool Macska::operator!=(const Macska& m) const {
	return faj != m.faj || nev != m.nev || szul != m.szul ||
		gazdi != m.gazdi || chip != m.chip || bunda != m.bunda || nem != m.nem;
}

/// Globális inserter
std::ostream& operator<<(std::ostream& os, Macska& m) {
	return os << "\nMacska adatai:\n\tFaj: " << m.getFaj() << "\n\tNev: " << m.getNev() << "\n\tSzuletesi ido: " << m.getSzul() <<
		"\n\tChip szam: " << m.getChip() << "\n\tBunda: " << m.getBunda() << "\n\tNem: " << (m.getNem() ? "Nosteny" : "Him") <<
		"\nTulaj adatai:\n\t" << m.getTulaj();
}

/// Globális inserter
std::ofstream& operator<<(std::ofstream& of, Macska& m) {
	of << m.getFaj() << ";" << m.getNev() << ";" << m.getSzul().getEv() << ";" << m.getSzul().getHo() << ";" << m.getSzul().getNap()
		<< ";" << m.getChip() << ";" << m.getBunda() << ";" << m.getNem() << ";" << m.getTulaj().getNev() << ";" << m.getTulaj().getCim()
		<< ";" << m.getTulaj().getTel() << std::endl;
	return of;
}