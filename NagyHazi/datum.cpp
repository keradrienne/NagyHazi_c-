/**
 * \file datum.cpp
 *
 * Datum osztály tagfüggvényinek megvalósítása (definíciója)
 */
#define _CRT_SECURE_NO_WARNINGS			// VS ne nyafogjon a localtime miatt

#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

#include "memtrace.h"
#include "datum.h"

using std::setw;
using std::setfill;

Datum::Datum() {
    time_t tim;
    tim = time(NULL);       // lekérdezzük a jelenlegi időt
    struct tm *tp = localtime(&tim);  // átalakítjuk
    ev = tp->tm_year+1900;
    ho = tp->tm_mon+1;
    nap = tp->tm_mday;

}

Datum::Datum(int ev, int ho, int nap) {
    time_t tim;
    tim = time(NULL);       // lekérdezzük a jelenlegi időt
    struct tm* tp = localtime(&tim);  // átalakítjuk
    int mev = tp->tm_year + 1900;
    if (ev < 2000 || ev > mev || ho > 12 || ho < 1 || nap > 31 || nap < 1) throw "Rossz datum";
    else {
        this->ev = ev;
        this->ho = ho;
        this->nap = nap;
    }
}

void Datum::setEv(int ev) {
    time_t tim;
    tim = time(NULL);       // lekérdezzük a jelenlegi időt
    struct tm* tp = localtime(&tim);  // átalakítjuk
    int mev = tp->tm_year + 1900;
    if (ev < 2000 || ev > mev) throw "Rossz datum";
    else this->ev = ev;
}

std::ostream& operator<<(std::ostream& os, const Datum& d) {
    return os << setw(4) << d.getEv() << "-"
       << setw(2) << setfill('0') << d.getHo() << "-"
       << setw(2) << d.getNap();
}
