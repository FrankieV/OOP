#include <iostream>
#include "Carta.h"
#include <list>
#include <vector>
#include <stdlib.h>
#include <ctime>


void Mescola_Carte(list<Carta> &);

using namespace std;

int main()
{
   srand(time(0));
   list<Carta> Mazzo_Carte;
   
   Carta c;
   for(int i = 0; i < 4; i++)
   {
     switch(i)
     {
      case(0):
      c.setSeme("D");
      break;
      case(1):
      c.setSeme("M");
      break;
      case(2):
      c.setSeme("S");
      break;
      case(3):
      c.setSeme("C");
      break;
     }
     
     for(int j = 1; j <= 10; j++)
     {
     c.setValore(j);
     Mazzo_Carte.push_back(c);
     }
   }
   
   Mescola_Carte(Mazzo_Carte);
   
   for(list<Carta>::iterator it=Mazzo_Carte.begin(); it != Mazzo_Carte.end(); it++)
   {
     cout << *it;
   }   
}

void Mescola_Carte(list<Carta> &Mazzo_Carte)
{
  unsigned int pos_estratta;
  list<Carta>::iterator it_2;
  Carta tmp;
 
  for(list<Carta>::iterator it=Mazzo_Carte.begin(); it != Mazzo_Carte.end(); it++)
  {
     pos_estratta = rand() % 39;
     it_2 = Mazzo_Carte.begin();
     
     for(int i = 0; i <= pos_estratta; i++)
     {
       ++it_2;
     }
     
     tmp.setValore(it_2 -> getValore());
     tmp.setSeme(it_2 -> getSeme());
     it_2 -> setValore(it -> getValore());
     it_2 -> setSeme(it -> getSeme());
     it -> setValore(tmp.getValore());
     it -> setSeme(tmp.getSeme());
     
  }
   
}


