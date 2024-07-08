#include "sqlite3.h"
#include "kviz.h"
#ifndef IGRA_H
#define IGRA_H

class Igra
{
    std::string ime;
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    std::string sql;
    Kviz* ptrKviz;
    std::vector<Pitanje> kolekcijaPitanja;
    std::string br_kviza;
    int odg;
    int tacni_odg = 0;

public:

    void izborKviza();

    void ucitavanje();

    void odgovaranje();
};

#endif