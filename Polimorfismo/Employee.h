#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
using std::string;
using namespace std;

class Employee
{
    public:
        Employee(const string & f, const string &l): firstName(f), lastName(l){}
        void setFirstName(const string & fn) { firstName = fn; }
        string getFirstName() const {return firstName;}
        void setLastName(const string & ln) { lastName = ln; }
        string getLastName() const {return lastName; }
        
        virtual double earnings() const = 0;
        virtual void print() const { cout << firstName << " " << lastName << endl; }
        virtual ~Employee(){cout << "Employee destructor"<<endl;}
    
    private:
        string firstName, lastName;
};

#endif
