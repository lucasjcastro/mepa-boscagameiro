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
	if ( M[s-1]=1 && M[s]=1 )
	{
		M[s-1] = 1;
	}
	else
	{
		M[s-1] = 0;
	}
	this->popM();
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
	M[s] = 1 - M[s];
}
		
void
Mepa::CMME()
{
	if(M[s-1] < M[s])
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
Mepa::CMMA()
{
	if ( M[s-1] > M[s] )
	{
		M[s-1] = 1;
	}
	else
	{
		M[s-1] = 0;
	}
	this->popM();
}
		
void
Mepa::CMIG()
{
	if(M[s-1] == M[s])
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
Mepa::CMDG()
{
	if ( M[s-1] != M[s] )
	{
		M[s-1] = 1;
	}
	else
	{
		M[s-1] = 0;
	}
	this->popM();
}
		
void
Mepa::CMEG()
{
	if(M[s-1] <= M[s])
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
Mepa::CMAG()
{
	if ( M[s-1] >= M[s] )
	{
		M[s-1] = 1;
	}
	else
	{
		M[s-1] = 0;
	}
	this->popM();
}


void
Mepa::ARMZ( int n )
{
	
}

void
Mepa::DSVS( int p )
{
	
}

void
Mepa::DSVF( int p )
{
	
}

void
Mepa::NADA()
{
	
}

void
Mepa::LEIT()
{
	
}

void
Mepa::IMPR()
{
	
}

void
Mepa::IMPL()
{
	
}

void
Mepa::IMPC()
{
	
}

void
Mepa::INPP()
{
	
}

void
Mepa::AMEM( int m )
{
	
}

void
Mepa::PARA()
{
	
}

/* ---- Fim dos metodos privados ---- */
