#include <iostream>
#include "pitanje.h"
#include <vector>
#ifndef KVIZ_H
#define KVIZ_H

class Kviz
{
    int m_IDKviza;
    std::string m_NazivKviza;
    std::vector<Pitanje> m_KolekcijaPitanja;


 public:
    Kviz();
    
    Kviz(int IDKviza, std::string NazivKviza, std::vector<Pitanje> KolekcijaPitanja);

    ~Kviz();

    Kviz(const Kviz& original);

    void setIDKviza(int IDKviza);
    int getIDKviza();

    void setNazivKviza(std::string NazivKviza);
    std::string getNazivKviza();

    void setKolekcijaPitanja(std::vector<Pitanje>& KolekcijaPitanja);
    std::vector<Pitanje> getKolekcijaPitanja();

};

#endif