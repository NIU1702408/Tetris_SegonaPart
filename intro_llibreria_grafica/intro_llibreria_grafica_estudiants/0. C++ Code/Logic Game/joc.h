#ifndef JOC_H
#define JOC_H
#include "Tauler.h"

class Joc
{
public:
	Joc() { m_posicio.vertical = 0; m_posicio.horitzontal = 0; m_figuraCollocada = true; }
	bool getFiguraCollocada() const { return m_figuraCollocada; }
	Figura getFigura() const { return m_figura; }
	
	void novaFigura(const TipusFigura& tipus);
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);
	void dibuixa() const;
private:
	Tauler m_tauler;
	Figura m_figura;
	Posicio m_posicio;
	bool m_figuraCollocada;
};

#endif