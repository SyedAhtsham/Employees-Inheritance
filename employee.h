//
//  employee.h
//  OOP Assignment 3
//
//  Created by Syed Ahtsham on 6/6/21.
//  Copyright © 2021 Syed Ahtsham. All rights reserved.
//

#ifndef employee_h
#define employee_h


//
//  main.cpp
//  OOP Assignment 3
//
//  Created by Syed Ahtsham on 6/6/21.
//  Copyright © 2021 Syed Ahtsham. All rights reserved.
//

#include <iostream>
#include <string>
#include "date.h"
using namespace std;

class Employee{
  
private:
    string name;
    Date dateOfJoining;
    float taxRate;
    
    friend istream& operator >> (istream&, Employee&);
    friend ostream& operator << (ostream&, const Employee&);

public:
    
    Employee(string a_name = "Ali", float a_taxRate = 0.0, Date a_dateOfJoining = Date()):name(a_name), taxRate(a_taxRate), dateOfJoining(a_dateOfJoining){
      
    }
    
    void setName(string name);
    string getName() const;
        
    void setTaxRate(float );
    float getTaxRate() const;
    
    virtual void input() = 0;
    
    virtual void output() const = 0;
    
    virtual float calculateSalary() const = 0;
    

    virtual ~Employee(){
        cout<<"Employee des"<<endl;
    }
    

    
};




#endif /* employee_h */
