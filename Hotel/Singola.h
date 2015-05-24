//Definizione della classe derivata Singola

#ifndef SINGOLA_H
#define SINGOLA_H

#include "Camera.h"

class Singola : public Camera
{
	public:
		Singola();
		int getPrezzo() const;
		void print() const;
	
	private:
		int Prezzo;
};

#endif
