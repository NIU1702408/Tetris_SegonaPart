#ifndef CUA_H
#define CUA_H

#include "figura.h"

struct NodeFigura
{
	Figura valor;
	NodeFigura* seguent;
};

struct NodeMoviment
{
	int valor;
	NodeMoviment* seguent;
};

class CuaFigura
{
public:
	CuaFigura() : m_primer(nullptr), m_ultim(nullptr) {};
	~CuaFigura();

	void afegeix(const Figura& valor);
	void treu();
	Figura& getPrimer() const { return m_primer->valor; }
	Figura& getUltim() const { return m_ultim->valor; }
	bool esBuida() const { return m_primer == nullptr; }
private:
	NodeFigura* m_primer;
	NodeFigura* m_ultim;
};

class CuaMoviment
{
public:
	CuaMoviment() : m_primer(nullptr), m_ultim(nullptr) {};
	~CuaMoviment();

	void afegeix(const int& valor);
	void treu();
	int& getPrimer() const { return m_primer->valor; }
	int& getUltim() const { return m_ultim->valor; }
	bool esBuida() const { return m_primer == nullptr; }
private:
	NodeMoviment* m_primer;
	NodeMoviment* m_ultim;
};

#endif 
