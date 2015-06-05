#include "Prenotazione.h"

Prenotazione::~Prenotazione(){}

string Prenotazione::getNome() const
{
	return Nome;
}

string Prenotazione::getCognome() const
{
	return Cognome;
}

int Prenotazione::getCodCarta() const
{
	return cod_Carta;
}

bool Prenotazione::getColazione() const
{
	return colazione;
}

void Prenotazione::setNome(string n)
{
	if (!n.empty())
		Nome = n;
}

void Prenotazione::setCognome(string c)
{
	if (!c.empty())
		Cognome = c;
}

void Prenotazione::setCodCarta(int cod)
{
	if (cod >= 0)
		cod_Carta = cod;
}

void Prenotazione::setColazione()
{
	colazione = true;
}

istream& operator >> (istream & in, Prenotazione & p)
{
   string scelta_colazione;
   cout << "Inserisci il nome del cliente: ";
   in >> p.Nome;
   cout << endl << "Inserisci il cognome del cliente: ";
   in >> p.Cognome;
   cout << endl << "Inserisci la carta di credito del cliente: "; 
   in >> p.cod_Carta;
   cout << endl << "Il cliente desidera la colazione? - s: si / n: no ";
   in >> scelta_colazione;
   
   if(scelta_colazione == "s")
         p.colazione = true;
         
   
   return in;

}

ostream& operator << (ostream & out, const Prenotazione & p)
{
  out << "Nome del cliente: " << p.Nome << endl << "Cognome del cliente: " << p.Cognome << endl << "Codice carta cliente: " << p.cod_Carta << endl;
  if(p.colazione)
  out << "Colazione: Si" << endl;
  else
  out << "Colazione: No" << endl;
  
  return out;
} 

void Prenotazione::eliminaDatiCliente()
{
   this -> Nome = "";
   this -> Cognome = "";
   this -> cod_Carta = 0;
   this -> colazione = false;
}

