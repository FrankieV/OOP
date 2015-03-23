#include <iostream>
#include <cassert>
#include "Razionale.h"

using namespace std;

Razionale::Razionale():numeratore(0),denominatore(1)
{ }

Razionale::Razionale(int num): numeratore(num), denominatore(1)
{ }

Razionale::Razionale(int num, int den)
{
  numeratore = num;
  setDenominatore(den);
}

int Razionale::getNumeratore() const
{
  return numeratore;
}

int Razionale::getDenominatore() const
{
  return denominatore;
}

void Razionale::setNumeratore(int n)
{
   numeratore = n;
}

void Razionale::setDenominatore(int d)
{
   if(d != 0)
      denominatore = d;
   else
      denominatore = 1;
}

void Razionale::Print() const
{
  cout << numeratore << "/" << denominatore; 
}

void Razionale::Inverti() 
{
  assert(denominatore==0);
  int tmp = numeratore;
  numeratore = denominatore;
  denominatore = tmp;
}

void Razionale::prodottoAssegna(const Razionale& r)
{
  numeratore *= r.numeratore;
  denominatore  *= r.denominatore;
}

void Razionale::sommaAssegna(const Razionale& r)
{ 
  int mcd = 2;
  int max = 1;
  while(mcd <= denominatore || mcd <= r.denominatore)
  {
    if(mcd % denominatore == 0 && mcd % r.denominatore == 0)
    {
      max = mcd;
    }
    
    mcd++;
  }
  
  int num_new_1 = (max/denominatore)*numeratore;
  int num_new_2 = (max/r.denominatore)*r.numeratore;
  
  numeratore = num_new_1 + num_new_2;
  denominatore = max;
  
}

double Razionale::Converti() const
{
  return (double)numeratore/denominatore;
}

void Razionale::Riduci()
{
  int cont = 2;
  int mcm = 0;
  bool trovato = false;
  while(cont <= numeratore && cont <= denominatore)
  {
     if(numeratore % cont == 0 && denominatore % cont == 0 && trovato == false)
     {
        mcm = cont;
        trovato = true;
     }     
     cont++;
  } 
  
  while(numeratore % mcm == 0 && denominatore % mcm == 0)
  {
    numeratore /= mcm;
    denominatore /= mcm;
  }
  
}
