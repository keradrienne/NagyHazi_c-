/**
 *
 * \file kutya.cpp
 *
 * Kutya osztály tagfüggvényinek megvalósítása (definíciója)
*/
#include <iostream>

#include "memtrace.h"
#include"kutya.h"

Kutya::Kutya(const char* faj, const char* nev, const Datum& szul,
	const Tulaj& gazdi, const char* chip, const char* bunda, bool nem) :Allat(faj, nev, szul), gazdi(gazdi) {
	if (chip != "" && bunda != "") {
		this->chip = chip;
		this->bunda = bunda;
		this->nem = nem;
	} else throw "Hibas bemenet";
}

bool Kutya::operator==(const Kutya& k) const {
	return faj == k.faj && nev == k.nev && szul == k.szul &&
		gazdi == k.gazdi && chip == k.chip && bunda == k.bunda && nem == k.nem;
}

bool Kutya::operator!=(const Kutya& k) const {
	return faj != k.faj || nev != k.nev || szul != k.szul || 
		gazdi != k.gazdi || chip != k.chip || bunda != k.bunda || nem != k.nem;
}

std::ostream& operator<<(std::ostream& os, Kutya& k) {
	return os << "\n\tKutya adatai:\n\t\tFaj: " << k.getFaj() << "\n\t\tNev: " << k.getNev() << "\n\t\tSzuletesi ido: " << k.getSzul() <<
		"\n\t\tChip szam: " << k.getChip() << "\n\t\tBunda: " << k.getBunda() << "\n\t\tNem: " << (k.getNem() ? "Nosteny" : "Him") <<
		"\n\tTulaj adatai:\n\t" << k.getTulaj();
}

std::ofstream& operator<<(std::ofstream& of, Kutya& k) {
	of << k.getFaj() << ";" << k.getNev() << ";" << k.getSzul().getEv() << ";" << k.getSzul().getHo() << ";" << k.getSzul().getNap() 
		<< ";" << k.getChip() << ";" << k.getBunda() << ";" << k.getNem() << ";" << k.getTulaj().getNev() << ";" << k.getTulaj().getCim() 
		<< ";" << k.getTulaj().getTel() << std::endl;
	return of;
}