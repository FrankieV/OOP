#include <iostream>
#include "GestoreFatture.h"

using namespace std;

int main()
{
    GestoreFatture gest_fatture;
    string azienda_a;
    string azienda_b;
    PRODOTTO p;
    int importo;
    for(int i = 0; i < 4; i++)
    {
        cout << "Inserisci l'azienda che ha emesso la fattura: ";
        cin >> azienda_a;
        cout << endl << "Inserisci l'azienda che ricevuto la fattura: ";
        cin >> azienda_b;
        cout << endl << "Inserisci l'importo della fattura: " ;
        cin >> importo;
        cout << endl << "Inserisci il tipo di prodotto: ALIMENTARE, SPORTIVO, CULTURALE ";
        cin >> p;
        Fattura f(azienda_a,azienda_b,importo,p);
        gest_fatture.aggiungi(f);
    }
    
    for(list<Fattura>::iterator it = gest_fatture.getContent().begin(); it != gest_fatture.getContent().end(); it++)
    {
      cout << it -> getAziendaEmessa() << " " << it -> getAziendaRicevuta() << " " << it ->getImportoFattura() << " " << it -> getTipoProdotto();
    }
    
   /* cout << "Azienda che ha emesso piu' fatture: " << gest_fatture.piuFatture();
    cout << "Azienda che ha emesso la fattura piu' alta: " << gest_fatture.importoMaggiore();
    cout << "Azienda che ha emesso la fattura piu' bassa: " << gest_fatture.importoMinore();*/
    
    
    return 0;
}
