#include <iostream>
#include "Mepa.h"

int main(int argc, char *argv[])
{
	if ( argc < 2 )
	{
		std::cout << "Numero insuficiente de parametros. " <<
				"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
		return 0;
	}
	int
	numRegBase;
	
	int
	tamMemPrograma;
	
	int
	tamMemDados;
	
	int
	numDoArqSaida;
	
	/* iterador comeca em 1 pq o argv[0] eh o nome do programa */
	for ( int i = 1; i < argc; i++ )
	{
		/* verifica se é opcao */
		if ( argv[i][0] == '-' )
		{
			/* verifica qual opcao */
			switch ( argv[i][1] )
			{
				case 'J':
					break;
					
				case 'D':
					i++;
					if ( !(i < argc -1) )
					{
						std::cout << "Numero insuficiente de parametros. " << 
							"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
						return 0;
					}
					if ( !atoi(argv[i]) )
					{
						std::cout 
						<< "O parametro " << i+1 << " precisa ser um numero. " << 
							"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
						return 0;
					}
					numRegBase = atoi(argv[i]);
					break;
					
				case 'P':
					i++;
					if ( !(i < argc -1) )
					{
						std::cout << "Numero insuficiente de parametros. " << 
							"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
						return 0;
					}
					if ( !atoi(argv[i]) )
					{
						std::cout 
						<< "O parametro " << i+1 << " precisa ser um numero. " << 
							"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
						return 0;
					}				
					tamMemPrograma = atoi(argv[i]);
					break;
					
				case 'M':
					i++;
					if ( !(i < argc -1) )
					{
						std::cout << "Numero insuficiente de parametros. " << 
							"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
						return 0;
					}
					if ( !atoi(argv[i]) )
					{
						std::cout 
						<< "O parametro " << i+1 << " precisa ser um numero. " << 
							"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
						return 0;
					}
					tamMemDados = atoi(argv[i]);
					break;
					
				case 'I':
					std::cout
					<< "Alunos:" << std::endl
					<< '\t' << "Leandro A. Boscariol" << std::endl
					<< '\t' << "Lucas B. Gameiro" << std::endl;
					return 0;
					
				case '?':
					std::cout 
					<< "Uso: mepa [opcoes] arquivo.mep" << std::endl
					<< "Exemplo: mepa -D 5 foo.mep" << std::endl
					<< std::endl
					<< "Opcoes:" << std::endl
					<< "-J" << "\t" << "Abre janela e mostra execucao do programa" << std::endl
					<< "-D n" << "\t" << "Numero n de registradores base" << std::endl
					<< "-P n" << "\t" << "Tamanho n em palavras de 16 bits da memoria de programa" << std::endl
					<< "-M n" << "\t" << "Tamanho n em palavras de 16 bits da memoria de dados" << std::endl
					<< "-I" << "\t" << "Identificacao da equipe" << std::endl
					<< "-?" << "\t" << "Lista completa dos comandos" << std::endl
					<< "-R foo" << "\t" << "Salvar no arquivo foo o resultado da instrucao MOSM. " << std::endl
								<< '\t' << "Caso nao seja utilizado, o resultado e mostrado na saida padrao" << std::endl;
					
					return 0;
					
				case 'R':
					i++;
					if ( !(i < argc -1) )
					{
						std::cout << "Numero insuficiente de parametros. " << 
							"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
						return 0;
					}
					/* O construtor da MEPA recebera recebera o argv[numArqSaida] */
					numDoArqSaida = i;
					break;
					
				default:
					std::cout << "Parametro " << i + 1 << " desconhecido. " <<
							"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
					return 0;
			
			}
		}
		else if ( 1 )// verificar se o parametro é do tipo *.mep e iniciar a mepa.
		{
			/* verifica se não ha parametros sobrando */
			if ( argc != i + 1 )
			{
				std::cout << "Numero excedente de parametros. " << 
					"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
				return 0;
			}
			
		}
		else
		{
			std::cout << "Tipo de arquivo invalido. " <<
				"Digite 'mepa -?' para a lista completa de opcoes." << std::endl;
			return 0;
		}
	}
	
	//iniciar mepa, etc...

	Mepa
	magaiver();
	
	return 0;
}
