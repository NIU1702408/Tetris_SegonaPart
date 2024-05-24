#include "Joc.h"

//Inicialitza el joc a partir d'un fitxer passat per 
void Joc::inicialitza(const string& nomFitxer)
{
	Posicio posicio;
	int tipus, gir;
	ifstream fitxer;
	m_figuraCollocada = false;

	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		//llegeix figura, posició (x,y), gir (posició de la figura), i el tauler amb els seus colors
		fitxer >> tipus;
		m_figura.incialitza(TipusFigura(tipus));

		fitxer >> posicio.vertical >> posicio.horitzontal;

		posicio.vertical--;
		posicio.horitzontal--;

		m_figura.setPosicio(posicio);
		m_posicio = posicio;

		fitxer >> gir;
		for (int i = 0; i < gir; i++)
			m_figura.girar(GIR_HORARI);

		for (int i = 0; i < N_FILES_TAULER; i++)
		{
			for (int j = 0; j < N_COL_TAULER; j++)
			{
				int color;
				fitxer >> color;

				m_tauler.setTauler(ColorFigura(color), i, j);
			}
		}

		fitxer.close();
	}
}

//gira la figura en la direcció especificada, verifica si el moviment és vàlid i ajusta la rotació de la figura en cas de que no ho sigui
bool Joc::giraFigura(DireccioGir direccio)
{
	bool gira = true;
	m_figura.girar(direccio);

	if (!m_tauler.esMovimentValid(m_figura, m_posicio))
	{
		if (direccio == GIR_HORARI)
			m_figura.girar(GIR_ANTI_HORARI);
		else
			m_figura.girar(GIR_HORARI);
		gira = false;
	}

	return gira;
}

//mou la figura en la direcció especificada, verifica si la posició és vàlida i ajusta la rotació si no ho és
bool Joc::mouFigura(int dirX)
{
	bool mou = true;
	m_figura.desplacar(dirX);

	if (!m_tauler.esMovimentValid(m_figura, m_figura.getPosicio()))
	{
		if (dirX == -1)
			m_figura.desplacar(1);
		else
			m_figura.desplacar(-1);
		mou = false;
	}
	else
		m_posicio = m_figura.getPosicio();

	return mou;
}

//baixa la figura actual una fila
int Joc::baixaFigura()
{
	int nFiles = 0;
	m_figura.baixar(1);

	//si el moviment no és vàlid, col·loca la figura en la posició actual i elimina les files completades i retorna nFiles (eliminades)
	if (!m_tauler.esMovimentValid(m_figura, m_figura.getPosicio()))
	{
		m_figura.baixar(-1);
		m_tauler.collocarFigura(m_figura, m_figura.getPosicio());
		m_figuraCollocada = true;
		nFiles = m_tauler.eliminarFilesCompletades();
	}
	else
		m_posicio = m_figura.getPosicio();

	return nFiles;
}

//escriu l'estat actual del tauler en un fitxer passat com a paràmetre
void Joc::escriuTauler(const string& nomFitxer)
{
	int i, j;
	ofstream fitxer;

	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		//si la figura encara no està col·locada, la col·loca temporament per escriure el tauler
		if (!m_figuraCollocada)
			m_tauler.collocarFigura(m_figura, m_posicio);

		//s'escriu el tauler en el document
		for (int i = 0; i < N_COL_TAULER; i++)
		{
			for (int j = 0; j < N_FILES_TAULER; j++)
				fitxer << int(m_tauler.getTauler(i, j)) << " ";
			fitxer << endl;
		}

		//s'elimina la figura que em col·locat temporalment
		if (!m_figuraCollocada)
			m_tauler.eliminarFigura(m_figura, m_posicio);
		fitxer.close();
	}
}

void Joc::dibuixa() const
{
	m_tauler.dibuixa();
	m_figura.dibuixa();
}