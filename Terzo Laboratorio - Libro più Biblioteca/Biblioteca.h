#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Libro.h"

class Biblioteca
{
	public:
			Biblioteca( int );
			~Biblioteca();
			int getCapacita() const;
			int getSpazioRimasto() const;
			bool inserisci( const Libro& );
			int trova( int ) const;
			void stampaBiblioteca() const;			
	private: 
			const int Capacita;
			int NumeroDiLibri;
			Libro *Collezione;
};

#endif
