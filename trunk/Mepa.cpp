#include "Mepa.h"
#include <fstream>

Mepa::Mepa( const char* vNome )
{
	this->mPC = -1;
	this->mS = -1;
	
	this->mArqEntrada.open( vNome, std::fstream::in );
}

Mepa::~Mepa()
{
}

void 
Mepa::proximaInstrucao()
{
	this->mPC++;
}
		
void
Mepa::proximaInstrucao(int vNovaPos)
{
	this->mPC = vNovaPos;
}

void
Mepa::pushM()
{
	
}

void
Mepa::CRCT(int vK)
{
	
}
