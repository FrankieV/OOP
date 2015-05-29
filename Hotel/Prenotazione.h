#include <iostream>
using namespace std;

#include<string>

#ifndef PRENOTAZIONE_H
#define PRENOTAZIONE_H

class Prenotazione
{
	public:
		Prenotazione();
		void setNumeroCamera( int );
		void setNomeClientePrenotazione( string );
		void setCognomeClientePrenotazione( string );
		void setNumeroCartaDiCredito( string );
		void setImportoPrenotazione( int );
		string getNomeClientePrenotazione() const;
		string getCognomeClientePrenotazione() const;
		string getNumeroCartaDiCredito() const;
		int getNumeroCamera() const;
		int getImportoPrenotazione() const;

	private:
		int importoPrenotazione;
		int NumeroCamera;
		string NomeCliente;
		string CognomeCliente;
		string NumeroCartaDiCredito;
};

#endif
