#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/********************************************************************************/
/* PURPOSE: Function writes hardcoded array into a file of the users choosing.  */
/* Created because the instructions dictated so.                                */
/* INPUT PARAMETERS: Name is the name of the file that the user inputs.         */
/* fArray is the empty array of zeros that will be written too from the file.   */
/* size is the size of the array.                                               */
/* OUTPUT PARAMETERS: function is a void function, just changes variables.      */
/* IMPLEMENTATION METHOD: Uses reinterpret to change the values of the array to */
/* binary from char.                                                            */
/********************************************************************************/

void arrayToFile(string Name, int fArray[], int size)			// (name, *arr, arrsize) in binary, read into array, close
{
	fstream fFile;
	cout << "Opening File...\n";					
	fFile.open(Name.c_str(), ios::out | ios::binary);		//opens file to be written too in binary.
	if(fFile)
	{
		cout << "Writing first array to file...\n";
		fFile.write(reinterpret_cast<char *>(fArray), sizeof(fArray) * size);	//changes values of array from int to char.
		//for(int i = 0; i < size; i++)
		//{
		//	fFile << *(fArray + i);
		//}
		cout << "Closing File...\n";	
	}
	else
	{
		cout << "Error opening file!\n";			//check that file could be opened.
	}
	fFile.close();
}

/********************************************************************************/
/* PURPOSE: Function writes file into a second empty array.                     */
/* Created because instructions dictated so.                                    */
/* INPUT PARAMETERS: Name is the name of the file that the user inputs.         */
/* fArray is the empty array of zeros that will be written too from the file.   */
/* size is the size of the array.                                               */
/* OUTPUT PARAMETERS: function is a void function, just changes variables.      */
/* IMPLEMENTATION METHOD: Uses reinterpret to change the values of the array to */
/* character from binary.                                                       */
/********************************************************************************/

void fileToArray(string Name, int fArray[], int size)						//(name, *arr, arrsize) in binary, read into array, close
{
	fstream fFile;
	cout << "Opening File...\n";
	fFile.open(Name.c_str(), ios::in | ios::binary);					//opens file to be read as binary into char.
	if(fFile)
	{
		cout << "Writing file into second array...\n";
		fFile.read(reinterpret_cast<char *>(fArray), sizeof(fArray) * size);		//reads binary into char.
		//for(int b = 0; b < size; b++)
		//{
		//	fFile >> *(fArray + b);
		//}
		cout << "Closing File...\n";
	}
	else
	{
		cout << "Error opening file!\n";						//check that file could be opened.
	}
	fFile.close();
}

/********************************************************************************/
/* PURPOSE:  Writes and array into a file, then writes the file to another array*/
/* IMPLEMENTED BY:  Aaron Brunette                                              */
/* DATE:  11/20/2015                                                            */
/* USER INFORMATION:  User inputs the name of the file.                         */
/* IMPLEMENTATION METHOD:  Program uses read to read array to char into file and array */
/* OVERVIEW OF SUBPARTS:  1 function to copy array to file and file to array.   */
/********************************************************************************/

int main()
{	
	fstream fFile;	
	string fileName;					//name of file to be written too
	const int SIZE = 10;					//size of fArray
	int fArray1[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};	//array to be written to file
	int fArray2[SIZE];					//array to be written into from file

	for(int c = 0; c < SIZE; c++)
	{
		fArray2[c] = 0;
	}

	cout << "Please enter a file name: ";			//check to see if this is input by user
	cin >> fileName;

	//cout << "Opening file...\n";
	//fFile.open(fileName.c_str(), ios::out);			//not important*********************open file to be written too, check if specific file is to be used instead of "randomfile.cpp"
	
	//if(fFile.open(fileName.c_str()))				//not important*********************
	//{
	arrayToFile(fileName, fArray1, SIZE);					//function 1

	fileToArray(fileName, fArray2, SIZE);					//function 2
		
		//cout << fFile << endl;
		//cout << endl;				//debugging^

	cout << "Here is array 1: \n";
	for(int g = 0; g < SIZE; g++)
	{
		cout << fArray1[g] << " ";		//reads out first array.
	}
	cout << endl;
	cout << "Here is array 2: \n";	
	for(int q = 0; q < SIZE; q++)
	{
		cout << fArray2[q] << " ";		//reads out second array.
	}
	cout << endl;
	//}
	//else
	//{
	//	cout << "Error reading file! Program will close.\n";		//not important***************
	//}

	//fileName.close();					//opened in fuction instead, not needed

  return 0;
}
