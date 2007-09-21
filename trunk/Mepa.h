#ifndef MEPA_H_
#define MEPA_H_

#include <vector>
#include <string>
#include <fstream>

class Mepa
{
	private:
	
		/* Instrucoes do Programa */
		std::vector<std::string>
		mP;
		
		/* Memoria do Programa */
		std::vector<int>
		mM;
		
		/* Registradores Base, apontadores para M */
		std::vector<int>
		mD;
		
		/* ponteiro pra proxima instrucao */
		int
		mPC;
		
		/* endereco do topo da pilha */
		int
		mS;
		
		/* arquivo de entrada da MEPA */
		std::fstream
		mArqEntrada;
	
	public:
	
		/** 
		 * Cria uma instancia de Mepa
		 * @param nome do arquivo de entrada
		 */
		Mepa( const char* );
	
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
		
		/**
		 * Aloca uma nova posicao na pilha M e incrementa S
		 */
		void
		pushM();
		
		/**
		 * Carrega a constante na pilha
		 * @param constante a ser carregada
		 */
		void
		CRCT(int k);
		
};

#endif /*MEPA_H_*/
