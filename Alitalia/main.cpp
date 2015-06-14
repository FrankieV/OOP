#include "Alitalia.h"

int main()
{
	Tratta t[5];
	Alitalia ALI;
	string rispostas;
	string Partenza;
	string Arrivo;
	TipoAereo ta;
	Percentile pe;
	int rispostai;
	for( int i = 0; i < 5; i++ )
		{	
			cout << endl << endl;

			cout << "Inserisci la città di partenza: ";
			cin >> rispostas;
			t[i].setDa(rispostas);
			cout << endl;

			cout << "Inserisci la città di arrivo: ";
			cin >> rispostas;
			t[i].setA(rispostas);
			cout << endl;

			cout << "Inserisci la distanza della tratta: ";
			cin >> rispostai;
			t[i].setDistanza(rispostai);
			cout << endl;
			
			cout << "Inserisci il tipo del treno: -1 A, -2 B, -3 C, -4 D";
			cin >> rispostai;
			switch( rispostai )
				{
					case 1:
						ta = A;
						break;
			
					case 2:
						ta = B;
						break;
			
					case 3:	
						ta = C;
						break;
					
					case 4:
						ta = D;
						break;
		
					break;
				}

			t[i].setTipo( ta );

			ALI.add(t[i]);
		}

	cout << endl << endl << "                           ::::Primo Metodo:::" << endl << endl;
	cout << "Sia X la media delle distanze di tutte le tratte. Determinare la MEDIA"; 
	cout <<	" distanza fra quelle che hanno una distanza minore o uguale a X." << endl;
	cout << "Se la lista delle tratte e' vuota, restituire -1" << endl;
	cout << "In questo caso è :" << ALI.metodo1() << endl << endl;;

	cout << endl << endl << "                           ::::Secondo Metodo:::" << endl << endl;
	cout << "Determinare il quartile richiesto sulle distanze ordinate in modo crescente. Il metodo non deve modificare la lista tratte." << endl;
	cout << "Se la lista delle tratte e' vuota, restituire -1" << endl;
	cout << "Si ricorda che, data una lista ordinata di N elementi!" << endl;
	cout << "- il PRIMO_QUARTILE e' l'elemento che si trova in posizione N/4(approssimato per difetto)" << endl;
	cout <<	"- il secondo quartile, o MEDIANA, e' l'elemento che si trova in posizione N/2 (approssimato per difetto)" << endl;
	cout << "- il TERZO_QUARTILE e' l'elemento che si trova in posizione 3*N/4(approssimato per difetto)" << endl << endl;
	cout << "Inserisci il percentile: 1-PRIMO_QUARTILE, 2-MEDIANA, 3-TERZO_QUARTILE" << endl;
	cin >> rispostai;

	switch( rispostai )
	{
		case 1:
			pe = PRIMO_QUARTILE;
			break;

		case 2:
			pe = MEDIANA;
			break;

		case 3:
			pe = TERZO_QUARTILE;
			break;
		
		break;
	}

	cout << "In questo caso è :" << ALI.metodo2(pe) << endl << endl;
	
	cout << endl << endl << "                           ::::Terzo Metodo:::" << endl << endl;
	cout << "Data una citta' di partenza e una di destinazione, verificare se esiste una";
	cout <<	" connessione dalla citta' di partenza a quella di destinazione, Restituire"; 
	cout << " true se tale connessione esiste, false altrimenti." << endl;
	cout <<	"Se la citta' di partenza coincide con la citta' di destinazione, restituire";
	cout << " true. Se la lista tratte e' vuota, e la citta' di partenza e' diversa da quella";
	cout << " di destinazione, restituire false." << endl << endl;

	cout << "Inserisci la città di partenza: ";
	cin >> Partenza;
	cout << endl;
	cout << "Inserisci la città di destinazione: ";
	cin >> Arrivo;
	cout <<endl;
	cout << "In questo caso è :" << ((ALI.metodo3( Partenza, Arrivo ))? "VERO":"FALSO") << endl << endl;
	
	cout << endl << endl << "                           ::::Quarto Metodo:::" << endl << endl;
	cout << "Dato un tipo di treno T, determinare il numero di citta' da cui partono e arrivano solo treni di tipo T.";
	cout << endl;
	cout << "In questo caso è :" << ALI.metodo4( ta ) << endl << endl;	
	
	return 0;
}
