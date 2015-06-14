#ifndef TRATTA_H
#define TRATTA_H

#include <string>
#include <list>
#include <iostream>
#include <vector>

using namespace std;

enum TipoAereo{UNDEF=0, A, B, C, D};
enum Percentile{PRIMO_QUARTILE=0, MEDIANA, TERZO_QUARTILE};

class Tratta
{
  private:
      string da;
      string a;
      int distanza;
      TipoAereo tipo;
  public:
      Tratta(string _da = "", string _a = "", int _distanza = 0, TipoAereo _tipo = UNDEF);
      string getDa()const;
      string getA()const;
      int getDistanza()const;
      TipoAereo getTipo()const;
      void setDa(string);
      void setA(string);
      void setDistanza(int);
      void setTipo(TipoAereo); 
<<<<<<< HEAD
      bool operator==(const Tratta&)const;	
      bool operator<(const Tratta&) const;
=======
      bool operator==(const Tratta&)const;
	 bool operator<(const Tratta&) const;
>>>>>>> 044ce621082209a3cc6d4ede41bd36b1273d403c
};
#endif
