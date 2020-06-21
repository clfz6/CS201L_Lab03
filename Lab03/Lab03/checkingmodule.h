#pragma once
#include <string>

using namespace std;

void Deposit(double& account, double amount);
char MainMenu();
double GetValue(string question);
double GetValue(string question, double upperLimit);
double GetInterestRate(int creditScore);
void Withdraw(double& account, double amount_to_withdraw);
int GetLoanMonths();
int GetCreditRating();
double CalculateLoanAmount(double principal, double interestRate, int num_months_loan);
double OutputAccount(double amount);