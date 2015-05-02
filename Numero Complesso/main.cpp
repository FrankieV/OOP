#include <iostream>
using namespace std;
#include "NumeroComplesso.h"

int main()
{
	NumeroComplesso c1;
	NumeroComplesso c2;
	NumeroComplesso somma;
	NumeroComplesso prodotto;
	cin >> c1;
	cin >> c2;
	cout << c1++;	
	prodotto = c1 * c2;
	cout << prodotto;
	return 0;
}
