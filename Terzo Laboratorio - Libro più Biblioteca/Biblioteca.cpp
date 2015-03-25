#include <iostream>
#include "Biblioteca.h"
#include "Libro.h"

using namespace std;

Biblioteca::Biblioteca( int cap ) : Capacita(cap), NumeroDiLibri(0)
{
	if( Capacita > 0)
		Collezione = new Libro[Capacita];
}

Biblioteca::~Biblioteca()
{
	delete [] Collezione;
}

int Biblioteca::getCapacita()const
{
	return Capacita;
}

int Biblioteca::getSpazioRimasto()const
{
	return Capacita - NumeroDiLibri;
}

bool Biblioteca::inserisci(const Libro &l)
{
	if( NumeroDiLibri < Capacita)
		{
			Collezione[NumeroDiLibri].setLibro( l );
			NumeroDiLibri++;
			return true;
		}
	return false;
}

int Biblioteca::trova( int cod ) const
{
	for( int i = 0; i < Capacita; i++)
		{
			if( Collezione[i].getCodice() == cod )
				return i;
		}
	return -1;
}
		
void Biblioteca::stampaBiblioteca() const
{
	cout << "La Biblioteca può contenere : " << Capacita << " libri." << endl << endl;
	cout << "La Biblioteca al momento contiene: ";
	if( NumeroDiLibri > 1) 
		cout << NumeroDiLibri << " libri." << endl << endl;
	else
		cout << NumeroDiLibri << " libro." << endl << endl;	
	for( int i = 0; i < NumeroDiLibri; i++)
		{
			cout << "Libro Numero : " << i+1;
			Collezione[i].stampaLibro();
		}
}



