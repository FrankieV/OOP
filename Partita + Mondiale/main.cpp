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
	for( int i = 0; i < 5; i++)
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
			cout << endl << endl;
		}
	
	cout << endl << endl << "                           ::::Primo Metodo:::" << endl << endl;
	cout << "Sia M la media dei gol segnati in tutte le partite (utilizzare la divistone intera)." << endl << endl;
	cout << "Sia P to partita con meno gol segnati tra le partite con un numero di gol segnati >= M.( nel caso in cui più partite soddisfino la condizione prendere la prima in ordine di apparizione nella lista)" << endl << endl;
	cout << "Restituire i gol della partita P. " << endl << endl;
	cout << "Se non sono presenti partite, restituire -1." << endl << endl;
	cout << "In questo caso è :" << MO.metodo1() << endl << endl;

	cout << endl << endl << "                           ::::Secondo Metodo:::" << endl << endl;
	cout << "Determinare il numero di arbitri che non hanno mai arbitrato piu' di una partita della stessa squadra. " << endl << endl;
	cout << "Se non sono presenti partite, restituire -1" << endl << endl;
	cout << "In questo caso è :" << MO.metodo2() << endl << endl;


	cout << endl << endl << "                           ::::Terzo Metodo:::" << endl << endl;
	cout << "Restituire il numero di arbitri che hanno arbitrato solo partite finite con piu' di due gol di differenza" << endl << endl;
	cout << "Se non sono presenti partite, restituire -1." << endl << endl;
	cout << "In questo caso è :" << MO.metodo3() << endl << endl;

	
	cout << endl << endl << "                           ::::Quarto Metodo:::" << endl << endl;
	cout << "Data la seguente definizone: " << endl;
	cout <<	"Una squadra S1 domina una squadra S2 se:" << endl;
	cout << "- S1 vince una partita in trasferta contro S2 con almeno due gol di scarto, oppure " << endl;
	cout << "- S1 domina S3 ed S3 domina S2." << endl << endl; 
	cout << "Il metodo deve restituire il numero di squadre dominate dalla squadra1 della prima partita della lista." << endl << endl;
	cout << "Note:" << endl << endl;
	cout << "	-Una squadra S domina sempre se stessa." << endl << endl;
	cout << "Se non sono presenti partite, restituire -1." << endl << endl;
	cout << "In questo caso è :" << MO.metodo4() << endl << endl;

	return 0;
}
