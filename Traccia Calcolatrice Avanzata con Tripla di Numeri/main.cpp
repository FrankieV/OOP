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
	for( list<TriplaNumeri>::iterator it = (CA.getContent()).begin(); it !=  (CA.getContent()).end(); it++)
		{
			cout << it -> getNum1();
			cout << it -> getNum2();
			cout << it -> getNum3();
			cout << endl;
		}
//	cout << CA.metodo1() << endl;
//	cout << CA.metodo2() << endl;
//	cout << CA.metodo3() << endl;
	return 0;
}
