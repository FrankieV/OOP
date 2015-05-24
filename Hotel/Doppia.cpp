//Definizione delle funzioni membro per la classe Doppia

#include "Doppia.h"

//Costruttore per la classe Doppia che utilizza quello della classe base astratta Camera
Doppia::Doppia(): Camera(), Prezzo(50){}

int Doppia::getPrezzo() const
{
	return Prezzo;
}

void Doppia::print() const
{
	cout << endl;
	cout << "CAMERA DOPPIA" << endl;
	cout << "Numero: " << getNum() << endl;
	cout << "Prezzo: " << Prezzo;
}