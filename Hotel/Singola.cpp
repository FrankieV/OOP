//Definizione delle funzioni membro per la classe Singola

#include "Singola.h"

//Costruttore per la classe Singola che utilizza quello della classe base astratta Camera
Singola::Singola(): Camera(), Prezzo(30){}

int Singola::getPrezzo() const
{
	return Prezzo;
}

void Singola::print() const
{
	cout << endl;
	cout << "CAMERA SINGOLA" << endl;
	cout << "Numero: " << getNum() << endl;
	cout << "Prezzo: " << Prezzo;
}
