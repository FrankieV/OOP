#include <iostream>
#include "Studente.h"


using namespace std;

int main()
{
	Studente s1;
	Data d(2, 12, 1994);
	s1.getBirthDate();

	s1.setBirthDate(d);
	s1.setMatricola(161992);
	s1.setVoto(22);
	
	cout << s1.getMatricola() << "\n" << s1.getVoto(0);

	cout << endl << "Media dei voti: " << s1.getMedia() << endl;
	cout << s1.getNumEsami() << "\n" << "Voto massimo: " << s1.getVotoMax() << endl;

	Studente s2;
	s2.leggiStudente();
	cout << endl << "Media dei voti: " << s2.getMedia() << endl;
	cout << s2.getNumEsami() << "\n" << "Voto massimo: " << s2.getVotoMax() << endl;

	int N = 0; // numero di studenti
	cout << "Inserisci il numero di studenti " << endl;
	cin >> N;
	Studente *S = new Studente[N];
	for (int i = 0; i < N; i++)
	{
		S[i].leggiStudente();
	}

         for (int i = 0; i < N; i++)
	{
	  cout << "Studende num: " << i << " " << "Matricola: " << S[i].getMatricola();
	  cout << endl << "Media dei voti: " << S[i].getMedia() << endl;
	  cout << S[i].getNumEsami() << "\n" << "Voto massimo: " << S[i].getVotoMax() << endl;
	}
	
}
