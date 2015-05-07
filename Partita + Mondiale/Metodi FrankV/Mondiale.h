#ifndef Mondiale_H
#define Mondiale_H

#include "Partita.h"

#include <cstdlib>
#include <iostream>  
#include <list>
#include <vector>


using namespace std;

/*
	Questa classe contiene una lista di partite. Ogni partita e' caratterizzata dalle seguenti informazioni:	
	
	- squadral1: il none della squadra che gioca in casa (string);
	
	- squadra2: il nome della squadra che gioca in trasferta (string);

	- golSquadra1: il numero di gol della squadra che gioca in casa (int);

	- golSquadra2: il numero di gol della squadra che gioca in trasferta (int);

	- arbitro: il cognome dell'arbitro della partita (string)

	Implementare net file WorldCup2014.cpp i metodi della classe WorldCup2014.
*/
                                  
class Mondiale //questa riga è corretta NON MODIFICARE
{
	private:
		list<Partita> partite;
	public:
		// DESCRIZIONE NEL FILE .cpp
		int metodo1();
		
		// DESCRIZIONE NEL FILE .cpp 
		int metodo2();
		
		// DESCRIZIONE NEL FILE .cpp 
		int metodo3();
		
		// DESCRIZIONE NEL FILE .cpp
		int metodo4();
		
		inline bool aggiungi(Partita p) { partite.push_back(p); return true; }
		
		inline list<Partita>& getContent() { return partite; }
		
		bool VerificaArbitro(const string &, const vector<string> &) const;
};

#endif
