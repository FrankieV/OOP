#ifndef LIBRO_H
#define LIBRO_H

class Libro
{
	public:
		Libro();
		Libro( const Libro& );
		Libro( int, char *, char *);	
		~Libro();
		void setCodice( int );
		void setTitolo( const char * );
		void setAutore( const char * );
		int getCodice() const;
		char* getTitolo() const;
		char* getAutore() const;
		void setLibro( const Libro& l );
		void stampaLibro() const;
	private:
		int Codice;
		char *Titolo;
		char *Autore;
};//Fine classe libro

#endif
