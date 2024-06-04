#include "Cua.h"

CuaFigura::~CuaFigura() 
{
	while (!esBuida()) 
		treu();
}

void CuaFigura::afegeix(const Figura& valor) 
{
	NodeFigura* nouNode = new NodeFigura;
	nouNode->valor = valor;

	if (esBuida()) 
	{
		m_primer = nouNode;
		m_ultim = nouNode;
	}
	else 
	{
		m_ultim->seguent = nouNode;
		m_ultim = nouNode;
	}
}

void CuaFigura::treu() 
{
	if (!esBuida()) 
	{
		NodeFigura* nodeATreure = m_primer;
		m_primer = m_primer->seguent;

		if (m_primer == nullptr) 
			m_ultim = nullptr;
		delete nodeATreure;
	}
}

CuaMoviment::~CuaMoviment()
{
	while (!esBuida())
		treu();
}

void CuaMoviment::afegeix(const int& valor)
{
	NodeMoviment* nouNode = new NodeMoviment;
	nouNode->valor = valor;

	if (esBuida())
	{
		m_primer = nouNode;
		m_ultim = nouNode;
	}
	else
	{
		m_ultim->seguent = nouNode;
		m_ultim = nouNode;
	}
}

void CuaMoviment::treu()
{
	if (!esBuida())
	{
		NodeMoviment* nodeATreure = m_primer;
		m_primer = m_primer->seguent;

		if (m_primer == nullptr)
			m_ultim = nullptr;
		delete nodeATreure;
	}
}