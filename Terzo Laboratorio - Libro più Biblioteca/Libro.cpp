#include <iostream>
#include <cstring>
#include "Libro.h"	

using namespace std;

//Costruttore senza parametri classe Libro
Libro::Libro():Codice(0)
{
	Titolo = new char [1];
	Titolo[0] = '\0';
	Autore = new char [1];	
	Autore[0] = '\0';
}

//Costruttore per copia classe Libro
Libro::Libro( const Libro& l): Codice(l.Codice)
{
	Titolo = 0;
	setTitolo( l.Titolo);
	Autore = 0;
	setAutore( l.Autore );	
}

//Costruttore con tre parametri classe Libro
Libro::Libro( int Cod, char * Tit, char * Aut ) : Codice(Cod)
{
	Titolo = 0;
	setTitolo( Tit );
	Autore = 0;
	setAutore( Aut );
}

//Distruttore classe Libro
Libro::~Libro()
{
	delete [] Titolo;
	delete [] Autore;
}

//Definizione funzione membro setCodice
void Libro::setCodice( int cod )
{
	Codice = ( cod >= 0 )? cod : 0; 
}

//Definizione funzione membro setTitolo
void Libro::setTitolo( const char *tit )
{
	if( Titolo != 0)		
		delete [] Titolo;
	Titolo = new char [ strlen( tit ) + 1 ];
	strcpy( Titolo, tit );
}

//Definizione funzione membro setAutore
void Libro::setAutore( const char *aut )
{
	if( Autore != 0)		
		delete [] Autore;
	Autore = new char [ strlen( aut ) + 1 ];
	strcpy( Autore, aut );
}

//Definizione funzione membro getCodice
int Libro::getCodice() const
{
	return Codice;
}

//Definizione funzione membro getTitolo
char* Libro::getTitolo() const
{
	return Titolo;
}

//Definizione funzione membro getAutore
char* Libro::getAutore() const
{
	return Autore;
}

//Definizone della funzione membro setLibro a tre parametri
void Libro::setLibro( int codice, const char* titolo, const char* autore )
{
	Codice = codice;
	Titolo = 0;
	setTitolo( titolo );
	Autore = 0;
	setAutore( autore );
}

//Definizione funzione membro setLibro per copia
void Libro::setLibro( const Libro& l ) 
{
	Codice = l.Codice;
	Titolo = 0;
	setTitolo( l.Titolo );
	Autore = 0;
	setAutore( l.Autore );
}

//Definizione funzione membro stampaLibro 
void Libro::stampaLibro() const
{
	cout << endl;	
	cout << "Il codice del libro è:" << endl;
	cout << Codice << endl << endl;
	cout << "Il titolo del libro è:" << endl;
	cout << Titolo << endl << endl;
	cout << "L'autore del libro è:" << endl;
	cout << Autore << endl << endl;
}

