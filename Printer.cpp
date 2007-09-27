#include "Printer.h"
#include <iomanip>

Printer::Printer( const char* vNomeEntrada )
{
	this->nomeArqEntrada = vNomeEntrada;
}

Printer::Printer( const char* vNomeSaida, const char* vNomeEntrada )
{
	this->nomeArqEntrada = vNomeEntrada;
	this->arqSaida.open( vNomeSaida, std::ofstream::out );
}

Printer::~Printer()
{
	if ( arqSaida.is_open() )
	{
		this->arqSaida.close();
	}
}

void
Printer::printCabecalho()
{
	if ( arqSaida.is_open() )
	{
		arqSaida << "DUMP DE MEMORIA: " << nomeArqEntrada << std::endl
			<< "-----" <<	"-----" << "-----" << "-----" << "-----"
			<< "-----" <<	"-----" << std::endl;
	}
	else
	{
		std::cout << "DUMP DE MEMORIA: " << nomeArqEntrada << std::endl
			<< "-----" <<	"-----" << "-----" << "-----" << "-----"
			<< "-----" << "-----" << std::endl;
	}
}

void
Printer::printPC( int vPC )
{
	char fill;
	if ( arqSaida.is_open() )
	{
		arqSaida << "i: ";
		fill = arqSaida.fill();
		arqSaida << std::setfill( '0' ) << std::setw( 5 );
		arqSaida << vPC << std::endl;
		arqSaida.fill( fill );
	}
	else
	{
		std::cout << "i: ";
		fill = std::cout.fill();
		std::cout << std::setfill( '0' ) << std::setw( 5 );
		std::cout << vPC << std::endl;
		std::cout.fill( fill );
	}
}

void
Printer::printS( int vS )
{
	char fill;
	if ( arqSaida.is_open() )
	{
		arqSaida << "s: ";
		fill = arqSaida.fill();
		arqSaida << std::setfill( '0' ) << std::setw( 5 );
		arqSaida << vS << std::endl;
		arqSaida.fill( fill );
	}
	else
	{
		std::cout << "s: ";
		fill = std::cout.fill();
		std::cout << std::setfill( '0' ) << std::setw( 5 );
		std::cout << vS << std::endl;
		std::cout.fill( fill );
	}
}

void
Printer::printD( std::vector<int>* pD )
{
	char 
	fill;
	
	if ( arqSaida.is_open() )
	{
		fill = arqSaida.fill();
		for ( unsigned int i = 0; i < pD->size(); i++ )
		{
			if ( pD->at( i ) == VAZIO )
			{
				break;
			}
			arqSaida << "D[" << i << "]: ";
			arqSaida << std::setfill( '0' ) << std::setw( 5 );
			arqSaida << pD->at( i ) << std::endl;
			arqSaida.fill( fill );
		}
		arqSaida << "-----" << "-----" << "-----" << std::endl;
	}
	else
	{
		fill = std::cout.fill();
		for ( unsigned int i = 0; i < pD->size(); i++ )
		{
			if ( pD->at( i ) == VAZIO )
			{
				break;
			}
			std::cout << "D[" << i << "]: ";
			std::cout << std::setfill( '0' ) << std::setw( 5 );
			std::cout << pD->at( i ) << std::endl;
			std::cout.fill( fill );
		}
		std::cout << "-----" << "-----" << "-----" << std::endl;
	}
}

void
Printer::printM( std::vector<int>* pM, int vS )
{
	char 
	fill;
	
	if ( arqSaida.is_open() )
	{
		fill = arqSaida.fill();
		
		for ( int i = 0; i <= vS; i++ )
		{
			arqSaida << '[';
			arqSaida << std::setfill( '0' ) << std::setw( 5 );
			arqSaida << i << "] ";
			arqSaida << std::setfill( fill );
			arqSaida << pM->at( i ) << std::endl;
		}
	}
	else
	{
		fill = std::cout.fill();
		
		for ( int i = 0; i <= vS; i++ )
		{
			std::cout << '[';
			std::cout << std::setfill( '0' ) << std::setw( 5 );
			std::cout << i << "] ";
			std::cout << std::setfill( fill );
			std::cout << pM->at( i ) << std::endl;
		}
	}
}

void
Printer::printRodape()
{
	if ( arqSaida.is_open() )
	{
		arqSaida << "-----" <<	"-----" << "-----" << "-----" << "-----" 
			<< "-----" <<	"-----" << std::endl << std::endl;
	}
	else
	{
		std::cout << "-----" <<	"-----" << "-----" << "-----" << "-----" 
			<< "-----" <<	"-----" << std::endl << std::endl;
	}
}


