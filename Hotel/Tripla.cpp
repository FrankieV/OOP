//Definizione delle funzioni membro per la classe Tripla

#include "Tripla.h"

//Costruttore per la classe Tripla che utilizza quello della classe base astratta Camera
Tripla::Tripla(): Camera(), Prezzo(75){}

int Tripla::getPrezzo() const
{
	return Prezzo;
}

void Tripla::print() const
{
	cout << endl;
	cout << "CAMERA TRIPLA" << endl;
	cout << "Numero: " << getNum() << endl;
	cout << "Prezzo: " << Prezzo;
}
