#include "Hotel.h"

Hotel::Hotel( int ns, int nd, int nt ): numSingole(ns), numDoppie(nd), numTriple(nt)
{
	for( int i = 0; i < numSingole + numDoppie + numTriple; i++ )
		{
			// inizializza le camere singole
			if( i < numSingole )
				{
					Singola s;
					camere.push_back( &s );
				}

			//inizializza le camere doppie
			if( i >= numSingole && i < numDoppie + numSingole )
				{
					Doppia d;
					camere.push_back( &d );
				}

			//inizializza le camere triple
			if( i >= numDoppie + numSingole && i < numTriple + numDoppie + numSingole)
				{
					Tripla t;
					t.print();
					camere.push_back( &t );		
				}
		}
}

int Hotel::getNumSingole() const
{
	return numSingole;
}

int Hotel::getNumDoppie() const
{
	return numDoppie;
}

int Hotel::getNumTriple() const
{
	return numTriple;
}

list<Camera*> Hotel::getCamere() const
{
	return camere;
}

void Hotel::stampa()
{
	cout << "Salve questo è un Hotel della catena Ollivier Hint, questo Hotel ha " << numSingole + numDoppie + numTriple << " camere";
			
}

