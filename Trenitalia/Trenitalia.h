#ifndef TRENITALIA_H
#define TRENITALIA_H

#include "Tratta.h"
#include <cstdlib>
#include <list>

class Trenitalia
{
 private:
    list<Tratta> tratte;
 public:
    int metodo1();
    int metodo2(Percentile p);
    bool metodo3(string partenza,string destinazione);
    int metodo4(TipoTreno t);
    void stampa();
    void add(Tratta t);
    inline list<Tratta>& getContent();
    void stampalista();
};
list<Tratta>& Trenitalia::getContent()
{
    return tratte;
}
#endif
