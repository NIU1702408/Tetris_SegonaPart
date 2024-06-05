#include "Figura.h"

//Constructor predeterminat de Figura, inicialitza totes les dades de la classe
Figura::Figura()
{
	m_mida = 0;
	m_fila = -1;
	m_columna = -1;
	m_gir = 0;
	m_color = NO_COLOR;
	m_tipusFigura = NO_FIGURA;
	m_posicio.vertical = 0;
	m_posicio.horitzontal = 0;
	m_moviment = true;
	for (int i = 0; i < MAX_ALCADA; i++)
		for (int j = 0; j < MAX_AMPLADA; j++)
			m_figura[i][j] = NO_COLOR;

}

//Constructor que inicialitza una figura concreta (O,I,T...)
Figura::Figura(const TipusFigura& figura, const Posicio& pos, const int& numGir)
{
	m_mida = 0;
	m_tipusFigura = figura;
	m_posicio = pos;

	//inicialitzem matriu de la figura
	for (int i = 0; i < MAX_ALCADA; i++)
		for (int j = 0; j < MAX_AMPLADA; j++)
			m_figura[i][j] = NO_COLOR;

	//configurem la mida i matriu de la figura segons el tipus
	switch (m_tipusFigura)
	{
	case FIGURA_O:
		m_mida = 2;
		m_color = COLOR_GROC;
		m_figura[0][0] = COLOR_GROC;
		m_figura[0][1] = COLOR_GROC;
		m_figura[1][0] = COLOR_GROC;
		m_figura[1][1] = COLOR_GROC;
		break;
	case FIGURA_I:
		m_mida = 4;
		m_color = COLOR_BLAUCEL;
		m_figura[1][0] = COLOR_BLAUCEL;
		m_figura[1][1] = COLOR_BLAUCEL;
		m_figura[1][2] = COLOR_BLAUCEL;
		m_figura[1][3] = COLOR_BLAUCEL;
		break;
	case FIGURA_T:
		m_mida = 3;
		m_color = COLOR_MAGENTA;
		m_figura[0][1] = COLOR_MAGENTA;
		m_figura[1][0] = COLOR_MAGENTA;
		m_figura[1][1] = COLOR_MAGENTA;
		m_figura[1][2] = COLOR_MAGENTA;
		break;
	case FIGURA_L:
		m_mida = 3;
		m_color = COLOR_TARONJA;
		m_figura[0][1] = COLOR_TARONJA;
		m_figura[1][1] = COLOR_TARONJA;
		m_figura[2][1] = COLOR_TARONJA;
		m_figura[2][2] = COLOR_TARONJA;
		break;
	case FIGURA_J:
		m_mida = 3;
		m_color = COLOR_BLAUFOSC;
		m_figura[0][1] = COLOR_BLAUFOSC;
		m_figura[1][1] = COLOR_BLAUFOSC;
		m_figura[2][0] = COLOR_BLAUFOSC;
		m_figura[2][1] = COLOR_BLAUFOSC;
		break;
	case FIGURA_Z:
		m_mida = 3;
		m_color = COLOR_VERMELL;
		m_figura[0][0] = COLOR_VERMELL;
		m_figura[0][1] = COLOR_VERMELL;
		m_figura[1][1] = COLOR_VERMELL;
		m_figura[1][2] = COLOR_VERMELL;
		break;
	case FIGURA_S:
		m_mida = 3;
		m_color = COLOR_VERD;
		m_figura[0][1] = COLOR_VERD;
		m_figura[0][2] = COLOR_VERD;
		m_figura[1][0] = COLOR_VERD;
		m_figura[1][1] = COLOR_VERD;
		break;
	}

	//gira la figura en sentit horari el nombre de vegades que indica la variable
	for (int i = 0; i < numGir; i++)
		girar(GIR_HORARI);
}

//Inicialitza una figura com amb el constructor, però permet reinicialitzar una figura existent amb un nou tipus
void Figura::inicialitza(const TipusFigura& figura, const Posicio& pos, const int& numGir)
{
	m_mida = 0;
	m_tipusFigura = figura;
	m_posicio = pos;

	//inicialitzem matriu de la figura
	for (int i = 0; i < MAX_ALCADA; i++)
		for (int j = 0; j < MAX_AMPLADA; j++)
			m_figura[i][j] = NO_COLOR;

	//configurem la mida i matriu de la figura segons el tipus
	switch (m_tipusFigura)
	{
	case FIGURA_O:
		m_mida = 2;
		m_color = COLOR_GROC;
		m_figura[0][0] = COLOR_GROC;
		m_figura[0][1] = COLOR_GROC;
		m_figura[1][0] = COLOR_GROC;
		m_figura[1][1] = COLOR_GROC;
		break;
	case FIGURA_I:
		m_mida = 4;
		m_color = COLOR_BLAUCEL;
		m_figura[1][0] = COLOR_BLAUCEL;
		m_figura[1][1] = COLOR_BLAUCEL;
		m_figura[1][2] = COLOR_BLAUCEL;
		m_figura[1][3] = COLOR_BLAUCEL;
		break;
	case FIGURA_T:
		m_mida = 3;
		m_color = COLOR_MAGENTA;
		m_figura[0][1] = COLOR_MAGENTA;
		m_figura[1][0] = COLOR_MAGENTA;
		m_figura[1][1] = COLOR_MAGENTA;
		m_figura[1][2] = COLOR_MAGENTA;
		break;
	case FIGURA_L:
		m_mida = 3;
		m_color = COLOR_TARONJA;
		m_figura[0][1] = COLOR_TARONJA;
		m_figura[1][1] = COLOR_TARONJA;
		m_figura[2][1] = COLOR_TARONJA;
		m_figura[2][2] = COLOR_TARONJA;
		break;
	case FIGURA_J:
		m_mida = 3;
		m_color = COLOR_BLAUFOSC;
		m_figura[0][1] = COLOR_BLAUFOSC;
		m_figura[1][1] = COLOR_BLAUFOSC;
		m_figura[2][0] = COLOR_BLAUFOSC;
		m_figura[2][1] = COLOR_BLAUFOSC;
		break;
	case FIGURA_Z:
		m_mida = 3;
		m_color = COLOR_VERMELL;
		m_figura[0][0] = COLOR_VERMELL;
		m_figura[0][1] = COLOR_VERMELL;
		m_figura[1][1] = COLOR_VERMELL;
		m_figura[1][2] = COLOR_VERMELL;
		break;
	case FIGURA_S:
		m_mida = 3;
		m_color = COLOR_VERD;
		m_figura[0][1] = COLOR_VERD;
		m_figura[0][2] = COLOR_VERD;
		m_figura[1][0] = COLOR_VERD;
		m_figura[1][1] = COLOR_VERD;
		break;
	}

	//gira la figura en sentit horari el nombre de vegades que indica la variable
	for (int i = 0; i < numGir; i++)
		girar(GIR_HORARI);
}

Figura& Figura::operator=(const Figura& other) {
	if (this != &other) { // Comprova l'autoassignació
		// Assigna els valors dels membres de dades
		m_mida = other.m_mida;
		m_fila = other.m_fila;
		m_columna = other.m_columna;
		m_gir = other.m_gir;
		m_color = other.m_color;
		m_tipusFigura = other.m_tipusFigura;
		m_posicio = other.m_posicio;
		m_moviment = other.m_moviment;

		// Copia profunda de la matriu m_figura
		for (int i = 0; i < MAX_ALCADA; ++i) {
			for (int j = 0; j < MAX_AMPLADA; ++j) {
				m_figura[i][j] = other.m_figura[i][j];
			}
		}
	}
	return *this;
}

IMAGE_NAME colorToPng(ColorFigura color)
{
	switch (color)
	{
	case COLOR_GROC:    return GRAFIC_QUADRAT_GROC;
		break;
	case COLOR_BLAUCEL: return GRAFIC_QUADRAT_BLAUCEL;
		break;
	case COLOR_BLAUFOSC:return GRAFIC_QUADRAT_BLAUFOSC;
		break;
	case COLOR_MAGENTA: return GRAFIC_QUADRAT_MAGENTA;
		break;
	case COLOR_TARONJA: return GRAFIC_QUADRAT_TARONJA;
		break;
	case COLOR_VERD:    return GRAFIC_QUADRAT_VERD;
		break;
	case COLOR_VERMELL: return GRAFIC_QUADRAT_VERMELL;
		break;
	default:    return GRAFIC_FONS;
		break;
	}
}

IMAGE_NAME colorToPng_shadow(ColorFigura color)
{
	switch (color)
	{
	case COLOR_GROC:    return GRAFIC_QUADRAT_GROC_SHADOW;
		break;
	case COLOR_BLAUCEL: return GRAFIC_QUADRAT_BLAUCEL_SHADOW;
		break;
	case COLOR_BLAUFOSC:return GRAFIC_QUADRAT_BLAUFOSC_SHADOW;
		break;
	case COLOR_MAGENTA: return GRAFIC_QUADRAT_MAGENTA_SHADOW;
		break;
	case COLOR_TARONJA: return GRAFIC_QUADRAT_TARONJA_SHADOW;
		break;
	case COLOR_VERD:    return GRAFIC_QUADRAT_VERD_SHADOW;
		break;
	case COLOR_VERMELL: return GRAFIC_QUADRAT_VERMELL_SHADOW;
		break;
	default:	return GRAFIC_FONS;
		break;
	}
}

IMAGE_NAME colorToPng_small(ColorFigura color)
{
	switch (color)
	{
	case COLOR_GROC:    return GRAFIC_QUADRAT_GROC_SMALL;
		break;
	case COLOR_BLAUCEL: return GRAFIC_QUADRAT_BLAUCEL_SMALL;
		break;
	case COLOR_BLAUFOSC:return GRAFIC_QUADRAT_BLAUFOSC_SMALL;
		break;
	case COLOR_MAGENTA: return GRAFIC_QUADRAT_MAGENTA_SMALL;
		break;
	case COLOR_TARONJA: return GRAFIC_QUADRAT_TARONJA_SMALL;
		break;
	case COLOR_VERD:    return GRAFIC_QUADRAT_VERD_SMALL;
		break;
	case COLOR_VERMELL: return GRAFIC_QUADRAT_VERMELL_SMALL;
		break;
	default:	return GRAFIC_FONS;
		break;
	}
}

void Figura::dibuixa(const bool& shadow) const
{
	IMAGE_NAME color;

	if (shadow)
		color = colorToPng_shadow(m_color);
	else
		color = colorToPng(m_color);

	for (int i = 0; i < m_mida; i++)
	{
		for (int j = 0; j < m_mida; j++)
		{
			if (m_figura[i][j] != NO_COLOR)
				GraphicManager::getInstance()->drawSprite(color, 
					POS_X_TAULER + ((m_posicio.horitzontal + 1 + j) * MIDA_QUADRAT),
					POS_Y_TAULER + ((m_posicio.vertical + i) * MIDA_QUADRAT), false);
		}
	}
}

void Figura::dibuixaFiguraSmall(const int& posCua) const
{
	IMAGE_NAME color = colorToPng_small(m_color);

	for (int i = 0; i < m_mida; i++)
	{
		for (int j = 0; j < m_mida; j++)
		{
			if (m_figura[i][j] != NO_COLOR)
				GraphicManager::getInstance()->drawSprite(color,
					POS_X_TAULER + 380 + (j * MIDA_QUADRAT_SMALL),
					POS_Y_TAULER + (posCua * 70) + (i * MIDA_QUADRAT_SMALL), false);
		}
	}
}

//gira la figura en la direccióGir (horaria o antihoraria)
void Figura::girar(const DireccioGir& gir)
{
	ColorFigura transposada[MAX_ALCADA][MAX_AMPLADA];
	ColorFigura invertir[MAX_ALCADA][MAX_AMPLADA];

	// Transposa matriu
	for (int i = 0; i < m_mida; ++i)
		for (int j = 0; j < m_mida; ++j)
			transposada[j][i] = m_figura[i][j];

	for (int i = 0; i < m_mida; ++i)
		for (int j = 0; j < m_mida; ++j)
			m_figura[i][j] = transposada[i][j];

	//Inverteix matriu segons la direcció de gir
	if (gir == GIR_HORARI)
	{
		for (int i = 0; i < m_mida; ++i)
			for (int j = 0; j < m_mida; ++j)
				invertir[i][j] = m_figura[i][m_mida - 1 - j];
	}
	else
		for (int i = 0; i < m_mida; ++i)
			for (int j = 0; j < m_mida; ++j)
				invertir[i][j] = m_figura[m_mida - 1 - i][j];

	for (int i = 0; i < m_mida; ++i)
		for (int j = 0; j < m_mida; ++j)
			m_figura[i][j] = invertir[i][j];
}

ifstream& operator>>(ifstream& input, Figura& figura)
{
	int tipus, fila, columna, gir;
	input >> tipus >> fila >> columna >> gir;
	figura.setTipus((TipusFigura)tipus);
	figura.setFila(fila);
	figura.setColumna(columna);
	figura.setGir(gir);
	return input;
}
