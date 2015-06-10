#include"Alitalia.h"

/*
Sia X la media delle distanze di tutte le tratte. Determinare la MEDIA 
distanza fra quelle che hanno una distanza minore o uguale a X.

Se la lista delle tratte e' vuota, restituire -1;
*/
int Alitalia:: metodo1()
{
    if(tratte.empty())
        return -1;
         
	int X = 0;
	int somma_distanze = 0;
	for(list<Tratta>::iterator it = tratte.begin(); it != tratte.end(); it++)
	{
	    somma_distanze += it -> getDistanza();
	}
	
	X = somma_distanze / tratte.size();
	
	somma_distanze = 0;
	int cont = 0;
	
	for(list<Tratta>::iterator it = tratte.begin(); it != tratte.end(); it++)
	{
	    if(it -> getDistanza() <= X)
	    {
	        somma_distanze += it -> getDistanza();
	        cont++;
	    }
	}
	
	return somma_distanze / cont;
	
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
    if(tratte.empty())
        return -1;
        
	vector<int> distanze;
	for(list<Tratta>::iterator it = tratte.begin(); it != tratte.end(); it++)
	{
	    distanze.push_back(it -> getDistanza());
	}
	
	ordinaDistanze(distanze);
	
	switch(p)
	{
	    case(PRIMO_QUARTILE):
	        return distanze[distanze.size()/4];
	        break;
	    case(MEDIANA):
	        return distanze[distanze.size()/2];
	        break;
	    case(TERZO_QUARTILE):
	        return distanze[(3*distanze.size())/4];
	        break;
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
	if(tratte.empty() && partenza != destinazione)
	return false;
	
	if(partenza == destinazione)
	return true;
	
	for(list<Tratta>::iterator it = tratte.begin(); it != tratte.end(); it++)
	{
	    if(it -> getDa() == partenza && it -> getA() == destinazione)
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
	list<string> CittaPartenzaArrivo;
	list<string> solo_t;
	bool solo_tipo_t = true;
	
	for(list<Tratta>::iterator it = tratte.begin(); it != tratte.end(); it++)
	{
	    if(it -> getTipo() == t)
	    {
	        CittaPartenzaArrivo.push_back(it -> getA());
	        CittaPartenzaArrivo.push_back(it -> getDa());
	    }
	}
	
	CittaPartenzaArrivo.sort();
	CittaPartenzaArrivo.unique();
	
	for(list<string>::iterator it = CittaPartenzaArrivo.begin(); it != CittaPartenzaArrivo.end(); it++)
	{
	    for(list<Tratta>::iterator it_2 = tratte.begin(); it_2 != tratte.end(); it_2++)
	    {
	        if(*it == it_2 -> getA() || *it == it_2 -> getDa())
	        {
	            if(it_2 -> getTipo() != t)
	                solo_tipo_t = false;
	        } 
	    }   
	    
	    if(solo_tipo_t)
	        solo_t.push_back(*it);
	        
	     solo_tipo_t = true; 
	}
	
	return solo_t.size();
	
}

void Alitalia::add(Tratta t)
{
 tratte.push_back(t);
}

void Alitalia::ordinaDistanze(vector<int> &distanze)
{
    int tmp;
    for(int i = 0; i < distanze.size(); i++)
    {
        for(int j = i; j < distanze.size(); j++)
        {
            if(distanze[i] > distanze[j])
            {
                tmp = distanze[j];
                distanze[j] = distanze[i];
                distanze[i] = tmp;
            }
        }
    
    }

}



