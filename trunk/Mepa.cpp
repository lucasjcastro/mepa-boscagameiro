#include "Mepa.h"

/* ---- Inicio dos metodos publicos ---- */

Mepa::Mepa( const char* vNome )
{
	this->mPC = -1;
	this->mS = -1;
	
	this->mArqEntrada.open( vNome, std::fstream::in );
}

Mepa::~Mepa()
{
}

/* ---- Fim dos metodos publicos ---- */

/* ---- Inicio dos metodos privados ---- */

void 
Mepa::proximaInstrucao()
{
	this->mPC++;
}

void
Mepa::proximaInstrucao(int vNovaPosicao)
{
	this->mPC = vNovaPosicao;
}

void
Mepa::pushM()
{
	mS++;
	mM.push_back(VAZIO);
}

void
Mepa::CRCT(int vK)
{
	this->pushM();
	mM[mS] = vK;
}

/* ---- Fim dos metodos privados ---- */
