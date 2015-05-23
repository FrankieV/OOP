#include "Fattura.h"

Fattura::Fattura() : AziendaRicevente("Nessuna"), AziendaEmittente("Nessuna"), Importo(0.0)
{
	setTipoProdotto( 0 );
}

void Fattura::setAziendaRicevente( string AR )
{
	AziendaRicevente = AR;
}

void Fattura::setAziendaEmittente( string AE )
{
	AziendaEmittente = AE;
}

void Fattura::setImporto( float i )
{
	Importo = i;
}

void Fattura::setTipoProdotto( int t )
{
	t = ( t >= 1 && t <= 3 )? t : 0;
	switch (t)
		{
			case 0:
				TipoProdotto = NO_TYPE;
				break;
			case 1:
				TipoProdotto = ALIMENTARE;
				break;	
			case 2:
				TipoProdotto = SPORTIVO;	
				break;
			case 3:
				TipoProdotto = CULTURALE;	
				break;
		}
}

string Fattura::getAziendaRicevente() const
{
	return AziendaRicevente;
}

string Fattura::getAziendaEmittente() const
{
	return AziendaEmittente;
}

float Fattura::getImporto() const
{
	return Importo;
}

Tipo Fattura::getTipoProdotto() const
{
	return TipoProdotto;
}

ostream& operator << ( ostream& out, const Fattura& f )
{
	out << "L'azienda che ha emesso la fattura e': " << f.AziendaEmittente << endl << endl;
	out << "L'azienda che ha ricevuto la fattura e': " << f.AziendaRicevente << endl << endl;
	out << "L'importo della fattura e' di: " << f.Importo << " euro." << endl << endl;
	cout << "Il tipo del prodotto venduto e': ";
	switch( f.TipoProdotto )
		{
			case NO_TYPE:
				cout << "Nessun Tipo. " << endl << endl;
				break;
			case ALIMENTARE:
				cout << "Alimentare. " << endl << endl;
				break;
			case SPORTIVO:
				cout << "Sportivo. " << endl << endl;
				break;
			case CULTURALE:
				cout << "Culturale. " << endl << endl;  
				break;		
		}
}

istream& operator >> ( istream& in, Fattura& f )
{
	int i;
	cout << "Inserisci l'azienda che ha emesso la fattura: ";
	in >> f.AziendaEmittente;
	cout << endl;	
	cout << "Inserisci l'azienda che ha ricevuto la fattura: ";
	in >> f.AziendaRicevente;
	cout << endl;
	cout << "Inserisci l'importo della fattura: ";
	in >> f.Importo;
	cout << endl;
	cout << "Inserisci il tipo del prodotto: " << endl;
	cout << "-digita 1: Alimentare;" << endl;
	cout << "-digita 2: Sportivo;" << endl;
	cout << "-digita 3: Culturale;" << endl;
	cout << "-digita qualsiasi tasto : Nessun Tipo." << endl;
	cin >> i;
	f.setTipoProdotto( i );
}
