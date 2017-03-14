
#include <iostream>
using namespace std;

/********************************************************************************/
/* PURPOSE: Runs a binary search on a given array of lotto numbers to see if any*/
/* are the same as the inputted winning number.                                 */
/* INPUT PARAMETERS: array is the given array of lotto numbers played each week.*/
/* win is the winning lotto number that the user input. LOTTO is the number of  */
/* values in the array.                                                         */
/* OUTPUT PARAMETERS: found is the value true or false depending on whether or  */
/* not the binary search found the same value in the array as the winning number*/
/* IMPLEMENTATION METHOD: Program uses a while loop to compare each value in the*/
/* array to the winning number until there is a match or not.                   */
/********************************************************************************/

int getWinNum(int array[], int win, const int LOTTO)	//Function to compare values in array to winning number.
{
  int first = 0,					//First value in array.
      last = LOTTO - 1,					//Last value in array.
      middle,						//Middle value in array.
      position = -1;					//Not sure if necessary.
  bool found = false;					//Output value to tell whether function found a match.

  while (!found && first <= last)			//While loop to compare each value in array to the winning value.
  {
	middle = (first + last) / 2;			//Finding the middle value.
	if (array[middle] == win)			//If loop to compare middle value to winning number.
	{
		found = true;				//If match is found, output is set to true.
		position = middle;			//Not sure if necessary.
	}
	else if (array[middle] > win)			//Redefining bounds of binary search.
		last = middle - 1;			//Lowers upper bound.
	else if (array[middle] < win)			//Redefining bounds of binary search.
		first = middle + 1;			//Raises lower bound.
  }
  return found;						//Returns value depending on whether a match was found.
}


// Unecessary input validation, commented out.

//int entNum()
//{
//  int win;
//
//  cout << "Please enter this week's winning 5-digit number: " << endl;
//  cin >> win;

//  if (win < 10000 || win > 99999)
//  {
//	cout << "Please enter a 5-digit number: " << endl;
//	cin >> win;
//  }
//  return win;
//}


/********************************************************************************/
/* PURPOSE:  Compares given lotto numbers with winning lotto number to tell user if they are a winner.                  */
/* IMPLEMENTED BY:  Aaron Brunette                                                   */
/* DATE:  10/23/2015                                                              */
/* USER INFORMATION:  Inputs winning lotto number and hits enter.                     */
/* IMPLEMENTATION METHOD:  Program uses a binary search to compare given lotto numbers to winning lotto number.     */
/* OVERVIEW OF SUBPARTS:  getWinNum takes input values and runs them through a binary search to see if any lotto numbers are the same as the winning lotto number.        */
/********************************************************************************/

int main()
{
  const int LOTTO = 10;										//Max number of values in array.
  int nums[LOTTO] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};	//Given numbers put into array.
  int win;											//Variable win for user to input winning number.
  bool result;											//Result to tell whether binary search found a match.

  cout << "Please enter this week's winning number: " << endl;					//Asks user to input win.
  cin >> win;  											//Assigns user input to win.

  result = getWinNum(nums, win, LOTTO);								//Sets result of getWinNum to result.

  if (result == false)										//Tests result to determine if match was found.
	cout << "You are not a winner this week!" << endl;					//Displays false output.
  else
	cout << "You are a winner!" << endl;							//Else displays true output.
  return 0;
}
