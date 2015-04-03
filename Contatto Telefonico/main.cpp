#include "Contatto.h"
#include "MyString.h"
#include <iostream>


using namespace std;
void InserisciContatto(Contatto *,unsigned &,unsigned &);
void EliminaContatto(Contatto *, unsigned);
void Visualizza_Contatti(Contatto *lista_cont, unsigned cont);
void Ordine_Alfabetico(Contatto *lista_cont, unsigned cont);

int main()
{
 unsigned num_contatti;
 unsigned scelta = 0;
 unsigned cont = 0;

 cout << "Quanti contatti vuoi inserire? ";
 cin >> num_contatti;
 
 Contatto *Lista_Contatti = new Contatto[num_contatti];
 
 while(scelta != 5)
 {
   cout << "Gestisci rubrica telefonica " << endl;
   cout << "1. Inserisci un contatto" << endl;
   cout << "2. Elimina contatto" << endl;
   cout << "3. Visualizza contatti" << endl;
   cout << "4. Ordina in ordine alfabetico" << endl;
   cout << "5. Esci" << endl;
   
   cin >> scelta;
   
    switch(scelta)
    { 
      case 1:
      InserisciContatto(Lista_Contatti,num_contatti,cont);
      break;
      case 2:
      EliminaContatto(Lista_Contatti,cont);
      break;
      case 3:
      Visualizza_Contatti(Lista_Contatti, cont);
      break;
      case 4:
      Ordine_Alfabetico(Lista_Contatti,cont);
      break;
      case 5:
      scelta = 5;
      break;
      
    }
    
 }
 
 return 0;
 
}

void InserisciContatto(Contatto *Contatti, unsigned &num_contatti, unsigned &cont)
{
   if(cont < num_contatti)
   {
   cin >> Contatti[cont];
   cont++;
   }
   else
   cout << "Impossibile aggiungere un nuovo contatto! " << endl;
}

void EliminaContatto(Contatto *Contatti, unsigned cont)
{
  MyString Name, Surname;
  cout << "Inserisci il nome del contatto da eliminare: ";
  cin >> Name;
  cout << endl << "Inserisci il cognome del contatto da eliminare: ";
  cin >> Surname;
  
  for(int i = 0; i < cont; i++)
  {
    if(Contatti[i].getNome() == Name && Contatti[i].getCognome() == Surname)
    {
      Contatti[i].setNome(" ");
      Contatti[i].setCognome(" ");
      Contatti[i].setTelNum(" ");
      Contatti[i].setMail(" ");
      break;
    }
  }

}

void Visualizza_Contatti(Contatto *lista_cont, unsigned cont)
{
  for(int i = 0; i < cont; i++)
  {
   if(!(lista_cont[i].getNome() == " "))
   cout << lista_cont[i];
  }
}

void Ordine_Alfabetico(Contatto *lista_cont, unsigned cont)
{
  Contatto tmp;
  for(int i = 0; i < cont-1; i++)
  {
    for(int j = i+1; j < cont; j++)
    {
    if(lista_cont[i].getCognome() > lista_cont[j].getCognome())
    {
       tmp = lista_cont[i];
       lista_cont[i] = lista_cont[j];
       lista_cont[j] = tmp;
    }
    else if(lista_cont[i].getCognome() == lista_cont[j].getCognome())
    {
     if(lista_cont[i].getNome() > lista_cont[j].getNome())
      {
       tmp = lista_cont[i];
       lista_cont[i] = lista_cont[j];
       lista_cont[j] = tmp;
      }
    }
    }
  }

}


