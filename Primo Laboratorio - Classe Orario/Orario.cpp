#include <iostream>
#include "Orario.h"

using namespace std;

//definizione del costruttore della classe Orario
Orario::Orario(): secondi(0), minuti(0), ore(0){}

//definizione della funzione membro setOrario della classe Orario
void Orario::setOrario( int hour, int minutes, int seconds )
{
	ore = ( hour >= 0 && hour <= 24 )? hour : 0;
	minuti = ( minutes >= 0 && minutes <= 59 )? minutes : 0;
	secondi = ( seconds >= 0 && seconds <= 59 )? seconds : 0;
}

//definizione della funzione membro printOrario della classe Orario
void Orario::printOrario() const
{
	if( ore < 10)
		cout << "0" << ore << ":";
	else 
		cout << ore << ":";
	if( minuti < 10)
		cout << "0" << minuti << ":";
	else
		cout << minuti << ":";
	if( secondi < 10)
		cout << "0" << secondi;
	else 
		cout << secondi;
} 

//definizione della funzione membro incrementaSecondi della classe Orario
void Orario::incrementaSecondi()
{
	secondi += 1;
}

//definzione della funzione membro incrementaMinuti della classe Orario
void Orario::incrementaMinuti()
{
	minuti += 1;
}

//definizione della funzione membro incrementaOre della classe Orario
void Orario::incrementaOre()
{
	ore += 1;
}

//definzione della funzione membro confrontaOrari della classe Orario
bool Orario::confrontaOrari( const Orario &Or) const
{
	if( secondi == Or.secondi && minuti == Or.minuti && ore == Or.ore)
		return true;
	else 
		return false;
}
