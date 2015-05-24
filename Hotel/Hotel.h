#ifndef HOTEL_H
#define HOTEL_H

#include <list>
#include "Camera.h"
#include "Singola.h"
#include "Doppia.h"
#include "Tripla.h"

class Hotel
{
	public:
		Hotel( int, int, int );
		int getNumSingole() const;
		int getNumDoppie() const;
		int getNumTriple() const;
		list<Camera*> getCamere() const;	
		void stampa();
	
	private:
		list<Camera*> camere;
		int numSingole;
		int numDoppie;		
		int numTriple;
};

#endif
