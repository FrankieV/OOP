#include <iostream>
#include <string>
using namespace std;

#ifndef FATTURA_H
#define FATTURA_H

enum Tipo{ NO_TYPE = 0, ALIMENTARE, SPORTIVO, CULTURALE };

class Fattura
{
	public:
		
		Fattura();
		
		void setAziendaRicevente( string );
		void setAziendaEmittente( string );
		void setImporto( float );
		void setTipoProdotto( int );
		
		string getAziendaRicevente() const;
		string getAziendaEmittente() const;
		float getImporto() const;
		Tipo getTipoProdotto() const;
		
		friend ostream& operator << ( ostream&, const Fattura& );
		friend istream& operator >> ( istream&, Fattura& );

	private:

		string AziendaRicevente;
		string AziendaEmittente;
		float Importo;	
		Tipo TipoProdotto;

};
#endif	

