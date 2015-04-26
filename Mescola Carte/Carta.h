//Definizione della classe Carta
//La definizione delle funzioni membro è nel file Carta.cpp
#include <iostream>
using namespace std;
#include <string>
#ifndef CARTA_H
#define CARTA_H

class Carta
{
	friend ostream &operator << ( ostream&, const Carta& );
	
	public:
		Carta();
		void setValore( int );
		void setSeme( int );	
		void setMescolata ();
		int getValore() const;
		const string& getSeme() const;
		int getCount() const;
		int getCountCarte() const;
		int getNumeroCarta() const;
		bool getMescolata() const;
		const Carta& operator=(const Carta& c);
	private:
		int Valore;
		string Seme;
		int numeroCarta;
		static int Count;
		static int CountCarte;
		bool mescolata;
};

#endif

