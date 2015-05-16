#ifndef GESTOREFATTURE_H
#define GESTOREFATTURE_H

#include "Fattura.h"
#include <cstdlib>
#include <iostream>  
#include <list>
#include <vector>
#include <string>


class GestoreFatture
{
  public:
  inline bool aggiungi(Fattura f) { fatture.push_back(f); return true; }
  inline list<Fattura>& getContent() { return fatture; }
  const string piuFatture();
  const string importoMaggiore();
  const string importoMinore();
  const string metodo4();
  const int metodo5();
  const int metodo6();
  const int metodo7();
  const int metodo8();
  const int metodo9();
  const int metodo10();
  const string metodo11();
  const string metodo12();

  private:
    list<Fattura> fatture;

};

#endif
