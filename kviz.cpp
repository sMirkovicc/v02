#include <iostream>
#include <string>
#include <vector>
#include "kviz.h"


    Kviz::Kviz()
    {

    }
    
    Kviz::Kviz(int IDKviza, std::string NazivKviza, std::vector<Pitanje> KolekcijaPitanja)
    : m_IDKviza(IDKviza), m_NazivKviza(NazivKviza), m_KolekcijaPitanja(KolekcijaPitanja)
    {
        
    }

    Kviz::~Kviz()
    {
        //std::cout << "Destruktor klase Kviz pozvan\n";
    }

    Kviz::Kviz(const Kviz& original)
    : m_IDKviza(original.m_IDKviza), m_NazivKviza(original.m_NazivKviza), m_KolekcijaPitanja(original.m_KolekcijaPitanja)
    {
        
    }

    void Kviz::setIDKviza(int IDKviza)
    {
        m_IDKviza = IDKviza;
    }
    int Kviz::getIDKviza()
    {
        return m_IDKviza;
    }

    void Kviz::setNazivKviza(std::string NazivKviza)
    {
        m_NazivKviza = NazivKviza;
    }
    std::string Kviz::getNazivKviza()
    {
        return m_NazivKviza;
    }

    void Kviz::setKolekcijaPitanja(std::vector<Pitanje>& KolekcijaPitanja)
    {
        m_KolekcijaPitanja = KolekcijaPitanja;
    }
    std::vector<Pitanje> Kviz::getKolekcijaPitanja()
    {
        return m_KolekcijaPitanja;
    }
