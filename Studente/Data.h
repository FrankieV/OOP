#pragma once
#ifndef DATA_H
#define DATA_H

class Data
{
public:
	Data();
	Data(int, int, int);
	Data(const Data &);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void leggiData(int, int, int);
	void printDate() const;

private:
	int day, month, year;
};

#endif
