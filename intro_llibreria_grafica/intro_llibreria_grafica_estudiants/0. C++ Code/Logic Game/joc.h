#ifndef JOC_H
#define JOC_H
#include "Tauler.h"

class Joc
{
public:
	Joc() { m_posicio.vertical = 0; m_posicio.horitzontal = 0; m_figuraCollocada = false; }
	void inicialitza(const string& nomFitxer);

	bool getFiguraCollocada() const { return m_figuraCollocada; }

	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();

	void novaFigura();
	void novaFigura(const Figura& figura);
	void escriuTauler(const string& nomFitxer);
	void dibuixa();
	bool comprovaGameOver() const;
private:
	void baixaShadow();
	void dibuixaCua();

	Tauler m_tauler;
	Figura m_figura;
	Figura m_cuaFigures[MAX_CUA];
	Figura m_shadow;
	Posicio m_posicio;
	bool m_figuraCollocada;
};

#endif