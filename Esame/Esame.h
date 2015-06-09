#ifndef ESAME_H
#define ESAME_H
#include<string>
#include<iostream>
using namespace std;

class Esame
{
	private:
		string nomestudente;
		string matricola;
		string nomeEsame; 
		int voto;
		int crediti;
	public:
		Esame(string, string, string, int, int);
		void setNomeStudente(string);
		void setMatricola(string);
		void setNome(string);
		void setVoto(int);
		void setCrediti(int); 
		void stampa();

		string getNomeStudente();
		string getMatricola();
		string getNomeEsame();
		int getCrediti();
		int getVoto();

};

#endif
		
