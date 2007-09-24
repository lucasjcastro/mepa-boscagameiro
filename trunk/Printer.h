#ifndef PRINTER_H_
#define PRINTER_H_
#include <fstream>
#include <iostream>
#include <vector>

#define VAZIO -1

class Printer
{
	private:
	
		std::ofstream
		arqSaida;
		
		const char*
		nomeArqEntrada;
		
	public:
		
		Printer( const char * );
		
		/**
		 * Construtor, etc...
		 * @param Nome do arquivo de saida 
		 */
		Printer( const char *, const char * );
		
		virtual 
		~Printer();
		
		/* Imprime o cabecalho... */
		void
		printCabecalho();
		
		/**
		 * Imprime o end. da proxima instrucao
		 * @param End. da proxima instrucao 
		 */
		void
		printPC( int );
		
		/**
		 * Imprime o end. do topo da pilha
		 * @param End. do topo da pilha (s)
		 */
		void
		printS( int );
		
		/**
		 * Imprime os registradores base
		 * @param Ponteiro para o vetor (D) registradores base
		 */
		void
		printD( std::vector<int>* );
		
		/**
		 * Imprime os valores da memoria
		 * @param Ponteiro para o vetor (M) memoria
		 * @param End. do topo da pilha (s)
		 */
		void
		printM( std::vector<int>*, int );
		
		/* Imprime o rodape... */
		
		void
		printRodape();
};

#endif /*PRINTER_H_*/
