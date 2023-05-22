//
//  Salaried.cpp
//  OOP Assignment 3
//
//  Created by Syed Ahtsham on 6/6/21.
//  Copyright © 2021 Syed Ahtsham. All rights reserved.
//

#include <stdio.h>
#include "employee.h"
#include<iostream>
using namespace std;


class SalariedEmployee: public Employee
{
private:
    float salary;
    
    friend istream& operator >> (istream& in, SalariedEmployee& obj)
    {
        cout<<"Salaried Employee Input"<<endl<<endl;

       in >> (Employee&)obj;
        cout<<"Enter the Salary: ";
        in>>obj.salary;
        
        return in;
    }
    
    friend ostream& operator << (ostream& out, const SalariedEmployee& obj)
    {
        out<<"Salaried Employee Output"<<endl<<endl;

        out<<(Employee&)obj;
        
        return out;
        
        }
    
public:
        
    SalariedEmployee(string a_name = "Ali", float a_taxRate = 0.0, Date a_dateOfJoining = Date(),float a_salary = 0.0):Employee(a_name, a_taxRate, a_dateOfJoining), salary(a_salary) {
      
    }
    
    void setSalary(float salary)
    {
        this->salary = salary;
    }
    
    float getSalary() const{
        return salary;
    }
    
        virtual void input()
           {
               cin>>*this;
           }
        
    virtual float calculateSalary() const
        {
        
        float tax = (getTaxRate()/salary)*100;
        float sal = salary-tax;
        
        return sal;
        }
    
        virtual void output() const
            {
                cout<<*this;
            }
    
    
        virtual ~SalariedEmployee()
        {
        cout<<"Salaried des"<<endl;
        }
    
    
};
