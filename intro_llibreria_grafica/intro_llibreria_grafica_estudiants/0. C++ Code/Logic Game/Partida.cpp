#include "Partida.h"

void Partida::actualitzaValors()
{
	m_puntuacio += 10;

	m_nivell = int(m_puntuacio / 1000);

	m_speed = 1.0;
	for (int i = 0; i < m_nivell; i++)
		m_speed /= 1.1;
}

void Partida::actualitza(double deltaTime)
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

	if (!m_joc.getFiguraCollocada())
	{
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

		//if (Keyboard_ProcessKeyDown(KEYBOARD_Q))

		m_temps += deltaTime;
		if (m_temps > m_speed)
		{
			int files = 0;
			files = m_joc.baixaFigura();
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
			m_temps = 0.0;
		}
	}
	else
	{
		m_joc.novaFigura();
		actualitzaValors();
	}
}