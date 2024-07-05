#include <iostream>
#include <string>
#include <vector>
#include "kviz.h"
#include "sqlite3.h"


static int ispisiKvizove(void* pok, int argc, char** argv, char** azColName)
{
    std::cout << *argv << std::endl; 
    
    return 0;
}

static int ucitajPitanja(void* pok, int argc, char** argv, char** azColName)
{
    std::string odgovori[4] = {argv[3], argv[4], argv[5], argv[6]};
    Pitanje p(atoi(argv[0]), atoi(argv[1]), argv[2], odgovori, atoi(argv[7]));

    reinterpret_cast<std::vector<Pitanje>*>(pok)->emplace_back(p);

    return 0;
}

static int ucitajKviz(void* pok, int argc, char** argv, char** azColName)
{
    reinterpret_cast<Kviz*>(pok)->setIDKviza(atoi(argv[0]));
    reinterpret_cast<Kviz*>(pok)->setNazivKviza(argv[1]);

    return 0;
}


class Igra
{
    std::string ime;
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    std::string sql;
    Kviz kviz;
    Kviz* ptrKviz = &kviz;
    std::vector<Pitanje> kolekcijaPitanja;
    std::string br_kviza;
    int odg;
    int tacni_odg = 0;

public:

    void izborKviza()
    {
        std::cout << "Unesite vase ime: ";
        std::cin >> ime;

        std::cout << "\nTrenutno dostupni kvizovi:" << std::endl;

        rc = sqlite3_open("kviz.db", &db);

        rc = sqlite3_exec(db, "SELECT Naziv from kviz", &ispisiKvizove, NULL, &zErrMsg);

        std::cout << "\nIzaberite zeljeni kviz: ";
        std::cin >> br_kviza;
        std::cout << "\n";

        ucitavanje();
    }

    void ucitavanje()
    {
        sql = "SELECT * from kviz where IDKviza=" + br_kviza;
        
        rc = sqlite3_exec(db, sql.c_str(), &ucitajKviz, static_cast<void*>(ptrKviz), &zErrMsg);
        
        sql = "SELECT * from pitanje where IDKviza=" + br_kviza;

        rc = sqlite3_exec(db, sql.c_str(), &ucitajPitanja, static_cast<void*>(&kolekcijaPitanja), &zErrMsg);

        ptrKviz->setKolekcijaPitanja(kolekcijaPitanja);

        odgovaranje();
        
        sqlite3_close(db);
    }

    void odgovaranje()
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
    }
};

int main(int argc, char** argv)
{
    Igra kviz;
    kviz.izborKviza();


   return 0;
    
}