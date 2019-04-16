
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
		PhysicalNumber::PhysicalNumber(const PhysicalNumber &a)
		{
          this->num=a.num;
		  this->unit=a.unit;
		}
        PhysicalNumber PhysicalNumber:: operator+(const PhysicalNumber& a) const 
		{
			double res=trans(*this,a)+num;
          
			return  PhysicalNumber(res,unit);
		}
	    PhysicalNumber PhysicalNumber:: operator+() const
		{
			return *this;
		}
        PhysicalNumber PhysicalNumber:: operator-(const PhysicalNumber& a) const 
		{
			double res =num- trans(*this,a);
			return PhysicalNumber(res,unit);
		}
        PhysicalNumber PhysicalNumber::operator-()  
		{
			return *this;
		}
        PhysicalNumber PhysicalNumber:: operator--(int)
		{
			PhysicalNumber temp(this->num,this->unit);
			num--;
			return temp;
		}
	    PhysicalNumber PhysicalNumber:: operator--()  
		{
			num--;
			return *this;
		}
        PhysicalNumber PhysicalNumber:: operator++(int) //PhysicalNumber result(*this);   // make a copy for resul
		{
			PhysicalNumber res(*this);
			++(*this);
			return res;
		}
        PhysicalNumber& PhysicalNumber:: operator++()  
		{
			return *this;
		}
		PhysicalNumber PhysicalNumber:: operator+=(const PhysicalNumber& a)  
		{
			this->num=trans(*this,a)+num;
			return *this;
		}
        PhysicalNumber PhysicalNumber:: operator-=(const PhysicalNumber& a)  
		{
			this->num=num-trans(*this,a);
			return *this;
		}

		bool PhysicalNumber::operator<(const PhysicalNumber& a)
		{
			double res = trans(*this, a);
            if (num < res) 
			  return true;
            return false; 
		}
		bool PhysicalNumber::operator>(const PhysicalNumber& a)
		{
			double res = trans(*this, a);
            if (num > res) return true;
			return true;
		}
		bool PhysicalNumber::operator<=(const PhysicalNumber& a)
		{
			double res = trans(*this, a);
            if (num <= res) return true;
			return false;
		}
		bool PhysicalNumber::operator>=(const PhysicalNumber& a)
		{
            double res = trans(*this, a);
            if (num >= res) return true;
			return false;		
		}
		bool PhysicalNumber::operator==(const PhysicalNumber& a)
		{
			double res = trans(*this, a);
            if (num == res) return true;
			return false;
		}
		bool PhysicalNumber::operator!=(const PhysicalNumber& a)
		{
            double res = trans(*this, a);
            if (num == res) return false;
			return true;		
		}
		ostream& operator<<(ostream& o, const PhysicalNumber &a)
		{
			if(a.unit==Unit::TON)o<<a.num<<"[ton]";
			else if (a.unit==Unit::KG)o<<a.num<<"[kg]";
			else if (a.unit==Unit::G)o<<a.num<<"[g]";
			else if (a.unit==Unit::KM)o<<a.num<<"[km]";
			else if (a.unit==Unit::M)o<<a.num<<"[m]";
			else if (a.unit==Unit::CM)o<<a.num<<"[cm]";
			else if (a.unit==Unit::HOUR)o<<a.num<<"[hour]";
			else if (a.unit==Unit::MIN)o<<a.num<<"[min]";
			else if (a.unit==Unit::SEC)o<<a.num<<"[sec]";
			return o;
		}
		 istream& operator>>(istream& is, PhysicalNumber& p){
    string s;
    is>>s;
    bool error = false;
    int unitStart = s.find("[");
    int unitEnd= s.find("]");
    if(unitStart<0||unitEnd<0||unitEnd!=s.length()-1) error = true;
    if(!error) {
      string newUnit=s.substr(unitStart+1,unitEnd-unitStart-1);	
      if(newUnit.compare("cm")== 0 || newUnit.compare("CM")== 0) p.unit = Unit::CM;
      else if (newUnit.compare("m")== 0 || newUnit.compare("M")== 0) p.unit = Unit::M;
      else if (newUnit.compare("km")== 0 || newUnit.compare("KM")== 0) p.unit = Unit::KM;
      else if (newUnit.compare("sec")== 0 || newUnit.compare("SEC")== 0) p.unit = Unit::SEC;
      else if (newUnit.compare("min")== 0 || newUnit.compare("MIN")== 0) p.unit = Unit::MIN;
      else if (newUnit.compare("hour")== 0 || newUnit.compare("HOUR")== 0) p.unit = Unit::HOUR;
      else if (newUnit.compare("g")== 0 || newUnit.compare("G")== 0) p.unit = Unit::G;
      else if (newUnit.compare("kg")== 0 || newUnit.compare("KG")== 0) p.unit = Unit::KG;
      else if (newUnit.compare("ton")== 0 || newUnit.compare("TON")== 0) p.unit = Unit::TON;
      else  error=true;
    }
    double newNum;
    if (error) auto errorState = is.rdstate();
    else {
          try {
             newNum = stod(s.substr(0,unitStart));
	  }
	  catch (exception &e) { 
		  auto errorState = is.rdstate();
		  return is;
	  }
            p.num=newNum;
    }  
    return is;
  }

		double PhysicalNumber::trans(const PhysicalNumber &a, const PhysicalNumber &b)const
		{
			bool check=false; double res=0;
			switch (a.unit)
			{
				case Unit::TON:
				{
				 switch (b.unit)
				 {
				  case Unit::TON:
				   res=b.num;
					return res;

				  case Unit::KG:
				   res=(b.num/1000);
					return res;
                  
				  case Unit::G:
				   res=b.num/(1000*1000);
					return res;
				
				  default:
					 throw std::invalid_argument( "Incompatible Dimensions!" );;
				 }
				}
				

                case Unit::KG:
				{
				 switch (b.unit)
				 {
				  case Unit::TON:
				   res=b.num*1000;
					return res;

				  case Unit::KG:
				   res=b.num;
					return res;
                  
				  case Unit::G:
				   res=b.num*(1000);
					return res;
				
				  default:
					 throw std::invalid_argument( "Incompatible Dimensions!" );;
				 }
				}
				
				case Unit::G:
				{
				 switch (b.unit)
				 {
				  case Unit::TON:
				   res=b.num/1000000;
					return res;

				  case Unit::KG:
				   res=b.num/1000;
					return res;
                  
				  case Unit::G:
				   res=b.num;
					return res;
				
				  default:
					 throw std::invalid_argument( "Incompatible Dimensions!" );;
				 }
				}

               case Unit::KM:
			   {
				 switch (b.unit)
				 {
				  case Unit::KM:
				   res=b.num;
					return res;

				  case Unit::M:
				   res=(b.num/1000);
					return res;
                  
				  case Unit::CM:
				   res=b.num/(100*100);
					return res;
				
				  default:
					 throw std::invalid_argument( "Incompatible Dimensions!" );;
				 }
				}

                case Unit::M:
			    {
				 switch (b.unit)
				 {
				  case Unit::KM:
				   res=b.num*1000;
					return res;

				  case Unit::M:
				   res=b.num;
					return res;
                  
				  case Unit::CM:
				   res=b.num/(100);
					return res;
				
				  default:
					 throw std::invalid_argument( "Incompatible Dimensions!" );;
				 }
				}

				 case Unit::CM:
			   {
				 switch (b.unit)
				 {
				  case Unit::KM:
				   res=b.num*100000;
					return res;

				  case Unit::M:
				   res=(b.num*100);
					return res;
                  
				  case Unit::CM:
				   res=b.num;
					return res;
				
				  default:
					 throw std::invalid_argument( "Incompatible Dimensions!" );;
				 }
				}


				case Unit::HOUR:
				{
				 switch (b.unit)
				 {
				  case Unit::HOUR:
				   res=b.num;
				  return res;

				  case Unit::MIN:
				   res=(b.num/60);
				  return res;
                  
				  case Unit::SEC:
				   res=b.num/(60*60);
				   return res;
				
				  default:
					 throw std::invalid_argument( "Incompatible Dimensions!" );;
				 }

				 case Unit::MIN:
				{
				 switch (b.unit)
				 {
				  case Unit::HOUR:
				   res=b.num*60;
				  return res;

				  case Unit::MIN:
				   res=b.num;
				  return res;
                  
				  case Unit::SEC:
				   res=b.num/(60);
				   return res;
				
				  default:
					 throw std::invalid_argument( "Incompatible Dimensions!" );;
				 }
				}
				 case Unit::SEC:
				{
				 switch (b.unit)
				 {
				  case Unit::HOUR:
				   res=b.num*3600;
				  return res;

				  case Unit::MIN:
				   res=(b.num*60);
				  return res;
                  
				  case Unit::SEC:
				   res=b.num;
				   return res;
				
				  default:
					 throw std::invalid_argument( "Incompatible Dimensions!" );;
				 }
				}
			}
		}
		        return res;
		}

};
