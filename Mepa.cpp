#include "Mepa.h"
#include <math.h>

/* ---- Inicio dos metodos publicos ---- */

Mepa::Mepa( const char* vNomeEntrada, int tamD, int tamP, int tamM )
{
	D.resize(tamD,VAZIO);
	P.resize(tamP);
	M.resize(tamM,VAZIO);
	
	/* seta ponteiro para nulo */
	this->PC = 0;
	this->s = -1;
	
	this->pRelatorio = new Printer( vNomeEntrada );
	
	/* abre arquivo de entrada */
	this->mArqEntrada.open( vNomeEntrada, std::fstream::in );
}

Mepa::Mepa( const char* vNomeEntrada, const char* vNomeSaida, int tamD, int tamP, int tamM )
{
	D.resize(tamD,VAZIO);
	P.resize(tamP);
	M.resize(tamM,VAZIO);
	
	/* seta ponteiro para nulo */
	this->PC = 0;
	this->s = -1;
	
	this->pRelatorio = new Printer( vNomeSaida, vNomeSaida );
	
	/* abre arquivo de entrada */
	this->mArqEntrada.open( vNomeEntrada, std::fstream::in );
	// lembrar de passar o nome do arquivo de saida para a classe de imprimir a merda la
}

Mepa::~Mepa()
{
	/* fecha arquivo de entrada */
	this->mArqEntrada.close();
	
	delete
	this->pRelatorio;
}

void Mepa::executa()
{
	bool
	Para = false;
	
	while(!para)
	{
		switch(P[PC].comando)
		{
			case crct:
				CRCT(P[PC].argumentos[0]);
				break;
			case soma:
				SOMA();
				break;
			case subt:
				SUBT();
				break;
			case mult:
				MULT();
				break;
			case divi:
				DIVI();
				break;
			case invr:
				INVR();
				break;
			case conj:
				CONJ();
				break;
			case disj:
				DISJ();
				break;
			case nega:
				NEGA();
				break;
			case cmme:
				CMME();
				break;
			case cmma:
				CMMA();
				break;
			case cmig:
				CMIG();
				break;
			case cmdg:
				CMDG();
				break;
			case cmeg:
				CMEG();
				break;
			case cmag:
				CMAG();
				break;
			case dsvs:
				DSVS(P[PC].argumentos[0]);
				break;
			case dsvf:
				DSVF(P[PC].argumentos[0]);
				break;
			case nada:
				NADA();
				break;
			case leit:
			case impr:
			case impl:
			case impc:
			case inpp:
			case amem:
			case para:
				PARA();
				Para = true;
				break;
			case crvl:
			case armz:
			case chpr:
			case enpr:
			case dmen:
			case rptr:
			case crvi:
			case armi:
			case cren:
			case mosm:
				break;
		}
	}
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
Mepa::DIVI()
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
	s++;
	this->PC++;
	
	M[s] = P[PC].comando;
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
	std::cout << toascii( M[s] ) << std::endl;
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
	pRelatorio->printCabecalho();
	pRelatorio->printPC( PC );
	pRelatorio->printS( s );
	pRelatorio->printD( &D );
	pRelatorio->printM( &M, s );
	pRelatorio->printRodape();
}

void
Mepa::carregaP()
{
	unsigned int
	linha = 0;
	
	char
	instrucao[4];
	
	char
	proximo;
	
	int
	arg;
	
	p
	tempStruct;
	
	/* ainda não adicionei a instrucao pq nao sei 
	 * como fazer, revisar */
	/* e ainda não tratei se tiver label, pq nao sei 
	 * como fazer nem se vai precisar */
	while ( !mArqEntrada.eof() && linha <= P.size() )
	{
		mArqEntrada >> linha >> instrucao;
		mArqEntrada.ignore( 1, ' ');
		proximo = mArqEntrada.peek();
		if ( proximo >= '0' && proximo <= '9' )
		{
			mArqEntrada >> arg;
			tempStruct.argumentos.push_back( arg );
			proximo = mArqEntrada.peek();
			if ( proximo == ',' )
			{
				mArqEntrada.ignore( 1, ',' );
				mArqEntrada >> arg;
				tempStruct.argumentos.push_back( arg );
			}
		}
		P[ linha ] = tempStruct;
		
		mArqEntrada.ignore( 30, '\n' );
		linha++;
	}
}

/* ---- Fim dos metodos privados ---- */
