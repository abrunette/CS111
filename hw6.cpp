
#include <iostream>
using namespace std;

/********************************************************************************/
/* PURPOSE: Function takes the input values and runs them through a given       */
/* formula.                                                                     */
/* INPUT PARAMETERS: NS, numbers of shares. SP, sales price. SC, sales          */
/* commission. PP, purchace price. PC, purchase commission.                     */
/* OUTPUT PARAMETERS: The only output is resultantIncome, which is the value of */
/* the input values after being put through the given formula                   */
/* IMPLEMENTATION METHOD: Uses the input values and runs them through the given */
/* formula.                                                                     */
/********************************************************************************/

double profit(int NS, double SP, double SC, double PP, double PC)
{
  double resultantIncome = (((NS * SP) - SC) - ((NS * PP) + PC));
  return resultantIncome;
}

/********************************************************************************/
/* PURPOSE:  Calculates the profit/loss after selling shares at given values.   */
/* IMPLEMENTED BY:  Aaron Brunette                                              */
/* DATE: 10/09/2015                                                             */
/* USER INFORMATION:  Inputs relevent data when prompted.                       */
/* IMPLEMENTATION METHOD:  Runs function profit to calculate output data.       */
/* OVERVIEW OF SUBPARTS:  Profit takes input data and runs through a given function.       */
/********************************************************************************/

int main()
{
  int NS;				//Number of shares bought.
  double PP, PC, SP, SC, Profit;	//Purchase Price, Purchase Commission, Selling Price, Selling Commission, and Profit. 
 
  cout << "Please enter the number of shares purchased: " << endl;	//User inputs number of shares.
  cin >> NS;
  
  while (NS < 0)	//Input validation that NS is not a negative number.
  {
	cout << "Please enter a positive number of shares purchased: " << endl;
	cin >> NS;
  }

  cout << "Please enter the purchace price per share: " << endl;	//User inputs Purchase Price.
  cin >> PP;
  
  while (PP < 0)	//Input validation that PP is not a negative number.
  {
	cout << "Please enter a positive number for purchase price: " << endl;
	cin >> PP;
  } 
  
  cout << "Please enter the purchace commission paid: " << endl;	//User inputs Purchase Commission.
  cin >> PC;

  while (PC < 0)	//Input validation that PC is not a negative number.
  {
	cout << "Please enter a positive number for purchase commission: " << endl;
	cin >> PC;
  }

  cout << "Please enter the sales price per share: " << endl;		//User inputs sales price per share.
  cin >> SP;

  while (SP < 0)	//Input validation that SP is not a negative number.
  {
	cout << "Please enter a positive sales price: " << endl;
	cin >> SP;
  }

  cout << "Please enter the sales commission paid: " << endl;		//user inputs sales commission.
  cin >> SC;

  while (SC < 0)	//Input validation that SP is not a negative number.
  {
	cout << "Please enter a positive number for sales commission: " << endl;
	cin >> SC;
  }

 double finprofit = profit(NS, SP, PC, PP, SC);		//Call and run function profit.

  if (finprofit < 0)
	cout << "You have made a loss of: $" << finprofit << endl;	//If finprofit is less than 0, output a loss.
  else
  	cout << "You have made a profit of: $" << finprofit << endl;	//If finprofit is greater than 0, output a profit.

  return 0;
}
