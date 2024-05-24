#ifndef PARTIDA_H
#define PARTIDA_H
#include "joc.h"

using namespace std;

class Partida 
{
public:
    Partida() : m_temps(0) {};
    Partida(const string& nomFitxer) : m_temps(0) { m_joc.inicialitza(nomFitxer); }

    void inicialitza(const string& nomFitxer) { m_temps = 0; m_joc.inicialitza(nomFitxer); }
    void actualitza(double deltaTime);
private:
    double m_temps;
    Joc m_joc;
};

#endif 
