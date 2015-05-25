//Definizione della classe derivata Singola

#ifndef SINGOLA_H
#define SINGOLA_H

#include "Camera.h"

class Singola : public Camera
{
	public:
		Singola() : Camera(), Prezzo(30){}//Costruttore per la classe Singola che utilizza quello della classe base astratta Camera
		int getPrezzo() const { return Prezzo; }
		void print() const { cout << endl << "CAMERA SINGOLA" << endl << "Numero: " << getNum() << endl << "Prezzo: " << Prezzo; }
	
	private:
		int Prezzo;
};

#endif
