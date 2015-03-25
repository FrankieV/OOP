#include <iostream>
#include "Libro.h"
using namespace std;

int main()
{	
	Libro l;	
	cout << l.getTitolo() << endl;
	cout << l.getAutore() << endl;
	cout << l.getCodice() << endl;		
	return 0;
}

