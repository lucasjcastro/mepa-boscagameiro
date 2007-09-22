#ifndef MEPA_H_
#define MEPA_H_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#define VAZIO -1

class Mepa
{
	private:
	
		/* Instrucoes do Programa */
		std::vector<std::string>
		P;
		
		/* Memoria do Programa */
		std::vector<int>
		M;
		
		/* Registradores Base, apontadores para M */
		std::vector<int>
		D;
		
		/* ponteiro pra proxima instrucao */
		int
		PC;
		
		/* endereco do topo da pilha */
		int
		s;
		
		/* arquivo de entrada da MEPA */
		std::fstream
		mArqEntrada;
		
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
	
		/**
		 * Armazena valor na pilha
		 * @param n valor armazenado
		 */
		void
		ARMZ( int n );
		
		/**
		 * Desvio incondicional
		 * @param p Posicao a ser desviada
		 */
		void
		DSVS( int p );
		
		/**
		 * Desvio condicional se falso
		 * @param p Posicao a ser desviada 
		 */
		void
		DSVF( int p );
		
		/**
		 * Nao faz nada 
		 */
		void
		NADA();
		
		/**
		 * Le proximo valor de entrada
		 */
		void
		LEIT();
		
		/**
		 * Imprime valor do topo da pilha 
		 */
		void
		IMPR();
		
		/**
		 * Imprime valor do topo da pilha e pula linha 
		 */
		void
		IMPL();
		
		/**
		 * Imprime caracter
		 */
		void
		IMPC();
		
		/**
		 * Inicia programa principal
		 */
		void
		INPP();
		
		/**
		 * Aloca quantidade de memoria requisitada
		 * @param m Memoria a ser alocada
		 */
		void
		AMEM( int m );
		
		/**
		 * Para execucao do programa
		 */
		void
		PARA();
		
		/**
		 * Carrega valor do topo da pilha
		 * @param k Nivel lexico
		 * @param n Deslocamento
		 */
		void
		CRVL( int k, int n );
		
		/**
		 * Armazena valor do topo da pilha 
		 * em algum lugar q ainda nao sei
		 * @param k Nivel lexico
		 * @param n Deslocamento 
		 */
		void
		ARMZ( int k, int n );
		
		/**
		 * Chama procedimento
		 * @param L Procedimento
		 */
		void
		CHPR( int L );
		
		/**
		 * Entra no procedimento
		 * @param k Nivel lexico do procedimento
		 */
		void
		ENPR( int k );
		
		/**
		 * Retorna procedimento
		 * @param k Nivel lexico do procedimento
		 */
		void
		RTPR( int k );
		
		/**
		 * Desaloca memoria
		 * @param n Quantidade de memoria a ser desalocada
		 */
		void
		DMEN( int n );
		
		/**
		 * Retorna procedimento
		 * @param k Nivel lexico do procedimento
		 * @param n numero de argumentos
		 */
		void
		RTPR( int k, int n );
		
		/**
		 * Carrega valor indiretp
		 */
		void
		CRVI( int k, int n );
		
		/**
		 * Armazena valor indireto
		 */
		void
		ARMI( int k, int n );
		
		/**
		 * Carrega Endereço
		 */
		void
		CREN( int k, int n );
		
		/**
		 * Mostra memoria de acordo com
		 * o arquivo a16-t02
		 */
		void
		MOSM();
		
	public:
	
		/** 
		 * Cria uma instancia de Mepa
		 * @param nome do arquivo de entrada
		 */
		Mepa(const char*,int,int,int);
	
		virtual
		~Mepa();
		
};

#endif /*MEPA_H_*/
