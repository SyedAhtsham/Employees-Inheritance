//
//  Commissioned.cpp
//  OOP Assignment 3
//
//  Created by Syed Ahtsham on 6/6/21.
//  Copyright © 2021 Syed Ahtsham. All rights reserved.
//

#include "employee.h"
#include<iostream>
using namespace std;


class CommissionedEmployee: public Employee
{
private:
    float sales;
    float commissionRate;
    
    friend istream& operator >> (istream& in, CommissionedEmployee& obj)
    {
        cout<<"Commissioned Employee Input"<<endl<<endl;

       in >> (Employee&)obj;
        cout<<"Enter the Sales: ";
        in>>obj.sales;
        cout<<"Enter the Commission Rate: ";
        in>>obj.commissionRate;
        
        return in;
    }
    
    friend ostream& operator << (ostream& out, const CommissionedEmployee& obj)
    {
        out<<"Commissioned Employee Output"<<endl<<endl;

        out<<(Employee&)obj;
        out<<"Sales of Employee: "<<obj.sales<<endl;
        out<<"Commission Rate: "<<obj.commissionRate<<endl;

        return out;
        }
    
public:
    
        CommissionedEmployee(string a_name = "Ali", float a_taxRate = 0.0, Date a_dateOfJoining = Date(),float a_sales = 0.0, float a_commRate = 0.0):Employee(a_name, a_taxRate, a_dateOfJoining), sales(a_sales), commissionRate(a_commRate) {
          
        }
    
    void setSales(float sales)
    {
        this->sales = sales;
    }
    
    float getSales() const{
        return sales;
    }
    
    void setCommissionRate(float commissionRate)
    {
        this->commissionRate = commissionRate;
    }
       
    float getCommissionRate() const{
        return commissionRate;
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
        float salary = (commissionRate/sales)*100;
               float tax = (getTaxRate()/salary)*100;
               salary = salary-tax;
               
               return salary;
               }
    
    virtual ~CommissionedEmployee(){
        cout<<"commmissioned des"<<endl;
    }
    
    
};
