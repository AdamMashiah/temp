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
		
		
        PhysicalNumber operator+(const PhysicalNumber &a) const;
	    PhysicalNumber operator+() const;
        PhysicalNumber operator-(const PhysicalNumber &a) const;
        PhysicalNumber operator-() const;
        PhysicalNumber operator--(int a) const;
	    PhysicalNumber operator--() const;
        PhysicalNumber operator++(int a) const;
        PhysicalNumber operator++() const;
		PhysicalNumber operator+=(const PhysicalNumber &a) const;
        PhysicalNumber operator-=(const PhysicalNumber &a) const;

		bool operator<(const PhysicalNumber &a);
		bool operator>(const PhysicalNumber &a);
		bool operator<=(const PhysicalNumber &a);
		bool operator>=(const PhysicalNumber &a);
		bool operator==(const PhysicalNumber &a);
		bool operator!=(const PhysicalNumber &a);

		friend ostream& operator<<(ostream& o, const PhysicalNumber& a);
		friend istream& operator>>(istream& i, PhysicalNumber& a);
	};
	


}