#include <iostream>
#include <string>
#include <vector>
//#include "pitanje.h"
#include "kviz.h"
#include "sqlite3.h"


static int ucitajKviz(void* pok, int argc, char** argv, char** azColName)
{
    std::string odgovori[4] = {argv[3], argv[4], argv[5], argv[6]};
    Pitanje p(atoi(argv[0]), atoi(argv[1]), argv[2], odgovori, atoi(argv[7]));

    reinterpret_cast<std::vector<Pitanje>*>(pok)->emplace_back(p);

    return 0;
}


class Igra
{
    std::string ime;
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    const char *sql;
    std::vector<Pitanje> kolekcijaPitanja;
    int br_kviza;
    int odg;
    int tacni_odg = 0;

public:

    void izborKviza()
    {
        std::cout << "Unesite vase ime: ";
        std::cin >> ime;

        std::cout << "\nTrenutno dostupni kvizovi:" << std::endl;
        std::cout << "\t1. Formula 1" << std::endl;
        std::cout << "\t2. Filmovi" << std::endl;
        std::cout << "\t3. Muzika" << std::endl;
        std::cout << "\nIzaberite zeljeni kviz: ";
        std::cin >> br_kviza;
        std::cout << "\n";

        ucitavanje();
    }

    void ucitavanje()
    {
        
        switch (br_kviza)
        {
            case 1:
                //sql = "SELECT TekstPitanja, Odgovor1, Odgovor2, Odgovor3, Odgovor4, TacanOdgovor from pitanje where IDKviza=1";
                sql = "SELECT * from pitanje where IDKviza=1";
                std::cout << "Formula 1\n\n";
                break;
            case 2:
                //sql = "SELECT TekstPitanja, Odgovor1, Odgovor2, Odgovor3, Odgovor4, TacanOdgovor from pitanje where IDKviza=2";
                sql = "SELECT * from pitanje where IDKviza=2";
                std::cout << "Filmovi\n\n";
                break;
            case 3:
                //sql = "SELECT TekstPitanja, Odgovor1, Odgovor2, Odgovor3, Odgovor4, TacanOdgovor from pitanje where IDKviza=3";
                sql = "SELECT * from pitanje where IDKviza=3";
                std::cout << "Muzika\n\n";
                break;
        }

        rc = sqlite3_open("kviz.db", &db);

        rc = sqlite3_exec(db, sql, &ucitajKviz, static_cast<void*>(&kolekcijaPitanja), &zErrMsg);

        odgovaranje(kolekcijaPitanja, ime);
        
        sqlite3_close(db);
    }

    void odgovaranje(std::vector<Pitanje>& pitanje, std::string ime)
    {
        for(int i = 0; i < pitanje.size(); i++)
        {
            std::cout << "Pitanje " << i+1 << ":" << std::endl;
            std::cout << pitanje[i].getPitanje() << "\n\n";
            for (int j = 0; j < 4; j++)
            {
                std::cout << pitanje[i].getOdgovor(j) << std::endl;
            }
            std::cout << "\nVas odgovor: ";
            std::cin >> odg;
            std::cout << "\n";
            if(odg == pitanje[i].getTacanOdgovor())
            {
                tacni_odg++;
            }
        }
        std::cout << ime << " je pogodio " << tacni_odg << "/" << pitanje.size() << " pitanja." << std::endl;
    }
};

int main(int argc, char** argv)
{
    Igra kviz;
    kviz.izborKviza();



   /* Open database */
   //rc = sqlite3_open("kviz.db", &db);
   
   /*if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }*/

   /* Create SQL statement */
   /*switch (izborKviza())
   {
    case 1:
        sql = "SELECT TekstPitanja, Odgovor1, Odgovor2, Odgovor3, Odgovor4, TacanOdgovor from pitanje where IDKviza=1";
        break;
    case 2:
        sql = "SELECT TekstPitanja, Odgovor1, Odgovor2, Odgovor3, Odgovor4, TacanOdgovor from pitanje where IDKviza=2";
        break;
    case 3:
        sql = "SELECT TekstPitanja, Odgovor1, Odgovor2, Odgovor3, Odgovor4, TacanOdgovor from pitanje where IDKviza=3";
        break;
   }*/
   
   //sql = "SELECT * from pitanje";

   /* Execute SQL statement */
   //rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    
   /*if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Operation done successfully\n");
   }*/

   //sqlite3_close(db);

   return 0;
    
}