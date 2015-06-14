#ifndef REGISTROESAMI_H
#define REGISTROESAMI_H
#include<iostream>
#include"Esame.h"
#include<list>
#include<string>
#include<vector>
using namespace std ;

class Registroesami
{
	private:
		list<Esame> esami;
		
	public:
		void aggiungi(Esame);
		int metodo1();
		bool metodo2(string);
		int metodo3(string);
		int metodo3bis(string esame);
		int metodo4(string);
		void ordinaLista(vector<int> &);
		int getMedia(vector<int>& voti, vector<int>& crediti);
		void StampaLista();
};
#endif
