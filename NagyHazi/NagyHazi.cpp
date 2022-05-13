#include <iostream>
#include <string>

#include "memtrace.h"
#include "kutya.h"
#include "papagaj.h"
#include "macska.h"

#include "list.hpp"

using namespace std;

/// <summary>
/// hiányzik:
///     beolvasás
/// </summary>
/// <returns></returns>

/// TESZT 1.
void test_1() {
    Lista<Kutya> kutyak;
    Lista<Papagaj> papagajok;
    Lista<Macska> macskak;

    Kutya k("Golden retriever", "Buksi", Datum(2019, 3, 22),
        Tulaj("Alma", "2233 Ecser, Szalaska dulo 010/36", "06 70 636 5237"),
        "326981-BA", "feher alapon fekete pottyos", false);

    Papagaj p("Kaukazusi papagaj", "Molly", Datum(),
        Tulaj("Korte", "3366 Ajka, Lanc utca 32.", "06 12 345 678"),
        "feher, kek szinu teljes tollazat", true);

    Macska m("Perzsa macska", "Cirmi", Datum(2020, 03, 01),
        Tulaj("Korte", "3366 Ajka, Lanc utca 32.", "06 12 345 678"),
        "568975-LK", "hosszu feher", true);

    kutyak.beszur(k);
    kutyak.beszur(k);
    papagajok.beszur(p);
    papagajok.beszur(p);
    macskak.beszur(m);
    macskak.beszur(m);
}

/// TESZT 2.
void test_2() {
    Lista<Kutya> kutyak;
    Lista<Papagaj> papagajok;
    Lista<Macska> macskak;

    Kutya k("Golden retriever", "Buksi", Datum(2019, 3, 22),
        Tulaj("Alma", "2233 Ecser, Szalaska dulo 010/36", "06 70 636 5237"),
        "326981-BA", "feher alapon fekete pottyos", false);
    Kutya k1("Golden retriever", "Potyi", Datum(),
        Tulaj("Alma", "2233 Ecser, Szalaska dulo 010/36", "06 70 636 5237"),
        "326981-BA", "feher alapon fekete pottyos", false);

    Papagaj p("Kaukazusi papagaj", "Molly", Datum(),
        Tulaj("Korte", "3366 Ajka, Lanc utca 32.", "06 12 345 678"),
        "feher, kek szinu teljes tollazat", true);

    Macska m("Perzsa macska", "Cirmi", Datum(2020, 03, 01),
        Tulaj("Korte", "3366 Ajka, Lanc utca 32.", "06 12 345 678"),
        "568975-LK", "hosszu feher", true);

    kutyak.beszur(k);
    kutyak.beszur(k1);
    papagajok.beszur(p);
    macskak.beszur(m);

    std::cout << kutyak;
    std::cout << papagajok;
    std::cout << macskak;
}

/// TESZT 3.
void test_3(){
    Lista<Kutya> kutyak;
    Lista<Papagaj> papagajok;
    Lista<Macska> macskak;


    Kutya k("Golden retriever", "Buksi", Datum(2019, 3, 22),
        Tulaj("Toth Alma", "2233 Ecser, Repa utca 23.", "06 70 636 5237"),
        "326981-BA", "feher alapon fekete pottyos", false);

    Papagaj p("Kaukazusi papagaj", "Molly", Datum(),
        Tulaj("Szabo Korte", "3366 Falva, Lanc utca 32.", "06 12 345 678"),
        "feher, kek szinu teljes tollazat", true);

    Macska m("Perzsa macska", "Cirmi", Datum(2020, 03, 01),
        Tulaj("Szabo Korte", "3366 Falva, Lanc utca 32.", "06 12 345 678"),
        "568975-LK", "hosszu feher", true);

    kutyak.beszur(k);
    papagajok.beszur(p);
    macskak.beszur(m);

    std::ofstream kFile("kutyak.txt");
    kFile << kutyak;
    kFile.close();

    std::ofstream mFile("macskak.txt");
    mFile << macskak;
    mFile.close();

    std::ofstream pFile("papagajok.txt");
    pFile << papagajok;
    pFile.close();
}

/// TESZT 4.
void test_4() {
    Lista<Kutya> kutyak;

    Kutya k("Golden retriever", "Buksi", Datum(2019, 3, 22),
        Tulaj("Toth Alma", "2233 Ecser, Repa utca 23.", "06 70 636 5237"),
        "326981-BA", "feher alapon fekete pottyos", false);

    Kutya k1("Golden retriever", "Potyi", Datum(2019, 3, 22),
        Tulaj("Toth Alma", "2233 Ecser, Repa utca 23.", "06 70 636 5237"),
        "326981-BA", "feher alapon piros pottyos", true);

    Kutya k2("Golden retriever", "Rebi", Datum(2019, 3, 22),
        Tulaj("Toth Alma", "2233 Ecser, Repa utca 23.", "06 70 636 5237"),
        "326981-BA", "feher alapon fekete pottyos", false);

    kutyak.beszur(k);
    kutyak.beszur(k1);

    kutyak.torol(k2);
}

/// TESZT 5.
void test_5() {
    Lista<Papagaj> papagajok;
    Lista<Macska> macskak;

    Papagaj p("Kaukazusi papagaj", "Molly", Datum(),
        Tulaj("Szabo Korte", "3366 Falva, Lanc utca 32.", "06 12 345 678"),
        "feher, kek szinu teljes tollazat", true);

    Papagaj p1("Orias papagaj", "David", Datum(2021,4,9),
        Tulaj("Gipsz Jakab", "8888 Csodafalva, Szep utca 7.", "06 12 345 678"),
        "feher, kek szinu teljes tollazat", true);

    papagajok.beszur(p);

    Lista<Papagaj>::iterator ip(papagajok);

    for (ip = papagajok.begin(); ip != papagajok.end(); ip++)
        if (ip->getFaj() == "Kaukazusi papagaj")
            papagajok.modosit(*ip, p1);

    std::cout << papagajok;
}

/// TESZT 6.
void test_6() {
    Papagaj p("Kaukazusi papagaj", "", Datum(),
        Tulaj("Szabo Korte", "3366 Falva, Lanc utca 32.", "06 12 345 678"),
        "feher, kek szinu teljes tollazat", true);
}

/// Főprogram a standard inputról olvas egy egész számot, majd
/// meghivja az annak megfelelő tesztesetet.
/// A további inputot és outputot a teszteset kezeli.
int main()
{
    try {
        int nr;
        std::cin >> nr; // hanyadik teszt eset
        switch (nr) {
        case 1:
            test_1();   // default 0 elemű kutya, macska, papagaj lista és 1-1 példány hozzáadása
            break;

        case 2:
            test_2();   // kutya, macska, papagaj 1-1 példánya listában + kiírás
            break;

        case 3:
            test_3();   // kutya, macska, papagaj 1-1 példánya listában + fájlba való kiírás
            break;
        case 4:
            test_4();   // törlés listából
            break;
        case 5:
            test_5();   // módosítás
            break;
        case 6:
            test_6();   // beolvasás
        }
    }
    // kivétel elkapása
    catch (const char *p) {
        std::cout << p << std::endl;
    }

    return 0;
}
