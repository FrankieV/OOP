#ifndef CalcolatriceAvanzata_H_
#define CalcolatriceAvanzata_H_
#include <iostream>
#include <cstdlib>        
#include <list>
#include <vector>
#include "TriplaNumeri.h"

using namespace std;

/*

Questa classe contiene una lista di triple di numeri. °gni. tripla e' caratterizzata dalle seguenti informazioni:
- num1: it prima numero della tripla (int);
- num2: it secondo numero della tripla (int);
- num3: it terzo numero della tripla (int).

Implementare nel file CalcolatriceAvanzata.cpp i metodi della classe CalcolatriceAvanzata.
 
*/

class CalcolatriceAvanzata      // questa riga e' corretta NON MODIFICARE
{
	private:

	     list<TriplaNumeri> numeri;

	public:

		// DESCRIZIONE NEL FILE .cpp
		int metodo1();
	
		// DESCRIZIONE NEL FILE .cpp
		int metodo2();
	
		// DESCRIZIONE NEL FILE .cpp
		int metodo3();
	
		// DESCRIZIONE NEL FILE .cpp
		int metodo4();
	
		inline bool aggiungi(TriplaNumeri c) { numeri.push_back(c); return true; }
	 
		inline list<TriplaNumeri>& getContent() { return numeri; }
};
#endif                                                 

