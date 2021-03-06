//Definizione della classe derivata Tripla

#include <iostream>
using namespace std;

#ifndef TRIPLA_H
#define TRIPLA_H

#include "Camera.h"

class Tripla : public Camera
{
	public:
		bool operator == ( const Camera& ); 
		Tripla() : Camera(), Prezzo(75) {} //Costruttore per la classe Tripla che utilizza quello della classe base astratta Camera
		int getPrezzo() const { return Prezzo; }
		void print() const {cout << endl << "CAMERA TRIPLA" << endl << "Numero: " << getNum() << endl << "Prezzo: " << Prezzo << endl << "Questa camera e' " << ((getOccupata())? "Occupata " : "Libera") << endl; }

	private:
		int Prezzo;
};

#endif
