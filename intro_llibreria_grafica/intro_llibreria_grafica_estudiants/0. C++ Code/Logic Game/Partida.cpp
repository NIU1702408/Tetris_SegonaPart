#include "Partida.h"
#include "InfoJoc.h"
#include "GraphicManager.h"
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/keyboard_sdl.h"

void Partida::actualitza(double deltaTime)
{
    GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
    m_joc.dibuixa();

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
		{
			while (!m_joc.getFiguraCollocada())
				m_joc.baixaFigura();
		}

		m_temps += deltaTime;
		if (m_temps > 1.0)
		{
			m_joc.baixaFigura();
			m_temps = 0.0;
		}
	}
}