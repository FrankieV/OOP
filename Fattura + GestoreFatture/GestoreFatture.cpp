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
   bool culturali = false;
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
        aziende_emesse.push_back(it -> getAziendaEmessa());
    }
    
    aziende_emesse.sort();
    aziende_emesse.unique();    
    
    for(list<string>::iterator it = aziende_emesse.begin(); it != aziende_emesse.end(); it++)
    {
        for(list<Fattura>::iterator it_2 = fatture.begin(); it_2 != fatture.end(); it_2++)
        {
            if(*it == it_2 -> getAziendaEmessa())
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

/* 10) Sia A1 l'azienda che ha emesso la fattura per un prodotto ALIMENTARE con l'importo piu' alto. Sia A2 l'azienda che ha emesso la fattura per un prodotto SPORTIVO con l'importo piu' basso. Restituire il numero di fatture emesse dall'azienda A1 all'azienda A2. */
const int GestoreFatture::metodo10()
{
    string A1;
    string A2;
    int importo_alimentare_alto = 0;
    int importo_sportivo_basso = 0;
    bool primo_alimentare = true;
    bool primo_sportivo = true;
    
    for(list<Fattura>::iterator it = fatture.begin(); it != fatture.end(); it++)
    {
        if(it -> getTipoProdotto() == ALIMENTARE && primo_alimentare)
        {
            A1 = it -> getAziendaEmessa();
            importo_alimentare_alto = it -> getImportoFattura();
            primo_alimentare = false;
        }
        
        if(it -> getTipoProdotto() == SPORTIVO && primo_sportivo)
        {
            A2 = it -> getAziendaEmessa();
            importo_sportivo_basso = it -> getImportoFattura();
            primo_sportivo = false;
        }
    }
    
    for(list<Fattura>::iterator it = fatture.begin(); it != fatture.end(); it++)
    {
        if(it -> getTipoProdotto() == ALIMENTARE)
        {
            if(it -> getImportoFattura() > importo_alimentare_alto)
            {
                importo_alimentare_alto = it -> getImportoFattura();
                A1 = it -> getAziendaEmessa();
            }
        }
        
        if(it -> getTipoProdotto() == SPORTIVO)
        {
            if(it -> getImportoFattura() < importo_sportivo_basso)
            {
                importo_sportivo_basso = it -> getImportoFattura();
                A2 = it -> getAziendaEmessa();
            }
        }
    }
    
    int cont_fatture = 0;
    
    for(list<Fattura>::iterator it = fatture.begin(); it != fatture.end(); it++)
    {
        if( it -> getAziendaEmessa() == A1 && it -> getAziendaRicevuta() == A2)
            cont_fatture++;
    }
    
    return cont_fatture;
}

/*11) Restituire la stringa con il nome di tutte le aziende che vendono solo prodotti ALIMENTARI separate da una virgola. Esempio di output: A1,A2,A3 (Le aziende devono essere ordinate in ordine lessicografico)*/
const string GestoreFatture::metodo11()
{
   list<string> aziende_alimentari;
   bool solo_alimentari = true;
   
   for(list<Fattura>::iterator it = fatture.begin(); it != fatture.end(); it++)
   {
      for(list<Fattura>::iterator it_2 = fatture.begin(); it_2 != fatture.end(); it_2++)
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
        aziende_alimentari.push_back(it -> getAziendaEmessa());
        
       solo_alimentari = false; 
   } 
   
   aziende_alimentari.sort();
   aziende_alimentari.unique();
   
   string aziende_ordinate;
   
   for(list<string>::iterator it = aziende_alimentari.begin(); it != aziende_alimentari.end(); it++)
   {
        aziende_ordinate.append(*it);
        aziende_ordinate.append(",");
   }
   
   return aziende_ordinate;
}

/* 12) Sia A l'azienda che compare di meno nelle fatture (cioe' quella che ha emesso e ricevuto meno fatture di tutte le altre). Restituire la stringa con il nome di tutte le aziende che hanno emesso/ricevuto una fattura a/da A separate da una virgola e uno spazio. Esempio di output: A1, A2, A3 (Le aziende devono essere ordinate in ordine lessicografico) */
const string GestoreFatture::metodo12()
{
    list<string> aziende;
    unsigned int fatture_emesse = 0;
    unsigned int fatture_ricevute = 0;
    for(list<Fattura>::iterator it = fatture.begin(); it != fatture.end(); it++)
    {
        aziende.push_back(it -> getAziendaEmessa());
        aziende.push_back(it -> getAziendaRicevuta());
    }
    
    aziende.sort();
    aziende.unique();
    
    string A = aziende.front();
    
    for(list<Fattura>::iterator it = fatture.begin(); it != fatture.end(); it++)
    {
        if(it -> getAziendaEmessa() == A)
            fatture_emesse++;
        else if(it -> getAziendaRicevuta() == A)
            fatture_ricevute++;   
    }
    
    unsigned int cont_emesse = 0;
    unsigned int cont_ricevute = 0;
    
    for(list<string>::iterator it = aziende.begin(); it != aziende.end(); it++)
    {
        for(list<Fattura>::iterator it_2 = fatture.begin(); it_2 != fatture.end(); it_2++)
        {
            if(*it == it_2 -> getAziendaEmessa())
                cont_emesse++;
            else if(*it == it_2 -> getAziendaRicevuta())
                cont_ricevute++;
        }
        
        if(cont_emesse > fatture_emesse && cont_ricevute > fatture_ricevute)
        {
            fatture_emesse = cont_emesse;
            fatture_ricevute = cont_ricevute;
            A = *it;
        }
        
        cont_emesse = 0;
        cont_ricevute = 0;     
    }
    
    list<string> aziende_emesse_ricevute;
    
    for(list<Fattura>::iterator it = fatture.begin(); it != fatture.end(); it++)
    {
        if(it -> getAziendaRicevuta() == A)
            aziende_emesse_ricevute.push_back(it -> getAziendaEmessa());
        else if(it -> getAziendaEmessa() == A)
            aziende_emesse_ricevute.push_back(it -> getAziendaRicevuta());
    }
    
     aziende_emesse_ricevute.sort();
     aziende_emesse_ricevute.unique();
     
     string aziende_ordinate;
     
     for(list<string>::iterator it = aziende_emesse_ricevute.begin(); it != aziende_emesse_ricevute.end(); it++)
     {
        aziende_ordinate.append(*it);
        aziende_ordinate.append(" ,");
     }
    
    return aziende_ordinate;
}
