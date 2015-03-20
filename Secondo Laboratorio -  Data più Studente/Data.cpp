#include <iostream>
using namespace std;

#include "Data.h"

//costruttore senza parametri
Data::Data(): Giorno(1), Mese(1), Anno(1900){}

//costruttore con copia
Data::Data(const Data &D) : Giorno(D.Giorno), Mese(D.Mese), Anno(D.Anno){}

//funzione che definisce il giorno
void Data::setGiorno( int gg )
	{
		Giorno = ( gg >= 1 && gg <= 31)? gg : 1; // convalida il giorno			
	}//fine della funzione setGiorno

//funzione che definisce il mese
void Data::setMese( int mm )
	{
		Mese = ( mm >= 1 && mm <= 12)? mm : 1; // convalida il mese
	}//fine della funzione setMese

//funzione che definisce l'anno
void Data::setAnno( int aaaa )
	{
		Anno = (aaaa >= 1900)? aaaa : 1900; // convalida l'anno
	}//fine della funzione setGiorno

//funzione che restituisce il Giorno
int Data::getGiorno() const
	{
		return Giorno;
	}//fine della funzione getGiorno

//funzione che restituisce il Mese
int Data::getMese() const
	{
		return Mese;
	}//fine della funzione getMese

//funzione che restituisce l'Anno
int Data::getAnno() const
	{
		return Anno;
	}//fine della funzione getAnno

//funzione che legge una Data
void Data::leggiData()
{ 
	cin >> Giorno >> Mese >> Anno;//fine funzione leggiData
	setGiorno(Giorno);
	setMese(Mese);
	setAnno(Anno);
}

//funzione che stampa una Data
void Data::stampaData() const
{
	if(Giorno < 10)
		cout << "0" << Giorno << "/";
	else	
		cout << Giorno << "/";
	if(Mese < 10)
		cout << "0" << Mese << "/";
	else	
		cout << Mese << "/";
	cout << Anno;
}

