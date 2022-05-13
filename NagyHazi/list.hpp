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
        ListaElem(ListaElem* p = NULL) :kov(p) {}
        
        ListaElem& operator=(const ListaElem);
    };

    ListaElem* elso;	    // pointer az elsõre
    ListaElem* akt;	        // pointer az aktuálisra

    //Lista(const Lista&);
    Lista& operator=(const Lista&);
public:
    Lista() { akt = elso = new ListaElem; }	// strázsa létrehozása

    friend std::ostream& operator<<(std::ostream& os, const Lista& rhs) {
        ListaElem* i = rhs.elso;
        while (i->kov != NULL)
        {
            std::cout << i->adat;
            std::cout << std::endl;
            i = i->kov;
        }
        return os;
    }

    friend std::ofstream& operator<<(std::ofstream& of, const Lista& rhs) {
        ListaElem* i = rhs.elso;
        while (i->kov != NULL)
        {
            of << i->adat;
            i = i->kov;
        }
        return of;
    }

    void beszur(const T& dat);      	        // elem beszúrása
    void torol(const T& dat);                   // elem törlése
    void modosit(const T& dat, const T& mod);   // elem módosítása

    class iterator;		    // elõdeklaráció

    iterator begin() {      // létrehoz egy iterátort és az elejére állítja
        return(iterator(*this));
    }

    iterator end() {     // létrehozza és az utolsó elem után állítja
        return(iterator());
    }

    class iterator {		// belsõ osztály, a publikus részek kilátszanak
        ListaElem* akt;	    // mutató az aktuális elemre

    public:
        iterator() : akt(NULL) {};              // végére állítja az iterátort

        iterator(const Lista& l) : akt(l.elso) {// elejére állítja
            if (akt->kov == NULL)
                akt = NULL;                     // strázsa miatti trükk
        }

        iterator& operator++() {        // növeli az iterátort (pre)
            if (akt != NULL) {
                akt = akt->kov;  	    // következõre
                if (akt->kov == NULL)
                    akt = NULL;         // strázsa miatti trükk
            }
            return(*this);
        }

        iterator operator++(int) {  // növeli az iterátort (post)
            iterator tmp = *this;   // elõzõ érték
            operator++();	        // növel
            return(tmp);	        // elõzõvel kell visszatérni
        }

        bool operator!=(const iterator& i) const { // összehasonlít
            return(akt != i.akt);
        }

        T& operator*() {	// indirekció
            if (akt != NULL) return(akt->adat);
            else throw std::out_of_range("Hiba");
        }
        T* operator->() {	// indirekció
            if (akt != NULL) return(&akt->adat);
            else throw std::out_of_range("Hiba");
        }

    }; // iterator osztály vége

    ~Lista();
};

template <class T>          // tagfüggvénysablon
Lista<T>::~Lista() {
    ListaElem* p;			// futó pointer
    while ((p = elso) != NULL) {
        elso = p->kov;
        delete p;
    }
}

template <class T>                      // tagfüggvénysablon
void Lista<T>::beszur(const T& dat) {
    ListaElem* i = elso;
    while (i != NULL && i->adat != dat)
        i = i->kov;
    if (i != NULL)              // ha nincs a feltételnek megfelelõ elem
        throw "Mar van ilyen allat a listaban";
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
    ListaElem *elozo = NULL;
    ListaElem *i = elso;
    while (i != NULL && i->adat != dat)
    {
        elozo = i;
        i = i->kov;
    }

    //megatalált elem törlése
    if (i == NULL)              // ha nincs a feltételnek megfelelõ elem
        throw "Nincs ilyen elem";
        //throw "Nincs ilyen elem";
    else if (elozo == NULL) {   // ha az elsõ elemet kell törölni
        ListaElem *uj = i->kov;
        delete(i);
        elso = uj;
        std::cout << "Sikeres torles" << std::endl;
    }
    else {                      //ha lista belsõ vagy utolsó elemét kell törölni
        elozo->kov = i->kov;
        delete(i);
        std::cout << "Sikeres torles" << std::endl;
    }
}

template <class T>                      // tagfüggvénysablon
void Lista<T>::modosit(const T& dat, const T& mod) {
    //módosítandó elem keresése
    ListaElem * i = elso;
    while (i != NULL && i->adat != dat)
        i = i->kov;
    if (i == NULL)              // ha nincs a feltételnek megfelelõ elem
        throw "Nincs ilyen elem";
    else {
        i->adat = mod;
        std::cout << "Sikeres modositas" << std::endl;
    }
}

#endif // GENERIKUS_LISTA_ITER_HPP
