#ifndef MEPA_H_
#define MEPA_H_

#include <vector>
#include <string>
#include <fstream>

#define VAZIO -1

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
		
		/**
		 * Aloca uma nova posicao na pilha M e incrementa S
		 */
		void
		pushM();
		
		/**
		 * Desaloca uma posicao na pilha M e decrementa S
		 */
		void
		popM();
		
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
		 * Carrega a constante na pilha
		 * @param k constante a ser carregada
		 */
		void
		CRCT(int k);
		
		/**
		 * Carrega Valor n no topo da pilha
		 * @param n valor a ser carregado na pilha
		 */
		void
		CRVL(int n);
		
		/**
		 * Somar
		 */
		void
		SOMA();
		
		/**
		 * Subtrair
		 */
		void
		SUBT();
		
		/**
		 * Multiplicar
		 */
		void
		MULT();
		
		/**
		 * Divisao Inteira
		 */
		void
		DIV();
		
		/**
		 * Inverter Sinal
		 */
		void
		INVR();
		
		/**
		 * Conjuncao
		 */
		void
		CONJ();
		
		/**
		 * Disjuncao
		 */
		void
		DISJ();
		
		/**
		 * Negacao
		 */
		void
		NEGA();
		
		/**
		 * Comparar Menor
		 */
		void
		CMME();
		
		/**
		 * Comparar Maior
		 */
		void
		CMMA();
		
		/**
		 * Comparar igual
		 */
		void
		CMIG();
		
		/**
		 * Comparar Desigual
		 */
		void
		CMDG();
		
		/**
		 * Comparar menor ou igual
		 */
		void
		CMEG();
		
		/**
		 * Comparar maior ou igual
		 */
		void
		CMAG();
	
	public:
	
		/** 
		 * Cria uma instancia de Mepa
		 * @param nome do arquivo de entrada
		 */
		Mepa(const char*);
	
		virtual
		~Mepa();
		
};

#endif /*MEPA_H_*/
