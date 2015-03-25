#include <iostream>
#include "Biblioteca.h"
#include "Libro.h"
#include <cstring>
using namespace std;

int main()
{
	int codice;
	char Autore[30];
	char Titolo[30];
	char a;
	int cont = 0;
	Biblioteca B(10);
	Libro l[5];
	for( int i = 0; i < 2; i++)
		{
			cout << "Inserisci il codice del libro :" << endl;			
			cin >> codice;	
			l[i].setCodice(codice);
			cout << endl << endl;
			cout << "Inserisci il nome dell'autore :'" << endl;
			cin.ignore();
			cin.clear();			
			cin.getline( Autore, 30 );
			l[i].setAutore( Autore );
			cout << endl << endl;
			cout << "Inserisci il titolo del libro :" << endl;
			cin.clear();
			cin.getline( Titolo, 30 );			
			l[i].setTitolo( Titolo );
			cout << endl << endl;
			B.inserisci( l[i] );		
		}
	B.stampaBiblioteca();
	return 0;
}
