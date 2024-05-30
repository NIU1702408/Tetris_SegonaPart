#ifndef PARTIDA_H
#define PARTIDA_H
#include "joc.h"

using namespace std;

class Partida 
{
public:
    Partida() : m_temps(0), m_speed(1.0), m_puntuacio(0), m_filesEliminades(0), m_nivell(0) , m_missatge(""), m_missatgeTemps(0)
    {
        srand(static_cast<unsigned>(time(0)));
        for (int i = 0; i < MAX_CUA + 1; i++)
            m_joc.novaFigura();
    };
    Partida(const string& nomFitxer) : m_temps(0), m_speed(1.0), m_puntuacio(0), m_filesEliminades(0), m_nivell(0), m_missatge(""), m_missatgeTemps(0)
        { m_joc.inicialitza(nomFitxer); }   

    void inicialitza(const string& nomFitxer) 
        { m_temps = 0; m_speed = 1.0; m_puntuacio = 0; m_filesEliminades = 0; m_nivell = 0; m_missatge = ""; m_missatgeTemps = 0;
        m_joc.inicialitza(nomFitxer); }
    void actualitza(double deltaTime);
private:
    void actualitzaValors();

    Joc m_joc;
    double m_temps;
    double m_speed;

    //registre de valors
    int m_puntuacio;
    int m_filesEliminades;
    int m_nivell;
    //imprimir missatges
    string m_missatge;
    long m_missatgeTemps;
};

#endif 
