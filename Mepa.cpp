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
	
	carregaP();
	
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
			case dmem:
			case rptr:
			case crvi:
			case armi:
			case cren:
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
Mepa::DMEM( int n )
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
	
	while ( !mArqEntrada.eof() && linha <= P.size() )
	{

//		proximo = mArqEntrada.peek();
//		/* caso for label resolvido */
//		if ( proximo >= '0' && proximo <= '9' )
//		{
//			/* o primeiro valor e o rotulo e o segunda a instrucao */
//			mArqEntrada >> tempRotulo.rotulo >> instrucao;
//			tempRotulo.endereco = linha;
//			
//
//			/* rotulo armazenado */
//			rotulos.push_back( tempRotulo );
//			
////-----------------------------------------------------------------------			
//			if ( instrucao == "AMEM" )
//			{
//				tempStruct.comando = amem;
//			}
//			else if ( instrucao == "ARMI" )
//			{
//				tempStruct.comando = armi;
//			}
//			else if ( instrucao == "ARMZ" )
//			{
//				tempStruct.comando = armz;
//			}
//			else if ( instrucao == "CHPR" )
//			{
//				tempStruct.comando = chpr;
//			}
//			else if ( instrucao == "CMAG" )
//			{
//				tempStruct.comando = cmag;
//			}
//			else if ( instrucao == "CMDG" )
//			{
//				tempStruct.comando = cmdg;
//			}
//			else if ( instrucao == "CMEG" )
//			{
//				tempStruct.comando = cmeg;
//			}
//			else if ( instrucao == "CMIG" )
//			{
//				tempStruct.comando = cmig;
//			}
//			else if ( instrucao == "CMMA" )
//			{
//				tempStruct.comando = cmma;
//			}
//			else if ( instrucao == "CMME" )
//			{
//				tempStruct.comando = cmme;
//			}
//			else if ( instrucao == "CONJ" )
//			{
//				tempStruct.comando = conj;
//			}
//			else if ( instrucao == "CRCT" )
//			{
//				tempStruct.comando = crct;
//			}
//			else if ( instrucao == "CREN" )
//			{
//				tempStruct.comando = cren;
//			}
//			else if ( instrucao == "CRVI" )
//			{
//				tempStruct.comando = crvi;
//			}
//			else if ( instrucao == "CRVL" )
//			{
//				tempStruct.comando = crvl;
//			}
//			else if ( instrucao == "DISJ" )
//			{
//				tempStruct.comando = disj;
//			}
//			else if ( instrucao == "DIVI" )
//			{
//				tempStruct.comando = divi;
//			}
//			else if ( instrucao == "DMEM" )
//			{
//				tempStruct.comando = dmem;
//			}
//			else if ( instrucao == "DSVF" )
//			{
//				tempStruct.comando = dsvf;
//			}
//			else if ( instrucao == "DSVS" )
//			{
//				tempStruct.comando = dsvs;
//			}
//			else if ( instrucao == "ENPR" )
//			{
//				tempStruct.comando = enpr;
//			}
//			else if ( instrucao == "IMPC" )
//			{
//				tempStruct.comando = impc;
//			}
//			else if ( instrucao == "IMPL" )
//			{
//				tempStruct.comando = impl;
//			}
//			else if ( instrucao == "IMPR" )
//			{
//				tempStruct.comando = impr;
//			}
//			else if ( instrucao == "INPP" )
//			{
//				tempStruct.comando = inpp;
//			}
//			else if ( instrucao == "INVR" )
//			{
//				tempStruct.comando = invr;
//			}
//			else if ( instrucao == "LEIT" )
//			{
//				tempStruct.comando = leit;
//			}
//			else if ( instrucao == "MOSM" )
//			{
//				tempStruct.comando = mosm;
//			}
//			else if ( instrucao == "MULT" )
//			{
//				tempStruct.comando = mult;
//			}
//			else if ( instrucao == "NADA" )
//			{
//				tempStruct.comando = nada;
//			}
//			else if ( instrucao == "NEGA" )
//			{
//				tempStruct.comando = nega;
//			}
//			else if ( instrucao == "PARA" )
//			{
//				tempStruct.comando = para;
//			}			
////-----------------------------------------------------------------------			
//			/* verifica se e intrucao de desvio e substitui o rotulo */
//			if ( instrucao == "DSVF" || instrucao == "DSVS" )
//			{
//				std::string
//				rotulo;
//				
//				/* le o rotulo */
//				mArqEntrada >> rotulo;
//				
//				/* procura por ele no vetor de rotulos */
//				for ( int i = 0; i < (int) rotulos.size(); i++ )
//				{
//					tempRotulo = rotulos[i];
//					/* compara rotulo lido com o do vetor */
//					if ( tempRotulo.rotulo == rotulo )
//					{
//						tempStruct.argumentos.push_back( tempRotulo.endereco );
//						break;
//					}
//				}
//				
//			}
//			/* se nao for instrucao de desvio */
//			else
//			{
//				mArqEntrada.ignore( 1, ' ');
//				proximo = mArqEntrada.peek();
//				
//				/* se tem argumento */
//				if ( proximo >= '0' && proximo <= '9' )
//				{
//					mArqEntrada >> arg;
//					tempStruct.argumentos.push_back( arg );
//					proximo = mArqEntrada.peek();
//					
//					/* se tem outro argumento */
//					if ( proximo == ',' )
//					{
//						mArqEntrada.ignore( 1, ',' );
//						mArqEntrada >> arg;
//						tempStruct.argumentos.push_back( arg );
//					}
//				}
//			}
//		}
//		/* rotulos nao resolvidos */
//		else
		{
			tempStruct.argumentos.resize(0);
			char
			chinelo[5];
			
			/* le a primeira parte e verica se tem label */
			mArqEntrada.read( chinelo, 5 );
			chinelo[5] = '\0';
			if ( strcmp( chinelo, "     \0" ) )
			{
				strcpy( tempRotulo.rotulo, chinelo );
				tempRotulo.endereco = linha;
				rotulos.push_back( tempRotulo );
			}
			
			/* le a instrucao */
			mArqEntrada >> instrucao;
//-----------------------------------------------------------------------			
			if ( instrucao == "AMEM" )
			{
				/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = amem;
			}
			else if ( instrucao == "ARMI" )
			{
				/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = armi;
			}
			else if ( instrucao == "ARMZ" )
			{
				/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = armz;
			}
			else if ( instrucao == "CHPR" )
			{
				/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = chpr;
			}
			else if ( instrucao == "CMAG" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = cmag;
			}
			else if ( instrucao == "CMDG" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = cmdg;
			}
			else if ( instrucao == "CMEG" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = cmeg;
			}
			else if ( instrucao == "CMIG" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = cmig;
			}
			else if ( instrucao == "CMMA" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = cmma;
			}
			else if ( instrucao == "CMME" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = cmme;
			}
			else if ( instrucao == "CONJ" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = conj;
			}
			else if ( instrucao == "CRCT" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = crct;
			}
			else if ( instrucao == "CREN" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = cren;
			}
			else if ( instrucao == "CRVI" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = crvi;
			}
			else if ( instrucao == "CRVL" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = crvl;
			}
			else if ( instrucao == "DISJ" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = disj;
			}
			else if ( instrucao == "DIVI" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = divi;
			}
			else if ( instrucao == "DMEM" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = dmem;
			}
			else if ( instrucao == "DSVF" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = dsvf;
			}
			else if ( instrucao == "DSVS" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = dsvs;
			}
			else if ( instrucao == "ENPR" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = enpr;
			}
			else if ( instrucao == "IMPC" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = impc;
			}
			else if ( instrucao == "IMPL" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = impl;
			}
			else if ( instrucao == "IMPR" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = impr;
			}
			else if ( instrucao == "INPP" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = inpp;
			}
			else if ( instrucao == "INVR" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = invr;
			}
			else if ( instrucao == "LEIT" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = leit;
			}
			else if ( instrucao == "MOSM" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = mosm;
			}
			else if ( instrucao == "MULT" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = mult;
			}
			else if ( instrucao == "NADA" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = nada;
			}
			else if ( instrucao == "NEGA" )
			{
				/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = nega;
			}
			else if ( instrucao == "PARA" )
			{
/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = para;
			}
			else if ( instrucao == "RTPR" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = rtpr;
			}
			else if ( instrucao == "SOMA" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = soma;
			}
			else if ( instrucao == "SUBT" )
			{/*testes*/		std::cout << instrucao << '\t';
				tempStruct.comando = subt;
			}
//-----------------------------------------------------------------------	
			
			/* verifica se e intrucao de desvio e substitui o rotulo */
			if ( instrucao == "DSVF" || instrucao == "DSVS" )
			{
				mArqEntrada.ignore( 1, ' ' );
				
				/* le o rotulo com chinelo pois e o mesmo
				 * formato que esta armazenado no vetor de rotulos */
				mArqEntrada.read( chinelo, 5 );
				chinelo[5] = '\0';
				
				/* procura pelo rotulo no vetor de rotulos */
				for ( int i = 0; i < (int) rotulos.size(); i++ )
				{
					tempRotulo = rotulos[i];
					
//					std::cout << "-" << tempRotulo.rotulo << " " << chinelo << "-";
					
					/* compara os rotulos (obs: comparacao de string com char*) */
					if ( !strcmp( tempRotulo.rotulo, chinelo ) )
					{
						/* armazena endereco do rotulo no vetor de argumentos da struct */
						tempStruct.argumentos.push_back( tempRotulo.endereco );
						break;
					}
				}
			}
			/* se nao for instrucao de desvio */
			else
			{
				mArqEntrada.ignore( 1, ' ');
				proximo = mArqEntrada.peek();
				/* verifica se tem argumento */
				if ( proximo >= '0' && proximo <= '9' )
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
		}
		/* armazena struct temporaria em P */
		
/**/	std::cout << tempStruct.comando;
/**/	for ( unsigned int i = 0; i < tempStruct.argumentos.size(); i++ )
/**/		std::cout << '\t' << tempStruct.argumentos[i];
		std::cout << std::endl;
		P[ linha ] = tempStruct;
		
		/* anda ate o final da linha */
		mArqEntrada.ignore( 100, '\n' );
		linha++;
	}
	/*teste*/
	std::cout << std::endl;
	for ( unsigned int i = 0; i < rotulos.size(); i++ )
	{
		tempRotulo = rotulos[i]; 
		std::cout << tempRotulo.rotulo << '\t' << tempRotulo.endereco << std::endl;
	}
}

/* ---- Fim dos metodos privados ---- */
