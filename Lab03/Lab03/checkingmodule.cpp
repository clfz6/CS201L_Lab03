#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include "checkingmodule.h"

using namespace std;

double account, borrowAmount, intRate;
int months;

void Deposit(double& account, double amount)
{
	account = account + amount;

	cout << "Summary of Account" << endl;
	cout << "	Amount $" << account << endl << endl;
}

char MainMenu()
{
	char userInput, upperInput;
	
	try
	{
		cout << "Main Menu ( Enter one of the following )" << endl;
		cout << "	(D)eposit, (W)ithdraw, (L)oan, or (Q)uit" << endl;
		cin >> userInput;
		upperInput = toupper(userInput);
		if (upperInput != 'D' && upperInput != 'W' && upperInput != 'L' && upperInput != 'Q')
			throw runtime_error("Invalid input.");
	}
	catch (runtime_error& e)
	{
		cout << e.what() << endl;
		MainMenu();
	}

	switch(upperInput)
	{
	case 'D':
		Deposit(account, GetValue("How much do you want to deposit? ==> "));
		break;
	case 'W':
		Withdraw(account, GetValue("How much do you want to withdraw? ==> ", account));
		break;
	case 'L':
		intRate = GetInterestRate(GetCreditRating());
		months = GetLoanMonths();
		borrowAmount = GetValue("How much do you want to borrow? ");
		CalculateLoanAmount(borrowAmount, intRate, months);
		OutputAccount(borrowAmount);
		break;
	case 'Q':
		exit(1);
	default:
		break;
	}

	return userInput;
}

double GetValue(string question)
{
	bool correct = false;
	double amount;
	while (correct == false)
	{
		try
		{
			cout << question;
			cin >> amount;
			cout << endl;

			if (amount <= 0)
				throw runtime_error("You must enter an amount greater than 0");

			correct = true;
		}
		catch (runtime_error& e)
		{
			cout << e.what() << endl;
		}
	}
	return amount;
}

double GetValue(string question, double upperLimit)
{
	double amount;
	bool correct = false;

	while (correct == false)
	{
		try
		{
			cout << question;
			cin >> amount;
			cout << endl;

			if (amount <= 0 || amount > upperLimit)
				throw runtime_error("You must enter an amount greater than 0, and less than or equal to ");

			correct = true;
		}
		catch (runtime_error& e)
		{
			cout << e.what() << upperLimit << endl;
		}
	}
	return amount;
}

double GetInterestRate(int creditScore)
{
	double rate;
	if (creditScore <= 500)
	{
		rate = 0.05;
	}
	else if (creditScore <= 700)
	{
		rate = 0.03;
	}
	else
	{
		rate = 0.01;
	}
	return rate;
}

void Withdraw(double& account, double amount_to_withdraw)
{
	account -= amount_to_withdraw;

	cout << "Summary of Account" << endl;
	cout << "	Amount $" << account << endl << endl;
}

int GetLoanMonths()
{
	int months = 0;
	bool correct = false;

	while (correct == false)
	{
		try
		{
			cout << "How many months for the loan? 12, 24, 36 or 60 ==> ";
			cin >> months;
			cout << endl;
			if (months == 12 || months == 24 || months == 36 || months == 60)
			{
				correct = true;
			}
			else
			{
				throw runtime_error("You must enter 12, 24, 36 or 60 only");
			}
		}
		catch (runtime_error e)
		{
			cout << e.what() << endl;
		}
	}

	return months;
}

int GetCreditRating()
{
	int input;
	bool correct = false;
	while (correct == false)
	{
		try
		{
			cout << "What is your credit rating? [300, 850] ==> ";
			cin >> input;
			cout << endl;
			if (input < 300 || input > 850)
			{
				throw runtime_error("You must choose a value from 300 - 850 inclusive.");
			}
			correct = true;
		}
		catch (runtime_error& excpt)
		{
			cout << excpt.what() << endl;
		}
	}
	
	return input;
}

double CalculateLoanAmount(double principal, double interestRate, int num_months_loan)
{
	double amount;
	amount = principal * pow(1 + (interestRate / 12), (num_months_loan / 12));
	return amount;
}

double OutputAccount(double amount)
{
	double totalAmount = 0;
	cout << "Interest Rate : " << intRate << endl;
	cout << "Principal : " << borrowAmount << endl; 
	cout << "Months : " << months << endl;
	cout << "Your total loan amount is " << CalculateLoanAmount(borrowAmount, intRate, months) << endl << endl;
	return totalAmount;
}

