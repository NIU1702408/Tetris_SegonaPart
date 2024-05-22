#include "Tauler.h"

//Constructor predeterminat, inicialitza la matriu tauler amb el color negre
Tauler::Tauler()
{
	for (int i = 0; i < MAX_COL; i++)
		for (int j = 0; j < MAX_FILA; j++)
			m_tauler[i][j] = COLOR_NEGRE;
}

//inicialitza el tauler amb el tauler passat com a paràmetre
Tauler::Tauler(ColorFigura tauler[MAX_COL][MAX_FILA])
{
	for (int i = 0; i < MAX_COL; i++)
		for (int j = 0; j < MAX_FILA; j++)
			m_tauler[i][j] = tauler[i][j];
}

void Tauler::dibuixa() const
{
	for (int i = 0; i < N_FILES_TAULER; i++)
	{
		for (int j = 0; j < N_COL_TAULER; j++)
		{
			if (m_tauler[i][j] != COLOR_NEGRE)
			{
				IMAGE_NAME color = colorToPng(m_tauler[i][j]);
				GraphicManager::getInstance()->drawSprite(color,
					POS_X_TAULER + (j * MIDA_QUADRAT),
					POS_Y_TAULER + MIDA_QUADRAT * (i + 1), false);
			}
		}
	}
}

//comprova si la posició és vàlida
bool Tauler::posicioValida(const Posicio& pos) const
{
	bool esValid = true;

	//verifica si la posició està dins els límits del tauler
	if (0 > pos.horitzontal || pos.horitzontal >= MAX_FILA || pos.vertical >= MAX_COL)
		esValid = false;
	else
	{
		//verifica si la posició està buida o té un color que no sigui negre
		if (m_tauler[pos.vertical][pos.horitzontal] != COLOR_NEGRE)
			esValid = false;
	}

	return esValid;
}

//Comprova si el moviment d'una figura a una posició determinada es vàlida
bool Tauler::esMovimentValid(const Figura& figura, const Posicio& pos) const
{
	bool esValid = true;
	int i = 0;

	//si esValid és fals, s'interrumpen els dos bucles i es retorna esValid, sinó és continuará verificant que la posició de la figura és vàlida fins que es surti del bucle
	while (i < figura.getMida() && esValid)
	{
		int j = 0;
		while (j < figura.getMida() && esValid)
		{
			//si hi ha color, la celda  estarà ocupada per la figura amb la seva forma actual
			if (figura.getFigura(i, j) != NO_COLOR)
			{
				//es calcula la posició temporal de la celda actual quan sumem la posició actual amb les coordenades relatives dins la figura
				Posicio pos_tmp;
				pos_tmp.vertical = pos.vertical + i;
				pos_tmp.horitzontal = pos.horitzontal + j;

				//verifica si la posició temporal calculada és vàlida
				esValid = posicioValida(pos_tmp);
			}
			j++;
		}
		i++;
	}

	return esValid;
}

//busca i elimina les files completades 
int Tauler::eliminarFilesCompletades()
{
	int nCompletades = 0;

	// Comprovar totes les files i buscar las filas completadas
	for (int i = 0; i < MAX_FILA; ++i)
	{
		bool completa = true;
		int j = 0;

		while (j < MAX_COL&& completa)
		{
			//si hi ha una casella de color negre, no estarà completa la celda
			if (m_tauler[i][j] == 0) {
				completa = false;
			}
			j++;
		}

		//si està completa les files per sobre d'elles baixaran i s'afegirà una fila amb COLOR_NEGRE a la primera
		if (completa)
		{
			nCompletades++;
			for (int fila = i; fila > 0; --fila)
				for (int k = 0; k < MAX_COL; ++k)
					m_tauler[fila][k] = m_tauler[fila - 1][k];

			for (int k = 0; k < MAX_COL; ++k)
				m_tauler[0][k] = COLOR_NEGRE;
		}

	}
	return nCompletades;
}

//elimina una figura del tauler
void Tauler::eliminarFigura(Figura figura, const Posicio& pos)
{
	//estableix de COLOR_NEGRE (buides) les celdes ocupades per la figura
	for (int i = 0; i < figura.getMida(); i++)
		for (int j = 0; j < figura.getMida(); j++)
			if (figura.getFigura(i, j) != NO_COLOR)
			{
				m_tauler[pos.vertical + i][pos.horitzontal + j] = COLOR_NEGRE;
			}
}

//col·loca una figura en una posició passada com a paràmetre sense verificar si la posició és vàlida 
void Tauler::collocarFigura(Figura figura, const Posicio& pos) // no comprovo si es valid
{
	for (int i = 0; i < figura.getMida(); i++)
		for (int j = 0; j < figura.getMida(); j++)
		{
			//estableix el color de la figura en el tauler
			if (figura.getFigura(i, j) != NO_COLOR)
			{
				m_tauler[pos.vertical + i][pos.horitzontal + j] = figura.getColor();
			}
		}
	//actualitza la posició de la figura
	figura.setPosicio(pos);
}