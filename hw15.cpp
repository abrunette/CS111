#include <iostream>
#include <string>
using namespace std;

/********************************************************************************/
/* PURPOSE: Function takes a string and tells user whether it is a palindrome.  */
/* INPUT PARAMETERS: Function accepts a string that the user inputs. It also    */
/* initializes the length of the string in the function.                        */
/* OUTPUT PARAMETERS: Function eventually returns true or false depending on the*/
/* results of the recursive function.                                           */
/* IMPLEMENTATION METHOD: Function uses recursion to continually call a shorter */
/* string which it then compares each string to an if statement.                */
/********************************************************************************/

bool findpalindrome(string find)		//function findpalindrome
{
	int sentlen = find.length();		//length in characters of the string the user input

	if(sentlen <= 1)			//test if string is 1 or less characters
	{
		return true;
	}
	else if(sentlen > 1 && find.at(0) != find.at(sentlen-1))	//test if first and last character are different
	{
		return false;
	}
	else								//recursion calls function to test smaller string
	{
		return (findpalindrome(find.substr(1, sentlen - 2)));	
	}

}

/********************************************************************************/
/* PURPOSE:  Tells user whether their input is a palindrome.                    */
/* IMPLEMENTED BY:  Aaron Brunette                                              */
/* DATE:  12/11/2015                                                            */
/* USER INFORMATION:  User inputs a word.                                       */
/* IMPLEMENTATION METHOD:  Uses a function to comapre strings.                  */
/* OVERVIEW OF SUBPARTS:  findpalindrome compares strings with recursion to find a palindrome.*/
/********************************************************************************/

int main()
{
	string sent;											//initialize string for user input
	bool ispal = false;										//holding variable for findpalindrome result, default false

	cout << "Please enter one word and I will tell you whether it is a palindrome: " << endl;	//User input palindrome
	getline(cin, sent);
	
	ispal = findpalindrome(sent);									//call function, sets result to ispal

	if(ispal == true)										//test for string is palindrome
	{
		cout << "You have entered a palindrome." << endl;
	}
	else												//else test for is not palindrome
	{
		cout << "You did not enter a palindrome." << endl;
	}	

	return 0;
}

