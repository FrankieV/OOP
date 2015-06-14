#ifndef TRATTA_H
#define TRATTA_H

#include <string>
#include <list>
#include <iostream>

using namespace std;

enum TipoTreno{UNDEF=0, REGIONALE, ESPRESSO, INTERCITY, EUROSTAR};
enum Percentile{PRIMO_QUARTILE=0, MEDIANA, TERZO_QUARTILE};

class Tratta
{
  private:
      string da;
      string a;
      int distanza;
      TipoTreno tipo;
  public:
      Tratta(string _da = "", string _a = "", int _distanza = 0, TipoTreno _tipo = UNDEF);
      string getDa()const;
      string getA()const;
      int getDistanza()const;
      TipoTreno getTipo()const;
      void setDa(string);
      void setA(string);
      void setDistanza(int);
      void setTipo(TipoTreno); 
      bool operator==(const Tratta&)const;
};
#endif
