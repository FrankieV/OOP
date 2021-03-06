
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
	bool stessa_squadra = false;
	list<string> Arbitri;
	for( list<Partita>::iterator it1 = partite.begin(); it1 != partite.end(); it1++ )
		{
			for( list<Partita>::iterator it2 = partite.begin(); it2 != partite.end(); it2++ )
				{
					if( it1 != it2 )
						{
							if( ( it1-> getArbitro() == it2 -> getArbitro() ) && ( it1 -> getSquadra1() == it2 -> getSquadra1() || 
								  it1 -> getSquadra1() == it2 -> getSquadra2() || it1 -> getSquadra2() == it2 -> getSquadra1() || 
								  it1 -> getSquadra2() == it2 -> getSquadra2()))
								stessa_squadra = true;						
						}
				} 
			if( stessa_squadra == false )
				Arbitri.push_back( it1 -> getArbitro());
			stessa_squadra = false;
		}

	Arbitri.sort();
	Arbitri.unique();
	return Arbitri.size();
}

/*
Restituire il numero di arbitri che hanno arbitrato solo partite finite con piu' di due gol di                                             differenza                                                         
Se non sono presenti partite, restituire -1.

*/
int Mondiale::metodo3()
{
	/* IMPLEMENTARE QUESTO METODO*/

	bool Solo = true;
	list<string> Arbitri;
	for( list<Partita>::iterator it1 = partite.begin(); it1 != partite.end(); it1++ )
		{
			for( list<Partita>::iterator it2 = partite.begin(); it2 != partite.end(); it2++ )
			{
				if( (it1 -> getArbitro() == it2 -> getArbitro()) && ( it2 -> getGolSquadra1() - it2 -> getGolSquadra2() <= 2 ) && 
				  ( it2 -> getGolSquadra2() - it2 -> getGolSquadra1() <= 2 ))
							Solo = false;
			}
			if( Solo == true )			
				Arbitri.push_back( it1 -> getArbitro() );		
			Solo = true;
		}
	Arbitri.sort();
	Arbitri.unique();
	return Arbitri.size();
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
	string squadra;
	string squadraDominata;
	list<string> SquadreDominate;
	bool prima_volta = true;
	for( list<Partita>::iterator it1 = partite.begin(); it1 != partite.end(); it1++ )
		{
			if( prima_volta == true )
				{
					squadra = it1 -> getSquadra1();
					prima_volta = false;
				}			
			if( ( it1 -> getSquadra2() == squadra || it1 -> getSquadra2() == squadraDominata) && 
			  ( it1 -> getGolSquadra2() - it1 -> getGolSquadra1() >= 2 ))
				{	
					SquadreDominate.push_back( it1 -> getSquadra1() );	
					squadraDominata = it1 -> getSquadra1();	
					for( list<Partita>::iterator it2 = partite.begin(); it2 != partite.end(); it2++ )
						{
							if(( it1 -> getSquadra1() == it2 -> getSquadra2()) &&
							  ( it2 -> getGolSquadra2() - it2 -> getGolSquadra1() >= 2))
								SquadreDominate.push_back( it2 -> getSquadra1());						
						}
				}
		}
	SquadreDominate.sort();
	SquadreDominate.unique();
	return SquadreDominate.size();
}

