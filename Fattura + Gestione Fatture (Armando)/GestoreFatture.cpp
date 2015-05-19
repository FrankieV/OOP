#include "GestoreFatture.h"

/*Restituire il nome dell'azienda che ha emesso più fatture.*/
string GestoreFatture::metodo1()
{
	if( fatture.empty())
		return "EMPTY";

	int count = 0;
	int max = 0;
	string AziendaCheHaEmessoPiuFatture;
	for( list<Fattura>:: iterator it1 = fatture.begin(); it1 != fatture.end(); it1++ )
		{
			for( list<Fattura>:: iterator it2 = fatture.begin(); it2 != fatture.end(); it2++)
				{
					if( it1 != it2 ) 
						{
							if( it1 -> getAziendaEmittente() == it2 -> getAziendaEmittente() )
								count++;
						}
				}	
			if( count > max ) 
				{
					AziendaCheHaEmessoPiuFatture = it1 -> getAziendaEmittente();
					max = count;
				}		
			count = 0;
		}
	return AziendaCheHaEmessoPiuFatture;
}

/*Restituire il nome dell'azienda che ha emesso la fattura con l'importo maggiore.*/
string GestoreFatture::metodo2()
{
	if( fatture.empty())
		return "EMPTY";
	
	int max = fatture.front().getImporto();
	string AziendaConImportoMaggiore = fatture.front().getAziendaEmittente();	
	for( list<Fattura>:: iterator it = fatture.begin(); it != fatture.end(); it++ )
		{
			if( it -> getImporto() > max )
				{
					max = it -> getImporto();
					AziendaConImportoMaggiore = it -> getAziendaEmittente();
				}		
		}
	return AziendaConImportoMaggiore;
}

/*Restituire il nome dell'azienda che ha emesso la fattura con l'importo minore.*/
string GestoreFatture::metodo3()
{
	if( fatture.empty())
		return "EMPTY";	
	
	int min = fatture.front().getImporto();
	string AziendaConImportoMinore = fatture.front().getAziendaEmittente() ;	
	for( list<Fattura>:: iterator it = fatture.begin(); it != fatture.end(); it++ )
		{
			if( it -> getImporto() < min )
				{
					min = it -> getImporto();
					AziendaConImportoMinore = it -> getAziendaEmittente();
				}		
		}
	return AziendaConImportoMinore;
}

/*Sia M la media degli importi delle fatture emesse e ricevute da un'azienda. Restituire il nome dell'azienda che ha il valore di M più alto.*/
string GestoreFatture::metodo4()
{
	if( fatture.empty())
		return "EMPTY";

	list <string> Aziende;
	int MediaMassima = 0;		
	string AziendaConMediaMassima;	
	int cont = 0;
	int somma = 0;	
	int media = 0;
	bool prima_volta = true;
	for( list<Fattura>:: iterator it = fatture.begin(); it != fatture.end(); it++ )
		{
			Aziende.push_back( it -> getAziendaEmittente());
			Aziende.push_back( it -> getAziendaRicevente());
		}
	Aziende.sort();
	Aziende.unique();
	for( list<string>::iterator it1 = Aziende.begin(); it1 != Aziende.end(); it1++ )
		{
			for( list<Fattura>:: iterator it2 = fatture.begin(); it2 != fatture.end(); it2++ )
				{
					if( *it1 == it2 -> getAziendaEmittente() || *it1 == it2 -> getAziendaRicevente())
						{						
							cont++;
							somma = it2 -> getImporto();
						}				
				}		
			media = somma / cont;
			if( prima_volta == true )
				{
					MediaMassima = media;
					AziendaConMediaMassima = *it1; 		
					prima_volta = false;				
				}	
			if( media > MediaMassima )
				AziendaConMediaMassima = *it1;
	
			somma = 0;
			cont = 0;
			media = 0;	
		}
	return AziendaConMediaMassima;
}

/*Restituire il numero di aziende che ha emesso solo fatture per prodotti dello stesso tipo.*/
int GestoreFatture::metodo5()
{
	if( fatture.empty())
		return -1;

	list<string> Aziende;
	bool solo = true;
	for( list<Fattura>:: iterator it1 = fatture.begin(); it1 != fatture.end(); it1++ )	
		{
			for( list<Fattura>:: iterator it2 = fatture.begin(); it2 != fatture.end(); it2++ )
				{
					if(( it1 -> getAziendaEmittente() == it2 -> getAziendaEmittente()) && ( it1 -> getTipoProdotto() != it2 -> getTipoProdotto()))
						solo = false;
		
				}
			if( solo == true )
				Aziende.push_back( it1 -> getAziendaEmittente() );
			solo = true;
		}
	Aziende.sort();
	Aziende.unique();
	return Aziende.size();
}

/*Restituire la differenza tra il numero di aziende che ha emesso fatture solo per prodotti SPORTIVI e il numero di aziende che ha emesso fatture solo per prodotti CULTURALI.*/
int GestoreFatture::metodo6()
{

}

/*Restituire il numero di aziende che vende solo prodotti ALIMENTARI e compra almeno un prodotto SPORTIVO.*/
int GestoreFatture::metodo7()
{

}

/*Restituire il numero di aziende che non compra prodotti CULTURALI.*/
int GestoreFatture::metodo8()
{

}

/*S(A) la somma degli importi delle fatture emesse da un'azienda A. Siano A1 e A2 due aziende distinte tale per cui S(A1) + S(A2) sia massimo rispetto a tutte le altre coppie di aziende. Restituire il valore di S(A1) + S(A2).*/
int GestoreFatture::metodo9()
{

}

/*Sia A1 l'azienda che ha emesso la fattura per un prodotto ALIMENTARE con l'importo più alto. Sia A2 l'azienda che ha emesso la fattura per un prodotto SPORTIVO con l'importo più basso. Restituire il numero di fatture emesse dall'azienda A1 all'azienda A2.*/
int GestoreFatture::metodo10()
{

}

/* Restituire la stringa con il nome di tutte le aziende che vendono solo prodotti ALIMENTARI separate da una virgola. Esempio di output: A1,A2,A3 (Le aziende devono essere ordinate in ordine lessicografico)*/
int GestoreFatture::metodo11()
{

}

/*Sia A l'azienda che compare di meno nelle fatture (cioè quella che ha emesso e ricevuto meno fatture di tutte le altre). Restituire la stringa con il nome di tutte le aziende che hanno emesso/ricevuto una fattura a/da A separate da una virgola e uno spazio. Esempio di output: A1, A2, A3 (Le aziende devono essere ordinate in ordine lessicografico)*/
int GestoreFatture::metodo12()
{

}

/*Restituire il nome dell'azienda che collabora con più aziende.*/
int GestoreFatture::metodo13()
{

}

/*Restituire la somma degli importi delle fatture emesse dalle aziende che collaborano con la prima azienda in ordine lessicografico.*/
int GestoreFatture::metodo14()
{

}

/*Restituire la stringa con il nome di tutte le aziende che collabora con l'ultima azienda in ordine lessicografico. Esempio di output: A1A2A3 (Le aziende devono essere ordinate in ordine lessicografico)*/
int GestoreFatture::metodo15()
{

}

/*Restituire la somma degli importi delle fatture emesse dall'azienda che ha meno collaborazioni con altre aziende.

Per i metodi dal 13 al 16 si consideri la seguente definizione di collaborazione:
L'azienda A collabora con l'azienda B se:
    - A ha emesso una fattura a favore di B.
    - A collabora con C e C collabora con B.
*/
int GestoreFatture::metodo16()
{

}

