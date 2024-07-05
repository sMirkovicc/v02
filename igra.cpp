#include <iostream>
#include <string>
#include "igra.h"
#include "kviz.h"
#include "funkcije.h"

    void Igra::izborKviza()
    {
        std::cout << "Unesite vase ime: ";
        std::cin >> ime;

        std::cout << "\nTrenutno dostupni kvizovi:" << std::endl;

        rc = sqlite3_open("kviz.db", &db);

        rc = sqlite3_exec(db, "SELECT Naziv from kviz", funkcije::ispisiKvizove, NULL, &zErrMsg);

        std::cout << "\nIzaberite zeljeni kviz: ";
        std::cin >> br_kviza;
        std::cout << "\n";

        ucitavanje();
    }

    void Igra::ucitavanje()
    {
        sql = "SELECT * from kviz where IDKviza=" + br_kviza;

        ptrKviz = new Kviz;
        
        rc = sqlite3_exec(db, sql.c_str(), funkcije::ucitajKviz, static_cast<void*>(ptrKviz), &zErrMsg);
        
        sql = "SELECT * from pitanje where IDKviza=" + br_kviza;

        rc = sqlite3_exec(db, sql.c_str(), funkcije::ucitajPitanja, static_cast<void*>(&kolekcijaPitanja), &zErrMsg);

        ptrKviz->setKolekcijaPitanja(kolekcijaPitanja);

        odgovaranje();
        
        sqlite3_close(db);
    }

    void Igra::odgovaranje()
    {
        std::cout << ptrKviz->getNazivKviza() << std::endl;
        std::cout << "\n";

        for(int i = 0; i < ptrKviz->getKolekcijaPitanja().size(); i++)
        {
            std::cout << "Pitanje " << i+1 << ":" << std::endl;
            std::cout << ptrKviz->getKolekcijaPitanja()[i].getPitanje() << "\n\n";
            for (int j = 0; j < 4; j++)
            {
                std::cout << ptrKviz->getKolekcijaPitanja()[i].getOdgovor(j) << std::endl;
            }
            std::cout << "\nVas odgovor: ";
            std::cin >> odg;
            std::cout << "\n";
            if(odg == ptrKviz->getKolekcijaPitanja()[i].getTacanOdgovor())
            {
                tacni_odg++;
            }
        }
        std::cout << ime << " je pogodio " << tacni_odg << "/" << ptrKviz->getKolekcijaPitanja().size() << " pitanja." << std::endl;

        delete ptrKviz;
    }
