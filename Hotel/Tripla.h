//Definizione della classe derivata Tripla

#ifndef TRIPLA_H
#define TRIPLA_H

#include "Camera.h"

class Tripla : public Camera
{
	public:
		Tripla() : Camera(), Prezzo(75) {} //Costruttore per la classe Tripla che utilizza quello della classe base astratta Camera
		int getPrezzo() const { return Prezzo; }
		void print() const {cout << endl << "CAMERA TRIPLA" << endl << "Numero: " << getNum() << endl << "Prezzo: " << Prezzo; }

	private:
		int Prezzo;
};

#endif
