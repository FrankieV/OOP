#ifndef CARTA_H
#define CARTA_H


#include <string>
#include <iostream>

using namespace std;

class Carta
{
  friend ostream &operator << (ostream &, const Carta &);
  public:
   Carta(): valore(0), seme("none"){}
   const int getValore() const;
   const string &getSeme() const;
   void setValore(const unsigned int &);
   void setSeme(const string &);
  
  private:
  unsigned int valore;
  string seme;


};

#endif
