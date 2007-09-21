#include "Mepa.h"

/* ---- Inicio dos metodos publicos ---- */

Mepa::Mepa( const char* vNome )
{
	/* seta ponteiros para nulo */
	this->PC = -1;
	this->s = -1;
	
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
	this->PC++;
}

void
Mepa::proximaInstrucao(int vNovaPosicao)
{
	this->PC = vNovaPosicao;
}

void
Mepa::pushM()
{
	s++;
	M.push_back(VAZIO);
}

void
Mepa::popM()
{
	s--;
	M.pop_back();
}

void
Mepa::CRCT(int vK)
{
	this->pushM();
	M[s] = vK;
}

void
Mepa::CRVL(int n)
{
	this->pushM();
	M[s] = M[n];
}

void
Mepa::SOMA()
{
	M[s-1] += M[s];
	popM();
}
		
void
Mepa::SUBT()
{
	M[s-1] = M[s-1] - M[s];
	this->popM();
}
		
void
Mepa::MULT()
{
	M[s-1] *= M[s];
	popM();
}
		
void
Mepa::DIV()
{
	M[s-1] = M[s-1] / M[s];
	this->popM();
}
		
void
Mepa::INVR()
{
	M[s] = - M[s];
}
		
void
Mepa::CONJ()
{
	
}
		
void
Mepa::DISJ()
{
	if(M[s-1] == 1 || M[s] == 1)
	{
		M[s-1] = 1;
	}
	else
	{
		M[s-1] = 0;
	}
	popM();
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
