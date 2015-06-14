#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

using namespace std;


class Player
{
    friend ostream &operator << (ostream &, const Player &);
    public:
    Player():Nickname(""),isOnline(false),punteggio(0){}
    virtual ~Player(){}
    virtual int getPunteggio() const = 0;
    virtual string getTipo() const = 0;
    const string & getNick() const {return Nickname;}
    void setNick(string n) { Nickname = n; }
    void setPunteggio(int punti) {punteggio = punti; }
    
    protected:
    string Nickname; 
    int punteggio;
    bool isOnline;
    
};

ostream &operator << (ostream & out, const Player & p)
{
    out << "Nickname: " << p.Nickname << endl;
    out << "Punteggio: " << p.getPunteggio() << endl;
    out << "Tipo player: " << p.getTipo() << endl;
 
    return out;
}


#endif
