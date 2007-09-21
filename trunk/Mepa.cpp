#include "Mepa.h"

/* ---- Inicio dos metodos publicos ---- */

Mepa::Mepa( const char* vNome )
{
	/* seta ponteiros para nulo */
	this->mPC = -1;
	this->mS = -1;
	
	/* abre arquivo de entrada */
	this->mArqEntrada.open( vNome, std::fstream::in );
}

Mepa::~Mepa()
{
	/* fecha arquivo de entrada */
	this->mArqEntrada.close();
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
Mepa::popM()
{
	mS--;
	mM.pop_back();
}

void
Mepa::CRCT(int vK)
{
	this->pushM();
	mM[mS] = vK;
}

void
Mepa::CRVL(int n)
{
	this->pushM();
	mM[mS] = mM[n];
}

void
Mepa::SOMA()
{
	
}
		
void
Mepa::SUBT()
{
	mM[mS-1] = mM[mS-1] - mM[mS];
	this->popM();
}
		
void
Mepa::MULT()
{
	
}
		
void
Mepa::DIV()
{
	mM[mS-1] = mM[mS-1] / mM[mS];
	this->popM();
}
		
void
Mepa::INVR()
{
	
}
		
void
Mepa::CONJ()
{
	
}
		
void
Mepa::DISJ()
{
	
}
		
void
Mepa::NEGA()
{
	
}
		
void
Mepa::CMME()
{
	
}
		
void
Mepa::CMMA()
{
	
}
		
void
Mepa::CMIG()
{
	
}
		
void
Mepa::CMDG()
{
	
}
		
void
Mepa::CMEG()
{
	
}
		
void
Mepa::CMAG()
{
	
}

/* ---- Fim dos metodos privados ---- */
