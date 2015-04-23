//Definizione della classe Carta
//La definizione delle funzioni membro è nel file Carta.cpp
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
		int getValore() const;
		const string& getSeme() const;
		int getCount() const;
		int getCountCarte() const;
		const Carta& operator=(const Carta& c);
	private:
		int Valore;
		string Seme;
		int numeroCarta;
		static int Count;
		static int CountCarte;
};

#endif

