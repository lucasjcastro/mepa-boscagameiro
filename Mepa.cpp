#include "Mepa.h"
#include <math.h>

/* ---- Inicio dos metodos publicos ---- */

Mepa::Mepa( const char* vNomeEntrada, int tamD, int tamP, int tamM )
{
	D.resize(tamD,VAZIO);
	P.resize(tamP);
	M.resize(tamM,VAZIO);
	
	/* seta ponteiro para nulo */
	this->PC = -1;
	
	this->pRelatorio = new Printer();
	
	/* abre arquivo de entrada */
	this->mArqEntrada.open( vNomeEntrada, std::fstream::in );
}

Mepa::Mepa( const char* vNomeEntrada, const char* vNomeSaida, int tamD, int tamP, int tamM )
{
	D.resize(tamD,VAZIO);
	P.resize(tamP);
	M.resize(tamM,VAZIO);
	
	/* seta ponteiro para nulo */
	this->PC = -1;
	
	this->pRelatorio = new Printer(vNomeSaida);
	
	/* abre arquivo de entrada */
	this->mArqEntrada.open( vNomeEntrada, std::fstream::in );
	// lembrar de passar o nome do arquivo de saida para a classe de imprimir a merda la
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
Mepa::CRCT(int vK)
{
	s++;
	M[s] = vK;
}

void
Mepa::CRVL(int n)
{
	s++;
	M[s] = M[n];
}

void
Mepa::SOMA()
{
	M[s-1] += M[s];
	s--;
}
		
void
Mepa::SUBT()
{
	M[s-1] = M[s-1] - M[s];
	s--;
}
		
void
Mepa::MULT()
{
	M[s-1] *= M[s];
	s--;
}
		
void
Mepa::DIV()
{
	M[s-1] = M[s-1] / M[s];
	s--;
}
		
void
Mepa::INVR()
{
	M[s] = - M[s];
}
		
void
Mepa::CONJ()
{
	if ( M[s-1] == 1 && M[s] == 1 )
	{
		M[s-1] = 1;
	}
	else
	{
		M[s-1] = 0;
	}
	s--;
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
	s--;
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
	s--;
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
	s--;
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
	s--;
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
	s--;
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
	s--;
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
	s--;
}


void
Mepa::ARMZ( int n )
{
	M[n] = M[s];
	s--;
}

void
Mepa::DSVS( int p )
{
	PC = p;
}

void
Mepa::DSVF( int p )
{
	if(M[s] == 0)
	{
		this->PC = p;
	}
	else
	{
		this->PC++; 
	}
	s--;
}

void
Mepa::NADA()
{
	/* nao faz nada mesmo, apesar de eu achar 
	 * q precisa incrementar o PC, enfim...*/
}

void
Mepa::LEIT()
{
	int i;
	int v;
	
	s++;
	this->PC++;
	
	for(i=0;i < (int) P[PC].size(); i++)
	{
		/* transformando a string em um inteiro */
		v += atoi(&P[PC][i]) * (int) pow(10,(P[PC].size()-i-1));
	}
	M[s] = v;
}

void
Mepa::IMPR()
{
	std::cout << M[s];
	s--;
}

void
Mepa::IMPL()
{
	std::cout << M[s] << std::endl;
	s--;
}

void
Mepa::IMPC()
{
	std::cout << toascii( M[s] );
}

void
Mepa::INPP()
{
	this->s = -1;
	D[0] = 0;
}

void
Mepa::AMEM( int m )
{
	s += m;
}

void
Mepa::PARA()
{
	
}

void
Mepa::CRVL( int k, int n )
{
	s++;
	M[s] = M[D[k] + n];
}

void
Mepa::ARMZ( int k, int n )
{
	M[D[k]+n] = M[s];
	s--;
}

void
Mepa::CHPR( int L )
{
	s++;
	M[s] = PC + 1;
	PC = L;
	/* lembrar de arrumar essa merda pq agente
	 * tá recebendo o endereco nao o procedimento em si */
}

void
Mepa::ENPR( int k )
{
	s++;
	M[s] = D[k];
	D[k] = s + 1;
}

void
Mepa::RTPR( int k )
{
	D[k] = M[s];
	PC = M[s-1];
	s -= 2;
}

void
Mepa::DMEN( int n )
{
	s -= n;
}

void
Mepa::RTPR( int k, int n )
{    
	D[k] = M[s];
	PC = M[s-1];
	s -= (n+2);
}
		
void
Mepa::CRVI( int k, int n )
{
	s++;
	M[s] = M[ M[D[k] + n] ];
}
		
void
Mepa::ARMI( int k, int n )
{
	M[ M[D[k]+n] ] = M[s];
	s--;
}
		
void
Mepa::CREN( int k, int n )
{
	s++;
	M[s] = D[k] + n;
}

void
Mepa::MOSM()
{
	
}

/* ---- Fim dos metodos privados ---- */
