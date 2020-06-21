#pragma once
#include <string>

using namespace std;

void Deposit(float& account, float amount);
char MainMenu();
float GetValue(string question);
float GetValue(string question, float upperLimit);
float GetInterestRate(int creditScore);
void Withdraw(float& account, float amount_to_withdraw);
void GetLoanMonths();
int GetCreditRating();
float CalculateLoanAmount(float principal, float interestRate, int num_months_loan);
float OutputAccount(float amount);