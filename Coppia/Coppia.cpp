#include <iostream>
#include "Coppia.h"

using namespace std;

Coppia::Coppia(int p, int s) : primo(p), secondo(s) { }

bool Coppia::uguali(const Coppia &c)
{
    if(primo == c.primo && secondo == c.secondo)
     return true;
     
    return false;
}

void Coppia::sommaAssegna(const Coppia &c)
{
   primo += c.primo;
   secondo += c.secondo;
}

void Coppia::stampa()
{
  cout << "( " << primo << "," << secondo << " )";
}

int Coppia::getPrimo()
{
  return primo;
}

int Coppia::getSecondo()
{
  return secondo;
}

void Coppia::setPrimo(int p)
{
  primo = p; 
}

void Coppia::setSecondo(int s)
{
  secondo = s;
} 
