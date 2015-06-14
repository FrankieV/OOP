#ifndef ALITALIA_H
#define ALITALIA_H

#include "Tratta.h"
#include <cstdlib>
#include <list>
#include <vector>
#include <algorithm>

class Alitalia
{
 private:
    list<Tratta> tratte;
 public:
    int metodo1();
    int metodo2(Percentile p);
    bool metodo3(string partenza,string destinazione);
    int metodo4(TipoAereo t);
    void stampa();
    void add(Tratta t);
    inline list<Tratta>& getContent();
    void stampalista();
    void aggiungidestinazioni( list<string>& t);
};

list<Tratta>& Alitalia::getContent()
{
    return tratte;
}
#endif
