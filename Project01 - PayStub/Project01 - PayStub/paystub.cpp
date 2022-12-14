/**
	@file paystub.cpp
	@brief Calculates pay

	Calculates employees pay using pay periods, rate, taxes and insurance

	@author Quincy Muzik
	@date 10/8/2021
*/

/*
	Algorithum:
		- Ask user "Enter you name: "
		- Read Input name
		- Ask user "Enter your yearly salary" (Integer)
		- Read Input salary
		- Ask user "Enter the number of pay periods: " (Integer)
		- Read Input pay periods
		- Ask user "Enter the number of exemptions: " (Integer)
		- Read Input exemptions
		- Ask user "Enter the yearly cost of health insurance: " (Double)
		- Read Input yearly health insurance
		- Calculate salary for each pay period (salary/number of pay periods)
		- Calcualte FICA tax amount (pay period * FICA rate 6.2% )
		- Calculate withholding amount (salary for pay period * withholding rate 11.5% - number of exemptions * amount per exemption 15)
		- Calculate yearly heatlh insurance cost for the pay period (Yearly health insurance cost / number of pay periods)
		- Calculate net salary (salary for pay period - FICA - witholding - health insurance cost for the pay period)

		Output Display:
			- Employees Name
			- Input Yearly salary
			- Input number of pay periods
			- Input number of exemptions
			- Yearly cost of insurance
			- Salary for pay period
			- FICA tax amount (6.2%)
			- Witholding amount (11.5%)
			- Cost of health insuracne for this pay period
			- Net salary for this pay period
*/

/**
	Test #1
		Enter your name: Quincy Muzik
		Enter your yearly salary: 50000
		Enter the number of pay periods: 26
		Enter the number of exemptions: 3
		Enter the yearly cost of health insurance: 2000

		Your Name: Quincy Muzik
		Yearly Salary: 50000
		Pay Periods: 26
		Exemptions: 3
		Insurance: 2000
		Salary: 1923.08
		FICA: 119.23
		Witholding: 176.15
		Insurance: 76.92
		Net Salary: 1550.78

	Test #2
		Enter your name: Mary Reed
		Enter your yearly salary: 65000
		Enter the number of pay periods: 26
		Enter the number of exemptions: 4
		Enter the yearly cost of health insurance: 3000

		Your Name: Mary Reed
		Yearly Salary: 65000
		Pay Periods: 26
		Exemptions: 4
		Salary: 2500
		Insurance: 115.38
		FICA: 155
		Witholding: 227.50
		Net Salary: 2002.12

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::abs;
using std::setw;
using std::endl;
using std::left;
using std::right;
using std::setprecision;
using std::fixed;
using std::max;

/**
	@file paystub.cpp
	@brief Calculates employees final pay

	Calculates employees pay using pay periods, rate, taxes and insurance

	@return 0 on success, non-0 on error
*/

int main() {

	string name; // Name of employee 

	const double FICA_RATE = 0.062; // FICA tax rate
	const double WITHOLDING_RATE = 0.115; // Money witheld for other txaes 
	const int EXEMPTION_AMOUNT = 15; // Exemptions reduces tax witholding by 15

	int userSalary; // Users yearly salary
	int userPayPeriods; // Users pay periods per year 
	int userExemptions; // Users exemptions from taxes 
	double userHealthInsurance; // Users yearly cost of health insurance 
	double salaryPerPeriod; // User salary earned per pay period 
	double ficaTax; // FICA tax removed from net pay
	double witholdingAmount; // Withholding tax removed from net pay
	double healthInsuranceCost; // Health insurance removed from net pay 
	double netSalary; // Pay for pay period with taxes removed 


	// Ask user for their name 
	cout << "Enter your name: ";
	getline(cin, name);

	// Ask user for their salary
	cout << "Enter your yearly salary: ";
	// Read userSalary
	cin >> userSalary;

	// Ask user for number of pay periods 
	cout << "Enter the number of pay periods: ";
	// Read userPayPeriods 
	cin >> userPayPeriods;

	// Ask user for number of exemptions
	cout << "Enter the number of exemptions: ";
	// Read userExemptions
	cin >> userExemptions;

	// Ask use for yearly cost of health insurance
	cout << "Enter the yearly cost of health insurance: ";
	// Read userHealthInsurance 
	cin >> userHealthInsurance;

	// Declares at least 0 for exemptions
	userExemptions = max(0, userExemptions);

	// Declares at least 1 for payperiods
	userPayPeriods = max(1, userPayPeriods);

	// Calculate the salary per pay period 
	salaryPerPeriod = static_cast<double> (userSalary) / userPayPeriods;

	// Calculate the fica tax removed from salary 
	ficaTax = salaryPerPeriod * FICA_RATE;

	// Calculate the withholding tax removed from salary
	witholdingAmount = (salaryPerPeriod * WITHOLDING_RATE) - (userExemptions * EXEMPTION_AMOUNT);

	// Calculate the health insurance removed from salary
	healthInsuranceCost = userHealthInsurance / userPayPeriods;

	// Calculate the net salary 
	netSalary = salaryPerPeriod - ficaTax - witholdingAmount - healthInsuranceCost;

	// Display the final output
	cout << "\n\n";
	cout << "Your Name: " << name << "\n";
	cout << left << "Yearly Salary: ";
	cout << right << setw(9) << fabs(userSalary) << endl;
	cout << left << "Pay Periods: ";
	cout << right << setw(11) << userPayPeriods << endl;
	cout << left << "Exemptions: ";
	cout << right << setw(12) << userExemptions << endl;
	cout << left << "Insurance: ";
	cout << right << setw(13) << setprecision(2) << fixed << fabs(userHealthInsurance) << endl;
	cout << left << "Salary: ";
	cout << right << setw(16) << setprecision(2) << fixed << fabs(salaryPerPeriod) << endl;
	cout << left << "FICA: ";
	cout << right << setw(18) << setprecision(2) << fixed << fabs(ficaTax) << endl;
	cout << left << "Withholding: ";
	cout << right << setw(11) << setprecision(2) << fixed << fabs(witholdingAmount) << endl;
	cout << left << "Insurance: ";
	cout << right << setw(13) << setprecision(2) << fixed << fabs(healthInsuranceCost) << endl;
	cout << left << "Net Pay: ";
	cout << right << setw(15) << setprecision(2) << fixed << fabs(netSalary) << endl;

	return 0;
}