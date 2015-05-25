//Definizione della classe derivata Doppia

#ifndef DOPPIA_H
#define DOPPIA_H

#include "Camera.h"

class Doppia : public Camera
{
	public:
		Doppia(): Camera(), Prezzo(50){}//Costruttore per la classe Doppia che utilizza quello della classe base astratta Camera
		int getPrezzo() const { return Prezzo; }
		void print() const { cout << endl << "CAMERA DOPPIA" << endl << "Numero: " << getNum() << endl << "Prezzo: " << Prezzo; }

	private:
		int Prezzo;
};

#endif
