#include "Mepa.h"
#include <math.h>
#include <vector>

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
	
	this->pRelatorio = new Printer( vNomeEntrada, vNomeSaida );
	
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
	
	carregaP();
	
	while(!Para)
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
				LEIT();
				break;
			case impr:
				IMPR();
				break;
			case impl:
				IMPL();
				break;
			case impc:
				IMPC();
				break;
			case inpp:
				INPP();
				break;
			case amem:
				AMEM(P[PC].argumentos[0]);
				break;
			case para:
				PARA();
				Para = true;
				break;
			case crvl:
				CRVL(P[PC].argumentos[0],P[PC].argumentos[1]);
				break;
			case armz:
				ARMZ(P[PC].argumentos[0],P[PC].argumentos[1]);
				break;
			case chpr:
				CHPR(P[PC].argumentos[0]);
				break;
			case enpr:
				ENPR(P[PC].argumentos[0]);
				break;
			case dmem:
				DMEM(P[PC].argumentos[0]);
				break;
			case rptr:
				RTPR(P[PC].argumentos[0],P[PC].argumentos[1]);
				break;
			case crvi:
				CRVI(P[PC].argumentos[0],P[PC].argumentos[1]);
				break;
			case armi:
				ARMI(P[PC].argumentos[0],P[PC].argumentos[1]);
				break;
			case cren:
				CREN(P[PC].argumentos[0],P[PC].argumentos[1]);
				break;
			case mosm:
				MOSM();
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
	proximaInstrucao();
}

void
Mepa::SOMA()
{
	M[s-1] += M[s];
	s--;
	proximaInstrucao();
}
		
void
Mepa::SUBT()
{
	M[s-1] = M[s-1] - M[s];
	s--;
	proximaInstrucao();
}
		
void
Mepa::MULT()
{
	M[s-1] *= M[s];
	s--;
	proximaInstrucao();
}
		
void
Mepa::DIVI()
{
	M[s-1] = M[s-1] / M[s];
	s--;
	proximaInstrucao();
}
		
void
Mepa::INVR()
{
	M[s] = - M[s];
	proximaInstrucao();
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
	proximaInstrucao();
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
	proximaInstrucao();
}
		
void
Mepa::NEGA()
{
	M[s] = 1 - M[s];
	proximaInstrucao();
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
	proximaInstrucao();
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
	proximaInstrucao();
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
	proximaInstrucao();
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
	proximaInstrucao();
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
	proximaInstrucao();
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
	proximaInstrucao();
}

void
Mepa::DSVS( int p )
{
	proximaInstrucao( p );
}

void
Mepa::DSVF( int p )
{
	if(M[s] == 0)
	{
		proximaInstrucao( p );
	}
	else
	{
		proximaInstrucao();
	}
	s--;
}

void
Mepa::NADA()
{
	proximaInstrucao();
}

void
Mepa::LEIT()
{
	s++;
	proximaInstrucao();
	
	M[s] = P[PC].argumentos[0];
	proximaInstrucao();
}

void
Mepa::IMPR()
{
	std::cout << M[s];
	s--;
	proximaInstrucao();
}

void
Mepa::IMPL()
{
	std::cout << M[s] << std::endl;
	s--;
	proximaInstrucao();
}

void
Mepa::IMPC()
{
	std::cout << toascii( M[s] ) << std::endl;
	proximaInstrucao();
}

void
Mepa::INPP()
{
	this->s = -1;
	D[0] = 0;
	proximaInstrucao();
}

void
Mepa::AMEM( int m )
{
	s += m;
	proximaInstrucao();
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
	proximaInstrucao();
}

void
Mepa::ARMZ( int k, int n )
{
	M[D[k]+n] = M[s];
	s--;
	proximaInstrucao();
}

void
Mepa::CHPR( int L )
{
	s++;
	M[s] = PC + 1;
	PC = L;
}

void
Mepa::ENPR( int k )
{
	s++;
	M[s] = D[k];
	D[k] = s + 1;
	proximaInstrucao();
}

void
Mepa::DMEM( int n )
{
	s -= n;
	proximaInstrucao();
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
	proximaInstrucao();
}
		
void
Mepa::ARMI( int k, int n )
{
	M[ M[D[k]+n] ] = M[s];
	s--;
	proximaInstrucao();
}
		
void
Mepa::CREN( int k, int n )
{
	s++;
	M[s] = D[k] + n;
	proximaInstrucao();
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
	proximaInstrucao();
}

void
Mepa::carregaP()
{
	unsigned int
	linha = 0;
	
	std::string
	instrucao;
	
	char
	proximo;
	
	int
	arg;
	
	p
	tempStruct;
		
	std::vector<label>
	rotulos;
	
	label
	tempRotulo;
	
//################################################################
	while ( !mArqEntrada.eof() && linha <= P.size() )
	{
			char
			chinelo[6];
			
			/* le a primeira parte e verica se tem label */
			mArqEntrada.read( chinelo, 5 );
			chinelo[5] = '\0';
			/* strcmp retorna 0 se strings forem iguais */
			if ( strcmp( chinelo, "     \0" ) )
			{
				strcpy( tempRotulo.rotulo, chinelo );
				tempRotulo.endereco = linha;
				rotulos.push_back( tempRotulo );
			}
			
			mArqEntrada.ignore( 1 , ' ' ); 
			proximo = mArqEntrada.peek();
			linha++;
	}
	mArqEntrada.seekg( 0, std::ios_base::beg );
	linha = 0;
	
	
//################################################################	
	
	while ( !mArqEntrada.eof() && linha <= P.size() )
	{
			tempStruct.argumentos.resize(0);
			
			/* le a primeira parte e verica se tem label */

			mArqEntrada.ignore( 6 ); 
			proximo = mArqEntrada.peek();
			if ( proximo >= '0' && proximo <= '9' )
			{std::cout << "----" << '\t';
				int 
				value;
				
				mArqEntrada >> value;
				tempStruct.argumentos.push_back( value );
				tempStruct.comando = vazio;
			}
			else
			{
				/* le a instrucao */
				mArqEntrada >> instrucao;
//-----------------------------------------------------------------------			
				if ( instrucao == "AMEM" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = amem;
				}
				else if ( instrucao == "ARMI" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = armi;
				}
				else if ( instrucao == "ARMZ" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = armz;
				}
				else if ( instrucao == "CHPR" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = chpr;
				}
				else if ( instrucao == "CMAG" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = cmag;
				}
				else if ( instrucao == "CMDG" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = cmdg;
				}
				else if ( instrucao == "CMEG" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = cmeg;
				}
				else if ( instrucao == "CMIG" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = cmig;
				}
				else if ( instrucao == "CMMA" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = cmma;
				}
				else if ( instrucao == "CMME" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = cmme;
				}
				else if ( instrucao == "CONJ" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = conj;
				}
				else if ( instrucao == "CRCT" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = crct;
				}
				else if ( instrucao == "CREN" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = cren;
				}
				else if ( instrucao == "CRVI" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = crvi;
				}
				else if ( instrucao == "CRVL" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = crvl;
				}
				else if ( instrucao == "DISJ" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = disj;
				}
				else if ( instrucao == "DIVI" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = divi;
				}
				else if ( instrucao == "DMEM" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = dmem;
				}
				else if ( instrucao == "DSVF" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = dsvf;
				}
				else if ( instrucao == "DSVS" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = dsvs;
				}
				else if ( instrucao == "ENPR" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = enpr;
				}
				else if ( instrucao == "IMPC" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = impc;
				}
				else if ( instrucao == "IMPL" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = impl;
				}
				else if ( instrucao == "IMPR" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = impr;
				}
				else if ( instrucao == "INPP" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = inpp;
				}
				else if ( instrucao == "INVR" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = invr;
				}
				else if ( instrucao == "LEIT" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = leit;
				}
				else if ( instrucao == "MOSM" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = mosm;
				}
				else if ( instrucao == "MULT" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = mult;
				}
				else if ( instrucao == "NADA" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = nada;
				}
				else if ( instrucao == "NEGA" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = nega;
				}
				else if ( instrucao == "PARA" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = para;
				}
				else if ( instrucao == "RTPR" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = rtpr;
				}
				else if ( instrucao == "SOMA" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = soma;
				}
				else if ( instrucao == "SUBT" )
				{std::cout << instrucao << '\t';
					tempStruct.comando = subt;
				}
//-----------------------------------------------------------------------	
			}
			
			/* verifica se e intrucao de desvio e substitui o rotulo */
			if ( instrucao == "DSVF" || instrucao == "DSVS" || instrucao == "CHPR" )
			{
				mArqEntrada.ignore( 1, ' ' );
				
				proximo = mArqEntrada.peek();
				if ( proximo >= '0' && proximo <= '9' )
				{
					int seila;
					mArqEntrada >> seila;
					tempStruct.argumentos.push_back(seila);
				}
				else
				{
					/* le o rotulo com chinelo pois e o mesmo
					 * formato que esta armazenado no vetor de rotulos */
					char
					chinelo[6];

					mArqEntrada.read( chinelo, 5 );
					chinelo[5] = '\0';
					
					/* procura pelo rotulo no vetor de rotulos */
					for ( int i = 0; i < (int) rotulos.size(); i++ )
					{
						tempRotulo = rotulos[i];
	
						/* compara os rotulos (obs: comparacao de string com char*) */
						if ( strcmp( tempRotulo.rotulo, chinelo ) == 0 )
						{
							/* armazena endereco do rotulo no vetor de argumentos da struct */
							tempStruct.argumentos.push_back( (int) tempRotulo.endereco );
							break;
						}
					}
				}
			}
			/* se nao for instrucao de desvio */
			else
			{
				mArqEntrada.ignore( 1, ' ');
				proximo = mArqEntrada.peek();
				/* verifica se tem argumento */
				if ( proximo >= '0' && proximo <= '9' && proximo != '\n' )
				{
					mArqEntrada >> arg;
					tempStruct.argumentos.push_back( arg );
					proximo = mArqEntrada.peek();
					/* verifica se tem outro argumento */
					if ( proximo == ',' )
					{
						mArqEntrada.ignore( 1, ',' );
						mArqEntrada >> arg;
						tempStruct.argumentos.push_back( arg );
					}
				}
			}
		/* armazena struct temporaria em P */

		P[ linha ] = tempStruct;
		
		std::cout << std::endl;
		
		/* anda ate o final da linha */
		mArqEntrada.ignore( 100, '\n' );
		linha++;
	}
}

/* ---- Fim dos metodos privados ---- */
