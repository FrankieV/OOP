#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <iostream>

using namespace std;

class Game
{
    public:
    Game():max_player(0),pegi(0){}
    virtual ~Game(){}
    virtual const Player & getWinner() const = 0;
    bool operator == (const Game &) const;
    virtual int getMaxPlayer() const {return max_player;}
    virtual int getPegi() const {return pegi;}
    void setPlayer(const Player& p1) { *p = p1; }
    void getPlayer() const { cout << *p; }
    
    protected:
    Player* p;
    unsigned int max_player;
    unsigned int pegi;

};

#endif
