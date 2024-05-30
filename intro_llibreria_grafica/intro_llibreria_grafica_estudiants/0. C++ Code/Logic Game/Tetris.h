#pragma once
#ifndef TETRIS_H
#define TETRIS_H
#include "Partida.h"
#include <vector>

typedef enum
{
	NORMAL = 1,
	TEST,
	PUNTUACIONS,
	SORTIR
} OpcioMenu;

class Tetris
{
public:
	Tetris(): m_puntuacioActual(0) {};

	void mostraPuntuacions() const;
	void juga(const OpcioMenu& mode);

private:
	void inicialitzaNormal() { string fitxer; m_joc.inicialitza(fitxer); }
	void inicialitzaTest();
	void finalitzaNormal();
	void actualitzaPuntuacio(const string& nomJugador);

	Partida m_joc;
	int m_puntuacioActual;
	vector<int> m_puntuacions;
};


#endif
