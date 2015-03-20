#ifndef STUDENTE_H
#define STUDENTE_H
#include "Data.h"

using namespace std;

class Studente
{
	public:
		Studente();
		Studente( const Studente &);
		void setNumeroMatricola( int );
		void setVotoEsame( int, int);
		void setDataNascita();
		int getNumeroMatricola() const;
		int getVotoEsame( unsigned ) const;
		Data getDataNascita() const;
		void leggiStudente();
		void stampaStudente() const;
		double getMedia() const;
		int getVotoMax()  const;
		int getNumEsamiAllaLaurea() const;	
		bool StudentePiuGiovaneDi( const Studente &) const;
	private:
		int NumeroMatricola;
		int VotoEsame;
		Data DataNascita;
		int Esami[25];
		unsigned EsamiSuperati;
		int EsamiCorsoDiLaurea;
};

#endif
