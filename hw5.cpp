/********************************************************************************/
/* PURPOSE:  Read and display the total, sum, and average of numbers read from a file.                */
/* IMPLEMENTED BY:  Aaron Brunette                                              */
/* DATE:  10/02/2015                                                            */
/* USER INFORMATION:  Run the program                                           */
/* IMPLEMENTATION METHOD:  Reads the file and         */
/* OVERVIEW OF SUBPARTS:  Functions and classes used and their purposes.        */
/********************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
  ifstream myFile;	//Setting input file to "myFile"

  double avg;		//The average of all the numbers in the file.
  int number;		//The numbers in the file and the average of all the numbers in the file.
  double sum = 0;	//The sum of all the numbers in the file.
  int total = 0;	//The total number of numbers in the file.

  myFile.open("Random.txt");		//Opens the file "Random.txt
  
  if (myFile)	//If the input file can be read, continues with next function.
  {
 	 while (myFile >> number)		//Detects if the file still has numbers to be read.
  	 {
		++total;			//Adds 1 to the total.
		sum += number;			//Adds the most recently read number to the previous sum.
	 }
	 
	 avg = sum / total;  			//Divides the sum by the total to get the average of all the numbers in the file.
	 
 	 cout << "The number of numbers in the file is " << total << endl;		//Displays the total number of numbers in the file.
         cout << "The sum of all the numbers is " << sum << endl;			//Displays the sum of all the numbers in the file.
  	 cout << "The average of all the numbers in the file is " << avg << endl;	//Displays the average of all the numbers in the file.
	 

         myFile.close( );	//Closes the file when there are no more numbers to read.
  }
  else		//If the file cannot be read displays the following message.
	cout << "Error opening the file.\n";

  return 0;
}
