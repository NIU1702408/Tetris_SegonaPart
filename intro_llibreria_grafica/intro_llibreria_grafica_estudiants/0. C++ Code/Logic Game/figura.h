#ifndef FIGURA_H
#define FIGURA_H
#include "InfoJoc.h"

IMAGE_NAME colorToPng(ColorFigura color);

class Figura
{
public:
    Figura();
    Figura(const TipusFigura& figura,const Posicio& pos,const int& numGir);
    void inicialitza(const TipusFigura& figura, const Posicio& pos, const int& numGir);

    ColorFigura getColor() const { return m_color; }
    int getMida() const { return m_mida; }
    ColorFigura getFigura(const int& x, const int& y) const { return m_figura[x][y]; }
    Posicio getPosicio() const { return m_posicio; }
    void setPosicio(const Posicio& pos) { m_posicio = pos; }

    void girar(const DireccioGir& gir);
    void baixar(const int& dirY) { m_posicio.vertical += dirY; }
    void desplacar(const int& dirX) { m_posicio.horitzontal += dirX; }

    void dibuixa(const bool& shadow) const;
    void dibuixaFiguraSmall(const int& posCua) const;

private:
    TipusFigura m_tipusFigura; //forma de la figura
    ColorFigura m_color;
    Posicio m_posicio;
    int m_mida;
    ColorFigura m_figura[MAX_ALCADA][MAX_AMPLADA]; //matriu amb la forma de la figura i color

};

#endif