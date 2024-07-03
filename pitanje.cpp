#include <iostream>
#include <string>
#include "pitanje.h"



    Pitanje::Pitanje()
    {

    }

    Pitanje::Pitanje(int IDPitanja, int IDKviza, std::string Pitanje, std::string nizOdgovor[4], int TacanOdgovor)
    : m_IDPitanja(IDPitanja), m_IDKviza(IDKviza), m_Pitanje(Pitanje), m_TacanOdgovor(TacanOdgovor)
    {
        for(int i = 0; i < 4; i++)
        {
            m_nizOdgovor[i] = nizOdgovor[i];
        }
    }

    Pitanje::~Pitanje()
    {
        //std::cout << "Destruktor klase Pitanje pozvan\n";
    }

    Pitanje::Pitanje(const Pitanje& original)
    : m_IDPitanja(original.m_IDPitanja), m_IDKviza(original.m_IDKviza), m_Pitanje(original.m_Pitanje), m_TacanOdgovor(original.m_TacanOdgovor)
    {
        for(int i = 0; i < 4; i++)
        {
            m_nizOdgovor[i] = original.m_nizOdgovor[i];
        }
    }

    void Pitanje::setIDPitanja(int IDPitanja)
    {
        m_IDPitanja = IDPitanja;
    }
    int Pitanje::getIDPitanja()
    {
        return m_IDPitanja;
    }

    void Pitanje::setIDKviza(int IDKviza)
    {
        m_IDKviza = IDKviza;
    }
    int Pitanje::getIDKviza()
    {
        return m_IDKviza;
    }

    void Pitanje::setPitanje(std::string Pitanje)
    {
        m_Pitanje = Pitanje;
    }
    std::string Pitanje::getPitanje()
    {
        return m_Pitanje;
    }

    void Pitanje::setOdgovor(int i, std::string Odgovor)
    {
        m_nizOdgovor[i] = Odgovor;
    }
    std::string Pitanje::getOdgovor(int i)
    {
        return m_nizOdgovor[i];
    }

    bool Pitanje::setTacanOdgovor(int TacanOdgovor)
    {
        if(TacanOdgovor > 0 && TacanOdgovor < 5)
        {
            m_TacanOdgovor = TacanOdgovor;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int Pitanje::getTacanOdgovor()
    {
        return m_TacanOdgovor;
    }
