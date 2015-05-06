#include <iostream>
#include <string>
#include "Mondiale.h"
using namespace std;

int main()
{
	int n;
	string squadA;
	string squadB;
	string Refery;
	Mondiale MO;
	Partita PA;
	cout << endl << endl;
	for( int i = 0; i < 3; i++)
		{
			cout << "Inserisci il nome della prima squadra: ";
			cin >> squadA;
			PA.setSquadra1( squadA );
			cout << "Inserisci il nome della seconda squadra: ";			
			cin >> squadB;
			PA.setSquadra2( squadB );			
			cout << "Quanti gol ha fatto in questa partita " << squadA << " ?" << endl;			
			cin >> n;
			PA.setGolSquadra1( n );
			cout << "Quanti gol ha fatto in questa partita " << squadB << " ?" << endl;
			cin >> n;
			PA.setGolSquadra2( n );
			cout << "Chi ha arbitrato la partita " << squadA << " vs " << squadB << " ?" << endl;
			cin >> Refery;
			PA.setArbitro( Refery );
			MO.aggiungi( PA );
		}	
	cout << endl << endl << "                           ::::Primo Metodo:::" << endl << endl;
	cout << "Sia M la media dei gol segnati in tutte le partite (utilizzare la divistone intera)." << endl << endl;
	cout << "Sia P to partita con meno gol segnati tra le partite con un numero di gol segnati >= M.( nel caso in cui più partite soddisfino la condizione prendere la prima in ordine di appartztone nella lista)" << endl << endl;
	cout << "Restituire i gol della partita P. " << endl << endl;
	cout << "Se non sono presenti partite, restituire -1." << endl << endl;
	cout << "In questo caso è :" << MO.metodo1() << endl << endl;
//	cout << endl << endl << "                           ::::Secondo Metodo:::" << endl << endl;
//	cout << "Restituisce il primo numero della terza tripla della lista ordinata seguendo questi criteri : " << endl << endl;
//	cout << "-Prima tutte le triple con il valore piu' alto di num1." << endl << endl;
//	cout <<	"-A parita' di valore del num1, le triple con il valore piu' alto di num2." << endl << endl;
//	cout << "-A parita' di valore del num2, le triple con il valore piu' alto di num3." << endl << endl;
//	cout << "In questo caso è :" << CA.metodo2() << endl << endl;


//	cout << endl << endl << "                           ::::Terzo Metodo:::" << endl << endl;
//	cout << "Sia LD la lista di triple duplicate. Una tripla e considerata duplicata se i primi due nuneri sono uguali. "; 
//	cout << "Restituire il massimo della somma tra num1 e num2 degli elementi in LD." << endl << endl;
//	cout << "In questo caso è :" << CA.metodo3() << endl << endl;

//	
//	cout << endl << endl << "                           ::::Quarto Metodo:::" << endl << endl;
//	cout << "Sia P il primo numero a 4 cifre della lista (considerando solo il num3). " << endl;
//	cout <<	"Sia PMAX il numero max che e' possibile comporre usando tutte le cifre di P. " << endl;
//	cout << "Sia PMIN il numero min che e' possibile comporre usando tutte le cifre di P. " << endl;
//	cout << "Restituire PMAX-PMIN." << endl << endl;
//	cout << "In questo caso è :" << CA.metodo4() << endl << endl;
	return 0;
}
