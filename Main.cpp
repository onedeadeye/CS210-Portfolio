#include <iostream>
#include <iomanip>
#include "BankAccount.h"
#include "InputValidation.h"
using namespace std;

/*
* Displays and processes the accounting menu for program control.
* 
* @return True if user selected to restart data entry.
*/
bool doAccountingMenu(BankAccount* account) {
	cout << "Enter number selection to modify data, restart, or quit program." << endl;
	cout << "1 - Initial Investment, 2 - Monthly Deposit, 3 - Annual Interest" << endl;
	cout << "4 - Number of Years, 5 - Restart Program, 6 - Quit Program" << endl;

	int userInput = getValidIntInput(1, 6);

	switch (userInput) {
	case 1:
	{
		cout << "Enter new initial investment amount: ";
		double newInitialBalance = getValidDoubleInput();
		account->setInitialBalance(newInitialBalance);
		break;
	}
	case 2:
	{
		cout << "Enter new monthly deposit amount: ";
		double newMonthlyDeposit = getValidDoubleInput();
		account->setMonthlyDeposit(newMonthlyDeposit);
		break;
	}
	case 3:
	{
		cout << "Enter new annual interest rate: ";
		double newInterestRate = getValidDoubleInput();
		account->setInterestRate(newInterestRate);
		break;
	}
	case 4:
	{
		cout << "Enter new number of years: ";
		int newNumYears = getValidIntInput();
		account->setNumberOfYears(newNumYears);
		break;
	}
	case 5:
	{
		account->setDefaults();
		return true;
		break;
	}
	case 6:
	{
		exit(0);
	}
	}
	
	system("cls");
	return false;
}

int main() {
    auto userAccount = make_unique<BankAccount>();
	
	while (true) {
		userAccount->promptCollectInputs();
		do {
			userAccount->displayReportNoDeposits();
			cout << endl;
			userAccount->displayReportWithDeposits();
			cout << endl << endl << endl;
		} while (!doAccountingMenu(userAccount.get()));
	}
    
    return 0;
}