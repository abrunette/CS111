/********************************************************************************/
/* PURPOSE:  Caculates the sales from the total sales after tax, then displays all information.                */
/* IMPLEMENTED BY:  Aaron Brunette                                              */
/* DATE:  09/18/2015                                                            */
/* USER INFORMATION:  Input Month, Year, and total collected then hit enter.    */
/* IMPLEMENTATION METHOD: Creates variables to be filled by user, then uses input data to calculate required data and output with cout.  */
/* OVERVIEW OF SUBPARTS: Program only uses main parts.                          */
/********************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
  string month, year;
  double totalcoll, countytax, statetax, sales, totaltax;
  
	// Get the month, year, and sales.
	cout << setprecision(2) << fixed << endl;
	cout << "Enter the month: ";
	cin >> month;
	cout << "Enter the year: ";
	cin >> year;
	cout << "Enter the total sales collected: ";
	cin >> totalcoll;	

	// Calculate the individual taxes and the total collected.
	sales = totalcoll / 1.06;
	countytax = sales * 0.02;
	statetax = sales * 0.04;
	totaltax = countytax + statetax;

	// Display Month, Year, Total Collected, Sales, County Sales tax, State Sales Tax, and Total Sales Tax.
	cout << endl;
	cout << "Month: " << month << endl;
	cout << endl;
	cout << "Year: " << year << endl;
	cout << endl;
	cout << "------------------------" << endl;
	cout << endl;
	cout << "Total Collected:" << setw(11) << "$ "  << totalcoll << endl;
	cout << endl;
	cout << "Sales:" << setw(21) << "$ " << sales << endl;
	cout << endl;
	cout << "County Sales Tax:" << setw(10) << "$ " << countytax << endl;
	cout << endl;
	cout << "State Sales Tax:" << setw(11) << "$ " << statetax << endl;
	cout << endl;
	cout << "Total Sales Tax:" << setw(11) << "$ " << totaltax << endl;

  return 0;
}
