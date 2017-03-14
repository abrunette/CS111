#include <iostream>
#include <string>
using namespace std;

class information				//declaring class information
{
	private:
		string name;
		string address;
		int age;
		string pNum;
	public:
		void setName(string);
		void setAddress(string);
		void setAge(int);
		void setpNum(string);
		string getName() const;
		string getAddress() const;
		int getAge() const;
		string getpNum() const;
};

//Defining member functions********************************************************

//sets name to given value
void information::setName(string pname)
{
	name = pname;
}

//sets address to given value
void information::setAddress(string pAdd)
{
	address = pAdd;
}

//sets age to given value
void information::setAge(int pAge)
{
	age = pAge;
}

//sets pNum to given value
void information::setpNum(string ppNum)
{
	pNum = ppNum;
}

//returns value in name
string information::getName() const
{
	return name;
}

//returns value in address
string information::getAddress() const
{
	return address;
}

//returns value in age
int information::getAge() const
{
	return age;
}

//returns value in pNum
string information::getpNum() const
{
	return pNum;
}


//Begin main**********************************************************************


/********************************************************************************/
/* PURPOSE:  Declares a class, then creates 3 objects of the class and displays them.  */
/* IMPLEMENTED BY:  Aaron Brunette                                              */
/* DATE:  11/29/2015                                                            */
/* USER INFORMATION:  User runs the program.                                    */
/* IMPLEMENTATION METHOD:  Assigns values to class objects then displays them.  */
/* OVERVIEW OF SUBPARTS:  information holds given information.                  */
/********************************************************************************/

int main()
{
	//Define 3 objects, 1 per person
	information per1;
	information per2;
	information per3;

	//Person 1 information							//sets class members for per1
	per1.setName("Aaron");
	per1.setAddress("1234 Random Street");
	per1.setAge(19);
	per1.setpNum("1234567890");

	//Person 2 information							//sets class members for per2
	per2.setName("Dana");
	per2.setAddress("2579 Other Street");
	per2.setAge(50);
	per2.setpNum("1234567890");

	//Person 3 information							//sets class members for per3
	per3.setName("Kennedy");
	per3.setAddress("2468 This Street");
	per3.setAge(19);
	per3.setpNum("1234567890");

	cout << endl;

	cout << "Start of information." << endl;

	cout << endl;

	//Display information for person 1
	cout << "Here is the information for " << per1.getName() <<  ": \n";
	cout << "Address: " << per1.getAddress() << endl;
	cout << "Age: " << per1.getAge() << endl;
	cout << "Phone Number: " << per1.getpNum() << endl;
	cout << endl;

	//Display information for person 2
	cout << "Here is the information for " << per2.getName() << ": \n";
	cout << "Address: " << per2.getAddress() << endl;
	cout << "Age: " << per2.getAge() << endl;
	cout << "Phone Number: " << per2.getpNum() << endl;
	cout << endl;

	//Display information for person 3
	cout << "Here is the information for " << per3.getName() << ": \n";
	cout << "Address: " << per3.getAddress() << endl;
	cout << "Age: " << per3.getAge() << endl;
	cout << "Phone Number: " << per3.getpNum() << endl;

	cout << endl;
	cout << "End of information.\n";					//end of program
  return 0;
}
