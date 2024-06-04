#include "Partida.h"

void Partida::inicialitza(const OpcioMenu& mode, const string& fitxerTauler, const string& fitxerFigures, const string& fitxerMoviments)
{
	m_mode = mode;
	if (mode == NORMAL)
	{
		// Inicialitza el generador de nums aleatoris amb una seed del temps actual
		srand(static_cast<unsigned>(time(0)));

		// Inicialitza la cua (3 figures) i la figura actual
		for (int i = 0; i < MAX_CUA + 1; i++)
			m_joc.novaFigura();
	}
	else
	{
		m_joc.inicialitza(fitxerTauler);

		//inicialitzaFigures(fitxerFigures);
		//inicialitzaMoviments(fitxerMoviments);
	}
}

void Partida::actualitzaValors()
{
	// +10 per figura collocada
	m_puntuacio += 10;

	// Cada 1000 punts es 1 nivell més (faig + 1 pq comença al nivell 1)
	m_nivell = int((m_puntuacio / 1000) + 1);

	// Augmenta 0.1 la velocitat per cada nivell
	m_speed = 1.0;
	for (int i = 0; i < m_nivell; i++)
		m_speed /= 1.1;
}

void Partida::actualitzaFiles(const int& files)
{
	if (files > 0)
	{
		m_filesEliminades += files;
		m_puntuacio += files * 100;
		m_missatgeTemps = time(0);
		switch (files)
		{
		case 1:	m_missatge = "s i n g l e";
			break;
		case 2:	m_puntuacio += 50; m_missatge = "D 0 0 b l e !";
			break;
		case 3:	m_puntuacio += 75; m_missatge = "T r i p l e ! ! :D";
			break;
		case 4:	m_puntuacio += 100; m_missatge = "T E T R I S ! ! !";
			break;
		}
	}
}

void Partida::dibuixaPartida()
{
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
	m_joc.dibuixa();

	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 105, 1.0, "Puntuacio: " + to_string(m_puntuacio));
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 75, 1.0, "Files: " + to_string(m_filesEliminades));
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 45, 1.0, "Nivell: " + to_string(m_nivell));

	if (m_missatgeTemps)
	{
		if (time(0) - m_missatgeTemps < TEMPS_MISSATGE)
			GraphicManager::getInstance()->drawFont(FONT_RED_30, POS_X_TAULER + 250, POS_Y_TAULER - 75, 1.0, m_missatge);
		else
			m_missatgeTemps = 0;
	}
}

void Partida::actualitza(double deltaTime, bool gameOver)
{
	dibuixaPartida();
	if (m_mode == NORMAL)
	{
		if (!m_joc.getFiguraCollocada())
		{
			// aquests metodes s'aciven si es prem la tecla corresponent
			if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
				m_joc.mouFigura(1);
			if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
				m_joc.mouFigura(-1);
			if (Keyboard_GetKeyTrg(KEYBOARD_UP))
				m_joc.giraFigura(GIR_HORARI);
			if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
				m_joc.giraFigura(GIR_ANTI_HORARI);
			if (Keyboard_GetKeyTrg(KEYBOARD_SPACE))
				m_speed = 0.001;

			// el metode baixaFigura es automatic i depen de m_speed
			m_temps += deltaTime;
			if (m_temps > m_speed)
			{
				// actualitza les files eliminades despres de baixar una posicio la figura
				actualitzaFiles(m_joc.baixaFigura());
				m_temps = 0.0;
			}
		}
		else
		{
			m_joc.novaFigura();
			actualitzaValors();
		}
	}
	else
	{
		/*
		if (!m_joc.getFiguraCollocada())
		{

		}
		else
		{
			m_joc.novaFigura(m_nextFigura);
			actualitzaValors();
		}*/
	}
	gameOver = m_joc.comprovaGameOver();
}