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
<<<<<<< HEAD
    void aggiungidestinazioni( list<string>& t);
};

=======
    void ordinaDistanze(vector<int> &);
};
>>>>>>> 044ce621082209a3cc6d4ede41bd36b1273d403c
list<Tratta>& Alitalia::getContent()
{
    return tratte;
}
#endif
