#include <list>
#include "Fattura.h"

#ifndef GESTOREFATTURE_H
#define GESTOREFATTURE_H

class GestoreFatture
{
	public:
		string metodo1();
		
		string metodo2();
	
		string metodo3();
			
		string metodo4();
		
		int metodo5();

		int metodo6();

		int metodo7();
			
		int metodo8();
		
		int metodo9();
	
		int metodo10();

		string metodo11();
		
		string metodo12();

		string metodo13();

		int metodo14();

		string metodo15();

		int metodo16();
		
		inline bool aggiungi(Fattura f) { fatture.push_back(f); return true; }
		
		inline list<Fattura>& getContent() { return fatture; }

	private:
		list<Fattura> fatture;	
};
#endif
