#pragma once
class BankAccount
{
public:
	BankAccount(double t_initialBalance = -1, double t_monthlyDeposit = -1, double t_interestRate = -1, int t_numberOfYears = -1);
	const void displayDataInput();
	void promptCollectInputs();
	const void displayReportNoDeposits();
	const void displayReportWithDeposits();
	static void displayYearDetails(int year, double yearEndBalance, double interestEarned);
	void doAccountingMenu();
	void setInitialBalance(double t_initialBalance);
	void setMonthlyDeposit(double t_monthlyDeposit);
	void setInterestRate(double t_interestRate);
	void setNumberOfYears(int t_numberOfYears);
	void setDefaults();
private:
	double m_initialBalance;
	double m_monthlyDeposit;
	double m_interestRate;
	int m_numberOfYears;
};
