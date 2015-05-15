#include "GestoreFatture.h"


using namespace std;

/* 1) Restituire il nome dell'azienda che ha emesso più fatture. */
const string GestoreFatture::piuFatture() 
{
  if(fatture.empty())
    return "Lista vuota";
  
  string azienda_max;
  list<string> aziende;
  
  for(list<Fattura>::iterator it = fatture.begin(); it != fatture.end(); it++)
  {
    aziende.push_back(it -> getAziendaEmessa());
  }
  
  aziende.sort();
  aziende.unique();
  
  int max_fatture = 0;
  int cont = 0;
  
  for(list<string>::iterator it = aziende.begin(); it != aziende.end(); it++)
  {
    for(list<Fattura>::iterator it_2 = fatture.begin(); it_2 != fatture.end(); it_2++)
     {
        if(*it == it_2 -> getAziendaEmessa())
            cont++;
     }
     
     if(cont > max_fatture)
     {
        max_fatture = cont;
        azienda_max = *it;
     }
     
     cont = 0;
  }
  return azienda_max;
}

/* 2) Restituire il nome dell'azienda che ha emesso la fattura con l'importo maggiore.*/
const string GestoreFatture::importoMaggiore()
{
   if(fatture.empty())
        return "Lista vuota";
   
   string azienda_fattura_max = fatture.front().getAziendaEmessa();
   int importo_max = fatture.front().getImportoFattura();
   
   for(list<Fattura>::iterator it = fatture.begin(); it != fatture.end(); it++)
   {
      if(it -> getImportoFattura() > importo_max)
      {
        importo_max = it -> getImportoFattura();
        azienda_fattura_max = it -> getAziendaEmessa();
      }
   }
   
   return azienda_fattura_max; 
}

/* 3) Restituire il nome dell'azienda che ha emesso la fattura con l'importo minore. */
const string GestoreFatture::importoMinore()
{
   if(fatture.empty())
        return "Lista vuota";
        
   string azienda_fattura_min = fatture.front().getAziendaEmessa();
   int importo_min = fatture.front().getImportoFattura();
   
   for(list<Fattura>::iterator it = fatture.begin(); it != fatture.end(); it++)
   {
      if(it -> getImportoFattura() < importo_min)
      {
        importo_min = it -> getImportoFattura();
        azienda_fattura_min = it -> getAziendaEmessa();
      }
   }
   
   return azienda_fattura_min;   
}

/* 4) Sia M la media degli importi delle fatture emesse e ricevute da un'azienda. Restituire il nome dell'azienda che ha il valore di M più alto. */

const string GestoreFatture::metodo4()
{
    list<string> aziende;
    string azienda_valore_max;
    int importo_emessa = 0, importo_ricevuta = 0;
    int cont_emessa = 0, cont_ricevuta = 0;
    int somma_medie = 0;
    int M = 0;
    for(list<Fattura>::iterator it = fatture.begin(); it != fatture.end(); it++)
    {
        aziende.push_back(it -> getAziendaEmessa());
        aziende.push_back(it -> getAziendaRicevuta());
    }
    
    aziende.sort();
    aziende.unique();
    
    for(list<string>::iterator it = aziende.begin(); it != aziende.end(); it++)
    {
        for(list<Fattura>::iterator it_2 = fatture.begin(); it_2 != fatture.end(); it_2++)
        {
           if(*it == it_2 -> getAziendaEmessa())
           {
              importo_emessa = importo_emessa + it_2-> getImportoFattura();
              cont_emessa++;
           }
           else if(*it == it_2 -> getAziendaRicevuta())
           {
              importo_ricevuta = importo_ricevuta + it_2 -> getImportoFattura();
              cont_ricevuta++;
           }
        }
       
        somma_medie =  (importo_emessa/cont_emessa) + (importo_ricevuta/cont_ricevuta);
        
        if(somma_medie > M)
        {
          M = somma_medie;
          azienda_valore_max = *it;
        }
        
        importo_emessa = 0;
        importo_ricevuta = 0;
        cont_emessa = 0;
        cont_ricevuta = 0;
    }
    
    return azienda_valore_max;

}

/* 5) Restituire il numero di aziende che ha emesso solo fatture per prodotti dello stesso tipo. */
const int GestoreFatture::metodo5()
{
    bool stesso_tipo = true;
    list<string> aziende;

    for(list<Fattura>::iterator it = fatture.begin(); it != fatture.end(); it++)
    {
        for(list<Fattura>::iterator it_2 = fatture.begin(); it_2 != fatture.end(); it_2++)
        {
            if(it -> getAziendaEmessa() == it_2 -> getAziendaEmessa())
            {
                if(it -> getTipoProdotto() != it_2 -> getTipoProdotto())
                {
                    stesso_tipo = false;
                }
            }
        }
        
        if(stesso_tipo)
            aziende.push_back(it -> getAziendaEmessa());
            
        stesso_tipo = true;
    }
    
    aziende.sort();
    aziende.unique();
    
    return aziende.size();
}

/* 6) Restituire la differenza tra il numero di aziende che ha emesso fatture solo per prodotti SPORTIVI e il numero di aziende che ha emesso fatture solo per prodotti CULTURALI. */
const int GestoreFatture::metodo6()
{
  list<string> aziende_sportivi;
  list<string> aziende_culturali;
  
  bool solo_sportivi = true;
  bool solo_culturali = true;
  
  for(list<Fattura>::iterator it = fatture.begin(); it != fatture.end(); it++)
  {
    for(list<Fattura>::iterator it_2 = fatture.begin(); it_2 != fatture.end(); it_2++)
    {
        if(it -> getTipoProdotto() == SPORTIVO)
        {
            if(it -> getAziendaEmessa() == it_2 -> getAziendaEmessa())
             {
                  if(it_2 -> getTipoProdotto() != SPORTIVO)
                    solo_sportivi = false;
             }
        }
        else if(it -> getTipoProdotto() == CULTURALE)
        {
            if(it -> getAziendaEmessa() == it_2 -> getAziendaEmessa())
             {
                  if(it_2 -> getTipoProdotto() != CULTURALE)
                    solo_culturali = false;
             }
        }
    }
    
    if(solo_sportivi)
        aziende_sportivi.push_back(it -> getAziendaEmessa());
    else if(solo_culturali)
        aziende_culturali.push_back(it -> getAziendaEmessa());
    
    solo_sportivi = true;
    solo_culturali = true;
  }
  
    aziende_sportivi.sort();
    aziende_culturali.sort();
    aziende_sportivi.unique();
    aziende_culturali.unique();
    
    return aziende_sportivi.size() - aziende_culturali.size();
}

/* 7) Restituire il numero di aziende che vende solo prodotti ALIMENTARI e compra almeno un prodotto SPORTIVO. */
const int GestoreFatture::metodo7()
{
    list<string> aziende;
    list<string> aziende_sportive;
    bool solo_alimentari = true;
    for(list<Fattura>::iterator it = fatture.begin(); it != fatture.end(); it++)
    {
        for(list<Fattura>::iterator it_2 = fatture.begin(); it != fatture.end(); it_2++)
        {
            if(it -> getTipoProdotto() == ALIMENTARE)
            {
                if(it -> getAziendaEmessa() == it_2 -> getAziendaEmessa())
                {
                    if(it_2 -> getTipoProdotto() != ALIMENTARE)
                        solo_alimentari = false;
                }
            }
        }
        
        if(solo_alimentari)
            aziende.push_back(it -> getAziendaEmessa());
            
        solo_alimentari = true;
    }
    
    aziende.sort();
    aziende.unique();
    
    for(list<string>::iterator it = aziende.begin(); it != aziende.end(); it++)
    {
        for(list<Fattura>::iterator it_2 = fatture.begin(); it_2 != fatture.end(); it_2++)
        {
            if(*it == it_2 -> getAziendaRicevuta())
            {
                if(it_2 -> getTipoProdotto() == SPORTIVO)
                    aziende_sportive.push_back(*it);
            }
        }
    }
    
    aziende_sportive.sort();
    aziende_sportive.unique();
    
    return aziende_sportive.size();
}

/* 8) Restituire il numero di aziende che non compra prodotti CULTURALI. */
const int GestoreFatture::metodo8()
{
   culturali = false;
   list<string> aziende;
   
   for(list<Fattura>::iterator it = fatture.begin(); it != fatture.end(); it++)
   {
      for(list<Fattura>::iterator it_2 = fatture.begin(); it_2 != fatture.end(); it_2++)
      {
         if(it -> getAziendaRicevuta() == it_2 -> getAziendaRicevuta())
         {
            if(it -> getTipoProdotto() == CULTURALE)
                culturali = true;
         }
      }
      
      if(!culturali)
        aziende.push_back(it -> getAziendaRicevuta());
        
      culturali = false;
   }
   
   aziende.sort();
   aziende.unique();
   
   return aziende.size();      
}

/* 9) S(A) la somma degli importi delle fatture emesse da un'azienda A. Siano A1 e A2 due aziende distinte tale per cui S(A1) + S(A2) sia massimo rispetto a tutte le altre coppie di aziende. Restituire il valore di S(A1) + S(A2). */
const int GestoreFatture::metodo9()
{
    list<string> aziende_emesse;
    vector<int> somma_importi;
    int somma_fatture = 0;
    
    for(list<Fattura>::iterator it = fatture.begin(); it != fatture.end(); it++)
    {
        aziende_emesse.push_back(it -> getAziendeEmesse());
    }
    
    aziende_emesse.sort();
    aziende_emesse.unique();    
    
    for(list<string>::iterator it = aziende_emesse.begin(); it != aziende_emesse.end(); it++)
    {
        for(list<Fattura>::iterator it_2 = fatture.begin(); it_2 != fatture.end(); it_2++)
        {
            if(*it == it_2 -> getAziendeEmesse())
            {
                somma_fatture = somma_fatture + it_2 -> getImportoFattura();
            }
        }
        
        somma_importi.push_back(somma_fatture);
        somma_fatture = 0;
    }
    
    int coppia_max = somma_importi[0] + somma_importi[1];
    
    for(int i = 0; i < somma_importi.size(); i++)
    {
        for(int j = 0; j < somma_importi.size(); j++)
         {
            if( i != j)
            {
                if((somma_importi[i] + somma_importi[j]) > coppia_max)
                {
                    coppia_max = somma_importi[i] + somma_importi[j];
                }
            }
         }
    }
    
    return coppia_max;
}
