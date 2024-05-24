#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

class Tauler
{
public:
	Tauler();
	Tauler(ColorFigura tauler[N_FILES_TAULER][N_COL_TAULER]);

	ColorFigura getTauler(const int& x, const int& y) const { return m_tauler[x][y]; }
	void setTauler(ColorFigura color, int posX, int posY) { m_tauler[posX][posY] = color; }

	void dibuixa() const;
	bool esMovimentValid(const Figura& figura, const Posicio& pos) const;
	int eliminarFilesCompletades();
	void eliminarFigura(Figura figura, const Posicio& pos);
	void collocarFigura(Figura figura, const Posicio& pos);
private:
	bool posicioValida(const Posicio& pos) const;

	ColorFigura m_tauler[N_FILES_TAULER][N_COL_TAULER];
};
#endif