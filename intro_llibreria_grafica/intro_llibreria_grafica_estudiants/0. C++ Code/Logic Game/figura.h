#ifndef FIGURA_H
#define FIGURA_H
#include "InfoJoc.h"

IMAGE_NAME colorToPng(ColorFigura color);

class Figura
{
public:
    Figura();
    Figura(TipusFigura figura);
    Figura(TipusFigura figura, Posicio posicio);

    ColorFigura getColor() const { return m_color; }
    int getMida() const { return m_mida; }
    ColorFigura getFigura(const int& x, const int& y) const { return m_figura[x][y]; }
    Posicio getPosicio() const { return m_posicio; }
    void setPosicio(const Posicio& pos) { m_posicio = pos; }

    void dibuixa() const;
    void incialitza(TipusFigura figura);
    void girar(const DireccioGir& gir);
    void baixar(const int& dirY);
    void desplacar(const int& dirX);
private:
    TipusFigura m_tipusFigura; //forma de la figura
    ColorFigura m_color;
    Posicio m_posicio;
    int m_mida;
    ColorFigura m_figura[MAX_ALCADA][MAX_AMPLADA]; //matriu amb la forma de la figura i color

};

#endif