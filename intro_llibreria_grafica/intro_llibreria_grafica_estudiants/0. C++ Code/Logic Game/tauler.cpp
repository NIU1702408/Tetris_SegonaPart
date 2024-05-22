#include "Tauler.h"

//Constructor predeterminat, inicialitza la matriu tauler amb el color negre
Tauler::Tauler()
{
	for (int i = 0; i < MAX_COL; i++)
		for (int j = 0; j < MAX_FILA; j++)
			m_tauler[i][j] = COLOR_NEGRE;
}

//inicialitza el tauler amb el tauler passat com a par�metre
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

//comprova si la posici� �s v�lida
bool Tauler::posicioValida(const Posicio& pos) const
{
	bool esValid = true;

	//verifica si la posici� est� dins els l�mits del tauler
	if (0 > pos.horitzontal || pos.horitzontal >= MAX_FILA || pos.vertical >= MAX_COL)
		esValid = false;
	else
	{
		//verifica si la posici� est� buida o t� un color que no sigui negre
		if (m_tauler[pos.vertical][pos.horitzontal] != COLOR_NEGRE)
			esValid = false;
	}

	return esValid;
}

//Comprova si el moviment d'una figura a una posici� determinada es v�lida
bool Tauler::esMovimentValid(const Figura& figura, const Posicio& pos) const
{
	bool esValid = true;
	int i = 0;

	//si esValid �s fals, s'interrumpen els dos bucles i es retorna esValid, sin� �s continuar� verificant que la posici� de la figura �s v�lida fins que es surti del bucle
	while (i < figura.getMida() && esValid)
	{
		int j = 0;
		while (j < figura.getMida() && esValid)
		{
			//si hi ha color, la celda  estar� ocupada per la figura amb la seva forma actual
			if (figura.getFigura(i, j) != NO_COLOR)
			{
				//es calcula la posici� temporal de la celda actual quan sumem la posici� actual amb les coordenades relatives dins la figura
				Posicio pos_tmp;
				pos_tmp.vertical = pos.vertical + i;
				pos_tmp.horitzontal = pos.horitzontal + j;

				//verifica si la posici� temporal calculada �s v�lida
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
			//si hi ha una casella de color negre, no estar� completa la celda
			if (m_tauler[i][j] == 0) {
				completa = false;
			}
			j++;
		}

		//si est� completa les files per sobre d'elles baixaran i s'afegir� una fila amb COLOR_NEGRE a la primera
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

//col�loca una figura en una posici� passada com a par�metre sense verificar si la posici� �s v�lida 
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
	//actualitza la posici� de la figura
	figura.setPosicio(pos);
}