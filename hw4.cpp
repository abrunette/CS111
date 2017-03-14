/********************************************************************************/
/* PURPOSE:  Calculates phone bill depending on package chosen and minutes used.*/
/* IMPLEMENTED BY:  Aaron Brunette                                              */
/* DATE:  09/29/2015                                                            */
/* USER INFORMATION:  Input the package type and minutes to get the total amount due               */
/* IMPLEMENTATION METHOD: Uses if/else to determine the total amount due, depending on package type and minutes used set to given values.          */
/* OVERVIEW OF SUBPARTS:  The function consists of only the main fucntion       */
/********************************************************************************/
#include <iostream>
using namespace std;
int main()
{
  double pckgA, pckgB, pckgC, Amin, Bmin, min, bill; 
  char pckg;

	//Given package costs and minute rates.
	pckgA = 39.99; 
	pckgB = 59.99;
	pckgC = 69.99;
	Amin = 0.45;
	Bmin = 0.40;	

	//User inputs their package type and the number of minutes they used.
	cout << "Please input the package A, B, or C." << endl;
	cin >> pckg;
	cout << endl << "Please input the number of minutes you used." << endl;
	cin >> min;
	cout << endl;

	//Depending on the package type and minutes used the program outputs the total ammount due.
	if (pckg == 'A')
	{
	  bill = (min * Amin) + pckgA;
	  cout << "Your total amount due is $ " << bill << endl;
	}
	else if (pckg == 'B')
	{
	  bill = (min * Bmin) + pckgB;
	  cout << "Your total amount due is $ " << bill << endl;
	}
	else if (pckg == 'C')
	  cout << "Your total amount due is $ " << pckgC  << endl;
	//If the user entered a value other than A, B, or C the program outputs the following error message.
	else
  	  cout << "You have entered an incorrect package value." << endl;
  return 0;
}
