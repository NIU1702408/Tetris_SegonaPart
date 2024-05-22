#include "Partida.h"
#include "InfoJoc.h"
#include "GraphicManager.h"
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/keyboard_sdl.h"

void Partida::actualitza(double deltaTime)
{
    Figura figura(FIGURA_S);

    GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
    figura.dibuixa();
    
}

