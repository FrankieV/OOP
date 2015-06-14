#include "CodaConGentleman.h"
#include <iostream>

using namespace std;

int main()
{
    CodaConGentleman coda;
    
    string sesso;
    
    for(int i = 0; i < 9; i++)
    {
        Person p;
        cout << "Inserisci il sesso della persona: " << i << endl;
        cin >> sesso;
        p.setSesso(sesso);
        coda.add(p);
    }
    
    cout << "Lista: " << endl;
    
    coda.printCoda();
    
    coda.remove();
    
    cout << endl;
    coda.printCoda();
    
    coda.remove();
    
    cout << endl;
    coda.printCoda();
    
    return 0;
}
