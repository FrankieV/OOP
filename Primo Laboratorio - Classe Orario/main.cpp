#include <iostream>
#include "Orario.h"

using namespace std;

int main()
{
	Orario orario;
	cout << endl;
	cout << "Orario definito utilizzando il costruttore di default: " << endl;
	orario.printOrario();
	cout << endl << endl;
	orario.setOrario( 22, 16, 5);
	cout << "Orario definito utilizzando la funzione membro setOrario: " << endl; 
	orario.printOrario();
	cout << endl << endl;
	Orario time;
	time.setOrario( 21, 15, 4);
	time.incrementaOre();
	time.incrementaMinuti();
	time.incrementaSecondi();
	if( orario.confrontaOrari( time ) )
		cout << "I due orari si riferiscono allo stesso frangente di tempo!" << endl;
	else
		cout << "I due orari non si riferiscono allo stesso frangente di tempo!" << endl;
	cout << "Poichè il primo orario è: ";
	orario.printOrario();
	cout << " e il secondo orario é: ";
	time.printOrario();
	cout << endl << endl;	
	return 0;
}
