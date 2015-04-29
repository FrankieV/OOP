#include <iostream>
#include "CalcolatriceAvanzata.h"
#include <list>
using namespace std;

int CalcolatriceAvanzata::metodo1()
{
	/* IMPLEMENTARE QUESTO METODO */
	if( numeri.empty())
		return -1; 
	int count = 0; 
	bool primonumero = true;
	bool secondonumero = true;
	for( list<TriplaNumeri>::iterator it = numeri.begin(); it != numeri.end(); it++ )
		{
			if( it -> getNum1() > 1)
				{
					for( int i = 2; i < it -> getNum1(); i++)
						{	
							if(( it -> getNum1() % i) == 0 )
								primonumero = false;
						}	
				}			
			else			
				primonumero = false; 
			if( it -> getNum2() > 1)
				{
					for( int i = 2; i < it -> getNum2(); i ++)
						{					
							if((it -> getNum2() % i) == 0) 
								secondonumero = false;
						}				
				}
			else
				secondonumero = false;
			if( primonumero == true && secondonumero == false)
				count++;
			if( primonumero == false && secondonumero == true)
				count++;
			primonumero = true; 
			secondonumero = true;
		}
    return count;
}

/*

Restituire il num1 della terza tripla della lista ordinata nel seguente modo:

-Prima tutte le triple con il valore piu' alto di num1.
-A parita' di valore del num1, le triple con il valore piu' alto di num2.
-A parita' di valore del num2, le triple con il valore piu' alto di num3.

Se la lista ha meno di 3 elementi restituire -1.

ATTENZIONE: NON MODIFICARE la lista di numeri ma creare una copia temporanea.

*/

int CalcolatriceAvanzata::metodo2()
{
	if( numeri.size() < 3)
		return -1;

	int count = 1;
	TriplaNumeri Tmp;
	list<TriplaNumeri> temporanea = numeri;
	for( list<TriplaNumeri>::iterator it1 = temporanea.begin(); it1 != temporanea.end(); it1++)
		{
			for( list<TriplaNumeri>::iterator it2 = it1; it2 != temporanea.end(); it2++) 
				{
					if( it2 -> getNum1() > it1 -> getNum1())
						{							
							Tmp = *it1;
							*it1 = *it2;
							*it2 = Tmp;
						}
					else
						{
							if( it2 -> getNum1() == it1 -> getNum1() && it2 -> getNum2() > it1 -> getNum1())
								{
									Tmp = *it1;
									*it1 = *it2;
									*it2 = Tmp;
								}
							else
								{
									if( it2 -> getNum1() == it1 -> getNum1() && it2 -> getNum2() == it1 -> getNum2() && it2 -> getNum3() > it1 -> getNum3())
										{
											Tmp = *it1;
											*it1 = *it2;
											*it2 = Tmp;
										}
								}
						}
				}
		}

	for( list<TriplaNumeri>::iterator it = temporanea.begin(); it != temporanea.end(); it++)
  		{
			if( count == 3 ) 
			      return it -> getNum1(); 
    			count++;
		}
}

/*
Sia LD la lista di triple duplicate.
Una tripla e considerata duplicata se i primi due nuneri sono uguali. 
Restituire il massimo della somma tra num1 e num2 degli elementi in LD.

Esempio:
(1,2,4) (1,2,6) (3,4,7) (3,4,7) (3,4,8) (5,6,2)
Le triple duplicate sono (1,2,_) e (3,4,_).
La somma di num1 e num2 della prima trtpla e' pari a 3. 
La somma di num1 e num2 della seconda tripla a 7. 
Quindi il metodo deve restituire 7.

Se la lista e' vuota o non ha dupticati restituire -1. 

*/
int CalcolatriceAvanzata::metodo3()
{ 
	/* IMPLEMENTARE QUESTO METODO */
	int SommaPrimiDueNumeri = 0;
	bool Doppia = false;
	if( numeri.empty())	
		return -1;
	for( list<TriplaNumeri>::iterator it1 = numeri.begin(); it1 != numeri.end(); it1++ )
		{
			for( list<TriplaNumeri>::iterator it2 = numeri.begin(); it2 != numeri.end(); it2++ )
				{
					if( it1 != it2)
						{
							if( it1 -> getNum1() == it2 -> getNum1() && it1 -> getNum2() == it2 -> getNum2())
								{
								    Doppia=true;									
									if(( it1 -> getNum1() + it1 -> getNum2()) > SommaPrimiDueNumeri )
										SommaPrimiDueNumeri = it1 -> getNum1() + it1 -> getNum2();
								}						
						}
				}
		}
	if( Doppia == false)
		return -1;
	return SommaPrimiDueNumeri;
}


/*

Sta P il primo nunero a 4 ctfre della lista (considerando solo il num3).

Sia PMAX il numero max che e' possibile comporre usando tutte le cifre di P. 
Sia PMIN il nunero min che e' posstbtte comporre usando tutte le cifre di P.

Restituire PMAX-PMIN.

Ad esempio, sia P = 1243, allora PMAX = 4321 e PMIN = 1234.

Se la lista e' vuota o se non ha numeri a 4 cifre restituire -1.

*/

int CalcolatriceAvanzata::metodo4()
{
	/* IMPLEMENTARE QUESTO METODO */
	return -1;
}

