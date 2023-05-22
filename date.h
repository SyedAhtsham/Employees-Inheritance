


#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date{
  
private:
    int day, month, year;
    
    bool leapYear(const int var) const
    {
        if(((var%4==0) && (var%100 != 0)) || (var%400 == 0))
        {
            return true;
        }
        return false;
    }
    
    friend ostream& operator<<(ostream& , const Date&);
    friend istream& operator>>(istream& , Date&);

public:
    
    Date();
  
    
    Date(const int , const int , const int );
    

    void setMonth(const int );
    void setDay(const int );
    void setYear(const int );
    void setDate(const int , const int , const int );
    void displayDate() const;
    
    
    Date operator+(const Date &);
    
    
    
    
    
};


#endif
