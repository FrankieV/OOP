#include "Mondiale.h"

/*
sia M la media dei gol segnati in tutte le partite (utilizzare la divistone intera).
Sia P to partita con meno gol segnati tra le partite con un numero di gol segnati >= M.( nel caso in cui più partite soddisfino la condizione prendere la prima in ordine di apparizione nella lista)   
Restituire i gol della partita P.

Se non sono presenti partite, restituire -1.
*/

int Mondiale::metodo1()
{
	/* IMPLEMENTARE QUESTO METODO*/
	if(partite.empty())
		return -1;
	int somma_gol = 0;
	int cont_partite = 0;
	int M = 0;                                                                
	
	for(list<Partita>::iterator it = partite.begin(); it !=partite.end(); it++)
		{
			somma_gol = somma_gol + it -> getGolSquadra1() + it -> getGolSquadra2();
			cont_partite++;
		}

	M = somma_gol/cont_partite;
	
	bool prima_volta = true;
	int min;
	
	for( list<Partita>::iterator it = partite.begin(); it != partite.end(); it++)
		{
			if( it -> getGolSquadra1() + it -> getGolSquadra2() >= M)
				{		
					if(prima_volta)
						{
							min = it -> getGolSquadra1() + it -> getGolSquadra2();
							prima_volta = false;
						}
					if(it -> getGolSquadra1() + it -> getGolSquadra2() < min )
						min = it -> getGolSquadra1() +it -> getGolSquadra2();
				}
		}
	return min;
}


/*
Determinare il numero di arbitri che non hanno mai arbitrato piu' di una partita della stessa squadra. 
Se non sono presenti partite, restituire -1.

*/
int Mondiale::metodo2()
{
	
	/* IMPLEMENTARE QUESTO METODO*/
	if(partite.empty())
	    return -1;
	    
	vector<string> arbitri;
	int cont_presenze = 0;
	
	for(list<Partita>::iterator it = partite.begin(); it != partite.end(); it++)
	{
	    for(list<Partita>::iterator it_2 = partite.begin(); it_2 != partite.end(); it_2++)
	    {
	          if(it -> getSquadra1() == it_2 -> getSquadra1() || it -> getSquadra1() == it_2 -> getSquadra2() ||
                 it -> getSquadra2() == it_2 ->  getSquadra1() || it -> getSquadra2() == it_2 -> getSquadra2()) 
	          {
	            if(it -> getArbitro() == it_2 -> getArbitro())
	            cont_presenze++;
	          }
	    }
	    
	    if(cont_presenze <= 1 && VerificaArbitro(it -> getArbitro(), arbitri) == false)
	    arbitri.push_back(it -> getArbitro());
	    
	    cont_presenze = 0;
	}
		
	return arbitri.size();
	
}

/*
Restituire il numero di arbitri che hanno arbitrato solo partite finite con piu' di due gol di                                             differenza                                                         
Se non sono presenti partite, restituire -1.

*/
int Mondiale::metodo3()
{
	/* IMPLEMENTARE QUESTO METODO*/
	if(partite.empty())
	    return -1;
	
	int differenza_reti = 0;
	vector<string> arbitri;
	for(list<Partita>::iterator it = partite.begin(); it != partite.end(); it++)
	{
	  differenza_reti = abs(it -> getGolSquadra1() - it -> getGolSquadra2());
	  if(differenza_reti > 2 && VerificaArbitro(it -> getArbitro(), arbitri ) == false)
	  arbitri.push_back(it -> getArbitro());
	}
	
	return arbitri.size();

}

/*

Data la seguente definizone:
Una squadra S1 domina una squadra S2 se:
- S1 vince una partita in trasferta contro S2 con almeno due gol di scarto, oppure
- S1 domina S3 ed S3 domina S2.

Il metodo deve restituire il numero di squadre dominate dalla squadra1 della prima partita della lista.

Note:
	-Una squadra S domina sempre se stessa.

Nel caso in cui non ci siano partite restituire -1.
*/
int Mondiale::metodo4()
{
	/* IMPLEMENTARE QUESTO METODO*/
}

bool Mondiale::VerificaArbitro(const string & arbitro, const vector<string> &lista_arbitri ) const
{
  for(int i = 0; i < lista_arbitri.size(); i++)
  {
    if(arbitro == lista_arbitri[i])
    return true;
  }
 
 return false;
}
