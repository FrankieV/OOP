#include <iostream>
using namespace std;
#include "Contatto.h"

bool Rubrica_Piena( Contatto *c, int DimRubrica)
{
	for( int i = 0; i < DimRubrica; i++)
		{
			if( c[i].getNome() == "\0" && c[i].getCognome() == "\0" && c[i].getNumeroTelefonico() == "\0" && c[i].getEmail() == "\0")
				return false;
		}
	return true;
}

int Inserisci_Contatto( Contatto *c, int DimRubrica )
{
	int Contatto_Vuoto = 0;	
	if( Rubrica_Piena ( c, DimRubrica) == false)	
		{
			for( int i = 0; i < DimRubrica; i++)
				{
					if( c[i].getNome() == "\0" && c[i].getCognome() == "\0" && c[i].getNumeroTelefonico() == "\0" && c[i].getEmail() == "\0")
						{					
							Contatto_Vuoto = i;
							break;
						}
				}
			cin >> c[Contatto_Vuoto];
		}
	else	
		cout << "Lista Contatti Piena!!" << endl;
}

void Elimina_Contatto( Contatto *c, int DimRubrica )
{
	for( int i = 0; i < DimRubrica; i++ )
		{
			for( int j = 0; j < DimRubrica; j++ )			
				{				
					if( i != j )					
							{
								if( c[i].getNome() == c[j].getNome() && c[i].getCognome() == c[j].getCognome() )
									{
										c[i].setNome( "\0" );
										c[i].setCognome( "\0" );
										c[i].setNumeroTelefonico( "\0" );
										c[i].setEmail( "\0" );							
									}  
							}
					}
			}
}

void Ordine_Alfabetico( Contatto *c, int DimRubrica )
{
	Contatto *tmp = new Contatto[1];;	
	for( int i = 0; i < DimRubrica; i++ )
		{
			for( int j = 0; j < DimRubrica; j++ )
				{
					if( i != j )
						{
							if( c[j] < c[i] && j > i )
								{
									tmp[0]	= c[i];
									c[i] = c[j];
									c[j] = tmp[0];
								}					
						} 
				}		
		}
	delete []tmp;
}

void Stampa_Rubrica( Contatto *c, int DimRubrica )
{
	cout << endl << endl << "Visualizza i tuoi contatti : " << endl;
	for( int i = 0; i < DimRubrica; i++ )
		cout << c[i];
	cout << "------------------------------" << endl;
	cout << endl;
}

int main()
{	
	const int DimRubrica = 100;	
	int comando;
	Contatto *c = new Contatto[ DimRubrica ];
	
	cout << "------------------------------" << endl;
	cout << "Inserisci il comando da eseguire : " << endl;
	cout << "1 - Per inserire il contatto " << endl;	
	cout << "2 - Per eliminare un doppione " << endl;
	cout << "3 - Per visualizzare la tua lista contatti " << endl;
	cout << "4 - Per ordinare i tuoi contatti in ordine alfabetico " << endl;	
	cout << "5 - Per uscire" << endl;	
	cout << "------------------------------" << endl;
	cin >> comando;	
	while( comando >= 1 && comando <= 4 )
		{
			switch ( comando )
				{
					case 1:
						Inserisci_Contatto( c, DimRubrica ); 			
						break;
					case 2:
						Elimina_Contatto( c, DimRubrica ); 			
						break;	
					case 3:
						Stampa_Rubrica( c, DimRubrica );
						break;
					case 4:
						Ordine_Alfabetico( c, DimRubrica );
						break;
				}
			cout << endl << endl << "Inserisci il comando da eseguire : " << endl;
			cout << "1 - Per inserire il contatto " << endl;	
			cout << "2 - Per eliminare un doppione " << endl;
			cout << "3 - Per visualizzare la tua lista contatti " << endl;
			cout << "4 - Per ordinare i tuoi contatti in ordine alfabetico " << endl;	
			cout << "5 - Per uscire" << endl;	
			cout << "------------------------------" << endl;
			cin >> comando;	
		}
	return 0;
}
