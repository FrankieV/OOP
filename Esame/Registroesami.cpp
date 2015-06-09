#include<iostream>
#include"Esame.h"
#include"Registroesami.h"

#include <math.h>

using namespace std ; 


void Registroesami::StampaLista()
{
	for(list<Esame>::iterator it = esami.begin(); it!= esami.end(); it++ )
	{
		(*it).stampa();	
	}
}


void Registroesami::aggiungi(Esame E )
{
	esami.push_back(E);
}

/*
Metodo1 
Calcolare la varianza dei voti di tutti gli esami nel registro.

La varianza di un insieme di voti è definita come la media dei
quadrati della differenza fra ogni voto X e la media M di tutti i voti. 
Detto diversamente se X_1,..., X_n sono i voti nell'insieme, la varianza è pari a: 

	 n
	----
	\
	 )      (X_i - M)^2 
	/
	-----
	i=1
----------------------------------
		n

Utilizzare la divisione intera

Sela lista degli esami è vuota, restituire -1
*/

int Registroesami::metodo1()
{
    if(esami.empty())
        return -1;
        
	int M = 0;
	int somma_voti = 0;
	int varianza = 0;
	int quadrato = 0;
	
	for(list<Esame>::iterator it = esami.begin(); it != esami.end(); it++)
	{
	    somma_voti += it -> getVoto();
	}
	
	M = somma_voti / esami.size();
	
	for(list<Esame>::iterator it = esami.begin(); it != esami.end(); it++)
	{
	    quadrato = pow(it -> getVoto() - M, 2);
	    varianza += quadrato;
	    
	}
	
	return varianza;

}


/*
Dato uno studente s, sia P(s) la percentuale (intera) di successo di s agli esami nel registro, 
calcolata come il numero degli esami superati (voto non inferiore a 18) moltiplicato per 100 e diviso 
per il numero di esami che s ha sostenuto

Lo studente s è eccellente se P(s) è maggiore o uguale al 75-esimo percentile della distribuzione 
crescente delle percentuali di successo di tutti gli studenti

Data la matricola di uno studente s, il metodo restituisce true se lo studente s è eccellente, false altrimenti

Se il registro è vuoto restituisce false

Si ricorda che data una lista ordinata di N elementi, l'n-esimo percentile è l'elemento che si trova in  posizione N*n/100
(approssimato per difetto)  
 
*/

bool Registroesami::metodo2(string matricola)
{
    if(esami.empty())
        return -1;
        
	list<string> Studenti_Matr;
	vector<int> PercentualeSuccesso;
	for(list<Esame>::iterator it = esami.begin(); it != esami.end(); it++)
	{
	    Studenti_Matr.push_back(it -> getMatricola());
	}
	
	Studenti_Matr.sort();
	Studenti_Matr.unique();
	
	for(list<string>::iterator it = Studenti_Matr.begin(); it != Studenti_Matr.end(); it++)
	{
	    int num_esami_superati = 0;
	    int num_esami_sostenuti = 0;
	    for(list<Esame>::iterator it_2 = esami.begin(); it_2 != esami.end(); it_2++)
	    {
	        if(*it == it_2 -> getMatricola())
	        {
	            num_esami_sostenuti++;
	            if(it_2 -> getVoto() >= 18)
	            {
	                num_esami_superati++;
	            }
	        }
	    } 
	    
	    PercentualeSuccesso.push_back((num_esami_superati*100)/num_esami_sostenuti);
	}
	
	ordinaLista(PercentualeSuccesso);
	
	int pos_percentile = (PercentualeSuccesso.size() * 75) / 100;
	
	int cont = 0;
	
	for(list<string>::iterator it = Studenti_Matr.begin(); it != Studenti_Matr.end(); it++)
	{   
	    if(*it == matricola)
	    {
	        if(PercentualeSuccesso[cont] >= PercentualeSuccesso[pos_percentile])
	            return true;
	    }
	    
	    cont++;
	}
	
	return false;
	
	
}


/*
Uno studente è il peggiore per un esame se è quello che lo ha ripetuto più volte. 

Determinare il numero degli studenti peggiori per un dato esame	

Se il registro è vuoto restituisce 0.
*/

int Registroesami::metodo3(string esame)
{
	 if(esami.empty())
	    return -1;
	    
	 list<string> Studenti;
	 
	 for(list<Esame>::iterator it = esami.begin(); it != esami.end(); it++)
	 {
	    Studenti.push_back(it -> getMatricola());
	 }
	 
	 Studenti.sort();
	 Studenti.unique();
	 
	 int cont_ripetizioni = 0;
	 int num_studenti_peggiori = 0;
	 
	 for(list<string>::iterator it = Studenti.begin(); it != Studenti.end(); it++)
	 {
	    for(list<Esame>::iterator it_2 = esami.begin(); it_2 != esami.end(); it_2++)
	    {
	        if(*it == it_2 -> getMatricola() && it_2 -> getNomeEsame() == esame)
	        {
	            cont_ripetizioni++;
	        }
	    }
	    
	    if(cont_ripetizioni > 1)
	    num_studenti_peggiori++;
	    
	    cont_ripetizioni = 0;
	 }
	
	return num_studenti_peggiori;
}

/*
Dato uno studente determinare se questi ha la media più alta del registro, la media si intende pesata sui crediti e 
calcolata solo sugli esami superati, se la condizione è soddisfatta, restituire la media dello studente, 
altrimenti restituire -1  

la media di uno studente è convenzionalmente pari a 0 se questi non ha superato alcun esame

se il registro è vuoto restituire -1  
*/

int Registroesami::metodo4(string matricola)
{

    if(esami.empty())
        return -1;
         
    list<string> Studenti;
    vector<int> MediaStudenti;
    vector<int> Voti;
    vector<int> Crediti;
    
    for(list<Esame>::iterator it = esami.begin(); it != esami.end(); it++)
    {
       Studenti.push_back(it-> getMatricola());
    }
    
    Studenti.sort();
    Studenti.unique();
     
    for(list<string>::iterator it = Studenti.begin(); it != Studenti.end(); it++)
    {
        for(list<Esame>::iterator it_2 = esami.begin(); it_2 != esami.end(); it_2++)
        {
            if(*it == it_2 -> getMatricola())
            {
                if(it_2 -> getVoto() >= 18)  // presumo che ci sia una sola occorrenza di un esame superato
                {
                    Voti.push_back(it_2 -> getVoto());
                    Crediti.push_back(it_2 -> getCrediti());
                }
            }
        }
        
        MediaStudenti.push_back(getMedia(Voti,Crediti));
        
        Voti.clear();
        Crediti.clear();
    }
    
    int cont = 0;
    int media_studente = 0;
    for(list<string>::iterator it = Studenti.begin(); it != Studenti.end(); it++)
    {
        if(*it == matricola)
        {
            media_studente = MediaStudenti[cont];
            break;
        }
        
        cont++;
    }
    
    bool media_piu_alta = true;
    
    for(int i = 0; i < MediaStudenti.size(); i++)
    {
        if(i != cont)
        {
            if(media_studente <= MediaStudenti[i])
            {
                media_piu_alta = false;
            }
        }
    }
    
    if(media_piu_alta)
        return media_studente;
        
     return -1;
    
    
}

void Registroesami::ordinaLista(vector<int> &lista )
{
    int tmp = 0;
    for(int i = 0; i < lista.size(); i++)
    {
        for(int j = i; j < lista.size(); j++)
        {
            if(lista[i] > lista[j])
            {
                tmp = lista[j];
                lista[j] = lista[i];
                lista[i] = tmp;
            }
        }
    }
}

int Registroesami::getMedia(vector<int>& voti, vector<int>& crediti)
{
    int voti_per_crediti = 0;
    int somma_crediti = 0;
    for(int i = 0; i < voti.size(); i++)
    {
        voti_per_crediti = voti_per_crediti + (voti[i] * crediti[i]);
        somma_crediti += crediti[i];
    }
    
    return voti_per_crediti/somma_crediti;
    

}


