#include "Studente.h"
#include <iostream>

using namespace std;

Studente::Studente() : matricola(0), num_voti(0)
{
	for (int i = 0; i < 25; i++)
	{
		Voti[i] = 0;
	}
}

Studente::Studente(const Studente &s)
{
	matricola = s.matricola;
	birthDate = s.birthDate;
	for (int i = 0; i < 25; i++)
	{
		Voti[i] = s.Voti[i];
	}
	num_voti = s.num_voti;
}

void Studente::setMatricola(int m)
{
	matricola = m;
}

void Studente::setBirthDate(const Data &data)
{
	birthDate = data;
}

void Studente::setVoto(int v)
{
	if (num_voti <= 24)
	{
		if (v >= 18 && v <= 30)
		{
			Voti[num_voti] = v;
			num_voti++;
		}
	}
	else
	{
		cout << "Impossibile inserire il voto, hai inserito gia' 25 esami!";
	}
}

int Studente::getMatricola() const
{
	return matricola;
}

void Studente::getBirthDate() const
{
	birthDate.printDate();
}

float Studente::getMedia() const
{
	float somma = 0;
	float media = 0;

	if (num_voti > 0)
	{
		for (int i = 0; i < num_voti; i++)
		{
			somma += Voti[i];
		}

		media = somma / num_voti;
	}
	else
		cout << "Nessun esame in carriera!";


	return media;
}

int Studente::getVoto(int pos) const
{
	if (pos >= 0 && pos < 25)
	{
		if (Voti[pos] != 0)
			return Voti[pos];
		else
			cout << "Esame non ancora sostenuto!" << endl;
	}
	else
		cout << "Attenzione, indice errato!";

	return 0;
}

int Studente::getVotoMax() const
{
	int max = Voti[0];
	for (int i = 1; i < num_voti; i++)
	{
		if (Voti[i] > max)
		{
			max = Voti[i];
		}
	}

	return max;
}


int Studente::getNumEsami() const
{
	cout << "Esami rimanenti: ";
	return 25 - num_voti;
}

void Studente::leggiStudente()
{
	int dd = 0, mm = 0, yr = 0, voto = 0;
	cout << "Inserisci il numero di matricola ";
	cin >> matricola;
	cout << endl << "Inserisci la data di nascita " << endl;
	cout << "dd: ";
	cin >> dd;
	birthDate.setDay(dd);
	cout << endl << "mm ";
	cin >> mm;
	birthDate.setMonth(mm);
	cout << endl << "yr";
	cin >> yr;
	birthDate.setYear(yr);

	cout << endl << "Inserisci i voti " << endl;
	for (int i = 0; i < 25; i++)
	{
		cin >> voto;
		setVoto(voto);
	}
}

//bool Studente::youngStudent(const Studente &s) const
//{
//	if (birthDate.getYear() >= s.birthDate.getYear())
//	{
//		return false;
//	}
//	else if (birthDate.getMonth() >= s.birthDate.getMonth())
//	{
//		return false;
//	}
//	else if (birthDate.getDay() >= s.birthDate.getDay())
//	{
//		return false;
//	}
//
//	return true;
//
//}
