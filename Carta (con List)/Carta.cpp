#include "Carta.h"

const int  Carta::getValore() const
{
  return valore;
}

const string & Carta::getSeme() const
{
  return seme;
}

void Carta::setValore(const unsigned int & v)
{
 valore = v;
}

void Carta::setSeme(const string & s)
{
 seme = s;
}

ostream &operator << (ostream& o, const Carta &c)
{
  o << c.valore << " " << c.seme << endl;
  return o;
}
