#include "date.h"
#include <iostream>
using namespace std;


    
    Date::Date()
    {
        day = 1;
        month = 1;
        year = 2021;
    
    }
    
    Date::Date(const int d, const int m, const int y)
    {
        if(d==0)
        day = 1;
        else{
            setDay(d);
        }
        
        if(m==0)
        {
            month = 1;
        }
        else{
            setMonth(m);
        }
        
        if(y==0)
            {
                   year = 2021;
               }
               else{
                   setYear(y);
               }

    }
    
    
    void Date::setMonth(const int m)
    {
        if(m>0 && m<=12)
        {
            month = m;
        }
        else{
            month = 1;
        }
    }
 
    void Date::setDay(const int d)
     {
         if(d>0 && d<=31)
         {
             day = d;
         }
         else{
             day = 1;
         }
     }
    
    void Date::setYear(const int y)
      {
          if(y>1999 && y<=2999)
          {
              year = y;
          }
          else{
              year = 2000;
          }
      }
    
    void Date::setDate(const int d, const int m, const int y){
        setDay(d);
        setMonth(m);
        setYear(y);
    }
    
    void Date::displayDate() const
    {
        cout<<day<<"/"<<month<<"/"<<year;
    }
    
    Date Date::operator+(const Date &d)
    {
        Date temp;
        
        
        
        temp.day = this->day + d.day;
        
              temp.month = this->month + d.month;
          
        
        temp.year = this->year + (this->year - d.year);
        
        if(temp.year<0)
        {
            temp.year = -1 * temp.year;
        }
        
        if(temp.month > 12)
        {
            temp.month = temp.month-12;
            temp.year = temp.year+1;
        }
        
        if((temp.day > 31) && (temp.month == 1 || temp.month == 3 ||temp.month == 5  ||temp.month == 7 ||temp.month == 8 || temp.month == 10 || temp.month == 12) )
        {
            temp.month = month+1;
            temp.day = temp.day-31;
        }
        
        if((temp.day > 30) && (temp.month == 2 || temp.month == 4 ||temp.month == 6  ||temp.month == 9 ||temp.month == 11 ) )
        {
            
            
            
        temp.month = month+1;
            
          temp.day = temp.day-30;

            if((temp.day == 29 && temp.month == 2) && (leapYear(temp.year)))
            {
                temp.day = 1;
                temp.month = 3;
            }
            
        }
        
     
        return temp;
    }
    
    
 ostream& operator<<(ostream& out, const Date& obj){
    obj.displayDate();
    return out;
}

 istream& operator>>(istream& in, Date& obj){
    
    int d, m, y;
    cout<<"Enter Day: ";
    in>>d;
    cout<<"Enter Month: ";
    in>>m;
    cout<<"Enter Year: ";
    in>>y;
    obj.setDate(d, m, y);
    return in;
}
