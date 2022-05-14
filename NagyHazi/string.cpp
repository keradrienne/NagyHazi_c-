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

String::String(const char* p) {
	len = strlen(p);
	pData = new char[len + 1];
	strcpy(pData, p);
}

String::String(const String& s) {
	pData = new char[(len = s.len) + 1];
	strcpy(pData, s.pData);
}

String& String::operator=(const String& s) {
	if (this != &s) {
		delete[] pData;
		pData = new char[(len = s.len) + 1];
		strcpy(pData, s.pData);
	}
	return *this;
}

bool String::operator==(const String& s) const {
	if (len != s.len) return false;
	else {
		for (size_t i = 0; i < len; i++)
			if (pData[i] != s.pData[i]) return false;
	}
	return true;
}

bool String::operator!=(const String& s) const {
	if (len != s.len) return true;
	else {
		for (size_t i = 0; i < len; i++)
			if (pData[i] != s.pData[i]) return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const String& s) { return os << s.c_str(); }