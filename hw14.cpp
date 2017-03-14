#include <iostream>
using namespace std;

class NumDays
{
	private:
		double days;
		double hours;
		void hDays();	//hours to days
		void dHours();	//days to hours
	
	public: //constructor, mutators, accessors
		NumDays(double h = 0)
			{
				hours = h;
				hDays();
				//dHours();
			}
		void setDays(double d)
			{ days = d; 
			}	//hDays(); }
		void setHours(double h)
			{ hours = h;
			}	//hDays(); }
		double getDays() //const
			{ return days; }
		double getHours()
			{ return hours; }

	public: //overloaded operators
		NumDays operator+(const NumDays &);
		NumDays operator-(const NumDays &);
		NumDays operator++();
		NumDays operator++(int);
		NumDays operator--();
		NumDays operator--(int);
};

//Start of member definitions*****************************************************

void NumDays::hDays()		//function converts hours to days.
{
	days += (hours / 8);
}

void NumDays::dHours()		//function converts days to hours.
{
	hours += (days * 8);
}

NumDays NumDays::operator + (const NumDays &right)	//definition of overloaded + operator 
{
	NumDays temp;

	temp.days = days + right.days;
	temp.hDays();
	//temp.dHours();
	return temp;
}

NumDays NumDays::operator - (const NumDays &right)	//definition of overloaded - operator
{
	NumDays temp;

	temp.days = days - right.days;
	temp.dHours();
	return temp;
}

NumDays NumDays::operator++()				//definition of overloaded prefix operator
{
	++hours;
	dHours();
	//hDays();
	return *this;
}

NumDays NumDays::operator++(int)			//definition of overloaded postfix operator
{
	NumDays temp(hours);
	hours++;
	hDays();
	//dHours();
	return temp;
}

NumDays NumDays::operator--()				//definition of overloaded prefix operator
{
	--hours;
	dHours();
	return *this;
}

NumDays NumDays::operator--(int)			//definition of overloaded postfix operator
{
	NumDays temp(hours);
	hours--;
	hDays();
	return temp;
}

//Start of Main******************************************************************

/********************************************************************************/
/* PURPOSE:  Test the overloaded operators, +, -, ++, --                        */
/* IMPLEMENTED BY:  Aaron Brunette                                              */
/* DATE:  12/06/2015                                                            */
/* USER INFORMATION:  User only needs to run program.                           */
/* IMPLEMENTATION METHOD:  Uses defined class and overloaded operators.         */
/* OVERVIEW OF SUBPARTS:  No functions used.                                    */
/********************************************************************************/

int main()
{
	double hr1 = 25.0;
	double dy1 = 4.0;
	double hr2 = 10.0;
	double dy2 = 3.0;

	NumDays nOne, nTwo, nTree;

	cout << "Setting values to class objects..." << endl;
	cout << endl;

	//set day members for objects 1 and 2
	nOne.setDays(dy1);
	cout << "Object 1, Days: " << nOne.getDays() << endl;
	nTwo.setDays(dy2);
	cout << "Object 2, Days: " << nTwo.getDays() << endl;

	//set hour members for objects 1 and 2
	cout << endl;
	nOne.setHours(hr1);
	cout << "Object 1, Hours: " << nOne.getHours() << endl;
	nTwo.setHours(hr2);
	cout << "Object 2, Hours: " << nTwo.getHours() << endl;
	cout << endl;

	//test of overloaded +
	cout << "Testing + overload..." << endl;
	nTree = nOne + nTwo;
	cout << "Here is the sum of both day objects added together, in hours: " << nTree.getHours() << endl;

	cout << endl;

	//test of overloaded -
	cout << "Testing - overload..." << endl;
	nTree = nOne - nTwo;
	cout << "Here is the sum of both day objects when subtracted, in hours: " << nTree.getHours() << endl;

	//start of the prefix test
	nTree = ++nOne;
	cout << "Here is the prefix incremented hours: " << nTree.getHours() << endl;
	cout << "Here is the prefix incremented days: " << nTree.getDays() << endl;
	
	cout << endl;

	nTree = --nTwo;
	cout << "Here is the prefix decremented hours: " << nTree.getHours() << endl;
	cout << "Here is the prefix decremented days: " << nTree.getDays() << endl;

	//start of the postfix test
	nTree = nOne++;
	cout << "Here is the postfix incremented hours: " <<  nTree.getHours() << endl;
	cout << "Here is the postfix incremented days: " << nTree.getDays() << endl;
	
	cout << endl;

	nTree = nTwo--;
	cout << "Here is the postfix decremented hours: " << nTree.getHours() << endl;
	cout << "Here is the postfix decremented days: " << nTree.getDays() << endl;

	cout << endl;

	cout << "I could not get my hours to increment right, but the days increment by one like they should.\n";

	return 0;
}
