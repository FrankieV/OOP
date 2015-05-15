#ifndef FATTURA_H
#define FATTURA_H

#include <string>
#include <list>
using namespace std;

enum PRODOTTO {ALIMENTARE = 0, SPORTIVO, CULTURALE};

class Fattura
{
    public:
        Fattura():AziendaEmessa(""), AziendaRicevuta(""),ImportoFattura(0),tipo_prodotto(ALIMENTARE){}
        Fattura(const string & aziendaEmessa , const string & aziendaRicevuta , const int & importo, PRODOTTO p): AziendaEmessa(aziendaEmessa), 
                                                                                                      AziendaRicevuta(aziendaRicevuta),
                                                                                                      ImportoFattura(importo),
                                                                                                      tipo_prodotto(p){}
        string getAziendaEmessa() const { return AziendaEmessa; }
        string getAziendaRicevuta() const { return AziendaRicevuta; }
        int getImportoFattura() { return ImportoFattura; }
        PRODOTTO getTipoProdotto() {return tipo_prodotto;}
    private:  
        string AziendaEmessa, AziendaRicevuta;
        int ImportoFattura;
        PRODOTTO tipo_prodotto;
};

#endif
