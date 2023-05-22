//
//  Hourly.cpp
//  OOP Assignment 3
//
//  Created by Syed Ahtsham on 6/6/21.
//  Copyright © 2021 Syed Ahtsham. All rights reserved.
//

#include "employee.h"
#include<iostream>
using namespace std;


class HourlyEmployee: public Employee
{
private:
    int hoursWorked;
    float hourlyRate;
    
    friend istream& operator >> (istream& in, HourlyEmployee& obj)
    {
        cout<<"Hourly Employee Input"<<endl<<endl;
       in >> (Employee&)obj;
        cout<<"Enter the Hours Worked: ";
        in>>obj.hoursWorked;
        cout<<"Enter the Hourly Rate: ";
        in>>obj.hourlyRate;
        
        return in;
    }
    
    friend ostream& operator << (ostream& out, const HourlyEmployee& obj)
    {
        out<<"Hourly Employee Output"<<endl<<endl;
        out<<(Employee&)obj;
        out<<"Hours Worked: "<<obj.hoursWorked<<endl;
        out<<"Hourly Rate: "<<obj.hourlyRate<<endl;

        return out;
        }
    
public:
       HourlyEmployee(string a_name = "Ali", float a_taxRate = 0.0, Date a_dateOfJoining = Date(),int a_hoursWorked = 0, float a_hourlyRate = 0.0):Employee(a_name, a_taxRate, a_dateOfJoining), hoursWorked(a_hoursWorked), hourlyRate(a_hourlyRate) {
          
        }
    
    void setHoursWorked(int hoursWorked)
    {
        this->hoursWorked = hoursWorked;
    }
    
    int getHoursWorked() const{
        return hoursWorked;
    }
    
    void setHourlyRate(float hourlyRate)
    {
        this->hourlyRate = hourlyRate;
    }
       
    float getHourlyRate() const{
        return hourlyRate;
    }
    virtual void input()
              {
                  cin>>*this;
              }
        
        virtual void output() const
                     {
                         cout<<*this;
                     }
        
    virtual float calculateSalary() const
                  {
        float salary = hoursWorked * hourlyRate;
                  float tax = (getTaxRate()/salary)*100;
                  salary = salary-tax;
                  
                  return salary;
                  }
        
        virtual ~HourlyEmployee(){
        cout<<"hourly des"<<endl;
        }
    
    
};

