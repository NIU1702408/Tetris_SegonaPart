#pragma once
#ifndef TETRIS_H
#define TETRIS_H
#include "Partida.h"

class Tetris
{
public:
	Tetris() { m_puntuacioActual.jugador = ""; m_puntuacioActual.xifra = 0; }

	void mostraPuntuacions() const;
	void juga(const OpcioMenu& mode);

private:
	void inicialitzaNormal();
	void inicialitzaTest();
	void actualitzaPuntuacio();

	Partida m_joc;
	Puntuacio m_puntuacioActual;
	vector<int> m_puntuacions;
};



#endif
