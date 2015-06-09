#include"Esame.h"
#include<iostream>

using namespace std;


Esame::Esame(string N , string M , string NE, int V, int C ) : nomestudente(N), matricola(M), nomeEsame(NE), voto(V), crediti(C)
{

}
void Esame::setCrediti(int c)
{
	crediti=c;
}
int Esame::getCrediti()
{
	return crediti;
}
void Esame::setNomeStudente(string N)
{
	nomestudente=N;
}

void Esame::setMatricola(string M)
{
	matricola=M;
}
void Esame::setNome(string NE)
{
	nomeEsame= NE; 
}
void Esame::setVoto(int V)
{
	voto=V;
} 

string Esame::getNomeStudente()
{
	return nomestudente;
}
string Esame::getMatricola()
{
	return matricola;
}
string Esame::getNomeEsame()
{
	return nomeEsame;
}
int Esame::getVoto()
{
	return voto;
}

void Esame::stampa()
{
	cout<<"---------------------------------------"<<endl;
	cout<<"Nome studente: "<<nomestudente<<endl;
	cout<<"matricola: "<<matricola<<endl;
	cout<<"Nome esame: "<<nomeEsame<<endl;
	cout<<"Voto "<<voto<<endl;
	cout<<"---------------------------------------"<<endl;
}

