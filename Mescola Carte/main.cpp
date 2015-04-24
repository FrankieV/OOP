#include <iostream>
using namespace std;
#include "Carta.h"
#include <list>
#include <cstdlib>
#include <ctime>

bool MazzoMescolato( list<Carta> &l)
{
	for( list<Carta>::iterator it = l.begin(); it != l.end(); it++)
		{
			if( (*it).getMescolata() == false)
				return false;	
		}
	return true;			
}

void Mescola( list<Carta> &l)
{
	srand(time (0));
	int countCarta1 = 0;
	int countCarta2 = 0;
	int countMescolate = 0;
	Carta tmp;
	list<Carta>::iterator it1;
	list<Carta>::iterator it2;
	while( MazzoMescolato(l) == false )
		{
			it1 = l.begin();
			it2 = l.begin();			
			countCarta1 = rand()%40;
			for( int i = 0; i < countCarta1; i++)
				it1++;
			(*it1).setMescolata();
			countCarta2 = rand()%40;
			while( countCarta1 == countCarta2)
				countCarta2 = rand()%40;
			for( int i = 0; i < countCarta2; i++)
				it2++;
			(*it2).setMescolata();
			tmp = *it1;
			*it1 = *it2;
			*it2 = tmp;		
		}
	//cout << countMescolate;
}

int main()
{
	list<Carta> l;
	for( int i = 0; i < 40; i++ )
		{
			Carta carta;		
			l.push_back(carta); 
		}	
	Mescola( l );	
	for( list<Carta>::iterator it = l.begin(); it != l.end(); it++)
		{
			cout << *it << endl;	
		}			
	return 0;
}

