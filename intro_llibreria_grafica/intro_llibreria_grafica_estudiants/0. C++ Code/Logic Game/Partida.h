#ifndef PARTIDA_H
#define PARTIDA_H
#include "joc.h"

using namespace std;

class Partida
{
public:
    Partida() : m_temps(0), m_speed(1.0), m_puntuacio(0), m_filesEliminades(0), m_nivell(1), m_missatge(""), m_missatgeTemps(0) {};
    int getPuntuacio() const { return m_puntuacio; }

    void inicialitza(const OpcioMenu& mode, const string& fitxerTauler, const string& fitxerFigures, const string& fitxerMoviments);
    void actualitza(double deltaTime, bool gameOver);
private:
    void inicialitzaFigures(const string& fitxerFigures);
    void inicialitzaMoviments(const string& fitxerMoviments);
    void actualitzaValors();
    void actualitzaFiles(const int& files);
    void dibuixaPartida();

    Joc m_joc;
    OpcioMenu m_mode;
    double m_temps;
    double m_speed;

    //cua de figures i moviments pel metode test
    CuaFigura* m_figuraNodes;
    CuaMoviment* m_movimentNodes;

    //registre de valors
    int m_puntuacio;
    int m_filesEliminades;
    int m_nivell;
    //imprimir missatges
    string m_missatge;
    long m_missatgeTemps;
};

#endif 
