#ifndef ORARIO_H
#define ORARIO_H

class Orario
{
	public:
			Orario();
			void setOrario( int, int, int);
			void printOrario() const;
			void incrementaSecondi();
			void incrementaMinuti();
			void incrementaOre();
			bool confrontaOrari( const Orario& ) const;	
	private:	
			int ore;
			int minuti;
			int secondi;
};

#endif
