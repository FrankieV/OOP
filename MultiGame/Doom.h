#ifndef DOOM_H
#define DOOM_H

#include "Game.h"


class Doom : public Game
{
    public:
    Doom(){max_player = 1;}
    virtual ~Doom(){}
    virtual const Player& getWinner() const {return *p;}
    void setPegi(int p) { pegi = p; }; // posso accedere ai dati protected della classe base
    int getMaxPlayer() const {return max_player;}
    int getPegi() const {return pegi;}
    void setPlayer(Player* p1) { p = p1; }
};

#endif


