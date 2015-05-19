#include "GestoreFatture.h"

int main()
{
	Fattura f[5];
	GestoreFatture GF;
	for( int i = 0; i < 5; i++ )
		{	
			cout << endl << endl;
			cin >> f[i];
			GF.aggiungi(f[i]);
		}

	cout << endl << endl << "                           ::::Primo Metodo:::" << endl << endl;
	cout << "Restituire il nome dell'azienda che ha emesso più fatture." << endl << endl;
	cout << "In questo caso è :" << GF.metodo1() << endl << endl;

	cout << endl << endl << "                           ::::Secondo Metodo:::" << endl << endl;
	cout << "Restituire il nome dell'azienda che ha emesso la fattura con l'importo maggiore." << endl << endl;
	cout << "In questo caso è :" << GF.metodo2() << endl << endl;
	
	cout << endl << endl << "                           ::::Terzo Metodo:::" << endl << endl;
	cout << "Restituire il nome dell'azienda che ha emesso la fattura con l'importo minore." << endl << endl;
	cout << "In questo caso è :" << GF.metodo3() << endl << endl;

	cout << endl << endl << "                           ::::Quarto Metodo:::" << endl << endl;
	cout << "Sia M la media degli importi delle fatture emesse e ricevute da un'azienda. Restituire il nome dell'azienda che ha il valore di M più alto." << endl << endl;
	cout << "In questo caso è :" << GF.metodo4() << endl << endl;

	cout << endl << endl << "                           ::::Quinto Metodo:::" << endl << endl;
	cout << "Restituire il numero di aziende che ha emesso solo fatture per prodotti dello stesso tipo." << endl << endl;
	cout << "In questo caso è :" << GF.metodo5() << endl << endl;
	
	
//	for( int i = 0; i < 5; i++)
//		{
//			cout << f[i];
//		}
	return 0;
}
