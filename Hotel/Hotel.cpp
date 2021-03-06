#include "Hotel.h"

Hotel::Hotel( int ns, int nd, int nt ): numSingole(ns), numDoppie(nd), numTriple(nt)
{
	for( int i = 0; i < numSingole + numDoppie + numTriple; i++ )
		{
			// inizializza le camere singole
			if( i < numSingole )
				{
					Singola* s = new Singola();
					camere.push_back( s );
				}

			//inizializza le camere doppie
			if( i >= numSingole && i < numDoppie + numSingole )
				{
					Doppia* d = new Doppia();
					camere.push_back( d );	
				}

			//inizializza le camere triple
			if( i >= numDoppie + numSingole && i < numTriple + numDoppie + numSingole)
				{
					Tripla* t = new Tripla();
					camere.push_back( t );		
				}
		}
}

Hotel::Hotel( Hotel& h )
{
	for(list<Camera*>:: iterator it = h.camere.begin(); it != h.camere.end(); it++ )
		camere.push_back(*it);
}

Hotel:: ~Hotel()
{
	for( list<Camera*>:: iterator it = camere.begin(); it != camere.end(); it++ )
		delete *it;
}

void Hotel:: inserisciPrenotazione()
{
	cout << endl << endl;

	bool postolibero = false;
	bool colazione = false;
	Prenotazione p;
	string a;

	cout << "Inserisci il nome del cliente ( Nome, Cognome ): " << endl;
	cin >> a;
	p.setNomeClientePrenotazione(a);
	cin >> a;
	p.setCognomeClientePrenotazione(a);
	
	cout << "Inserisci il numero della carta di credito del cliente: " << endl;
	cin >> a;
	p.setNumeroCartaDiCredito(a);

	cout << "Il cliente vuole anche la colazione: " << endl;
	cin >> a;
	if( a == "si")
		colazione = true;

	cout << "Inserisci il tipo di camera ( singola, doppia, tripla ): " << endl;
	cin >> a;

	if( a == "singola")
		{
			list<Camera*>::iterator it = camere.begin();
			for(int i = 0; i < getNumSingole(); i ++ )
				{	
					if( (*it) -> getOccupata() == false )
						{
							postolibero = true;
							p.setNumeroCamera( (*it) -> getNum());
							(*it) -> setOccupata();
							if( colazione )
								p.setImportoPrenotazione( (*it) -> getPrezzo() + 15 );
							else
								p.setImportoPrenotazione( (*it) -> getPrezzo());
							break;
						}
					it++;	
				}
			if( postolibero == false )
				cout << "Spiacenti non ci sono camere singole libere in questo Hotel." << endl;		
		}

	if( a == "doppia")
		{
			list<Camera*>::iterator it = camere.begin();

			for( int i = 0; i < getNumSingole(); i++ )
				it++;

			for(int i = getNumSingole(); i < getNumSingole() + getNumDoppie(); i ++ )
				{
					if( (*it) -> getOccupata() == false )
						{
							postolibero = true;
							p.setNumeroCamera( (*it) -> getNum());
							(*it) -> setOccupata();
							if( colazione )
								p.setImportoPrenotazione( (*it) -> getPrezzo() + 15 );
							else
								p.setImportoPrenotazione( (*it) -> getPrezzo());
							break;
						}
					it++;						
				}		
			if( postolibero == false )
				cout << "Spiacenti non ci sono camere doppie libere in questo Hotel." << endl;
		}
	
	if( a == "tripla")
		{
			list<Camera*>::iterator it = camere.begin();

			for( int i = 0; i < getNumSingole() + getNumDoppie(); i++ )
				it++;

			for(int i = getNumSingole() + getNumDoppie(); i < getNumSingole() + getNumDoppie() + getNumTriple(); i ++ )
				{
					if( (*it) -> getOccupata() == false )
						{
							postolibero = true;
							p.setNumeroCamera( (*it) -> getNum());
							(*it) -> setOccupata();	
							if( colazione )
								p.setImportoPrenotazione( (*it) -> getPrezzo() + 15 );
							else
								p.setImportoPrenotazione( (*it) -> getPrezzo());						
							break;
						}
					it++;						
				}
			if( postolibero == false )
				cout << "Spiacenti non ci sono camere triple libere in questo Hotel." << endl;
		}

	prenotazioni.push_back(p);
}

void Hotel::eliminaPrenotazione()
{
	int num;	
	Prenotazione* p;	

	cout << endl << endl;
	cout << "ELIMINAZIONE PRENOTAZIONE!!" << endl;
	cout << "Inserisci il numero della stanza che si intende liberare. ";
	cin >> num;
	
	for( list<Camera*>:: iterator it = camere.begin(); it != camere.end(); it++ )
		{
			if( (*it) -> getNum() == num )
				(*it) -> setLibera();
		}
	
	for( list<Prenotazione>:: iterator it = prenotazioni.begin(); it != prenotazioni.end(); it++)
		{
			if( it -> getNumeroCamera() == num )
				it = prenotazioni.erase(it);	
		}
}

int Hotel::getNumSingole() const
{
	return numSingole;
}

int Hotel::getNumDoppie() const
{
	return numDoppie;
}

int Hotel::getNumTriple() const
{
	return numTriple;
}

list<Camera*> Hotel::getCamere() const
{
	return camere;
}

int Hotel::getTotaleImporti()
{
	if( prenotazioni.empty())
		return -1;

	int TotaleImporti = 0;

	for( list<Prenotazione>::iterator it = prenotazioni.begin(); it != prenotazioni.end(); it++ )
		{
			TotaleImporti += it -> getImportoPrenotazione();
		}

	return TotaleImporti;
}

void Hotel::stampa()
{
	cout << endl << "Salve questo è un Hotel della catena Ollivier Hint, questo Hotel ha ";
	cout << numSingole + numDoppie + numTriple << " camere" << endl;
	for( list<Camera*>:: iterator it = camere.begin(); it != camere.end(); it++ )
		(*it) -> print();		
	
	for( list<Camera*>:: iterator it = camere.begin(); it != camere.end(); it++ )
		{	
			stampa_iteratore(it);
			break;
		}
	
	for( list<Camera*>:: iterator it = camere.begin(); it != camere.end(); it++ )
		(*it) -> print();		
	
				
}

void Hotel::stampa_iteratore( list<Camera*>:: iterator it1)
{
	for(list<Camera*>:: iterator it = camere.begin(); it != camere.end(); it++)
		if( it1 == it )
			it = camere.erase(it);
}

void Hotel::stampaPrenotazioni()
{
	cout << endl << endl;

	int count = 1;
	
	cout <<"In questo hotel sono presenti " << prenotazioni.size() << " prenotazioni:" << endl;
	
	cout << endl;
	cout << "__________________________________________________________" << endl;

	for( list<Prenotazione>:: iterator it = prenotazioni.begin(); it != prenotazioni.end(); it++)
		{
			cout <<"Prenotazione numero: " << count << endl;
			cout <<"Nome cliente: " << it -> getNomeClientePrenotazione() << " " << it -> getCognomeClientePrenotazione() << endl;
			cout <<"Camera";

			if( it -> getNumeroCamera() >= 1 && it -> getNumeroCamera() < getNumSingole())
				{
					cout << " singola numero ";
					cout << it -> getNumeroCamera();
					if( it -> getImportoPrenotazione() > 30 )
						cout << " con colazione al prezzo di " << it -> getImportoPrenotazione() << " euro." << endl;
					else
						cout << " al prezzo di " << it -> getImportoPrenotazione() << " euro." << endl;		
				}

			if( it -> getNumeroCamera() >= getNumSingole() && it -> getNumeroCamera() < getNumSingole() + getNumDoppie())
				{
					cout << " doppia numero ";
					cout << it -> getNumeroCamera();
					if( it -> getImportoPrenotazione() > 50 )
						cout << " con colazione al prezzo di " << it -> getImportoPrenotazione() << " euro." << endl;
					else
						cout << " al prezzo di " << it -> getImportoPrenotazione() << " euro." << endl;	
				}

			if( it -> getNumeroCamera() >= getNumSingole() + getNumDoppie() && it -> getNumeroCamera() < getNumSingole() + getNumDoppie() + getNumTriple())
				{
					cout << " tripla numero ";
					cout << it -> getNumeroCamera();
					if( it -> getImportoPrenotazione() > 75 )
						cout << " con colazione al prezzo di " << it -> getImportoPrenotazione() << " euro." << endl;
					else
						cout << " al prezzo di " << it -> getImportoPrenotazione() << " euro." << endl;	
				}

			count++;
			
			cout << endl;
			cout << "__________________________________________________________" << endl;
		}
}
