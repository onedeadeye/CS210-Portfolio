#include "BankAccount.h"
#include "InputValidation.h"
#include <iomanip>
#include <iostream>
using namespace std;

BankAccount::BankAccount(double t_initialBalance, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears)
{
	m_initialBalance = t_initialBalance;
	m_monthlyDeposit = t_monthlyDeposit;
	m_interestRate = t_interestRate;
	m_numberOfYears = t_numberOfYears;
}

/*
* Displays a dynamically-updating screen for BankAccount construction. Displays an input prompt
* for the first defaulted input.
*/
const void BankAccount::displayDataInput()
{
	bool displayedInputPrompt = false;

	// Set up cout with the mutators we need
	cout << setprecision(2) << fixed << showpoint;

	cout << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;

	cout << "Initial Investment Amount: ";
	if (m_initialBalance != -1) { cout << "$" << m_initialBalance; }
	else { cout << "_"; displayedInputPrompt = true; }
	cout << endl;

	cout << "Monthly Deposit: ";
	if (m_monthlyDeposit != -1) { cout << "$" << m_monthlyDeposit; }
	else if (!displayedInputPrompt) { cout << "_"; displayedInputPrompt = true; }
	cout << endl;

	cout << "Annual Interest: ";
	if (m_interestRate != -1) { cout << m_interestRate << "%"; }
	else if (!displayedInputPrompt) { cout << "_"; displayedInputPrompt = true; }
	cout << endl;

	cout << "Number of years: ";
	if (m_numberOfYears != -1) { cout << m_numberOfYears; }
	else if (!displayedInputPrompt) { cout << "_"; displayedInputPrompt = true; }
	cout << endl;
}

/*
* Displays data input, then collects and validates inputs for each BankAccount component
*/
void BankAccount::promptCollectInputs() {
	// Loop once for each input
	for (int i = 0; i < 4; i++) {
		system("cls");
		this->displayDataInput();
		switch (i) {
		case 0:
		{
			double userInitialBalance = -1;
			userInitialBalance = getValidDoubleInput();
			this->setInitialBalance(userInitialBalance);
			break;
		}
		case 1:
		{
			double userMonthlyDeposit = -1;
			userMonthlyDeposit = getValidDoubleInput();
			this->setMonthlyDeposit(userMonthlyDeposit);
			break;
		}
		case 2:
		{
			double userInterestRate = -1;
			userInterestRate = getValidDoubleInput();
			this->setInterestRate(userInterestRate);
			break;
		}
		case 3:
		{
			int userNumYears = -1;
			userNumYears = getValidIntInput();
			this->setNumberOfYears(userNumYears);
			system("cls");
			this->displayDataInput();
			break;
		}
		default:
			break;
		}
	}
	system("pause");
	system("cls");
}

/**
 * Calculates and displays a report for given number of years detailing year end balance
 * and earned interest, without factoring in deposits.
 */
const void BankAccount::displayReportNoDeposits()
{
	double currentInvestment = m_initialBalance;
	double monthlyInterestRate = m_interestRate / 100 / 12;

	cout << " Balance and Interest without Additional Monthly Deposits" << endl;
	cout << "==========================================================" << endl;
	cout << " Year           Year End Balance        Interest Earned" << endl;
	cout << "----------------------------------------------------------" << endl;

	// Year loop
	for (int i = 0; i < m_numberOfYears; i++) {
		double yearsInterest = 0;
		// Month loop
		for (int j = 0; j < 12; j++) {
			double monthsInterest = currentInvestment * monthlyInterestRate;
			yearsInterest += monthsInterest;
			currentInvestment += monthsInterest;
		}
		displayYearDetails(i + 1, currentInvestment, yearsInterest);
		cout << endl;
	}
}

/**
* Calculates and displays a report for given number of years detailing year end balance
* and earned interest, factoring in deposits.
*/
const void BankAccount::displayReportWithDeposits()
{
	double currentInvestment = m_initialBalance;
	double monthlyInterestRate = m_interestRate / 100 / 12;


	cout << "  Balance and Interest with Additional Monthly Deposits" << endl;
	cout << "==========================================================" << endl;
	cout << " Year           Year End Balance        Interest Earned" << endl;
	cout << "----------------------------------------------------------" << endl;

	// Year loop
	for (int i = 0; i < m_numberOfYears; i++) {
		double yearsInterest = 0;
		// Month loop
		for (int j = 0; j < 12; j++) {
			double monthsInterest = currentInvestment * monthlyInterestRate;
			yearsInterest += monthsInterest;
			currentInvestment += monthsInterest;
			currentInvestment += m_monthlyDeposit;
		}
		displayYearDetails(i + 1, currentInvestment, yearsInterest);
	}
}

/**
* Prints the calculated results of one year's investment details in 3 separate fields
* @param year year number
* @param yearEndBalance the current dollar value of the investment
* @param interestEarned dollar amount of how much earned in that year
*/
void BankAccount::displayYearDetails(int year, double yearEndBalance, double interestEarned)
{
	cout << setprecision(2) << fixed << showpoint;
	cout << " " << year << "		" << "$" << yearEndBalance << "			" << "$" << interestEarned << endl;
}

void BankAccount::setInitialBalance(double t_initialBalance) {
	m_initialBalance = t_initialBalance;
}

void BankAccount::setMonthlyDeposit(double t_monthlyDeposit) {
	m_monthlyDeposit = t_monthlyDeposit;
}

void BankAccount::setInterestRate(double t_interestRate) {
	m_interestRate = t_interestRate;
}

void BankAccount::setNumberOfYears(int t_numberOfYears) {
	m_numberOfYears = t_numberOfYears;
}

void BankAccount::setDefaults() {
	m_initialBalance = -1;
	m_monthlyDeposit = -1;
	m_interestRate = -1;
	m_numberOfYears = -1;
}
