#include <iostream>
#include "Terna.h"

using namespace std;

Terna::Terna(int p, int s, int t)
{
    setPrimo(p);
    setSecondo(s);
    setTerzo(t);
}

int Terna::getPrimo()
{
  return primo;
}

int Terna::getSecondo()
{
  return secondo;
}


int Terna::getTerzo()
{
  return terzo;
}

void Terna::setPrimo(int p)
{
  if(p >= -100 && p <= 100)
    primo = p;
  else
    primo = 0;
}

void Terna::setSecondo(int s)
{
   if(s >= -100 && s <= 100)
    secondo = s;
   else
   secondo = 0;
}

void Terna::setTerzo(int t)
{
    if(t >= -100 && t <= 100)
    terzo = t;
    else
    terzo = 0;
}

void Terna::prodottoAssegna(const Terna &T)
{
  primo *= T.primo;
  secondo *= T.secondo;
  terzo *= T.terzo;
}

bool Terna::Maggiore(const Terna &T)
{
  int somma_t1 = primo + secondo + terzo;
  int somma_t2 = T.primo + T.secondo + T.terzo;
  
  if(somma_t1 > somma_t2)
     return true;
         
  return false;
}

bool Terna::Uguali(const Terna &T)
{
  if(primo == T.primo && secondo == T.secondo && terzo == T.terzo)
     return true;
     
  return false;
}
