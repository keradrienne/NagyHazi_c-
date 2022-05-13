/**
 * \file: list.hpp
 * 
 * Generikus lista iterátorral
 * 
 */

#include <iostream>
#include <fstream> 
#include <stdexcept>

#include "memtrace.h"

#ifndef GENERIKUS_LISTA_ITER_HPP
#define GENERIKUS_LISTA_ITER_HPP

template<class T>
class Lista {
    struct ListaElem {
        T  adat;		    // adat
        ListaElem* kov;	    // pointer a következõre
        ListaElem(ListaElem* p = NULL) :kov(p) {}   // Konstruktor
        
        ListaElem& operator=(const ListaElem);
    };

    ListaElem* elso;	    // pointer az elsõre
    ListaElem* akt;	        // pointer az aktuálisra

    //Lista(const Lista&);
    Lista& operator=(const Lista&);
public:
    Lista() { akt = elso = new ListaElem; }	// strázsa létrehozása

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
            of << i->adat;      // adat kiírás fájlba
            i = i->kov;         // iterátor növelése
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
    ListaElem* i = elso;                    // futó pointer
    // ismétlõdés keresése
    while (i != NULL && i->adat != dat)
        i = i->kov;     // iterátor növelése
    if (i != NULL)      // ha nincs a feltételnek megfelelõ elem
        throw "Mar van ilyen allat a listaban";
    else {
        ListaElem* p;			            // futó pointer
        for (p = elso; p->kov != NULL; p = p->kov);
        ListaElem* uj = new ListaElem(*p);  //régit másol
        p->adat = dat;                      // adat beírása
        p->kov = uj;                        // pointer beállítása
    } 
}

template <class T>
void Lista<T>::torol(const T& dat) {
    // törlendõ elem keresése
    ListaElem *elozo = NULL;    // lemaradó pointer
    ListaElem *i = elso;        // futó pointer
    while (i != NULL && i->adat != dat)
    {
        elozo = i;      //lemaradó pointer növelése
        i = i->kov;     // futó pointer növelése
    }

    //megatalált elem törlése
    if (i == NULL)              // ha nincs a feltételnek megfelelõ elem
        throw "Nincs ilyen elem";             
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
    if (i == NULL)              // ha nincs a feltételnek megfelelõ elem
        throw "Nincs ilyen elem";
    else {
        i->adat = mod;          // adat módosítása
    }
}

#endif // GENERIKUS_LISTA_ITER_HPP
