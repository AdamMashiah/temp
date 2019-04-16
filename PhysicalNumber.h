#include <iostream>
#include "Unit.h"
#pragma once
using namespace std;
namespace ariel
 {
	class PhysicalNumber
	{
       
       

	    public:
		double num;
		ariel::Unit unit;
		PhysicalNumber(double number, Unit u);
		PhysicalNumber(const PhysicalNumber &a);
        PhysicalNumber operator+(const PhysicalNumber &a) const;
	    PhysicalNumber operator+() const;
        PhysicalNumber operator-(const PhysicalNumber &a) const;
        PhysicalNumber operator-();
        PhysicalNumber operator--(int a);
	    PhysicalNumber operator--() ;
        PhysicalNumber operator++(int a) ;
        PhysicalNumber& operator++() ;
		PhysicalNumber operator+=(const PhysicalNumber &a) ;
        PhysicalNumber operator-=(const PhysicalNumber &a) ;

		bool operator<(const PhysicalNumber &a);
		bool operator>(const PhysicalNumber &a);
		bool operator<=(const PhysicalNumber &a);
		bool operator>=(const PhysicalNumber &a);
		bool operator==(const PhysicalNumber &a);
		bool operator!=(const PhysicalNumber &a);

		friend ostream& operator<<(ostream& o, const PhysicalNumber& a);
		friend istream& operator>>(istream& i, PhysicalNumber& a);

		double trans(const PhysicalNumber &a,const PhysicalNumber &b)const;
	};
	


}
