#include "Mepa.h"

Mepa::Mepa(char*)
{
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
