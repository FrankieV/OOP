#include <iostream>
using namespace std;
#include "Carta.h"

int Carta::Count = 0;

int Carta::CountCarte = 0;

Carta::Carta()
{
	Count = ( Count >= 0 && Count <= 12  )? Count+1 : 1;
	CountCarte++;
	numeroCarta = CountCarte;
	setValore(Count);
	setSeme(CountCarte);
	mescolata = false;
}

void Carta::setValore( int c )
{
	if( c >= 1 && c <= 52 )
		Valore = c;
}

void Carta::setSeme( int c )
{
	if( c >= 1 && c <= 13 )
		Seme = "♠";
	else
		{
			if( c > 13 && c <= 26 )
				Seme = "♣";
			else
				{
					if( c > 26 && c <= 39)
						Seme = "♥";
					else
						{
							if( c > 39 && c <= 52 )
								Seme = "♦";
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
		
	if( c.Valore == 11 )
		o << "Carta Numero " << c.numeroCarta << " : J di " << c.Seme << endl;	
	else
		{
			if( c.Valore == 12 )
				o << "Carta Numero " << c.numeroCarta << " : Q di " << c.Seme << endl;	
			else
				{
					if( c.Valore == 13 )
						o << "Carta Numero " << c.numeroCarta << " : K di " << c.Seme << endl;
					else 
						o << "Carta Numero " << c.numeroCarta << " : "<< c.Valore << " di " << c.Seme << endl;
				}		
		}
}

const Carta& Carta::operator=(const Carta& c)
{
	Valore = c.Valore;
	Seme = c.Seme;
}

