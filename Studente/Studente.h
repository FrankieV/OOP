#pragma once
#ifndef STUDENTE_H
#define STUDENTE_H

#include "Data.h"

class Studente
{
public:
	Studente();
	Studente(const Studente &);
	//Studente(int, const Data&, int[], int dim);
	void setMatricola(int);
	void setVoto(int);
	void setBirthDate(const Data&);
	int getMatricola() const;
	int getVoto(int) const;
	void getBirthDate() const;
	void leggiStudente();
	void printStudente() const;
	float getMedia() const;
	int getVotoMax() const;
	int getNumEsami() const;
//	bool youngStudent(const Studente &) const;

private:
	int matricola;
	Data birthDate;
	int num_voti;
	int Voti[25];
};

#endif

