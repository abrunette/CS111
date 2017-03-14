/********************************************************************************/
/* PURPOSE:  Compute and display the tax and tip on a restaurant bill.          */
/* IMPLEMENTED BY:  Aaron Brunette                                              */
/* DATE:  09/11/2015                                                            */
/* USER INFORMATION:  Run the program                                           */
/* IMPLEMENTATION METHOD:  Created double variables to be combined into appropriate data and output using cout.        */
/* OVERVIEW OF SUBPARTS:  Program only uses main function.                      */
/********************************************************************************/
#include <iostream>
using namespace std;
int main()
{
	// Declares given variables as double and performs math necessary for the total bill.
	double bill = 88.67;
 	double taxrate = 0.0875;
	double tipamt = 0.2;
	double tax = bill * taxrate;
 	double billwithtax = bill + tax;
	double tip = billwithtax * tipamt;
	double totalbill = billwithtax + tip;

	// Displays relevant bill information.
	cout << "Menu Cost: $" << bill << endl;
	cout << "Tax: $" << tax << endl;
	cout << "Tip: $" << tip << endl;
	cout << "Total Bill: $" << totalbill << endl;
 return 0;
}
