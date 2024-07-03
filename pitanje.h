#include <iostream>
#ifndef PITANJE_H
#define PITANJE_H


class Pitanje
{
    int m_IDPitanja;
    int m_IDKviza;
    std::string m_Pitanje;
    std::string m_nizOdgovor[4];
    int m_TacanOdgovor;
    
 public:
    Pitanje();
    
    Pitanje(int IDPitanja, int IDKviza, std::string Pitanje, std::string nizOdgovor[4], int TacanOdgovor);

    ~Pitanje();

    Pitanje(const Pitanje& original);

    void setIDPitanja(int IDPitanja);
    int getIDPitanja();

    void setIDKviza(int IDKviza);
    int getIDKviza();

    void setPitanje(std::string Pitanje);
    std::string getPitanje();

    void setOdgovor(int i, std::string Odgovor);
    std::string getOdgovor(int i);

    bool setTacanOdgovor(int TacanOdgovor);
    int getTacanOdgovor();
};

#endif