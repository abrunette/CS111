#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/********************************************************************************/
/* PURPOSE: Takes the input values and finds the sum of all the values in an    */
/* array.								        */
/* INPUT PARAMETERS: Array is the data read from the file into an array.        */
/* count is the amount of numbers in the array.                                 */
/* OUTPUT PARAMETERS: sum is the sum of all the values in the array when added  */
/* together in the function.                          			        */
/* IMPLEMENTATION METHOD: Uses a for loop to continually add the previous value */
/* to the sum then outputs sum when curr is equal to count.                     */
/********************************************************************************/

int totalnum (int array[], int count)	//The function totalnum, which finds the sum of all the values in a given array.
{
  int sum = 0;				//Variable sum, uses to collect the sum of all values in an array.
  int curr = 0;				//Variable curr, initialized to count the number of values in an array.
  for(curr; curr < count; curr++)	//For loop, to determine when there are no more values in an array to be read.
	{
  	  sum += array[curr];		//sum adding the most recently read value to sum.
  	}
  return sum;				//Returns sum as an output.
}


/********************************************************************************/
/* PURPOSE: Takes the input values and finds the minimum value in an array.     */
/* INPUT PARAMETERS: Array is the data read from the file into an array.        */
/* count is the amount of numbers in the array.                		        */
/* OUTPUT PARAMETERS: min is the minumum value in the array after the data in   */
/* the array is run though the program.                                         */
/* IMPLEMENTATION METHOD: Function uses an if loop to compare the current value */
/* to the previous value and sets the lowest value to min.                      */
/********************************************************************************/

int lownum (int array[], int count)		//The function lownum, which finds the lowest value in an array.
{						
  int min = array[0];				//Variable min, initially set to the first value in an array, changed when a lower value is found.
  int curr = 0;					//Variable curr, initialized to count the number of values in an array.
  for(curr; curr < count; curr++)		//For loop, to determine when there are no more values in an array to be read.
	{
		if(min > array[curr])	 	//If loop to continually check consecutive values in an array to find the lowest.
		{
			min = array[curr];	//If a lower value is found, it is set to min.
		}
	}
  return min;					//Returns min as an output.
}


/********************************************************************************/
/* PURPOSE: Takes the input values and finds the maximum value in an array.     */
/* INPUT PARAMETERS: Array is the data read from the file into an array.        */
/* count is the amount of numbers in the array.                                 */
/* OUTPUT PARAMETERS: max is the maximum value in the array after the data in   */
/* the array is run though the program.                                         */
/* IMPLEMENTATION METHOD: Function uses an if loop to compare the current value */
/* to the previous value and sets the highest value to max.                     */
/********************************************************************************/

int highnum (int array[], int count)		//The function highnum, which finds the highest value in an array.
{
  int max = array[0];				//Variable max, initially set to the first value in an array, changed when a higher value is found.
  int curr = 0;					//Variable curr, initialized to count the number of values in an array.
  for(curr; curr < count; curr++)		//For loop, to determine whent here are no more values in an array to be read.
	{
	  	if(max < array[curr])		//If loop to continually check consecutive values in an array to find the highest.
		{
			max = array[curr];	//If a higher values is found, it is set to max.
		}
	}
  return max;					//Returns max as an output.
}


/********************************************************************************/
/* PURPOSE: The function takes input values and runs them through progem to get */
/* the average of the data from the inputted array.                             */
/* INPUT PARAMETERS: Array is the data read from the file into an array.        */
/* count is the amount of numbers in the array. Sum is the sum of all read array*/
/* values. Avg is the average of the read array values.                         */
/* OUTPUT PARAMETERS: The only output variable is avg which is the average of   */
/* the input values when run through the function.                              */
/* IMPLEMENTATION METHOD: Function uses a while loop to take the sum of each    */
/* value in the array by adding them all together.                              */
/********************************************************************************/

double avgnum (int array[], int count)		//The fucntion avgnum, which finds the average value of an array.
{
  double sum = 0;				//Variable sum, used to find the sum of the values in an array.
  int curr = 0;					//Variable curr, initialized to count the number of values in an array.
  double avg;					//Variable avg, used to hold the average value of an array.

  while(curr < count)				//While loop to find when there are no more values in an array to be read.
	{
	  sum += array[curr];			//Finds the sum of all values in an array.
	  curr++;				//Moves to the next value in an array.
  	}
  avg = sum / count;				//Finds the average value of an array using the sum and total values in an array.
  return avg;					//Returns avg as an output.
}


/******************************************************************************************************************************/
/* PURPOSE:  Main calculates the sum, highest and lowest value, and average of a given array.                 		      */
/* IMPLEMENTED BY:  Aaron Brunette                                                  					      */
/* DATE:  10/17/2015                                                             					      */
/* USER INFORMATION:  Inputs the name of the file that contains a list of numbers.                    			      */
/* IMPLEMENTATION METHOD:  User inputs the name of the file, the program uses necessary functions to calculate output.        */
/* IMPLEMENTED BY:  Aaron Brunette                                                                			      */
/* OVERVIEW OF SUBPARTS:  Contains four functions to calculate the four requested outputs, sum, min, max, and average.        */
/******************************************************************************************************************************/

int main()
{
  const int SIZE = 100;						//The maximum values the defined array can hold, 100.
  int nums[SIZE];						//Initializing the array, nums.
  int count = 0;						//The counter to determine how many values have been read.
  int maximum, minimum, a, total;				//Variables maximum, minimum, and total used for final output. a used to set values in an array.
  double finavg;  						//Variable finavg, used for the final average output.

  ifstream numFile;						//Opens input of file, numFile.
  cout << "Enter filename: " << endl;				//Outputs text.
  string filename;						//Declares string to be used as file name.
  cin >> filename;						//User inputs filename.

  numFile.open(filename.c_str());				//Opens the file that the user input.

  for(int a = 0; a < 100; a++)					//For loop to set all values in an array to -1.
	{
	  nums[a] = -1;						//Sets a value in an array to -1.
	}
  
  int currentSlot = 0;						//Variable currentSlot, initialized to count the number of values in an array.
  while(numFile >> nums[currentSlot])				//While loop to read out values from a file into an array.
	{
	  currentSlot++;					//Increments currentSlot.
	}

  numFile.close();						//Closes file.

  minimum = lownum(nums, currentSlot);				//Calls function lownum and assigns it to variable minimum.
  maximum = highnum(nums, currentSlot);				//Calls function highnum and assigns it to variable maximum.
  finavg = avgnum(nums, currentSlot);				//Calls function avgnum and assigns it to variable finavg.
  total = totalnum(nums, currentSlot);				//Calls function totalnum and assigns it to variable total.

  cout << "Using provided file: " << filename  << endl;		//Outputs the name of the file that the user input.
  cout << "Total: " << total << endl;				//Outputs the sum of the input array.
  cout << "Highest: " << maximum << endl;			//Outputs the maximum value in an array.
  cout << "Lowest: " << minimum << endl;			//Outputs the minimum value in an array.
  cout << "Average: " << finavg << endl;			//Outputs the average of all values in an array.

  return 0;
}
