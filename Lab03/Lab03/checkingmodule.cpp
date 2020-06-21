#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include "checkingmodule.h"

using namespace std;

float account;

void Deposit(float& account, float amount)
{
	account = account + amount;

	cout << "Summary of Account" << endl;
	cout << "	Amount $" << account << endl << endl;
}

char MainMenu()
{
	char userInput;
	char upperInput;
	float amount;
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

	string question = "How much do you want to deposit? ==> ";
	bool correct = false;
	switch(upperInput)
	{
	case 'D':
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
		//GetValue(question);
		Deposit(account, amount);
		break;
	case 'W':
		amount = GetValue("How much do you want to withdraw? ==> ");
		Withdraw(account, amount);
		break;
	case 'L':
		cout << "-L"; //Fix
		break;
	case 'Q':
		exit(1);
	default:
		break;
	}

	return userInput;
}

float GetValue(string question)
{
	bool correct = false;
	float amount;
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

float GetValue(string question, float upperLimit)
{
	float amount;
	bool correct = false;

	while (correct == false)
	{
		try
		{
			cout << question;
			cin >> amount;
			cout << endl;

			if (amount <= 0)
				throw runtime_error("You must enter an amount greater than 0 and less than or equal to ");

			correct = true;
		}
		catch (runtime_error& e)
		{
			cout << e.what() << upperLimit << endl;
		}
	}
	return amount;
}

float GetInterestRate(int creditScore)
{
	float fl = 0;
	
	return fl;
}

void Withdraw(float& account, float amount_to_withdraw)
{
	account -= amount_to_withdraw;

	cout << "Summary of Account" << endl;
	cout << "	Amount $" << account << endl << endl;
}

void GetLoanMonths()
{

}

int GetCreditRating()
{
	int input;
	try
	{
		cout << "What is your credit rating? [300, 850] ==> ";
		cin >> input;
		if (input < 300 || input > 850)
		{
			throw runtime_error("You must choose a value from 300 - 850 inclusive.");
		}
	}
	catch (runtime_error& excpt)
	{
		cout << excpt.what() << endl;
	}
	
	return input;
}

float CalculateLoanAmount(float principal, float interestRate, int num_months_loan)
{
	float amount;
	amount = principal * pow(1 + (interestRate / 12), (num_months_loan / 12));
	return amount;
}

float OutputAccount(float amount)
{
	float totalAmount = 0;
	cout << "Interest Rate : " << GetInterestRate(GetCreditRating()) << endl;
	cout << "Principal : " << endl; //get principal
	//cout << "Months : " << GetLoanMonths() << endl;
	//cout << "Your total loan amount is " << CalculateLoanAmount( GetInterestRate(), GetLoanMonths()) //get principal
	return totalAmount;
}

