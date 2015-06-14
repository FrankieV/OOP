#include <iostream>
#include "GestioneHotel.h"
#include <iostream>


using namespace std;

int main()
{
	GestioneHotel Olliver_Hint;
	Olliver_Hint.InitHotel(10, 5, 8);
	
	unsigned int scelta;
    
    cout << "Benvenuto nel gestore prenotazioni dell' Hotel Olliver Hint" << endl;
    do
    {
      cout << "Gestore Prenotazioni - Olliver Hint" << endl;
      cout << "Premi 1 per aggiungere una prenotazione" << endl;
      cout << "Premi 2 per rimuovere una prenotazione" << endl;
      cout << "Premi 3 per ottenere le informazioni su tutte le camere" << endl;
      cout << "Premi 0 per uscire" << endl;
      
      cin >> scelta;
      
      switch(scelta)
      {
        case(1):
            Olliver_Hint.addPrenotazione();
            break;
        case(2):
            Olliver_Hint.removePrenotazione();
            break;
        case(3):
            Olliver_Hint.getInfoAllCamere();
            break;
        default:
            Olliver_Hint.getInfoAllCamere();
      }
    }while(scelta != 0);
    
	return 0;
}
