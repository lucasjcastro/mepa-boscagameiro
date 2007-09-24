#ifndef PRINTER_H_
#define PRINTER_H_
#include <fstream>
#include <iostream>

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
		 * @param End. do topo da pilha 
		 */
		void
		printS( int );
};

#endif /*PRINTER_H_*/
