#ifndef STRING_H
#define STRING_H
/**
 * \file string.h
 * 
 * String osztály deklarációja és globális függvényei
 */
#include <iostream>

#include "memtrace.h"

 /**
  * A String osztály.
  * A 'pData'-ban vannak a karakterek (a lezáró nullával együtt), 'len' a hossza.
  * A hosszba nem számít bele a lezáró nulla.
  */
class String {
    char *pData;
    size_t len;
public:
    /// Paraméter nélküli konstruktor:
    String() :pData(0), len(0) {
        pData = new char[1];
        *pData = '\0';
    }

    /// Sztring hosszát adja vissza.
    /// @return sztring tényleges hossza (lezáró nulla nélkül).
    size_t size() const { return len; }

    /// C-sztringet ad vissza
    /// @return pointer a tárolt, vagy azzal azonos tartalmú nullával lezárt sztring-re.
    const char* c_str() const { return pData; }

    /// Konstruktor: egy nullával lezárt char sorozatból
    String(const char*);

    /// MÁSOLÓ konstruktor
    /// @param s1 - String, amiből létrehozzuk az új String-et
    String(const String&);

    /// Destruktor
    ~String() { delete[] pData; }

    /// Értékadó operátor
    /// @param rhs_s - jobboldali String
    /// @return baoldali (módosított) string (referenciája)
    String& operator=(const String&);

    /// Két String egyezőségét vizsgálja
    /// @param s - jobb oldali operandus
    /// @return true, ha egyezik a két String
    bool operator==(const String&) const;

    /// Két String nem egyezőségét vizsgálja
    /// @param s - jobb oldali operandus
    /// @return true, ha nem egyezik a két String
    bool operator!=(const String&) const;
};

/// kiír az ostream-re (printString)
/// @param os - ostream típusú objektum
/// @param s0 - String, amit kiírunk
/// @return ostream típusú objektum
std::ostream& operator<<(std::ostream& os, const String& s);

#endif // STRING_H