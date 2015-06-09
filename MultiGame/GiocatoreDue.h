#ifndef GIOCATOREDUE_H
#define GIOCATOREDUE_H

#include "GiocatoreUno.h"

class GiocatoreDue : public GiocatoreUno
{
    public:
    GiocatoreDue(){}
    virtual ~GiocatoreDue(){}
    virtual int getPunteggio() const {return 3*punteggio;}
    virtual string getTipo() const { return "GiocatoreDue"; } 
};

#endif
