#ifndef PRENOTAZIONE_H
#define PRENOTAZIONE_H

#include <string>
#include <iostream>
using namespace std;

using namespace std;

class Prenotazione
{
friend istream &operator >> (istream &, Prenotazione &);
friend ostream &operator << (ostream &, const Prenotazione &);
public:
	Prenotazione() : Nome(""), Cognome(""), cod_Carta(0), colazione(false){}
	~Prenotazione();

	/* Funzioni get */
	string getNome() const;
	string getCognome() const;
	int getCodCarta() const;
	bool getColazione() const;
	
	/* Funzioni set*/
	void setNome(string);
	void setCognome(string);
	void setCodCarta(int);
	void setColazione();
	
	void eliminaDatiCliente();

	
private:
	string Nome, Cognome;
	int cod_Carta;
	bool colazione;
};

#endif
