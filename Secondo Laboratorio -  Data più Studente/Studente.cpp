#include <iostream>
#include "Studente.h"
#include "Data.h"

using namespace std;

//costruttore Studente con lista di inizializzazione
Studente::Studente(): NumeroMatricola(1), VotoEsame(0), DataNascita(), EsamiSuperati(0), EsamiCorsoDiLaurea (25)
	{
		for( int i = 0; i < 25; i++)
			Esami[i] = 0;
	}

//costruttore Studente per Copia
Studente::Studente( const Studente &S ): NumeroMatricola( S.NumeroMatricola ), VotoEsame( S.VotoEsame ), DataNascita( S.DataNascita ), 
							EsamiSuperati( S.EsamiSuperati ), EsamiCorsoDiLaurea( S.EsamiCorsoDiLaurea ){}

//funzione che definisce il numero di matricola dello Studente
void Studente::setNumeroMatricola( int NumMat )
	{
		NumeroMatricola = ( NumMat >= 1)? NumMat : 1;
	}

//funzione che definisce il voto di un dato esame del corso di laurea dello Studente
void Studente::setVotoEsame( int VotEx, int NumeroEsame)
	{
		if( VotEx >= 18 && VotEx <= 30)
			{
				VotoEsame = VotEx;
				EsamiSuperati++;
			} 
		if( VotEx <= 30)
			Esami[NumeroEsame] = VotEx;	
	}

//funzione che definisce la data di nascita dello Studente
void Studente::setDataNascita() 
	{
		DataNascita.leggiData();
	}

//funzione che restituisce il numero della matricola dello Studente
int Studente::getNumeroMatricola() const
	{
		return NumeroMatricola;
	}

//funzione che restituisce il voto di un dato esame dello studente
int Studente::getVotoEsame( unsigned NumeroEsame )const
	{
		if( NumeroEsame <= 25 )		
			return Esami[NumeroEsame];
	}

//funzione che restituisce la data di nascita dello studente
Data Studente::getDataNascita() const
	{
		return DataNascita;
	}

//metodo che legge dalla tastiera i dati dello studente
void Studente::leggiStudente()
	{
		int NumeroEsame;
		cout << "Inserisci numero matricola dello studente:" << endl;
		cin >> NumeroMatricola;
		cout << "Inserisci il voto dell'esame :( per uscire premi -1..):" << endl;		
		cin >> VotoEsame;
		while( VotoEsame != -1)
			{
				cout << "Esame numero:" << endl;				
				cin >> NumeroEsame;
				if( Esami[NumeroEsame] < 18 )
					Esami[NumeroEsame] = VotoEsame;
				setVotoEsame( VotoEsame, NumeroEsame );
				cout << "Inserisci il voto dell'esame :( per uscire premi -1..):" << endl;	
				cin >> VotoEsame;	
						
			}
		setNumeroMatricola( NumeroMatricola );
		cout << "Inserisci la data di nascita dello studente: (gg/mm/aaaa) " << endl;
		DataNascita.leggiData();
		cout << endl << endl;	
	}

//metodo che restituisce la media dei voti dello studente
double Studente::getMedia() const
	{
		double sommaEsami = 0;	
		double Media = 0;
		for ( int i = 0; i < 25; i++)
			{
				if( Esami[i] >= 18 && Esami[i] <= 30)
					sommaEsami = sommaEsami + Esami[i];
			}
		Media = sommaEsami / EsamiSuperati;
		return Media;
	}

//metodo che restituisce il voto massimo ottenuto dallo studente
int Studente::getVotoMax() const
	{
		int Max = Esami[0];
		for( int i = 0; i < 25; i++)
			{
				if( Esami[i] > Max)
					Max = Esami[i];
			}
		return Max;
	}

//metodo che restiuisce il numero degli esami rimanenti dello studente
int Studente::getNumEsamiAllaLaurea()const
	{
		int EsamiRimanenti = 0;
		EsamiRimanenti = EsamiCorsoDiLaurea - EsamiSuperati;
		return EsamiRimanenti;
	}

//funzione che verifica se uno studente è più giovane di un altro studente
bool Studente::StudentePiuGiovaneDi( const Studente &S) const
	{
		int AnnoDiNascitaPrimoStudente = DataNascita.getAnno();
		int AnnoDiNascitaSecondoStudente = S.DataNascita.getAnno();
		int MeseDiNascitaPrimoStudente = DataNascita.getMese();
		int MeseDiNascitaSecondoStudente = S.DataNascita.getMese();
		int GiornoDiNascitaPrimoStudente = DataNascita.getGiorno();
		int GiornoDiNascitaSecondoStudente = S.DataNascita.getGiorno();
		if( AnnoDiNascitaPrimoStudente > AnnoDiNascitaSecondoStudente )
			return true;
		if(( AnnoDiNascitaPrimoStudente == AnnoDiNascitaSecondoStudente ) && ( MeseDiNascitaPrimoStudente > MeseDiNascitaSecondoStudente))
			return true;
		if(( AnnoDiNascitaPrimoStudente == AnnoDiNascitaSecondoStudente ) && ( MeseDiNascitaPrimoStudente == MeseDiNascitaSecondoStudente ) && 
			( GiornoDiNascitaPrimoStudente > GiornoDiNascitaSecondoStudente ))
			return true;
		return false;	
	}	

//metodo che stampa su schermo i dati dello studente
void Studente::stampaStudente() const
	{	
		cout << endl;
		cout << "Numero matricola studente: " ;
		cout << NumeroMatricola << endl << endl;
		cout << "Nato il : ";
		DataNascita.stampaData();
		cout << endl << endl;
		cout << "Numero esami superati: " << EsamiSuperati << endl << endl;
		cout << "Il massimo ottenuto è: " << getVotoMax() << endl << endl;
		cout << "Con una media di : " << getMedia() << endl << endl;
		cout << "Su un totale di " << EsamiCorsoDiLaurea << " esami."<< endl << endl;
		cout << "Quindi gli esami rimanenti sono: " <<  getNumEsamiAllaLaurea() << endl << endl;
	}

