#include "Trenitalia.h"

int main()
{
	Tratta t[5];
	Trenitalia TRE;
	string rispostas;
	string Partenza;
	string Arrivo;
	TipoTreno tt;
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
			
			cout << "Inserisci il tipo del treno: -1 Regionale, -2 Intercity, -3 Espresso, -4 Eurostar";
			cin >> rispostai;
			switch( rispostai )
				{
					case 1:
						tt = REGIONALE;
						break;
			
					case 2:
						tt = INTERCITY;
						break;
			
					case 3:	
						tt = ESPRESSO;
						break;

					case 4:
						tt = EUROSTAR;
						break; 
		
					break;
				}

			t[i].setTipo( tt );

			TRE.add(t[i]);
		}

	cout << endl << endl << "                           ::::Primo Metodo:::" << endl << endl;
	cout << "Sia X la media delle distanze di tutte le tratte. Determinare la massima"; 
	cout <<	" distanza fra quelle che hanno una distanza minore o uguale a X." << endl;
	cout << "In questo caso è :" << TRE.metodo1() << endl << endl;;

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

	cout << "In questo caso è :" << TRE.metodo2(pe) << endl << endl;
	
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
	cout << "In questo caso è :" << ((TRE.metodo3( Partenza, Arrivo ))? "VERO":"FALSO") << endl << endl;
	
	cout << endl << endl << "                           ::::Quarto Metodo:::" << endl << endl;
	cout << "Dato un tipo di treno T, determinare il numero di citta' da cui partono e arrivano solo treni di tipo T.";
	cout << endl;
	cout << "In questo caso è :" << TRE.metodo4( tt ) << endl << endl;	
	
	return 0;
}
