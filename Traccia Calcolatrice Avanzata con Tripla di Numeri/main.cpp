#include <iostream>
#include "CalcolatriceAvanzata.h"
using namespace std;

int main()
{
	int n;
	CalcolatriceAvanzata CA;
	TriplaNumeri TN;
	for( int i = 0; i < 5; i++)
		{
			cin >> n;
			TN.setNum1( n );
			cin >> n;
			TN.setNum2( n );
			cin >> n;
			TN.setNum3( n );
			CA.aggiungi( TN );
		}	
	cout << endl << endl << "                           ::::Primo Metodo:::" << endl << endl;
	cout << "In questo caso è :" << CA.metodo1() << endl << endl;
	cout << endl << endl << "                           ::::Secondo Metodo:::" << endl << endl;
	cout << "Restituisce il primo numero della terza tripla della lista ordinata seguendo questi criteri : " << endl << endl;
	cout << "-Prima tutte le triple con il valore piu' alto di num1." << endl << endl;
	cout <<	"-A parita' di valore del num1, le triple con il valore piu' alto di num2." << endl << endl;
	cout << "-A parita' di valore del num2, le triple con il valore piu' alto di num3." << endl << endl;
	cout << "In questo caso è :" << CA.metodo2() << endl << endl;


	cout << endl << endl << "                           ::::Terzo Metodo:::" << endl << endl;
	cout << "Sia LD la lista di triple duplicate. Una tripla e considerata duplicata se i primi due nuneri sono uguali. "; 
	cout << "Restituire il massimo della somma tra num1 e num2 degli elementi in LD." << endl << endl;
	cout << "In questo caso è :" << CA.metodo3() << endl << endl;
	return 0;
}
