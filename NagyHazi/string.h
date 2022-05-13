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
    char *pData;        ///< pointer az adatra
    size_t len;         ///< hossz lezáró nulla nélkül
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

    /// Konstruktor: egy char karakterből (createStrFromChar)
    String(const char);

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

    /// Értékadó operátor
    /// @param rhs_s - jobboldali String
    /// @return baoldali (módosított) string (referenciája)
    String& operator+=(const String&);

    /// Sztrinhez karaktert összefűz
    /// @param rhs_c - jobboldali karakter
    /// @return új String, ami tartalmazza a két sztringet egymás után
    String operator+(const char) const;

    /// Két Stringet összefűz (concatString)
    /// @param rhs_s - jobboldali String
    /// @return új String, ami tartalmazza a két stringet egymás után
    String operator+(const String&) const;

    /// A string egy megadott indexű elemének REFERENCIÁJÁVAL tér vissza.
    /// @param idx - charakter indexe
    /// @return karakter (referencia)
    ///         Indexelési hiba esetén const char* kivételt dob.
    char& operator[](size_t idx);

    /// A string egy megadott indexű elemének REFERENCIÁJÁVAL tér vissza.
    /// Konstans stringre alkalmazható.
    /// @param idx - karakter indexe
    /// @return karakter (referencia)
    ///         Indexelési hiba esetén const char* kivételt dob.
    const char& operator[](size_t idx) const;

    /// Két String egyezőségét vizsgálja
    /// @param s - jobb oldali operandus
    /// @return true, ha egyezik a két String
    bool operator==(const String&) const;

    /// String és char* egyezőségét vizsgálja
    /// @param s - jobb oldali operandus
    /// @return true, ha egyeznek
    bool operator==(const char*) const;

    /// Két String nem egyezőségét vizsgálja
    /// @param s - jobb oldali operandus
    /// @return true, ha nem egyezik a két String
    bool operator!=(const String&) const;

    /// String és char* nem egyezőségét vizsgálja
    /// @param s - jobb oldali operandus
    /// @return true, ha nem egyeznek
    bool operator!=(const char*) const;
};

/// String operator+
String operator+(char c, String& s);

/// kiír az ostream-re (printString)
/// @param os - ostream típusú objektum
/// @param s0 - String, amit kiírunk
/// @return os
std::ostream& operator<<(std::ostream& os, const String& s);

/// Beolvas az istream-ről egy szót egy string-be.
/// @param is - istream típusú objektum
/// @param s0 - String, amibe beolvas
/// @return is
std::istream& operator>>(std::istream& is, String& s0);

#endif // STRING_H