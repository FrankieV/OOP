#include <iostream>
using namespace std;
#include "Carta.h"

int Carta::Count = 0;

int Carta::CountCarte = 0;

Carta::Carta()
{
	Count = ( Count >= 0 && Count <= 9 )? Count+1 : 1;
	CountCarte++;
	setValore(Count);
	setSeme(CountCarte);
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
						}
				}		
		}
}

int Carta::getValore() const
{
	return Valore;
}

const string& Carta::getSeme() const
{
	return Seme;
}

ostream &operator << ( ostream& o, const Carta& c)
{
	o << c.Valore << " di " << c.Seme;
}

const Carta& Carta::operator=(const Carta& c)
{
	Valore = c.Valore;
	Seme = c.Seme;
}

