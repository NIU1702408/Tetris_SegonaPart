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
    int getCentreFila() const { return m_centreFila; }
    int getCentreColumna() const { return m_centreColumna; }
    Posicio getPosicio() const { return m_posicio; }
    
    void setPosicio(const Posicio& pos) { m_posicio = pos; }
    void setTipus(const TipusFigura& tipus) { m_tipusFigura = tipus; }
    void setFila(const int& fila) { m_fila = fila; }
    void setColumna(const int& columna) { m_columna = columna; }
    void setGir(const int& gir) { m_gir = gir; }
    void setMoviment(const bool& moviment) { m_moviment = moviment; }

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
    int m_gir;
    bool m_moviment;
    ColorFigura m_figura[MAX_ALCADA][MAX_AMPLADA]; //matriu amb la forma de la figura i color
    int m_fila;
    int m_columna;

    const int m_centreFila = 1;
    const int m_centreColumna = 1;

};

ifstream& operator>>(ifstream& input, Figura& figura);

#endif
