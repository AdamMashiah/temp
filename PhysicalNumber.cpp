
#include<iostream>
#include "PhysicalNumber.h"
#include "Unit.h"
#include <sstream>
#include <stdexcept>

namespace ariel
{
        
		 double num;
		ariel::Unit unit;

		PhysicalNumber::PhysicalNumber(double number, Unit u)
		{
          this->unit=u;
		  this->num=number;
		}
		
        PhysicalNumber PhysicalNumber:: operator+(const PhysicalNumber& a) const {return *this;}
	    PhysicalNumber PhysicalNumber:: operator+() const {return *this;}
        PhysicalNumber PhysicalNumber:: operator-(const PhysicalNumber& a) const {return *this;}
        PhysicalNumber PhysicalNumber:: operator-() const {return *this;}
        PhysicalNumber PhysicalNumber:: operator--(int a) const {return *this;}
	    PhysicalNumber PhysicalNumber:: operator--() const {return *this;}
        PhysicalNumber PhysicalNumber:: operator++(int a) const{return *this;}
        PhysicalNumber PhysicalNumber:: operator++() const {return *this;}
		PhysicalNumber PhysicalNumber:: operator+=(const PhysicalNumber& a) const {return *this;}
        PhysicalNumber PhysicalNumber:: operator-=(const PhysicalNumber& a) const {return *this;}

		bool PhysicalNumber::operator<(const PhysicalNumber& a){return true;}
		bool PhysicalNumber::operator>(const PhysicalNumber& a){return true;}
		bool PhysicalNumber::operator<=(const PhysicalNumber& a){return true;}
		bool PhysicalNumber::operator>=(const PhysicalNumber& a){return true;}
		bool PhysicalNumber::operator==(const PhysicalNumber& a){return true;}
		bool PhysicalNumber::operator!=(const PhysicalNumber& a){return true;}

		ostream& operator<<(ostream& o, const PhysicalNumber &a)
		{
			o<<a.num;
			return o;
		}
		 istream & operator>>(istream& i, PhysicalNumber &a)
		 {	
			 i>>a.num;
			 return i;
		 }

;}