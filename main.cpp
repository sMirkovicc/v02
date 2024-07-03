#include <iostream>
#include <string>
#include <vector>
//#include "pitanje.h"
#include "kviz.h"
#include "sqlite3.h"

static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    static int j = 0;
    std::string odg;
    static int tacni_odg = 0;
    //std::cout << data << std::endl;
    std::cout << "Pitanje " << j + 1 << ":" << std::endl;
    j++;
    //fprintf(stderr, "%s: ", (const char*)data);
    
    //Pitanje* pitanje = new Pitanje(argv[0], argv[1], argv[2], odgovori, argv[7]);
    //std::string odgovori[4] = {argv[3], argv[4], argv[5], argv[6]};
    //Pitanje* pitanje = new Pitanje(atoi(argv[0]), atoi(argv[1]), argv[2], odgovori, atoi(argv[7]));

    //std::cout << "Tacan odgovor: " << pitanje->getTacanOdgovor() << std::endl;
    //int id = atoi(argv[0]);
    //std::cout << id << std::endl;
    
    for (i = 0; i < argc-1; i++) {
        printf("%s\n", argv[i] ? argv[i] : "NULL");
        
        
    }

    
    printf("\n");
    std::cout << "Vas odgovor: ";
    std::cin >> odg;
    std::cout << "\n";
    //printf("%s\n", argv[argc-1]);
    if (odg == argv[argc-1])
    {
        tacni_odg++;
    }

    if(j == 7)
    {
        std::cout << (const char*)data << " je pogodio " << tacni_odg << "/7" << " pitanja" << std::endl;
    }

    /*std::cout << "tacni odgovori:" << tacni_odg << std::endl;

    if (argc == 6)
    {
        std::cout << tacni_odg << "/7 tacnih odgovora\n";
    }*/

    return 0;
}

int izborKviza()
{
    int br_kviza;

    std::cout << "\nTrenutno dostupni kvizovi:" << std::endl;
    std::cout << "\t1. Formula 1" << std::endl;
    std::cout << "\t2. Filmovi" << std::endl;
    std::cout << "\t3. Muzika" << std::endl;
    std::cout << "\nIzaberite zeljeni kviz: ";
    std::cin >> br_kviza;
    std::cout << "\n";

    return br_kviza;
}

int main(int argc, char** argv)
{

    /*std::string proba[4] = {"a", "b", "c", "d"};
    Pitanje pitanje1(1, 1, "pitanje", proba, 2);
    Pitanje pitanje2(pitanje1);
    std::vector<Pitanje> kolekcijaPitanja;
    kolekcijaPitanja.emplace_back(pitanje1);
    kolekcijaPitanja.emplace_back(pitanje2);
    Kviz kviz1(1, "kviz", kolekcijaPitanja);*/

    std::string ime;

    std::cout << "Unesite vase ime: ";
    std::cin >> ime;

    //Pitanje* pitanje = new Pitanje;

    sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   const char *sql;
   const char *sql1;
   int i = 0;
   //const char* data = "Callback function called";
   //const char* data = (const char*)pitanje;
   const char* data = ime.c_str();


   /* Open database */
   rc = sqlite3_open("kviz.db", &db);
   
   /*if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }*/

   /* Create SQL statement */
   switch (izborKviza())
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
   }
   
   //sql = "SELECT * from pitanje";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    
   
   /*if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Operation done successfully\n");
   }*/

    

   sqlite3_close(db);
   return 0;

    /*//Kviz kviz2(kviz1);
    //std::cout << "ID pitanja: " << pitanje2.getIDPitanja() << std::endl;
    std::cout << "ID kviza: " << kviz1.getIDKviza() << std::endl;
    std::cout << "Naziv kviza: " << kviz1.getNazivKviza() << std::endl;
    for(int i = 0; i < kolekcijaPitanja.size(); i++)
    {
        std::cout << "Pitanja: " << kolekcijaPitanja[i].getPitanje() << std::endl;
    }
    /*for(int i = 0; i < 4; i++)
    {
        std::cout << "Odgovor " << i+1 << ": " << pitanje2.getOdgovor(i) << std::endl;
    }
    std::cout << "Tacan odgovor: " << pitanje2.getTacanOdgovor() << std::endl;*/
    
    
}