#include"Trenitalia.h"

/*
Sia X la media delle distanze di tutte le tratte. Determinare la massima 
distanza fra quelle che hanno una distanza minore o uguale a X.

Se la lista delle tratte e' vuota, restituire -1;
*/
int Trenitalia:: metodo1()
{
	if( tratte.empty())
		return -1;
	
	int cont = 0;
	int somma_distanze = 0;	
	int X;
	int distanza_massima = 0;
		
	for( list<Tratta>:: iterator it = tratte.begin(); it != tratte.end(); it++ )
		{
			somma_distanze += it -> getDistanza();
			cont++;
		}
		
	X = somma_distanze / cont;
	
	for( list<Tratta>:: iterator it = tratte.begin(); it != tratte.end(); it++ )
		{
			if( it -> getDistanza() <= X )
				{
					if( it -> getDistanza() > distanza_massima)
						distanza_massima = it -> getDistanza();
				}
		}
	
	return distanza_massima;
}

/*
Determinare il quartile richiesto sulle distanze ordinate in modo crescente. Il
metodo non deve modificare la lista tratte.

Se la lista delle tratte e' vuota, restituire -1;

Si ricorda che, data una lista ordinata di N elementi,

- il PRIMO_QUARTILE e' l'elemento che si trova in posizione N/4(approssimato
per difetto);

- il secondo quartile, o MEDIANA, e' l'elemento che si trova in posizione N/2
(approssimato per difetto);

- il TERZO_QUARTILE e' l'elemento che si trova in posizione 3*N/4(approssimato
per difetto); 
*/

int Trenitalia::metodo2(Percentile p)
{
	list<Tratta> copia_tratte;
	copia_tratte = tratte;
	Tratta tmp;	
	int index = 0;
	int cont = 0;
	
	for( list<Tratta>::iterator it1 = copia_tratte.begin(); it1 != copia_tratte.end(); it1++)
		{
			for( list<Tratta>::iterator it2 = it1; it2 != copia_tratte.end(); it2++ )
				{
					if( it1 -> getDistanza() > it2 -> getDistanza())
						{
							tmp = *it1;
							*it1 = *it2;
							*it2 = tmp;
						}	
				}
		}

	for( list<Tratta>::iterator it = copia_tratte.begin(); it != copia_tratte.end(); it++)
		cout << it->getDistanza();

	switch(p)
		{
			case PRIMO_QUARTILE:
				index = ( copia_tratte.size())/4;
				break;
			
			case MEDIANA:
				index = ( copia_tratte.size())/2;
				break;
			
			case TERZO_QUARTILE:	
				index = (copia_tratte.size()*3)/4;
				break;
		}
	
	for( list<Tratta>::iterator it = copia_tratte.begin(); it != copia_tratte.end(); it++ )
		{
			if( cont == index )
				return it -> getDistanza();
			cont++;		
		}	
}



/*
Data una citta' di partenza e una di destinazione, verificare se esiste una
connessione dalla citta' di partenza a quella di destinazione, Restituire
true se tale connessione esiste, false altrimenti.

Se la citta' di partenza coincide con la citta' di destinazione, restituire
true;

Se la lista tratte e' vuota, e la citta' di partenza e' diversa da quella 
di destinazione, restituire false;
*/

bool Trenitalia::metodo3(string partenza,string destinazione)
{
	if( tratte.empty())
		return false;
		
	if( partenza == destinazione )
		return true;
	
	list<string> Destinazioni;
	bool presente = false;

	for( list<Tratta>:: iterator it = tratte.begin(); it != tratte.end(); it++)
		{
			if( partenza == it -> getDa())
				Destinazioni.push_back( it -> getA());
		}

	Destinazioni.sort();
	Destinazioni.unique();

	for( list<string>::iterator it1 = Destinazioni.begin(); it1 != Destinazioni.end(); it1++ )
		{
			for( list<Tratta>::iterator it2 = tratte.begin(); it2 != tratte.end(); it2++ )
				{
					if( *it1 == it2 -> getDa())
						{
							for( list<string>:: iterator it3 = Destinazioni.begin(); it3 != Destinazioni.end(); it3++ )
								{
									if( it2 -> getA() == *it3 )
										presente = true;
								}
							
							if( presente == false )
								Destinazioni.push_back( it2 -> getA());
						}	
					presente = false;
				}
		}

	for( list<string>::iterator it = Destinazioni.begin(); it != Destinazioni.end(); it++ )
		{
			if( *it == destinazione )
				return true;
		}
		
	return false;
	
}


/*
Dato un tipo di treno T, determinare il numero di citta' 
da cui partono e arrivano solo treni di tipo T.
*/
int Trenitalia::metodo4(TipoTreno t)
{
	if( tratte.empty())
		return -1;
	
	list<string> citta;
	list<string> cittaSoloT;
	
	for( list<Tratta>::iterator it = tratte.begin(); it != tratte.end(); it++ )
		{
			citta.push_back( it -> getDa());	
			citta.push_back( it -> getA());
		}

	citta.sort();
	citta.unique();
	
	bool solo = true;

	for( list<string>::iterator it1 = citta.begin(); it1 != citta.end(); it1++ )
		{
			for( list<Tratta>::iterator it2 = tratte.begin(); it2 != tratte.end(); it2++ )
				{
					if( *it1 == it2 -> getA() || *it1 == it2 -> getDa())
						{
							if( t != it2 -> getTipo())
								solo = false; 
						}
				}
			
			if( solo == true )
				cittaSoloT.push_back( *it1 );

			solo = true;
		}

	return cittaSoloT.size();
	

}

void Trenitalia::stampalista()
{
	
}


void Trenitalia::add(Tratta t)
{
 tratte.push_back(t);
}
