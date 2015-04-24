#include <iostream>
using namespace std;
#include "Carta.h"

int Carta::Count = 0;

int Carta::CountCarte = 0;

Carta::Carta()
{
	Count = ( Count >= 0 && Count <= 9  )? Count+1 : 1;
	CountCarte++;
	numeroCarta = CountCarte;
	setValore(Count);
	setSeme(CountCarte);
	mescolata = false;
}

void Carta::setValore( int c )
{
	if( c >= 1 && c <= 40 )
		Valore = c;
}

void Carta::setSeme( int c )
{
	if( c >= 1 && c <= 10)
		Seme = "Spade";
	else
		{
			if( c > 10 && c <= 20 )
				Seme = "Coppe";
			else
				{
					if( c > 20 && c <= 30)
						Seme = "Denari";
					else
						{
							if( c > 30 && c <= 40 )
								Seme = "Bastoni";
							else
								Seme = "Nessun Seme";
						}
				}		
		}
}

void Carta::setMescolata() 
{
	mescolata = true;
}

int Carta::getValore() const
{
	return Valore;
}

const string& Carta::getSeme() const
{
	return Seme;
}

int Carta::getCount() const
{
	return Count;
}

int Carta::getCountCarte() const
{
	return CountCarte;
}

int Carta::getNumeroCarta() const
{
	return numeroCarta;
}

bool Carta::getMescolata() const
{
	return mescolata;
}

ostream &operator << ( ostream& o, const Carta& c)
{
	o << "Carta Numero " << c.numeroCarta << " : "<< c.Valore << " di " << c.Seme << endl;
}

const Carta& Carta::operator=(const Carta& c)
{
	Valore = c.Valore;
	Seme = c.Seme;
}

