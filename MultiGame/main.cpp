#include <iostream>

#include "Doom.h"
#include "GiocatoreUno.h"
#include "GiocatoreDue.h"
#include <list>
#include <iostream>


using namespace std;

int main()
{
    Doom p;
    cout << p.getMaxPlayer() << endl;
    p.setPegi(18);
    cout << p.getPegi() << endl;
    
    GiocatoreUno g1;
    g1.setNick("Nukel");
    g1.setPunteggio(35);
    
    GiocatoreDue g2;
    g2.setNick("Frank");
    g2.setPunteggio(20);
    
    Doom d2;
    
    list<Game*> games;
    p.setPlayer(&g1);
    d2.setPlayer(&g2);
    games.push_back(&p);
    games.push_back(&d2);
    
    for(list<Game*>::iterator it = games.begin(); it != games.end(); it++)
    {
        cout << "Max player: " << (*it) -> getMaxPlayer() << endl;
        (*(*it)).getPlayer(); // altro modo di accedere ai dati membro
        
    }

    return 0;
}
