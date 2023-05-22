//
//  main.cpp
//  OOP Assignment 3
//
//  Created by Syed Ahtsham on 6/6/21.
//  Copyright © 2021 Syed Ahtsham. All rights reserved.
//

#include "employee.h"
#include <iostream>
#include <string>
#include "date.h"
using namespace std;


    void Employee::setName(string n)
    {
        name = n;
    }
    
    string Employee::getName() const{
        return name;
    }

void Employee::setTaxRate(float tR)
 {
     taxRate = tR;
     
 }
 
 float Employee::getTaxRate() const{
     return taxRate;
 }
 

    
istream& operator >> (istream& in, Employee& obj)
{
   
    in.ignore();
    cout << "Enter Name: ";
    getline(in, obj.name);
    cout << "Enter Date of Joining: "<<endl;
    in>>obj.dateOfJoining;
    cout << "Enter Tax Rate: ";
    in>>obj.taxRate;

    return in;
}

    
ostream& operator << (ostream& out, const Employee& obj)
{
    out<<"Name: "<<obj.name;
    out<<endl;
    out<<"Date of Joining: "<<obj.dateOfJoining;
    out<<endl;
    out<<"Tax Rate: "<<obj.taxRate<<endl;
    
    return out;
}
