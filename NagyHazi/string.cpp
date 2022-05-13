/**
 *
 * \file string.cpp
 * 
 * String osztály tagfüggvényinek megvalósítása
*/

#ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a C sztringkezelő függvényeire
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <cstring>

#include "memtrace.h"
#include "string.h"

using std::ios_base;


/// Konstruktorok: egy char karakterből
String::String(const char p) {
	len = 1;
	pData = new char[2];
	pData[0] = p;
	pData[1] = '\0';
}
///                egy nullával lezárt char sorozatból
String::String(const char* p) {
	len = strlen(p);
	pData = new char[len + 1];
	strcpy(pData, p);
}

/// Másoló konstruktor: String-ből készít
String::String(const String& s) {
	pData = new char[(len = s.len) + 1];
	strcpy(pData, s.pData);
}
/// Destruktor (disposeString)

/// operator=
String& String::operator=(const String& s) {
	if (this != &s) {
		delete[] pData;
		pData = new char[(len = s.len) + 1];
		strcpy(pData, s.pData);
	}
	return *this;
}

/// operator+=
String& String::operator+=(const String& rhs_s) {
	*this = *this + rhs_s;
	return *this;
}

/// [] operátorok: egy megadott indexű elem REFERENCIÁJÁVAL térnek vissza
/// indexhiba esetén const char* kivételt dob!
char& String::operator[](size_t idx) {
	if (idx >= len || idx < 0) throw "const char*";
	return pData[idx];
}

const char& String::operator[](size_t idx) const {
	if (idx >= len || idx < 0) throw "const char *";
	return pData[idx];
}

/// + operátorok:
///                 String-hez jobbról karaktert ad
String String::operator+(const char p) const {
	char *uj = new char[len + 2];
	strcpy(uj, pData);
	uj[len] = p;
	uj[len + 1] = '\0';
	String ujs(uj);
	ujs.len = len + 1;
	delete[] uj;
	return ujs;
}
///                 String-hez String-et ad
String String::operator+(const String& s) const {
	char* uj = new char[len + s.len + 1];
	strcpy(uj, pData);
	strcat(uj, s.pData);
	String ujs(uj);
	ujs.len = len + s.len;
	delete[] uj;
	return ujs;
}

/// == operátorok
bool String::operator==(const String& s) const {
	if (len != s.len) return false;
	else {
		for (size_t i = 0; i < len; i++)
			if (pData[i] != s.pData[i]) return false;
	}
	return true;
}

bool String::operator==(const char* s) const {
	int db = 0;
	while (s[db] != '\0')
		db++;

	if (len != db) return false;
	else {
		for (size_t i = 0; i < len; i++)
			if (pData[i] != s[i]) return false;
	}
	return true;
}

/// != operátorok
bool String::operator!=(const String& s) const {
	if (len != s.len) return true;
	else {
		for (size_t i = 0; i < len; i++)
			if (pData[i] != s.pData[i]) return true;
	}
	return false;
}

bool String::operator!=(const char* s) const {
	int db = 0;
	while (s[db] != '\0')
		db++;

	if (len != db) return true;
	else {
		for (size_t i = 0; i < len; i++)
			if (pData[i] != s[i]) return true;
	}
	return false;
}

/// String operator+
String operator+(char c, String& s) { return String(c) + s; }

/// << operator, ami kiír az ostream-re
std::ostream& operator<<(std::ostream& os, const String& s) { return os << s.c_str(); }

// << operátor, ami beolvas az istreamről egy szót
std::istream& operator>>(std::istream& is, String& s0) {
	unsigned char ch;
	s0 = String("");
	std::ios_base::fmtflags fl = is.flags(); 
	is.setf(ios_base::skipws);
	while (is >> ch) {
		is.unsetf(ios_base::skipws);
		if (isspace(ch)) {
			is.putback(ch);
			break;
		}
		else {
			s0 = s0 + ch;
		}
	}
	is.setf(fl);
	return is;
}