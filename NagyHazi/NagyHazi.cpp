#include <iostream>
#include <string>

#include "memtrace.h"
#include "gtest_lite.h"
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
    TEST(Letehozas) {
        // Sikeres dátummal
        EXPECT_NO_THROW(Kutya k("Golden retriever", "Buksi", Datum(2019, 3, 22),
            Tulaj("Alma", "2233 Ecser, Szalaska dulo 010/36", "06 70 636 5237"),
            "326981-BA", "feher alapon fekete pottyos", false));

        // Sikeres dátum nélkül
        EXPECT_NO_THROW(Kutya k("Golden retriever", "Buksi", Datum(),
            Tulaj("Alma", "2233 Ecser, Szalaska dulo 010/36", "06 70 636 5237"),
            "326981-BA", "feher alapon fekete pottyos", false));

        // Sikertelen ősosztály
        EXPECT_ANY_THROW(Kutya k("", "Buksi", Datum(2019, 3, 22),
            Tulaj("Alma", "2233 Ecser, Szalaska dulo 010/36", "06 70 636 5237"),
            "326981-BA", "feher alapon fekete pottyos", false));

        // Sikertelen tulaj
        EXPECT_ANY_THROW(Kutya k("Golden retriever", "Buksi", Datum(2019, 3, 22),
            Tulaj("", "2233 Ecser, Szalaska dulo 010/36", "06 70 636 5237"),
            "326981-BA", "feher alapon fekete pottyos", false));

        // Sikertelen peldany
        EXPECT_ANY_THROW(Kutya k("Golden retriever", "Buksi", Datum(2019, 3, 22),
            Tulaj("Alma", "2233 Ecser, Szalaska dulo 010/36", "06 70 636 5237"),
            "", "feher alapon fekete pottyos", false));

        // Sikertelen dátum
        EXPECT_ANY_THROW(Kutya k("Golden retriever", "Buksi", Datum(1500, 3, 22),
            Tulaj("Alma", "2233 Ecser, Szalaska dulo 010/36", "06 70 636 5237"),
            "326981-BA", "feher alapon fekete pottyos", false));

        // Sikertelen dátum
        EXPECT_ANY_THROW(Kutya k("Golden retriever", "Buksi", Datum(3000, 3, 22),
            Tulaj("Alma", "2233 Ecser, Szalaska dulo 010/36", "06 70 636 5237"),
            "326981-BA", "feher alapon fekete pottyos", false));

        // Sikertelen dátum
        EXPECT_ANY_THROW(Kutya k("Golden retriever", "Buksi", Datum(2000, 30, 22),
            Tulaj("Alma", "2233 Ecser, Szalaska dulo 010/36", "06 70 636 5237"),
            "326981-BA", "feher alapon fekete pottyos", false));

        // Sikertelen dátum
        EXPECT_ANY_THROW(Kutya k("Golden retriever", "Buksi", Datum(2000, 1, 90),
            Tulaj("Alma", "2233 Ecser, Szalaska dulo 010/36", "06 70 636 5237"),
            "326981-BA", "feher alapon fekete pottyos", false));

        // Sikertelen dátum
        EXPECT_ANY_THROW(Kutya k("Golden retriever", "Buksi", Datum(2000, 1, 0),
            Tulaj("Alma", "2233 Ecser, Szalaska dulo 010/36", "06 70 636 5237"),
            "326981-BA", "feher alapon fekete pottyos", false));
    }ENDM

    TEST(Beszuras){
        Lista<Kutya> kutyak;
        Lista<Papagaj> papagajok;
        Lista<Macska> macskak;

        Kutya k("Golden retriever", "Buksi", Datum(2019, 3, 22),
            Tulaj("Alma", "2233 Ecser, Szalaska dulo 010/36", "06 70 636 5237"),
            "326981-BA", "feher alapon fekete pottyos", false);

        Kutya k1("Golden retriever", "Maja", Datum(2019, 3, 22),
            Tulaj("Alma", "2233 Ecser, Szalaska dulo 010/36", "06 70 636 5237"),
            "326981-BA", "feher alapon fekete pottyos", true);

        Papagaj p("Kaukazusi papagaj", "Molly", Datum(),
            Tulaj("Korte", "3366 Ajka, Lanc utca 32.", "06 12 345 678"),
            "feher, kek szinu teljes tollazat", true);

        Macska m("Perzsa macska", "Cirmi", Datum(2020, 03, 01),
            Tulaj("Korte", "3366 Ajka, Lanc utca 32.", "06 12 345 678"),
            "568975-LK", "hosszu feher", true);

        EXPECT_NO_THROW(kutyak.beszur(k));      // sikeres beszúrás üres listához
        EXPECT_NO_THROW(kutyak.beszur(k1));      // sikeres beszúrás nem üres listához
        EXPECT_NO_THROW(papagajok.beszur(p));   // sikeres beszúrás üres listához
        EXPECT_NO_THROW(macskak.beszur(m));     // sikeres beszúrás üres listához
        EXPECT_ANY_THROW(kutyak.beszur(k));     // sikertelen beszúrás már létező elem miatt
        
    }ENDM
}

/// TESZT 2.
void test_2() {
    TEST(Kiiras) {
        Lista<Kutya> kutyak;
        Lista<Papagaj> papagajok;
        Lista<Macska> macskak;

        Kutya k("Golden retriever", "Buksi", Datum(2019, 3, 22),
            Tulaj("Alma", "2233 Ecser, Repa utca 23.", "06 70 636 5237"),
            "326981-BA", "feher alapon fekete pottyos", false);

        Kutya k1("Golden retriever", "Potyi", Datum(),
            Tulaj("Alma", "2233 Ecser, Repa utca 23.", "06 70 636 5237"),
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

        EXPECT_NO_THROW(std::cout << kutyak);       // kiírás standard outputra
        EXPECT_NO_THROW(std::cout << papagajok);    // kiírás standard outputra
        EXPECT_NO_THROW(std::cout << macskak);      // kiírás standard outputra

    }ENDM
}

/// TESZT 3.
void test_3(){
    TEST(Fajlbairas) {
        Lista<Kutya> kutyak;
        Lista<Papagaj> papagajok;
        Lista<Macska> macskak;


        Kutya k("Golden retriever", "Buksi", Datum(2019, 3, 22),
            Tulaj("Toth Alma", "2233 Ecser, Repa utca 23.", "06 70 636 5237"),
            "326981-BA", "feher alapon fekete pottyos", false);

        Kutya k1("Golden retriever", "Potyi", Datum(),
            Tulaj("Toth Alma", "2233 Ecser, Repa utca 23.", "06 70 636 5237"),
            "326981-BA", "fekete alapon feher pottyos", false);

        Papagaj p("Kaukazusi papagaj", "Molly", Datum(),
            Tulaj("Szabo Korte", "3366 Falva, Lanc utca 32.", "06 12 345 678"),
            "feher, kek szinu teljes tollazat", true);

        Papagaj p1("Hullamos papagaj", "Jack", Datum(2020, 6, 8),
            Tulaj("Lista Pista", "9999 Almafalva Tukor koz 33.", "06 12 345 678"),
            "feher, kek szinu teljes tollazat", true);

        Macska m("Perzsa macska", "Cirmi", Datum(2020, 03, 01),
            Tulaj("Szabo Korte", "3366 Falva, Lanc utca 32.", "06 12 345 678"),
            "568975-LK", "hosszu feher", true);

        Macska m1("Perzsa macska", "Simi", Datum(),
            Tulaj("Szabo Korte", "3366 Falva, Lanc utca 32.", "06 12 345 678"),
            "568975-LK", "hosszu feher", true);

        kutyak.beszur(k);
        kutyak.beszur(k1);
        papagajok.beszur(p);
        papagajok.beszur(p1);
        macskak.beszur(m);
        macskak.beszur(m1);

        // kiírás fájlba
        EXPECT_NO_THROW(
            std::ofstream kFile("kutyak.txt");
            kFile << kutyak;
            kFile.close();
        );

        // kiírás fájlba
        EXPECT_NO_THROW(
            std::ofstream mFile("macskak.txt");
            mFile << macskak;
            mFile.close();
        );

        // kiírás fájlba
        EXPECT_NO_THROW(
            std::ofstream pFile("papagajok.txt");
            pFile << papagajok;
            pFile.close();
        );
    }ENDM
}

/// TESZT 4.
void test_4() {
    TEST(Torles) {
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

        Kutya k3("Golden retriever", "Maszat", Datum(2019, 3, 22),
            Tulaj("Toth Alma", "2233 Ecser, Repa utca 23.", "06 70 636 5237"),
            "326981-BA", "feher alapon fekete pottyos", false);

        Kutya k4("Golden retriever", "Puszedli", Datum(2019, 3, 22),
            Tulaj("Toth Alma", "2233 Ecser, Repa utca 23.", "06 70 636 5237"),
            "326981-BA", "feher alapon fekete pottyos", false);

        kutyak.beszur(k);
        kutyak.beszur(k1);
        kutyak.beszur(k2);
        kutyak.beszur(k3);

        EXPECT_NO_THROW(kutyak.torol(k));   // első elem törlése
        EXPECT_NO_THROW(kutyak.torol(k2));  // közbenső elem törlése
        EXPECT_NO_THROW(kutyak.torol(k3));  // utolsó elem törlése
        EXPECT_ANY_THROW(kutyak.torol(k4)); // olyan elem törlése, ami nincs benne a listába

    }ENDM
}

/// TESZT 5.
void test_5() {
    TEST(Modositas) {
        Lista<Papagaj> papagajok;

        Papagaj p("Kaukazusi papagaj", "Molly", Datum(),
            Tulaj("Szabo Korte", "3366 Falva, Lanc utca 32.", "06 12 345 678"),
            "feher, kek szinu tollazat", true);

        Papagaj p1("Orias papagaj", "Molly", Datum(),
            Tulaj("Szabo Korte", "3366 Falva, Lanc utca 32.", "06 12 345 678"),
            "feher, kek szinu tollazat", true);

        Papagaj p2("Torpe papagaj", "Pici", Datum(2000, 1, 13),
            Tulaj("Alap Peti", "2233 Ecser, Repa utca 23..", "06 90 258 589"),
            "piros szinu tollazat", false);

        Papagaj p3("Orias papagaj", "Nina", Datum(2021, 4, 9),
            Tulaj("Szeder Villo", "8888 Csodafalva, Szep utca 7.", "06 12 345 678"),
            "fekete, feher tollazat", true);

        papagajok.beszur(p);
        papagajok.beszur(p1);
        papagajok.beszur(p2);

        EXPECT_NO_THROW(papagajok.modosit(p, p1));  // sikeres módosítás
        EXPECT_ANY_THROW(papagajok.modosit(p3, p)); // sikertelen módosítás

        // első elem módosításának ellenőrzése
        EXPECT_STREQ(papagajok.begin()->getNev().c_str(), p1.getNev().c_str());

    }ENDM
}

int main()
{
        test_1(); // létrehozás + beszúrás
        test_2(); // kiírás
        test_3(); // kiírás fájlba
        test_4(); // törlés
        test_5(); // módosítás
}
