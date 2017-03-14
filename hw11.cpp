#include <iostream>
using namespace std;

struct wData			//given structure used in rest of program
{
	double tRain;
	double hTemp;
	double lTemp;
	double aTemp;
};

enum month { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };	//enumerated data type to cycle through array

/********************************************************************************/
/* PURPOSE:  Calculate required information from inputted weather data.         */
/* IMPLEMENTED BY:  Aaron Brunette                                              */
/* DATE:  11/15/2015                                                            */
/* USER INFORMATION:  User inputs requested data.                               */
/* IMPLEMENTATION METHOD:  Uses an array of structures to store multiples of same information to be used to output calcuated averages, totals, etc.         */
/* OVERVIEW OF SUBPARTS:  No fucntions used.                                    */
/********************************************************************************/

int main()
{
	const int numMonth = 12;
	wData wInfo[numMonth];
	month wMonth;
	
	double avgRain, totRain = 0, Atemp = 0, tempH, tempL;
	int tempRand2, tempRand1;						//variable for finding average rainfall and total rainfall

	for(wMonth = JANUARY; wMonth <= DECEMBER; wMonth = static_cast<month>(wMonth + 1))			//Makes sure user enters a value for each data point.
	{
		wInfo[wMonth].tRain;
		wInfo[wMonth].hTemp;
		wInfo[wMonth].lTemp;
		wInfo[wMonth].aTemp;
	}

	cout << "Please enter weather data for each month. For the love of god do not enter any characters, creates infinite loop, ctrl+c." << endl;

	for(wMonth = JANUARY; wMonth <= DECEMBER; wMonth = static_cast<month>(wMonth + 1))			//Has user enter info for every data point in struct using enum to cycle through array.
	//for(int wMonth = 0; wMonth < 12; wMonth++)
	{
		cout << endl;
		cout << "Please enter the following data for month " << wMonth << "." << endl;
		cout << endl;		

		cout << "Please enter the total rainfall for month " << wMonth << ": ";
		cin >> wInfo[wMonth].tRain;
		while(wInfo[wMonth].tRain < 0)									//Input validation, check user enters a value of at least 0, found this is not necessary, 
		{
			cout << "Please enter a number of 0 or greater: ";
			cin >> wInfo[wMonth].tRain;
		}
		
		cout << "Please enter the highest temperature in Fahrenheit for month " << wMonth << ": ";
		cin >> wInfo[wMonth].hTemp;
		while(wInfo[wMonth].hTemp > 140 || wInfo[wMonth].hTemp < (-100))				//Input validation, checks that user enters a value between stated bounds
		{
			cout << "Please enter a temperature between -100 and +140 degrees Fahrenheit: ";
			cin >> wInfo[wMonth].hTemp;
		}
	
		cout << "Please enter the lowest temperature in Fahrenheit for month " << wMonth << ": ";
		cin >> wInfo[wMonth].lTemp;
		while(wInfo[wMonth].lTemp > 140 || wInfo[wMonth].lTemp < (-100))				//Input validation, ^same as one above
		{
			cout << "Please enter a temperature between -100 and +140 degrees Fahrenheit: ";
			cin >> wInfo[wMonth].lTemp;
		}

		cout << "Please enter the average temperature in Fahrenheit for month " << wMonth << ": ";
		cin >> wInfo[wMonth].aTemp;
		//cout << wInfo[wMonth].aTemp;		//debugging
		while(wInfo[wMonth].aTemp > 140 || wInfo[wMonth].aTemp < (-100))				//Input validation, ^^same as two above
		{
			cout << "Please enter a temperature between -100 and +140 degrees Fahrenheit: ";
			cin >> wInfo[wMonth].aTemp;
		}
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	//find highest temperature
	tempH = wInfo[0].lTemp;
	for(int b = 0; b < numMonth; b++)
	{
		if(wInfo[b].hTemp > wInfo[b + 1].hTemp)
		{
			tempH = wInfo[b + 1].hTemp;			//ERROR HERE
			tempRand2 = b + 1;				//ERROR HERE
			//cout << (hp + 1);
		}
	}
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	//find lowest temperature
	tempL = wInfo[0].lTemp;
	for(int a = 0; a < numMonth; a++)
	{
		if(wInfo[a].lTemp < wInfo[a + 1].lTemp)
		{
			tempL = wInfo[a + 1].lTemp;			//ERROR HERE
			tempRand1 = a + 1;				//ERROR HERE
			//cout << tempRand1;
		}
		//cout << tempRand1 << " " << a;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	//find average temperature
	for(wMonth = JANUARY; wMonth <= DECEMBER; wMonth = static_cast<month>(wMonth + 1))
	{
		Atemp += wInfo[wMonth].aTemp;
	}
	Atemp /= 12;
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	//find total rainfall
	for(wMonth = JANUARY; wMonth <= DECEMBER; wMonth = static_cast<month>(wMonth + 1))			
	{
		totRain += wInfo[wMonth].tRain;
	}
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	avgRain = totRain / 12;				

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	//cout all information
	cout << endl;
	cout << "Here is the relevent data:" << endl;
	cout << endl;
	cout << "Average Monthly Rainfall: " << avgRain << endl;
	cout << "Total Rainfall for the year: " << totRain << endl;
	cout << "Highest Temperature: " << tempH << " in month " << tempRand2 << "." << endl;
	cout << "Lowest Temperature: " << tempL << " in month " << tempRand1 << "." << endl;
	cout << "Average Monthly Temperature: " << Atemp << endl;
	cout << "For some reason the logic in my code to find the highest and lowest temperatures does not want to work properly. It looks ok to me but I could not figure it out after 2 hours of debugging." << endl;
	
	//cout << "test";

	return 0;
}
