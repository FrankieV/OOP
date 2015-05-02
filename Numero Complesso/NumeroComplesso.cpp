#include <iostream>
#include "NumeroComplesso.h"
using namespace std;


istream& operator >> ( istream& i, NumeroComplesso& nc )
{
	cout << "Inserisci il numero complesso : ";
	i >> nc.parteReale >> nc.parteImmaginaria;
	nc.setParteReale( nc.parteReale );
	nc.setParteImmaginaria( nc.parteImmaginaria );
}

ostream& operator << ( ostream& o, const NumeroComplesso& nc )
{
	cout << "Il numero complesso è così formato : ";
	if( nc.parteImmaginaria != 0 && nc.parteReale != 0 )
		o << nc.parteReale << " + " << nc.parteImmaginaria << "i" << endl;
	else
		{
			if( nc.parteImmaginaria == 0 && nc.parteReale != 0 )
				o << nc.parteReale << endl;
			else
				{				
					if( nc.parteReale == 0 && nc.parteImmaginaria != 0)
						o << nc.parteImmaginaria << "i" << endl; 
					else
						o << nc.parteReale << endl << endl;
				}
		}
}

NumeroComplesso::NumeroComplesso(): parteReale(0), parteImmaginaria(0){}

NumeroComplesso::NumeroComplesso( float pr, float pi ): parteReale( pr ), parteImmaginaria( pi ){}

void NumeroComplesso::setParteReale( float pr )
{
	parteReale = pr;
}

void NumeroComplesso::setParteImmaginaria( float pi )
{
	parteImmaginaria = pi;
}

float NumeroComplesso::getParteReale() const
{
	return parteReale;
}

float NumeroComplesso::getParteImmaginaria() const
{
	return parteImmaginaria;
}

NumeroComplesso NumeroComplesso::operator + ( const NumeroComplesso& nc ) const
{
	NumeroComplesso Somma;	
	Somma.parteReale = parteReale + nc.parteReale;
	Somma.parteImmaginaria = parteImmaginaria + nc.parteImmaginaria;
	return Somma;	
}

NumeroComplesso NumeroComplesso::operator * ( const NumeroComplesso& nc ) const
{
	NumeroComplesso Prodotto;	
	Prodotto.parteReale = ( parteReale * nc.parteReale - parteImmaginaria * nc.parteImmaginaria);
	Prodotto.parteImmaginaria = ( parteImmaginaria * nc.parteReale + parteReale * nc.parteImmaginaria);
	return Prodotto;	
}

NumeroComplesso& NumeroComplesso::operator += ( const NumeroComplesso& nc ) 
{
	*this = *this + nc;
	return *this;	
}

NumeroComplesso& NumeroComplesso::operator *= ( const NumeroComplesso& nc ) 
{
	*this = *this * nc;
	return *this;	
}

NumeroComplesso& NumeroComplesso::operator ++ ()
{
	setParteReale( parteReale + 1 );
	setParteImmaginaria( parteImmaginaria + 1 );
	return *this;
}

NumeroComplesso NumeroComplesso::operator ++ ( int )
{
	NumeroComplesso tmp = *this;
	setParteReale( parteReale + 1 );
	setParteImmaginaria( parteImmaginaria + 1 );
	return tmp;
}
