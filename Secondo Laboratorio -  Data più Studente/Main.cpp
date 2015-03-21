#include <iostream>
#include "Studente.h"
using namespace std;

int main()
{
	double SommaVotiStudenti = 0;
	double NumeroTotaleEsami = 0;
	double MediaTotaleStudenti = 0;
	int StudenteConLaMediaMigliore = 0;	
	int n;
	cout << "Quanti studenti devi inserire ?" << endl;
	cin >> n;
	const int dim = n;
	int VotiMiglioriStudenti[dim];
	Studente *Stu = new Studente[dim];
	for( int i = 0; i < dim; i++)
		Stu[i].leggiStudente();
	double MediaMigliore = Stu[0].getMedia();
	for( int i = 0; i < dim; i++)
		{
			if( Stu[i].getMedia() > MediaMigliore)
				{
					StudenteConLaMediaMigliore = i;
					MediaMigliore = Stu[i].getMedia();
				}
			NumeroTotaleEsami += (25 - Stu[i].getNumEsamiAllaLaurea());						
			for( int NumEsami = 0; NumEsami < 25; NumEsami++)
				{
					if( Stu[i].getVotoEsame( NumEsami ) >= 18 && Stu[i].getVotoEsame( NumEsami ) <= 30)
						{
							SommaVotiStudenti += Stu[i].getVotoEsame( NumEsami );
						}				
				}		
		}
	MediaTotaleStudenti = SommaVotiStudenti/NumeroTotaleEsami;
	cout << endl << endl << endl << endl << endl << endl;
	cout << "PRIMO PUNTO ESERCITAZIONE:" << endl;
	cout << "La media totale degli studenti e': ";
	cout << MediaTotaleStudenti << endl << endl;
	cout << "SECONDO PUNTO ESERCITAZIONE:" << endl;
	cout << "Lo studente con la media migliore e': " << endl;
	Stu[StudenteConLaMediaMigliore].stampaStudente();	
	cout << endl << endl;


	//Trovare il voto più alto più frequente:
	for( int i = 0; i < dim; i++)
		VotiMiglioriStudenti[i] = Stu[i].getVotoMax();
	int VotoPiuFrequente = VotiMiglioriStudenti[0];
	int VotoPiuAlto = VotiMiglioriStudenti[0];	
	int Ricorrenze = 0;
	int MaxRicorrenze = 0;
	for( int i = 0; i < dim; i++ )
		{
			for( int j = 0; j < dim; j++ )
				{
					
					if( i != j)					
						{
							if( VotiMiglioriStudenti[i] == VotiMiglioriStudenti[j])
								Ricorrenze++;
						}				
				}	
			if( Ricorrenze > MaxRicorrenze )
				{
					MaxRicorrenze = Ricorrenze;
					VotoPiuFrequente = VotiMiglioriStudenti[i];
				}	
			if( Ricorrenze == MaxRicorrenze && VotiMiglioriStudenti[i] > VotoPiuAlto)
				{
					MaxRicorrenze = Ricorrenze;
					VotoPiuFrequente = VotiMiglioriStudenti[i];
					VotoPiuAlto = VotiMiglioriStudenti[i];
				}
			Ricorrenze = 0;		
		}
	cout << "TERZO PUNTO ESERCITAZIONE " << endl;
	cout << "Il voto piu' alto piu' frequente tra gli studenti e': " << VotoPiuFrequente << endl << endl;		
	

	//Trovare il mese in cui sono nati meno studenti
	const int NumeroMesi = 12;
	int MesiDiNascitaStudenti[NumeroMesi];
	int IndexRicorrenze = 0;	
	Data DataNascitaStudente;
	for( int i = 0; i < NumeroMesi; i++)
		MesiDiNascitaStudenti[i] = 0;
	for( int i = 0; i < dim; i++)
		{
			DataNascitaStudente = Stu[i].getDataNascita();
			IndexRicorrenze = DataNascitaStudente.getMese();
			MesiDiNascitaStudenti[IndexRicorrenze-1] += 1;
		}
	int MinRicorrenzeMese = dim + 1;
	int MeseConMenoRicorrenze;
	for( int i = 0; i < 12; i++)
		{
			if(MesiDiNascitaStudenti[i] != 0 && MesiDiNascitaStudenti[i] < MinRicorrenzeMese)
				{
					MeseConMenoRicorrenze = i + 1;
					MinRicorrenzeMese = MesiDiNascitaStudenti[i];				
				}	
		}
	cout << "QUARTO PUNTO ESERCITAZIONE: " << endl;			
	cout << "Il mese con meno studenti nati e': ";
	switch( MeseConMenoRicorrenze )
		{
			case 1:
				cout << "GENNAIO" << endl;
				break;
			case 2:
				cout << "FEBBRAIO" << endl;
				break;
			case 3:
				cout << "MARZO" << endl;
				break;
			case 4:
				cout << "APRILE" << endl;
				break;
			case 5:
				cout << "MAGGIO" << endl;
				break;
			case 6:
				cout << "GIUGNO" << endl;
				break;
			case 7:
				cout << "LUGLIO" << endl;
				break;
			case 8:
				cout << "AGOSTO" << endl;
				break;
			case 9:
				cout << "SETTEMBRE" << endl;
				break;
			case 10:
				cout << "OTTOBRE" << endl;
				break;
			case 11:
				cout << "NOVEMBRE" << endl;
				break;
			case 12:
				cout << "DICEMBRE" << endl;
				break;				
		}
	cout << endl;

	//Ordinamento studenti con riferimento alla data di nascita
	cout << "QUINTO PUNTO ESERCITAZIONE: " << endl;
	Studente StudenteProvvisorio;	
	for( int i = 0; i < dim; i++)
		{
			for( int j= 0; j < dim; j++)
				{
					if( i != j)
						{
							if(( Stu[i].StudentePiuGiovaneDi( Stu[j] ) == false ) && j > i)
								{
									StudenteProvvisorio = Stu[i];
									Stu[i] = Stu[j];
									Stu[j] = StudenteProvvisorio;		
								}
						}
				}		
		}
	cout << "Stampa delle Matricole in base alla data di nascita degli studenti ( dal più giovane al più vecchio): ";
	for( int i = 0; i < dim; i++ )
		cout << Stu[i].getNumeroMatricola() << " ";
	cout << endl << endl;
	return 0;
}
