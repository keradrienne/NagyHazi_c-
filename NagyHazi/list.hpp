/**
 * \file: list.hpp
 * 
 * Generikus lista iterátorral
 * 
 */

#include <iostream>
#include <fstream> 
#include <stdexcept>
#include <string>
#include <sstream>

#include "memtrace.h"

#ifndef GENERIKUS_LISTA_ITER_HPP
#define GENERIKUS_LISTA_ITER_HPP

template<class T>
class Lista {
    struct ListaElem {
        T  adat;		    // adat
        ListaElem* kov;	    // pointer a következõre
        // Konstruktor
        ListaElem(ListaElem* p = NULL) :kov(p) {}
        
        ListaElem& operator=(const ListaElem);
    };

    ListaElem* elso;	    // pointer az elsõre
    ListaElem* akt;	        // pointer az aktuálisra

    //Lista(const Lista&);
    Lista& operator=(const Lista&);
public:
    // strázsa létrehozása
    Lista() { akt = elso = new ListaElem; }	

    /// Globális inserter
    /// @param os - output stream referencia
    /// @param rhs - Lista referencia
    /// @return output stream referencia
    friend std::ostream& operator<<(std::ostream& os, const Lista& rhs) {
        ListaElem* i = rhs.elso;
        while (i->kov != NULL)
        {
            std::cout << std::endl << "\t--------------------------------------------------------------------------------";
            std::cout << i->adat;   // adat kiírása
            std::cout << std::endl << "\t--------------------------------------------------------------------------------" << std::endl;
            i = i->kov;             // pointer növelése
        }
        return os;
    }

    /// Globális fájlinserter
    /// @param of - output stream referencia
    /// @param rhs - Lista referencia
    /// @return output stream referencia
    friend std::ofstream& operator<<(std::ofstream& of, const Lista& rhs) {
        ListaElem* i = rhs.elso;    // futó pointer
        while (i->kov != NULL)
        {
            of << i->adat;          // adat kiírás fájlba
            i = i->kov;             // iterátor növelése
        }
        return of;
    }

    /// Elem beszúrása listába
    /// @param dat - beszúrandó adat refernciája
    void beszur(const T& dat);

    /// Elem törlése listából
    /// @param dat - törlendõ adat refernciája
    void torol(const T& dat);

    /// Elem módosítása a listában
    /// @param dat - módosítandó adat refernciája
    /// @param mod - módosító adat refernciája
    void modosit(const T& dat, const T& mod);

    /// Elemek beolvasása adatfájlból
    /// @param p - forrásfájl neve "nev.txt" formátumban
    void beolvas(const char* p);

    class iterator;		    // elõdeklaráció

    /// Létrehoz egy iterátort és az elejére állítja
    iterator begin() {      
        return(iterator(*this));
    }

    /// Létrehozza és az utolsó elem után állítja
    iterator end() {
        return(iterator());
    }

    class iterator {		// belsõ osztály, a publikus részek kilátszanak
        ListaElem* akt;	    // mutató az aktuális elemre

    public:
        /// Iterátor konstruktor
        /// Végére állítja az iterátort
        iterator() : akt(NULL) {};              

        /// Iterátor konstruktor
        /// Elejére állítja az iterátort
        /// @param l - lista refernciája
        iterator(const Lista& l) : akt(l.elso) {
            if (akt->kov == NULL)
                akt = NULL;                     // strázsa miatti trükk
        }

        /// Növeli az iterátort (pre)
        /// @return iterátor referencia
        iterator& operator++() {        
            if (akt != NULL) {
                akt = akt->kov;  	    // következõre
                if (akt->kov == NULL)
                    akt = NULL;         // strázsa miatti trükk
            }
            return(*this);
        }

        /// Növeli az iterátort (post)
        /// @return iterátor referencia
        iterator operator++(int) {  
            iterator tmp = *this;   // elõzõ érték
            operator++();	        // növel
            return(tmp);	        // elõzõvel kell visszatérni
        }

        /// Összehasonlít
        /// @param i - iterátor referencia
        /// @return bool
        bool operator!=(const iterator& i) const { 
            return(akt != i.akt);
        }

        /// Indirekció
        /// @return osztály referencia
        T& operator*() {	
            if (akt != NULL) return(akt->adat);     // visszatérés az adattal
            else throw std::out_of_range("Hiba");
        }

        /// Indirekció
        /// @return osztály pointer
        T* operator->() {
            if (akt != NULL) return(&akt->adat);    // visszatérés az adattal
            else throw std::out_of_range("Hiba");
        }

    }; // iterator osztály vége

    /// Destruktor
    ~Lista();
};

template <class T>
Lista<T>::~Lista() {
    ListaElem* p;			// futó pointer
    while ((p = elso) != NULL) {
        elso = p->kov;      // pointer átállítása
        delete p;           // törlés
    }
}

template <class T>
void Lista<T>::beszur(const T& dat) {
    ListaElem* i = elso;    // futó pointer
    // ismétlõdés keresése
    while (i != NULL && i->adat != dat)
        i = i->kov;         // iterátor növelése
    if (i != NULL) {        // ha nincs a feltételnek megfelelõ elem
        std::cout << "Mar van ilyen allat a listaban" << std::endl;
        throw "Mar van ilyen allat a listaban";
    } 
    else {
        ListaElem* p;			            // futó pointer
        for (p = elso; p->kov != NULL; p = p->kov);
        ListaElem* uj = new ListaElem(*p);  //régit másol
        p->adat = dat;                      // adat beírása
        p->kov = uj;                        // pointer beállítása
        std::cout << "Sikeres hozzaadas" << std::endl;
    } 
}

template <class T>
void Lista<T>::torol(const T& dat) {
    // törlendõ elem keresése
    ListaElem *elozo = NULL;    // lemaradó pointer
    ListaElem *i = elso;        // futó pointer
    while (i != NULL && i->adat != dat)
    {
        elozo = i;              //lemaradó pointer növelése
        i = i->kov;             // futó pointer növelése
    }

    //megatalált elem törlése
    if (i == NULL) {            // ha nincs a feltételnek megfelelõ elem
        std::cout << "Nincs ilyen elem" << std::endl;
        throw "Nincs ilyen elem";
    }
    else if (elozo == NULL) {   // ha az elsõ elemet kell törölni
        ListaElem *uj = i->kov; // pointer átállítása
        delete(i);              // törlendõ törlése
        elso = uj;              // lista eleje pointer beállítása
    }
    else {                      //ha lista belsõ vagy utolsó elemét kell törölni
        elozo->kov = i->kov;    // pointer átállítása
        delete(i);              // törlendõ törlése
    }
}

template <class T>
void Lista<T>::modosit(const T& dat, const T& mod) {
    //módosítandó elem keresése
    ListaElem * i = elso;       // futó pointer
    while (i != NULL && i->adat != dat)
        i = i->kov;             // pointer növelése
    if (i == NULL) {            // ha nincs a feltételnek megfelelõ elem
        std::cout << "Nincs ilyen elem" << std::endl;
        throw "Nincs ilyen elem";
    }
    else {
        i->adat = mod;          // adat módosítása
        std::cout << "Sikeres modositas" << std::endl;
    }
}

template<class T>
void Lista<T>::beolvas(const char* p) {
    std::ifstream file(p);      // fajl megnyitasa
    std::string faj, nev, bunda, chip, tNev, cim, tel, s, line;     // valtozók, amibe a beolvasáás megtörténik
    int ev = 0, ho = 0, nap = 0, db = 0;        // valtozók, amibe a beolvasáás megtörténik
    bool nem;                   // valtozó, amibe a beolvasáás megtörténik
    if (file) {                 // ha létezik ilyen fájl
        while (std::getline(file, line)) {      // sor beolvasása
            std::stringstream linestream(line);
            while (std::getline(linestream, s, ';')) {      // sor feldarabolása ; mentén
                if (db == 0) {
                    faj = s;
                    db++;
                }
                else if (db == 1) {
                    nev = s;
                    db++;
                }
                else if (db == 2) {
                    std::stringstream ss;
                    ss << s;
                    ss >> ev;
                    db++;
                }
                else if (db == 3) {
                    std::stringstream ss;
                    ss << s;
                    ss >> ho;
                    db++;
                }
                else if (db == 4) {
                    std::stringstream ss;
                    ss << s;
                    ss >> nap;
                    db++;
                }
                else if (db == 5) {
                    chip = s;
                    db++;
                }
                else if (db == 6) {
                    bunda = s;
                    db++;
                }
                else if (db == 7) {
                    std::stringstream ss;
                    ss << s;
                    ss >> nem;
                    db++;
                }
                else if (db == 8) {
                    tNev = s;
                    db++;
                }
                else if (db == 9) {
                    cim = s;
                    db++;
                }
                else if (db == 10) {
                    tel = s;
                    db++;
                }
                if (db == 11) {
                    db = 0;
                    T o(faj.c_str(), nev.c_str(), Datum(ev, ho, nap), Tulaj(tNev.c_str(), cim.c_str(),      // osztálypédány létrehozása
                        tel.c_str()), chip.c_str(), bunda.c_str(), nem);
                    Lista<T>::beszur(o);        // példány beszúrása listába
                }
            }
        }
    }
    else {
        std::cout << "Nincs ilyen fajl" << std::endl;
        throw "Nincs ilyen fajl";
    }
}

#endif // GENERIKUS_LISTA_ITER_HPP
