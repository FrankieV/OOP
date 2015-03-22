#include <iostream>
#include "Razionale.h"
using namespace std;

//Definizione del costruttore senza parametri della classe Razionale
Razionale::Razionale() : Numeratore(0), Denominatore(1){}

//Definizione del costruttore ad un parametro (Numeratore) della classe Razionale
Razionale::Razionale( int Num) : Denominatore(1)
{
	setNumeratore(Num);
}

//Definizione del costruttore a due parametri ( Numeratore e Denominatore ) della classe Razionale
Razionale::Razionale( int Num, int Den)
{
	setNumeratore( Num );
	setDenominatore( Den);
}

//Definizione della funzione membro setNumeratore della classe Razionale
void Razionale::setNumeratore( int Num )
{
	Numeratore = ( Num >= 0 )? Num : 0;
}

//Definizione della funzione membro setDenominatore della classe Razionale
void Razionale::setDenominatore( int Den)
{
	Denominatore = ( Den > 0)? Den : 1;
}

//Definizione della funzione membro getNumeratore della classe Razionale
int Razionale::getNumeratore() const
{
	return Numeratore;
}

//Definizione della funzione membro getDenominatore della classe Razionale
int Razionale::getDenominatore() const
{
	return Denominatore;
}

//Definizione della funzione membro converti della Classe Razionale
double Razionale::converti() const
{
	double Divisione = (( static_cast <double> ( Numeratore )) / ( static_cast <double> ( Denominatore )));
	return Divisione;
} 

//Definizione del metodo inverti della Classe Razionale
void Razionale::inverti() const 
{
	int num = Denominatore;
	int den = Numeratore;
	num = ( num <= 0 )? 0 : Denominatore;
	den = ( den <= 0 )? 1 : Numeratore;
	cout << num << " / " << den << endl;	
}


//Definizione della funzione membro stampaRazionale della classe Razionale
void Razionale::stampaRazionale() const
{
	cout << Numeratore << " / " << Denominatore << endl;
}

//Definizione della funzione membro riduci della classe Razionale
void Razionale::riduci()
{	
	int MCD = 0;
	int a = Numeratore;
	int b = Denominatore;
	if(( a * b ) == 0 )
		cout << " Impossibile calcolare il MCD perchè uno tra numeratore e denominatore è uguale a 0 " << endl;
	else
		{
			while( a != b )
				{ 
 					if( a > b )
						a -= b;
 					else b -= a;
 				}
		
		}
	MCD = a;
	Numeratore = Numeratore / MCD;
	Denominatore = Denominatore / MCD;
}

//Definizione del metodo che fa il prodotto tra due frazioni ( prodotto_e_Assegna ) della classe Razionale
void Razionale::prodotto_e_Assegna( const Razionale &R) 
{
	Numeratore = Numeratore * R.Numeratore;
	Denominatore = Denominatore * R.Denominatore;
}

//Definzione del metodo che fa la somma tra due funzioni ( somma_e_Assegna ) della classe Razionale
void Razionale::somma_e_Assegna( const Razionale &R )
{
	int a = Denominatore;
	int b = R.Denominatore;
	int MCD = 0;
	int mcm = 0;
	while( a != b )
		{ 
 			if( a > b )
				a -= b;
 			else b -= a;
 		}
	MCD = a;
	mcm = ( Denominatore * R.Denominatore ) / MCD;
	Numeratore = ((( mcm / Denominatore ) * Numeratore) + (( mcm / R.Denominatore ) * R.Numeratore ));
	Denominatore = mcm;		
}
