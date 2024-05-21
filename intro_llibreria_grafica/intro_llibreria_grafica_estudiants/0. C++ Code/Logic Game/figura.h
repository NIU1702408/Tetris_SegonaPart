#ifndef FIGURA_H
#define FIGURA_H

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef struct
{
    int vertical;
    int horitzontal;
} Posicio;

typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    NO_COLOR
} ColorFigura;

typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,
} TipusFigura;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
public:
    Figura();
    Figura(TipusFigura figura);

    ColorFigura getColor() const { return m_color; }
    int getMida() const { return m_mida; }
    ColorFigura getFigura(const int& x, const int& y) const { return m_figura[x][y]; }
    Posicio getPosicio() const { return m_posicio; }
    void setPosicio(const Posicio& pos) { m_posicio = pos; }

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