#ifndef DATA_H
#define DATA_H

class Data
	{
		public:
			Data();
			Data(const Data&);
			void setGiorno( int );
			void setMese( int );
			void setAnno( int );
			int getGiorno() const;
			int getMese() const;
			int getAnno() const;
			void leggiData();
			void stampaData() const;	
		private:
			int Giorno;
			int Mese;
			int Anno;
};

#endif
