#include "Prenotazione.h"

Prenotazione::Prenotazione() : NumeroCamera(0), NomeCliente( " " ), CognomeCliente( " " ), NumeroCartaDiCredito( " " ){}

void Prenotazione :: setNumeroCamera ( int numero )
{
    NumeroCamera = numero;
}

void Prenotazione::setNomeClientePrenotazione( string nome )
{
	NomeCliente = nome;
}

void Prenotazione::setCognomeClientePrenotazione( string cognome )
{
	CognomeCliente = cognome;	
}

void Prenotazione::setNumeroCartaDiCredito( string numero)
{
	NumeroCartaDiCredito = numero;
}
	
void Prenotazione::setImportoPrenotazione( int importo )
{
    importoPrenotazione = importo;
}

string Prenotazione::getNomeClientePrenotazione() const
{
	return NomeCliente;
}

string Prenotazione::getCognomeClientePrenotazione() const
{
	return CognomeCliente;
}

string Prenotazione::getNumeroCartaDiCredito() const
{
	return NumeroCartaDiCredito;
}

int Prenotazione::getNumeroCamera() const
{
	return NumeroCamera;
}

int Prenotazione::getImportoPrenotazione() const
{
    return importoPrenotazione;
}
