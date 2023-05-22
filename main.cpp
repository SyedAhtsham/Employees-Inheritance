//
//  main.cpp
//  OOP Assignment 3
//
//  Created by Syed Ahtsham on 6/6/21.
//  Copyright © 2021 Syed Ahtsham. All rights reserved.
//

#include <iostream>
#include "employee.h"
#include "Salaried.cpp"
#include "Commissioned.cpp"
#include "Hourly.cpp"
using namespace std;



int main()
{
    Employee** ptr = new Employee*[10];

    int n = 0, i = -1;
    char choice , opt;

    do
    {
        i++;
        cout << "\n\tChoose Salaried , Commissioned , Hourly Employee (s/c/h) : ";
        cin >> choice;

        switch (choice)
        {
        case 's':
        case 'S':
            ptr[i] = new SalariedEmployee;
            cout << endl;
            ptr[i]->input();
                break;

        case 'c':
        case 'C':
            ptr[i] = new CommissionedEmployee;
            cout << endl;
              ptr[i]->input();
                          break;
        case 'h':
        case 'H':
            ptr[i] = new HourlyEmployee;
            cout << endl;
              ptr[i]->input();
                          break;
        default:
            cout << "\n\tInvalid Choice ... ";
            system("pause");
        }
    
        cout << "\n\n\tEnter another (y/n) ? ";
        cin >> opt;

    } while((opt == 'Y' || opt == 'y' )&& (i != 9));

    if(i>=0){
        cout<<endl;
        cout<<"Displaying the Employees Info:"<<endl<<endl;
    for(int k=0; k<=i; k++)
    {
        ptr[k]->output();
        cout<<"Salary of Employee: "<<ptr[k]->calculateSalary()<<endl;
        cout<<endl;
        cout<<"----------------------"<<endl;
        cout<<"----------------------"<<endl<<endl;
    }
    }

    for (int j = 0; j <= i; j++)
        delete ptr[j];

    cout << "\nTerminated ... ";
    cout << endl << endl;
    system("pause");

    return 0;
    
    
}
