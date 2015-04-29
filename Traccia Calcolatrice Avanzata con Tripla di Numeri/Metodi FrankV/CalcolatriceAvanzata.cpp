int CalcolatriceAvanzata::metodo1()
{
  bool primo_1 = true, primo_2 = false;
  int num_start = 2;
  int num_bilanciate = 0;
  
for(list<TriplaNumert>::iterator it = numeri.begin(); it != numeri.end(); it++)
{
	 /* IMPLEMENTARE QUESTO METODO */ 
	 
	 if(numeri.empty())
		 return -1;
	 
     while(num_start < it -> getNum1()) 
     {
     if(it -> getNuml() % num_start == 0)    
	 primo_1 = false;
         
         num start++;
     }
     num_start = 2;
     while(num start < it -> getNum2()) 
     {
         if(it -> getNum2() % num_start == 0)
         primo_2 = false;

         nun start++;
     }
	
	if(it -> getNum1() <= 1) 
	primo_1 = false;

	if(it -> getNum2() <= 1)
	primo_2 = false;

	if(primo_l == false && primo_2 == true)
	nun_bilanciate++;
	else if(primo_1 == true && primo_2 == false)
	nun_bilanciate++;

	primo_1 = true;
    primo_2= true;
    num_start = 2;
}

return num bilanciate;
}



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
	    if(it -> getNuml() < it_2 -> getNum1())
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
				*tt = *it2;
				*it_2 = temp_num;
			}
		  }
		}
	}
  }
}

 /*
 Sia LD la lista di triple duplicate.
 Una tripla e' considerata duplicata se i primi due numeri sono uguali.
 Restituire il massimo della somma tra numi. e num degli elementi in LD.

 Esempio:
(1,2,4) (1,2,6) (3,4,7) (3,4,7) (3,4,8) (5,6,2) (6,5,2) Le triple duplicate sono (,,_) e (,,_).
 La somma di numi e num della prima tripla e' pari a .
 La somma di numi_ e num della seconda tripla a .
 Quindi il metodo deve restituire .

 Se la lista e' vuota o non ha duplicati restituire -1.

 */
 int CalcolatriceAvanzata::metodo3()
 {
 /* IMPLEMENTARE QUESTO METODO */
 return -1;
}

  /*
  Sia P il primo numero a  4 cifre della lista (considerando solo il numi).
 
  Sia PMAX il numero max che e' possibile comporre usando tutte le cifre di P.
  Sia PMIN il numero min che e' possibile comporre usando tutte le cifre di P.
 
  Restituire PMAX-PMIN.
 
Ad esempio, sia P = 1243, allora PMAX=4321 e PMIN=1234. 
 Se la lista e' vuota o se non ha numeri a  cifre restituire  -1.
 
  */
 int CalcolatriceAvanzata::metodo4()
  {
  /* IMPLEMENTARE QUESTO METODO */
  return -1;
 }
