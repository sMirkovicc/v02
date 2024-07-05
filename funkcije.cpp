#include <iostream>
#include <string>
#include <vector>
#include "kviz.h"
#include "sqlite3.h"
#include "igra.h"
#include "funkcije.h"

namespace funkcije
{
    int ispisiKvizove(void* pok, int argc, char** argv, char** azColName)
    {
        std::cout << *argv << std::endl; 
        
        return 0;
    }

    int ucitajPitanja(void* pok, int argc, char** argv, char** azColName)
    {
        std::string odgovori[4] = {argv[3], argv[4], argv[5], argv[6]};
        Pitanje p(atoi(argv[0]), atoi(argv[1]), argv[2], odgovori, atoi(argv[7]));

        reinterpret_cast<std::vector<Pitanje>*>(pok)->emplace_back(p);

        return 0;
    }

    int ucitajKviz(void* pok, int argc, char** argv, char** azColName)
    {
        reinterpret_cast<Kviz*>(pok)->setIDKviza(atoi(argv[0]));
        reinterpret_cast<Kviz*>(pok)->setNazivKviza(argv[1]);

        return 0;
    }
}