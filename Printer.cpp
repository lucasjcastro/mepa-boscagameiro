#include "Printer.h"

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
		arqSaida << "-----" <<	"-----" << "-----" << "-----" << "-----" 
		<< "-----" <<	"-----" << std::endl;
		this->arqSaida.close();
	}
	else
	{
		std::cout << "-----" <<	"-----" << "-----" << "-----" << "-----" 
		<< "-----" <<	"-----" << std::endl;
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
	if ( arqSaida.is_open() )
	{
		arqSaida << "i: ";
		arqSaida.fill( '0' );
		arqSaida.width( 5 );
		arqSaida << vPC;

	}
}