#include "GestoreFatture.h"

/*Restituire il nome dell'azienda che ha emesso più fatture.*/
string GestoreFatture::metodo1()
{
	if( fatture.empty())
		return "EMPTY";

	int count = 0;
	int max = 0;
	string AziendaCheHaEmessoPiuFatture;
	for( list<Fattura>:: iterator it1 = fatture.begin(); it1 != fatture.end(); it1++ )
		{
			for( list<Fattura>:: iterator it2 = fatture.begin(); it2 != fatture.end(); it2++)
				{
					if( it1 != it2 ) 
						{
							if( it1 -> getAziendaEmittente() == it2 -> getAziendaEmittente() )
								count++;
						}
				}	
			if( count > max ) 
				{
					AziendaCheHaEmessoPiuFatture = it1 -> getAziendaEmittente();
					max = count;
				}		
			count = 0;
		}
	return AziendaCheHaEmessoPiuFatture;
}

/*Restituire il nome dell'azienda che ha emesso la fattura con l'importo maggiore.*/
string GestoreFatture::metodo2()
{
	if( fatture.empty())
		return "EMPTY";
	
	int max = fatture.front().getImporto();
	string AziendaConImportoMaggiore = fatture.front().getAziendaEmittente();	
	for( list<Fattura>:: iterator it = fatture.begin(); it != fatture.end(); it++ )
		{
			if( it -> getImporto() > max )
				{
					max = it -> getImporto();
					AziendaConImportoMaggiore = it -> getAziendaEmittente();
				}		
		}
	return AziendaConImportoMaggiore;
}

/*Restituire il nome dell'azienda che ha emesso la fattura con l'importo minore.*/
string GestoreFatture::metodo3()
{
	if( fatture.empty())
		return "EMPTY";	
	
	int min = fatture.front().getImporto();
	string AziendaConImportoMinore = fatture.front().getAziendaEmittente() ;	
	for( list<Fattura>:: iterator it = fatture.begin(); it != fatture.end(); it++ )
		{
			if( it -> getImporto() < min )
				{
					min = it -> getImporto();
					AziendaConImportoMinore = it -> getAziendaEmittente();
				}		
		}
	return AziendaConImportoMinore;
}

/*Sia M la media degli importi delle fatture emesse e ricevute da un'azienda. Restituire il nome dell'azienda che ha il valore di M più alto.*/
string GestoreFatture::metodo4()
{
	if( fatture.empty())
		return "EMPTY";

	list <string> Aziende;
	int MediaMassima = 0;		
	string AziendaConMediaMassima;	
	int cont = 0;
	int somma = 0;	
	int media = 0;
	bool prima_volta = true;
	for( list<Fattura>:: iterator it = fatture.begin(); it != fatture.end(); it++ )
		{
			Aziende.push_back( it -> getAziendaEmittente());
			Aziende.push_back( it -> getAziendaRicevente());
		}
	Aziende.sort();
	Aziende.unique();
	for( list<string>::iterator it1 = Aziende.begin(); it1 != Aziende.end(); it1++ )
		{
			for( list<Fattura>:: iterator it2 = fatture.begin(); it2 != fatture.end(); it2++ )
				{
					if( *it1 == it2 -> getAziendaEmittente() || *it1 == it2 -> getAziendaRicevente())
						{						
							cont++;
							somma = it2 -> getImporto();
						}				
				}		
			media = somma / cont;
			if( prima_volta == true )
				{
					MediaMassima = media;
					AziendaConMediaMassima = *it1; 		
					prima_volta = false;				
				}	
			if( media > MediaMassima )
				AziendaConMediaMassima = *it1;
	
			somma = 0;
			cont = 0;
			media = 0;	
		}
	return AziendaConMediaMassima;
}

/*Restituire il numero di aziende che ha emesso solo fatture per prodotti dello stesso tipo.*/
int GestoreFatture::metodo5()
{
	if( fatture.empty())
		return -1;

	list<string> Aziende;
	bool solo = true;
	for( list<Fattura>:: iterator it1 = fatture.begin(); it1 != fatture.end(); it1++ )	
		{
			for( list<Fattura>:: iterator it2 = fatture.begin(); it2 != fatture.end(); it2++ )
				{
					if(( it1 -> getAziendaEmittente() == it2 -> getAziendaEmittente()) && ( it1 -> getTipoProdotto() != it2 -> getTipoProdotto()))
						solo = false;
		
				}
			if( solo == true )
				Aziende.push_back( it1 -> getAziendaEmittente() );
			solo = true;
		}
	Aziende.sort();
	Aziende.unique();
	return Aziende.size();
}

/*Restituire la differenza tra il numero di aziende che ha emesso fatture solo per prodotti SPORTIVI e il numero di aziende che ha emesso fatture solo per prodotti CULTURALI.*/
int GestoreFatture::metodo6()
{
	if( fatture.empty())
		return -1;
	
	list<string> soloProdottiSportivi;
	list<string> soloProdottiCulturali;
	bool solo = true;
	for( list<Fattura>:: iterator it1 = fatture.begin(); it1 != fatture.end(); it1++ )
		{
			for( list<Fattura>:: iterator it2 = fatture.begin(); it2 != fatture.end(); it2++ )
				{
					if( it1 -> getAziendaEmittente() == it2 -> getAziendaEmittente() && it2 -> getTipoProdotto() != SPORTIVO )
						solo = false;
				}
			if( solo == true )
				soloProdottiSportivi.push_back( it1 -> getAziendaEmittente());
			solo = true;
			for( list<Fattura>::iterator it3 = fatture.begin(); it3 != fatture.end(); it3++ )
				{
					if( it1 -> getAziendaEmittente() == it3 -> getAziendaEmittente() && it3 -> getTipoProdotto() != CULTURALE)
						solo = false;				
				}
			if( solo == true )
				soloProdottiCulturali.push_back( it1 -> getAziendaEmittente());
			solo = true;
		}
	soloProdottiSportivi.sort();
	soloProdottiSportivi.unique();
	soloProdottiCulturali.sort();
	soloProdottiCulturali.unique();
	return soloProdottiSportivi.size() - soloProdottiCulturali.size();
}

/*Restituire il numero di aziende che vende solo prodotti ALIMENTARI e compra almeno un prodotto SPORTIVO.*/
int GestoreFatture::metodo7()
{
	if( fatture.empty()) 
		return -1;
	
	list<string>soloProdottiAlimentari;
	list<string>almenoUnoSportivo;	
	bool solo = true;
	for( list<Fattura>:: iterator it1 = fatture.begin(); it1 != fatture.end(); it1++ )
		{
			for( list<Fattura>:: iterator it2 = fatture.begin(); it2 != fatture.end(); it2++ )
				{
					if( it1 -> getAziendaEmittente() == it2 -> getAziendaEmittente() && it2 -> getTipoProdotto() != CULTURALE )
						solo = false;
				}
			if( solo == true)
				soloProdottiAlimentari.push_back(it1->getAziendaEmittente());
			solo = true;		
		}
	soloProdottiAlimentari.sort();
	soloProdottiAlimentari.unique();

	for( list<string>:: iterator it1 = soloProdottiAlimentari.begin(); it1 != soloProdottiAlimentari.end(); it1++ )
		{
			for( list<Fattura>:: iterator it2 = fatture.begin(); it2 != fatture.end(); it2++ )
				{
					if( *it1 == it2 -> getAziendaRicevente() && it2 -> getTipoProdotto() == SPORTIVO )
						almenoUnoSportivo.push_back(*it1);
				}
		}
	almenoUnoSportivo.sort();
	almenoUnoSportivo.unique();
	return almenoUnoSportivo.size();
}

/*Restituire il numero di aziende che non compra prodotti CULTURALI.*/
int GestoreFatture::metodo8()
{
	if( fatture.empty()) 
		return -1;

	list<string>maiProdottiCulturali;
	bool mai = true;
	for( list<Fattura>:: iterator it1 = fatture.begin(); it1 != fatture.end(); it1++ )
		{
			for( list<Fattura>:: iterator it2 = fatture.begin(); it2 != fatture.end(); it2++ )
				{
					if( it1 -> getAziendaRicevente() == it2 -> getAziendaRicevente() && it2 -> getTipoProdotto() == CULTURALE )
						mai = false;		
				}
			if( mai == true )	
				maiProdottiCulturali.push_back( it1 -> getAziendaRicevente());
			mai = true; 
		}
	maiProdottiCulturali.sort();
	maiProdottiCulturali.unique();
	return maiProdottiCulturali.size();
}

/*S(A) la somma degli importi delle fatture emesse da un'azienda A. Siano A1 e A2 due aziende distinte tale per cui S(A1) + S(A2) sia massimo rispetto a tutte le altre coppie di aziende. Restituire il valore di S(A1) + S(A2).*/
int GestoreFatture::metodo9()
{
	if( fatture.empty()) 
		return -1;

	int sommaImporti = 0;
	list<string> aziende_scansionate;
	list<int> sommaImportiFatture;
	bool scansionata = false;
	for( list<Fattura>:: iterator it1 = fatture.begin(); it1 != fatture.end(); it1++ )
		{
			for( list <string>:: iterator it2 = aziende_scansionate.begin(); it2 != aziende_scansionate.end(); it2++ )
				{
					if( it1 -> getAziendaEmittente() == *it2)			
						scansionata = true;				
				}	

			if( scansionata == false)
				{
					for( list <Fattura>:: iterator it3 = fatture.begin(); it3 != fatture.end(); it3++ )
						{
							if( it1 -> getAziendaEmittente() == it3 -> getAziendaEmittente())
								{
									sommaImporti += it3 -> getImporto();
									aziende_scansionate.push_back( it1 -> getAziendaEmittente());						
								}
						}
					sommaImportiFatture.push_back(sommaImporti);
				}
			scansionata = false;
			sommaImporti = 0;
		}
	
	bool prima_volta = true;
	int max;
	
	if( sommaImportiFatture.size() <= 1 )
		return -1;

	for( list<int>:: iterator it1 = sommaImportiFatture.begin(); it1 != sommaImportiFatture.end(); it1++ )
		{
			for( list<int>::iterator it2 = sommaImportiFatture.begin(); it2 != sommaImportiFatture.end(); it2++ )
				{
					if( it1 != it2 )
						{
							if( prima_volta == true )
								{
									max = *it1 + *it2;
									prima_volta = false;
								}
							if( *it1 + *it2 > max )
								max = *it1 + *it2;								
						}
				}
		}
	return max;
}

/*Sia A1 l'azienda che ha emesso la fattura per un prodotto ALIMENTARE con l'importo più alto. Sia A2 l'azienda che ha emesso la fattura per un prodotto SPORTIVO con l'importo più basso. Restituire il numero di fatture emesse dall'azienda A1 all'azienda A2.*/
int GestoreFatture::metodo10()
{
	if( fatture.empty()) 
		return -1;
	
	bool prima_volta_al = true;	
	bool prima_volta_sp = true;
	int max;
	int min;
	int cont = 0;
	string A1;
	string A2;
	
	for( list<Fattura>::iterator it1 = fatture.begin(); it1 != fatture.end(); it1++ )
		{
			if( it1 -> getTipoProdotto() == ALIMENTARE )
				{
					if( prima_volta_al == true )
						{
							max = it1 -> getImporto();
							A1 = it1 -> getAziendaEmittente();
							prima_volta_al = false;				
						}
					if( it1 -> getImporto() > max )
						{
							max = it1 -> getImporto();
							A1 = it1 -> getAziendaEmittente();				
						}
				}
			if( it1 -> getTipoProdotto() == SPORTIVO )
				{
					if( prima_volta_sp == true )
						{
							min = it1 -> getImporto();
							A2 = it1 -> getAziendaEmittente();
							prima_volta_sp = false;				
						}
					if( it1 -> getImporto() < min )
						{
							min = it1 -> getImporto();
							A2 = it1 -> getAziendaEmittente();				
						}
				}
		}
	
	for( list<Fattura>:: iterator it2 = fatture.begin(); it2 != fatture.end(); it2++ )
		{
			if( it2 -> getAziendaEmittente() == A1 && it2 -> getAziendaRicevente() == A2 )
				cont++;
		}

	return cont;
}

/* Restituire la stringa con il nome di tutte le aziende che vendono solo prodotti ALIMENTARI separate da una virgola. Esempio di output: A1,A2,A3 (Le aziende devono essere ordinate in ordine lessicografico)*/
string GestoreFatture::metodo11()
{
	if( fatture.empty()) 
		return "EMPTY";

	list<string>AziendeAlimentari;
	string Aziende_Alimentari;
	string tmp;
	bool solo = true;
	bool prima_volta = true;
	
	for( list<Fattura>:: iterator it1 = fatture.begin(); it1 != fatture.end(); it1++ )
		{
			for( list<Fattura> :: iterator it2 = fatture.begin(); it2 != fatture.end(); it2++ )
				{
					if( it1 -> getAziendaEmittente() == it2 -> getAziendaEmittente() && it2-> getTipoProdotto() != ALIMENTARE )
						solo = false;
				}
			if( solo == true )
				AziendeAlimentari.push_back( it1 -> getAziendaEmittente());

			solo = true;
		}
	AziendeAlimentari.sort();
	AziendeAlimentari.unique();
	
	for(list<string>:: iterator it = AziendeAlimentari.begin(); it != AziendeAlimentari.end(); it++ )
		{
			if( prima_volta )
				{				
					Aziende_Alimentari.append( *it );
					prima_volta = false;
				}
			else
				{
					Aziende_Alimentari.append(", " );
					Aziende_Alimentari.append( *it );
				}
		}

	if( Aziende_Alimentari.empty()) 
		return "EMPTY";

	return Aziende_Alimentari;
}

/*Sia A l'azienda che compare di meno nelle fatture (cioè quella che ha emesso e ricevuto meno fatture di tutte le altre). Restituire la stringa con il nome di tutte le aziende che hanno emesso/ricevuto una fattura a/da A separate da una virgola e uno spazio. Esempio di output: A1, A2, A3 (Le aziende devono essere ordinate in ordine lessicografico)*/
string GestoreFatture::metodo12()
{
	if( fatture.empty()) 
		return "EMPTY";
	
	list<string> Aziende;
	list<string> da_a;
	string Emessa_Ricevuta;
	string A_Meno_Comparizioni;
	bool scansionata = false;
	bool prima_volta = true;
	int cont = 0;
	int min = 0;

	for( list<Fattura>:: iterator it1 = fatture.begin(); it1 != fatture.end(); it1++ )
		{
			for( list<string>:: iterator it2 = Aziende.begin(); it2 != Aziende.end(); it2++ )
				{
					if( *it2 == it1 -> getAziendaEmittente())
						scansionata = true;
				}				
			if( scansionata == false )
				Aziende.push_back( it1 -> getAziendaEmittente());
			scansionata = false;
			for( list<string>:: iterator it3 = Aziende.begin(); it3 != Aziende.end(); it3++ )
				{
					if( *it3 == it1 -> getAziendaRicevente())
						scansionata = true;
				}				
			if( scansionata == false )
					Aziende.push_back( it1 -> getAziendaRicevente());
			scansionata = false;		
		}	

	for( list<string>:: iterator it1 = Aziende.begin(); it1 != Aziende.end(); it1++ )
		{
			for( list<Fattura>:: iterator it2 = fatture.begin(); it2 != fatture.end(); it2++ )
				{
					if( *it1 == it2 -> getAziendaEmittente() || *it1 == it2 -> getAziendaRicevente())
						cont++;
				}
			if( prima_volta == true )
				{
					min = cont;
					A_Meno_Comparizioni = *it1;
					prima_volta = false;		
				}	
			if( cont < min)
				{
					min = cont;
					A_Meno_Comparizioni = *it1;
				}
			cont = 0;
		}

	for( list<Fattura>:: iterator it = fatture.begin(); it != fatture.end(); it++ )
		{
			if( A_Meno_Comparizioni == it -> getAziendaEmittente())
				da_a.push_back( it -> getAziendaRicevente());
			if( A_Meno_Comparizioni == it -> getAziendaRicevente())
				da_a.push_back( it -> getAziendaEmittente());
		}

	da_a.sort();
	da_a.unique();
	prima_volta = true;

	for( list<string>:: iterator it = da_a.begin(); it != da_a.end(); it++ )
		{
			if( prima_volta == true )
				{
					Emessa_Ricevuta.append(*it);
					prima_volta = false;
				}
			else
				{
					Emessa_Ricevuta.append( ", ");
					Emessa_Ricevuta.append(*it);
				}
		}

	return Emessa_Ricevuta;	
}

/*Restituire il nome dell'azienda che collabora con più aziende.*/
string GestoreFatture::metodo13()
{
	if( fatture.empty()) 
		return "EMPTY";

	int max = 0;
	list<string> Aziende;
	list<string> Collaboratrici;
	string Collaboratrice;
	string Massima_Collaboratrice;
	bool presente = false;	
	
	for( list<Fattura>:: iterator it = fatture.begin(); it != fatture.end(); it++ )
		{
			Aziende.push_back( it -> getAziendaEmittente());
			Aziende.push_back( it -> getAziendaRicevente());
		}
	Aziende.sort();
	Aziende.unique();

	for( list<string>:: iterator it1 = Aziende.begin(); it1 != Aziende.end(); it1++ )
		{
			for( list<Fattura>:: iterator it2 = fatture.begin(); it2 != fatture.end(); it2++ )
				{
					if( *it1 == it2 -> getAziendaEmittente() )
						{	
							for( list<string>:: iterator it = Collaboratrici.begin(); it != Collaboratrici.end(); it++)
								{
									if( it2 -> getAziendaRicevente() == *it )
										presente = true;
								}

							if( presente == false )
								Collaboratrici.push_back( it2 -> getAziendaRicevente());

							for( list<string>:: iterator it3 = Collaboratrici.begin(); it3 != Collaboratrici.end(); it3++ )
								{
									for( list<Fattura>:: iterator it4 = fatture.begin(); it4 != fatture.end(); it4++ )						
										{		
											if( *it3 == it4 -> getAziendaEmittente())
												Collaboratrici.push_back( it4 -> getAziendaRicevente());
										}
								}
						}
					presente = false;
				}
	
			Collaboratrici.sort();
			Collaboratrici.unique();
		
			if( Collaboratrici.size() > max )
				{
					max = Collaboratrici.size();
					Massima_Collaboratrice = *it1;
				}

			Collaboratrici.clear();
		}

	cout << endl << endl;
	return Massima_Collaboratrice;
		
	
}

/*Restituire la somma degli importi delle fatture emesse dalle aziende che collaborano con la prima azienda in ordine lessicografico.*/
int GestoreFatture::metodo14()
{

}

/*Restituire la stringa con il nome di tutte le aziende che collabora con l'ultima azienda in ordine lessicografico. Esempio di output: A1A2A3 (Le aziende devono essere ordinate in ordine lessicografico)*/
int GestoreFatture::metodo15()
{

}

/*Restituire la somma degli importi delle fatture emesse dall'azienda che ha meno collaborazioni con altre aziende.*/
int GestoreFatture::metodo16()
{

}

