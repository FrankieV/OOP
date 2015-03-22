#include <iostream>
#include "Razionale.h"

using namespace std;

int main()
{
	Razionale R( 16, 12 );
	Razionale Raz( 4, 7);
	cout << endl << endl << endl;
	cout << "PRIMO PUNTO ESERCITAZIONE :" << endl;
	cout << R.converti() << endl << endl << endl;
	cout << "SECONDO PUNTO ESERCITAZIONE :" << endl;
	R.inverti();
	cout << endl << endl;
	cout << "TERZO PUNTO ESERCITAZIONE :" << endl;
	R.stampaRazionale();
	cout << endl << endl;
	cout << "QUARTO PUNTO ESERCITAZIONE :" << endl;
	R.riduci();
	cout << 	R.getNumeratore() << " / " << R.getDenominatore();
	cout << endl << endl << endl;
	cout << "QUINTO PUNTO ESERCITAZIONE :" << endl;
	R.prodotto_e_Assegna( Raz );
	cout << R.getNumeratore() << " / " << R.getDenominatore() << endl << endl << endl;
	cout << "SESTO PUNTO ESERCITAZIONE :" << endl;
	R.somma_e_Assegna( Raz );
	cout << R.getNumeratore() << " / "	<< R.getDenominatore() << endl << endl << endl;
	return 0;
}
