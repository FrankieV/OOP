#ifndef GIOCATOREUNO_H
#define GIOCATOREUNO_H

class GiocatoreUno : public Player
{
    public:
    GiocatoreUno(){};
    virtual ~GiocatoreUno(){}
    virtual int getPunteggio() const {return 2*punteggio;}
    virtual string getTipo() const { return "GiocatoreUno"; } 
};

#endif
