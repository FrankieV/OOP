#include "CalcolatriceAvanzata.h"
#include "TriplaNumeri.h"

int CalcolatriceAvanzata::metodo1()
{
  bool primo_1 = true, primo_2 = true;
  int num_start = 2;
  int num_bilanciate = 0;
  
for(list<TriplaNumeri>::iterator it = numeri.begin(); it != numeri.end(); it++)
{
	 /* IMPLEMENTARE QUESTO METODO */ 
	 
	 if(numeri.empty())
		 return -1;
	 
     while(num_start < it -> getNum1()) 
     {
     if(it -> getNum1() % num_start == 0)    
	 primo_1 = false;
         
         num_start++;
     }
     num_start = 2;
     while(num_start < it -> getNum2()) 
     {
         if(it -> getNum2() % num_start == 0)
         primo_2 = false;

         num_start++;
     }
	
	if(it -> getNum1() <= 1) 
	primo_1 = false;

	if(it -> getNum2() <= 1)
	primo_2 = false;

	if(primo_1 == false && primo_2 == true)
	num_bilanciate++;
	else if(primo_1 == true && primo_2 == false)
	num_bilanciate++;

	primo_1 = true;
    primo_2= true;
    num_start = 2;
}

return num_bilanciate;
}

/*
Restituire il num1 della terza tripla della lista ordtnata nel seguente modo:
-Prima tutte le triple con il valore piu' alto di num1.
-A parita' di valore del num1, le triple con il valore piu' alto di num2.
-A parita' di valore del num2, le triple con il valore piu' alto di num3.
Se la lista ha meno di 3 elementi restituire -1.
ATTENZIONE: NON MODIFICARE la lista di numeri ma creare una copia temporanea.
*/

int CalcolatriceAvanzata::metodo2()
{
   /* IMPLEMENTARE QUESTO METODO */ 

   if(numeri.size() < 3)
   return -1;

   list<TriplaNumeri> tmp = numeri; 
   TriplaNumeri temp_num; 

   for(list<TriplaNumeri>::iterator it= tmp.begin(); it != tmp.end(); it++)
   { 
      for(list<TriplaNumeri>::iterator it_2 = it; it_2 != tmp.end(); it_2++) 
      {
	    if(it -> getNum1() < it_2 -> getNum1())
        {
			temp_num = *it;
			*it = *it_2;
			*it_2 = temp_num;
		}
		else if(it -> getNum1() == it_2 -> getNum1())
		{
		  if(it -> getNum2() < it_2 -> getNum2())
		  {
			temp_num = *it; 
			*it = *it_2;
			*it_2 = temp_num;
		  }
		  else if(it -> getNum2() == it_2 -> getNum2()) 
		  {
			if(it -> getNum3() < it_2 -> getNum3())
			{
				temp_num = *it; 
				*it = *it_2;
				*it_2 = temp_num;
			}
		  }
		}
	}
  }
  
  list<TriplaNumeri>::iterator it = tmp.begin();
  for(int i = 1; i < 3; i++)
  ++it;
  
  return it -> getNum1();
  
}

 /*
 Sia LD la lista di triple duplicate.
 Una tripla e' considerata duplicata se i primi due numeri sono uguali.
 Restituire il massimo della somma tra num1 e num2 degli elementi in LD.

 Esempio:
(1,2,4) (1,2,6) (3,4,7) (3,4,7) (3,4,8) (5,6,2) (6,5,2) Le triple duplicate sono (1,2,_) e (3,4,_).
 La somma di num1 e num2 della prima tripla e' pari a 3.
 La somma di num1_ e num2 della seconda tripla a 7.
 Quindi il metodo deve restituire 7.

 Se la lista e' vuota o non ha duplicati restituire -1.

 */
int CalcolatriceAvanzata::metodo3()
{
 /* IMPLEMENTARE QUESTO METODO */
 if(numeri.empty())
 return -1;
 
 int max = 0;
 int somma_num = 0;
 bool duplicati = false;
 list<TriplaNumeri> LD = numeri;
 for(list<TriplaNumeri>::iterator it = LD.begin(); it != LD.end(); it++)
 {
   for(list<TriplaNumeri>::iterator it_2 = it; it_2 != LD.end(); it_2++)
   {
     if(it != it_2)
     {
       if(it -> getNum1() == it_2 -> getNum1() && it -> getNum2() == it_2 -> getNum2())
       {
         duplicati = true;
         somma_num = it -> getNum1() + it -> getNum2();
         if(somma_num > max)
         {
           max = somma_num;
         } 
         it_2 -> setNum1(0);
         it_2 -> setNum2(0);
       }
     }
   }
   somma_num = 0;
 }
 
 if(!duplicati)
  return -1;
  
  return max;
 
}

  /*
  Sia P il primo numero a  4 cifre della lista (considerando solo il num3).
 
  Sia PMAX il numero max che e' possibile comporre usando tutte le cifre di P.
  Sia PMIN il numero min che e' possibile comporre usando tutte le cifre di P.
 
  Restituire PMAX-PMIN.
 
Ad esempio, sia P = 1243, allora PMAX=4321 e PMIN=1234. 
 Se la lista e' vuota o se non ha numeri a 4 cifre restituire  -1.
 
  */
int CalcolatriceAvanzata::metodo4()
{
  /* IMPLEMENTARE QUESTO METODO */
  
  if(numeri.empty())
   return -1;
  
  int cont_cifre = 0;
  int tmp;
  bool trovato = false;
  vector<int> PMAX, PMIN;
  for(list<TriplaNumeri>::iterator it = numeri.begin(); it != numeri.end(); it++)
  {
    if(!trovato)
    {
    tmp = it -> getNum3();
    while(tmp != 0)
    {
      PMAX.push_back(tmp % 10);
      PMIN.push_back(tmp % 10);
      cont_cifre++;
      tmp /= 10;
    }
    
    if(cont_cifre == 4)
    trovato = true;
    else
    {
      PMAX.clear();
      PMIN.clear();
      cont_cifre = 0;
    }
    }
  }
    
    if(trovato)
    {
    int temp;
    for(int i = 0; i < PMAX.size(); i++)
    {
      for(int j = i; j < PMAX.size(); j++)
      {
       if(PMAX[i] < PMAX[j])
       {
          temp = PMAX[i];
          PMAX[i] = PMAX[j];
          PMAX[j] = temp;
       }
      }
    }
    
    for(int i = 0; i < PMIN.size(); i++)
    {
      for(int j = i; j < PMIN.size(); j++)
      {
       if(PMIN[i] > PMIN[j])
       {
          temp = PMIN[i];
          PMIN[i] = PMIN[j];
          PMIN[j] = temp;
       }
      }
    }
    
     int p_max = 0, p_min = 0;
     for(int j = 0; j < PMAX.size()-1; j++)
      {
        p_max = (p_max + PMAX[j]) * 10;
        p_min = (p_min + PMIN[j]) * 10;
      }
     
     p_max += PMAX[3];
     p_min += PMIN[3];
     
     return p_max - p_min;
    
    }
     
    return -1;
    
}


