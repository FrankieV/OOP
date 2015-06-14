#include"Alitalia.h"
#include<string>
/*
Sia X la media delle distanze di tutte le tratte. Determinare la MEDIA 
distanza fra quelle che hanno una distanza minore o uguale a X.

Se la lista delle tratte e' vuota, restituire -1;
*/
int Alitalia:: metodo1()
{
	if( tratte.empty() )
		return -1;
		
	int cont_tratte = 0;
	int somma_distanze = 0;
	int X;
	int Media_Distanza;
		
	for( list<Tratta>::iterator it = tratte.begin(); it != tratte.end(); it++ )
		{
			cont_tratte++;	
			somma_distanze += it -> getDistanza();
		}
	X = somma_distanze / cont_tratte;

	cont_tratte = 0;
	somma_distanze = 0;

	for( list<Tratta>::iterator it = tratte.begin(); it != tratte.end(); it++ )
		{
			if( it -> getDistanza() <= X )
				{
					cont_tratte++;
					somma_distanze += it -> getDistanza();
				}
		}

	Media_Distanza = somma_distanze / cont_tratte;

	return Media_Distanza;
	
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

int Alitalia::metodo2(Percentile p)
{

	if( tratte.empty() )
		return -1;	

	list<Tratta> copiaTratte;
	copiaTratte = tratte;
	Tratta tmp;
	int index = 0;
	int cont = 1;

	for( list<Tratta>:: iterator it1 = copiaTratte.begin(); it1 != copiaTratte.end(); it1++ )
		{
			for( list<Tratta>:: iterator it2 = it1; it2 != copiaTratte.end(); it2++ )
				{
					if( it1 -> getDistanza() > it2 -> getDistanza()	)
						{
							tmp = *it1;	
							*it1 = *it2;
							*it2 = tmp;
						}	
				}
		}

	switch( p )
		{
			case PRIMO_QUARTILE:	
				index = (copiaTratte.size()) / 4;
				break;
			
			case MEDIANA:
				index = (copiaTratte.size()) / 2;
				break;
			
			case TERZO_QUARTILE:
				index = ((copiaTratte.size())*3) / 4;
				break;
		}

	for( list<Tratta>:: iterator it1 = copiaTratte.begin(); it1 != copiaTratte.end(); it1++ )
		{
					
			if( cont == index )
				return it1 -> getDistanza();
			
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

bool Alitalia::metodo3(string partenza,string destinazione)
{

	if( partenza == destinazione )
		return true;
	
	if( tratte.empty())
		return false;

	bool presente = false;
	list<string> destinazioni;	

	for( list<Tratta>:: iterator it = tratte.begin(); it != tratte.end(); it++ )
		{
			if( partenza == it -> getDa())
				destinazioni.push_back( it -> getA());
		}

	destinazioni.sort();
	destinazioni.unique();

	for( list<string>::iterator it1 = destinazioni.begin(); it1 != destinazioni.end(); it1++ )	
		{
			for( list<Tratta>::iterator it2 = tratte.begin(); it2 != tratte.end(); it2++ )
				{
					if( *it1 == it2 -> getDa())
						{
							for( list<string>::iterator it3 = destinazioni.begin(); it3 != destinazioni.end(); it3++ )	
								{
									if( *it3 == it2 -> getA())
										presente = true;
								}
				
							if( presente == false )
								destinazioni.push_back( it2 -> getA());
						}
					presente = false;
				}
		}
		
	destinazioni.sort();
	destinazioni.unique();

	for( list<string>::iterator it = destinazioni.begin(); it != destinazioni.end(); it++ )
		{
			if( destinazione == *it)
				return true;
		}
			
	return false;
}


/*
Dato un tipo di aereo t determinare il numero di citta' 
da cui partono e arrivano solo aerei di tipo t.
*/
int Alitalia::metodo4(TipoAereo t)
{
	if( tratte.empty())
		return -1;

	list<string> tuttelecitta;
	list<string> CittaTipot;
	bool solo = true;
	
	for( list<Tratta>::iterator it = tratte.begin(); it != tratte.end(); it++)
		{
			tuttelecitta.push_back( it-> getA());
			tuttelecitta.push_back( it-> getDa());			
		}
	
	tuttelecitta.sort();
	tuttelecitta.unique();

	for( list<string>::iterator it1 = tuttelecitta.begin(); it1 != tuttelecitta.end(); it1++ )
		{
			for( list<Tratta>:: iterator it2 = tratte.begin(); it2 != tratte.end(); it2++ )
				{
					if( *it1 == it2 -> getA() || *it1 == it2 -> getDa())
						{
							if( it2 -> getTipo() != t )
								solo = false;
						}
				}
				
			if( solo == true )
				CittaTipot.push_back(*it1);
		
			solo = true;
		}
		
	CittaTipot.sort();
	CittaTipot.unique();
	
	return CittaTipot.size();
}

void Alitalia::add(Tratta t)
{
 tratte.push_back(t);
}
