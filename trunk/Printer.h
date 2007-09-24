#ifndef PRINTER_H_
#define PRINTER_H_

class Printer
{
	public:
		
		Printer();
		
		/**
		 * Construtor, etc...
		 * @param Nome do arquivo de saida 
		 */
		Printer( const char * );
		
		virtual 
		~Printer();
};

#endif /*PRINTER_H_*/
