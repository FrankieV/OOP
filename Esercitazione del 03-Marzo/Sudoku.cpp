#include <iostream>

using namespace std;

void RiempiGriglia(int **, int);
void PrintGriglia(int **, int);
int Celle_Da_Riempire(int ** ,int N);
bool Verifica_Inserimento(int ** ,int, int,int,int);


int main()
{
   int N;
   cin >> N;
   int **Griglia = new int *[N];
   for(int i = 0; i < N; i++)
   {
      Griglia[i] = new int[N];
   
   }
   
   RiempiGriglia(Griglia,N);
   PrintGriglia(Griglia,N);
   int celle_rimanenti = Celle_Da_Riempire(Griglia,N);
   
   while(celle_rimanenti > 0)
   {
        int pos_I, pos_J;
        int num;
        cout << "In quale posizione vuoi inserire il numero? (r,c) " << endl;
        cin >> pos_I >> pos_J;
        cout << endl << "Inserisci il numero ";
        cin >> num;
        if(num != 0)
        {
        if(Verifica_Inserimento(Griglia,N,pos_I,pos_J,num))
        {
           celle_rimanenti--;
           Griglia[pos_I][pos_J] = num;
           cout << "Numero inserito correttamente! =) " << endl;
           PrintGriglia(Griglia,N);
        }
        else
        {
          cout << "Non posso inserire il numero! " << endl;
          PrintGriglia(Griglia,N);
        }
        }
        else
         cout << "Inserisci un numero diverso da 0" << endl;
   }
   
   for(int i = 0; i < N; i++)
   {
     delete [] Griglia[i];
   }
   
   delete [] Griglia;
   
   return 0;
}


void RiempiGriglia(int ** M,int N)
{
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
         cin >> M[i][j];
    }
  }
}


void PrintGriglia(int **M, int N)
{
   for(int i = 0; i < N; i++)
   {
      for(int j = 0; j < N; j++)
      {
        cout << M[i][j];
      }
      
      cout << endl;
   }
}


int Celle_Da_Riempire(int **M, int N)
{
  int cont = 0;
  for(int i = 0; i < N; i++)
   {
      for(int j = 0; j < N; j++)
      {
        if(M[i][j] == 0)
          cont++;
      }
   }
   
   return cont;
}

bool Verifica_Inserimento(int **M, int N, int pos_I, int pos_J,int num)
{
   for(int i = 0; i < N; i++)
   {
      if(i != pos_I)
      {
         if(num == M[i][pos_J])
         {
             return false;
         }
      }
   }
   
   for(int j = 0; j < N; j++)
   {
         if(j != pos_J)
         {
              if(num == M[pos_I][j])
              {
                  return false;
              }
         }
   
   }
   
   if(M[pos_I][pos_J] != 0)
         return false;
   
   return true;
}

// #END
