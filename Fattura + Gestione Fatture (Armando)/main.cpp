#include "GestoreFatture.h"

int main()
{
	Fattura f[5];
	GestoreFatture GF;
	for( int i = 0; i < 5; i++ )
		{	
			cout << endl << endl;
			cin >> f[i];
			GF.aggiungi(f[i]);
		}

	cout << endl << endl << "                           ::::Primo Metodo:::" << endl << endl;
	cout << "Restituire il nome dell'azienda che ha emesso più fatture." << endl << endl;
	cout << "In questo caso è :" << GF.metodo1() << endl << endl;

	cout << endl << endl << "                           ::::Secondo Metodo:::" << endl << endl;
	cout << "Restituire il nome dell'azienda che ha emesso la fattura con l'importo maggiore." << endl << endl;
	cout << "In questo caso è :" << GF.metodo2() << endl << endl;
	
	cout << endl << endl << "                           ::::Terzo Metodo:::" << endl << endl;
	cout << "Restituire il nome dell'azienda che ha emesso la fattura con l'importo minore." << endl << endl;
	cout << "In questo caso è :" << GF.metodo3() << endl << endl;

	cout << endl << endl << "                           ::::Quarto Metodo:::" << endl << endl;
	cout << "Sia M la media degli importi delle fatture emesse e ricevute da un'azienda. Restituire il nome dell'azienda che ha il valore di M più alto." << endl << endl;
	cout << "In questo caso è :" << GF.metodo4() << endl << endl;

	cout << endl << endl << "                           ::::Quinto Metodo:::" << endl << endl;
	cout << "Restituire il numero di aziende che ha emesso solo fatture per prodotti dello stesso tipo." << endl << endl;
	cout << "In questo caso è :" << GF.metodo5() << endl << endl;
	
	cout << endl << endl << "                           ::::Sesto Metodo:::" << endl << endl;
	cout << "Restituire la differenza tra il numero di aziende che ha emesso fatture solo per prodotti SPORTIVI e il numero di aziende che ha emesso fatture solo per prodotti CULTURALI." << endl << endl;
	cout << "In questo caso è :" << GF.metodo6() << endl << endl;
	
	cout << endl << endl << "                           ::::Settimo Metodo:::" << endl << endl;
	cout << "Restituire il numero di aziende che vende solo prodotti ALIMENTARI e compra almeno un prodotto SPORTIVO." << endl << endl;
	cout << "In questo caso è :" << GF.metodo7() << endl << endl;

	cout << endl << endl << "                           ::::Ottavo Metodo:::" << endl << endl;
	cout << "Restituire il numero di aziende che non compra prodotti CULTURALI." << endl << endl;
	cout << "In questo caso è :" << GF.metodo8() << endl << endl;

	cout << endl << endl << "                           ::::Nono Metodo:::" << endl << endl;
	cout << "S(A) la somma degli importi delle fatture emesse da un'azienda A. Siano A1 e A2 due aziende distinte tale per cui S(A1) + S(A2) sia massimo rispetto a tutte le altre coppie di aziende. Restituire il valore di S(A1) + S(A2)." << endl << endl;
	cout << "In questo caso è :" << GF.metodo9() << endl << endl;
	
	cout << endl << endl << "                           ::::Decimo Metodo:::" << endl << endl;
	cout << "Sia A1 l'azienda che ha emesso la fattura per un prodotto ALIMENTARE con l'importo più alto. Sia A2 l'azienda che ha emesso la fattura per un prodotto SPORTIVO con l'importo più basso. Restituire il numero di fatture emesse dall'azienda A1 all'azienda A2." << endl << endl;
	cout << "In questo caso è :" << GF.metodo10() << endl << endl;

	cout << endl << endl << "                           ::::Undicesimo Metodo:::" << endl << endl;
	cout << "Restituire la stringa con il nome di tutte le aziende che vendono solo prodotti ALIMENTARI separate da una virgola. Esempio di output: A1,A2,A3 (Le aziende devono essere ordinate in ordine lessicografico)" << endl << endl;
	cout << "In questo caso è :" << GF.metodo11() << endl << endl;

	cout << endl << endl << "                           ::::Dodicesimo Metodo:::" << endl << endl;
	cout << "Sia A l'azienda che compare di meno nelle fatture (cioè quella che ha emesso e ricevuto meno fatture di tutte le altre). Restituire la stringa con il nome di tutte le aziende che hanno emesso/ricevuto una fattura a/da A separate da una virgola e uno spazio. Esempio di output: A1, A2, A3 (Le aziende devono essere ordinate in ordine lessicografico)" << endl << endl;
	cout << "In questo caso è :" << GF.metodo12() << endl << endl;
	
	cout << endl << endl << "                           ::::Tredicesimo Metodo:::" << endl << endl;
	cout << "Restituire il nome dell'azienda che collabora con più aziende." << endl << endl;
	cout << "In questo caso è :" << GF.metodo13() << endl << endl;

	cout << endl << endl << "                           ::::Quattordicesimo Metodo:::" << endl << endl;
	cout << "Restituire la somma degli importi delle fatture emesse dalle aziende che collaborano con la prima azienda in ordine lessicografico." << endl << endl;
	cout << "In questo caso è :" << GF.metodo14() << endl << endl;

	cout << endl << endl << "                           ::::Quindicesimo Metodo:::" << endl << endl;
	cout << "Restituire la stringa con il nome di tutte le aziende che collabora con l'ultima azienda in ordine lessicografico. Esempio di output: A1A2A3 (Le aziende devono essere ordinate in ordine lessicografico)" << endl << endl;
	cout << "In questo caso è :" << GF.metodo15() << endl << endl;

	cout << endl << endl << "                           ::::Sedicesimo Metodo:::" << endl << endl;
	cout << "Restituire la somma degli importi delle fatture emesse dall'azienda che ha meno collaborazioni con altre aziende." << endl << endl;
	cout << "In questo caso è :" << GF.metodo16() << endl << endl;
//	for( int i = 0; i < 5; i++)
//		{
//			cout << f[i];
//		}
	return 0;
}
