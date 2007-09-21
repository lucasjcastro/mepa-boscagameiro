#ifndef MEPA_H_
#define MEPA_H_

#include <vector>
#include <string>

class Mepa
{
	private:
	
		/* Instrucoes do Programa */
		vector<std::string>
		mP;
		
		/* Memoria do Programa */
		vector<int>
		mM;
		
		/* Registradores Base, apontadores para M */
		vector<int>
		mD;
		
		/* ponteiro pra proxima instrucao */
		int
		mPC;
		
		/* endereco do topo da pilha */
		int
		mS;
	
	public:
	
		/** 
		 * Cria uma instancia de Mepa
		 * @param nome do arquivo de entrada
		 */
		Mepa(char[]);
	
		virtual
		~Mepa();
		
		/**
		 * Incrementa o ponteiro do PC, se possivel
		 */
		void
		proximaInstrucao();
		
		/**
		 * Altera o ponteiro do PC para a posicao passada, se possivel
		 * @param futuro valor do PC
		 */
		void
		proximaInstrucao(int);
		
};

#endif /*MEPA_H_*/
