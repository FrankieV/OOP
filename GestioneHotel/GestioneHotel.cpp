#include "GestioneHotel.h"


GestioneHotel::~GestioneHotel(){}

void GestioneHotel::InitHotel(unsigned int singole, unsigned int doppie, unsigned int triple)
{
    
    for (int i = 0; i < singole; i++)
	{
	    Singola* s = new Singola();
		Camere.push_back(s);
	}

	for (int i = 0; i < doppie; i++)
	{
        Doppia* d = new Doppia();
		Camere.push_back(d);
	}

	for (int i = 0; i < triple; i++)
	{
	    Tripla* t = new Tripla();
		Camere.push_back(t);
	}  
    
	num_singole = singole;
	num_doppie = doppie;
	num_triple = triple;
	
}

int GestioneHotel::getNumCamere() const
{
    return num_singole + num_doppie + num_triple;
}

int GestioneHotel::getNumCamereDisponibili() const
{
   return getNumCamere() - num_camere_occupate;
}

void GestioneHotel::addPrenotazione()
{
   unsigned int num_camera = 0;
   cout << "Inserisci il numero della camera che vuoi prenotare: ";
   cin >> num_camera;
   if(num_camera <= Camere.size())
   {
      if(Camere[num_camera] -> getPrenotazione())
      {
        cout << "Spiacente, la camera e' occupata" << endl;
        return;
      }
      else
      {
        Prenotazione p;
        cin >> p;
        Camere[num_camera] -> setPrenotazione(p);
        Camere[num_camera] -> setPrenotazione();
        num_camere_occupate++;
      }
   }
}

void GestioneHotel::removePrenotazione()
{
   unsigned int num_camera = 0;
   cout << "Elimina la prenotazione della camera numero: ";
   cin >> num_camera;
   if(num_camera <= Camere.size())
   {
     if(Camere[num_camera] -> getPrenotazione())
     {
       Camere[num_camera] -> reset();
       num_camere_occupate--;
     }
     else
     cout << "La camere scelta e' già vuota!" << endl;
   }
   else
   {
     cout << "Non esiste una camera con questo numero! " << endl;
   }
    
}


void GestioneHotel::getInfoAllCamere() const
{
  for(int i = 0; i < Camere.size(); i++)
  {
    cout << "---------------------------------------------" << endl;
    cout << "Tipo di camera: " << Camere[i] -> getTipo() << endl;
    cout << "Costo camera: " << Camere[i] -> getPrezzo() << endl;
    cout << "Numero camera: " << i << endl;
    if(Camere[i] -> getPrenotazione()){
      cout << "camera prenotata" << endl;
      cout << Camere[i] -> getInfoPrenotazione();
      }
    else
    {
      cout << "camera disponibile" << endl;
    }
  }
  
  cout << "---------------------------------------------" << endl;
  
  cout << "Camere disponibili " << getNumCamereDisponibili() << endl;
  cout << "Totale Ricavi " << getRicaviTot() << "euro" << endl;
  
}

int GestioneHotel::getRicaviTot() const
{
  int somma_ricavi = 0;
  for(int i = 0; i < Camere.size(); i++)
  {
    if(Camere[i] -> getPrenotazione())
    {
        somma_ricavi += Camere[i] -> getPrezzo();
        if(Camere[i] -> getInfoPrenotazione().getColazione())
        {
            somma_ricavi += 10;
        }
    }
  }
  
  return somma_ricavi;
}




