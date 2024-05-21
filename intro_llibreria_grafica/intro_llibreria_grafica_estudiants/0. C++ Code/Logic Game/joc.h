#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include "Figura.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Joc
{
public:
	Joc() { m_posicio.vertical = 0; m_posicio.horitzontal = 0; m_figuraCollocada = false; }
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);

private:
	Tauler m_tauler;
	Figura m_figura;
	Posicio m_posicio;
	bool m_figuraCollocada;
};

#endif