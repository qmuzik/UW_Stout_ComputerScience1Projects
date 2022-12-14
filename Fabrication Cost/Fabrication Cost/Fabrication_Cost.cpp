/**
	@file Fabrication_Cost.cpp
	@brief Determines Fabricaiton Cost

	Calculates the cost of fabricaiton with fixed cost

	@author Quincy Muzik
	@date 10/2/2021
*/

#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::setprecision;
using std::showpoint;
using std::fixed;
using std::setw;
using std::left;
using std::right;
using std::getline;
using std::endl;

/**
	@brief Determines Fabricaiton Cost

	Calculates the cost of fabricaiton with fixed cost

	@return 0 on success, non-0 on error

	Test and Results:

	Input:

		Company Name: Billy's Emporium
		Units: 4500
		Cost Per Unit: 3.75
		Percent Markup: 0.15

	Expected:

		Company Name: Billy's Emporium
		Units: 4500
		Cost Per Unit: 3.75
		Markup: 15.0%
		Total Cost: 22982.20

	Input:

		Company Name: Quincy's Store
		Units: 3300
		Cost Per Unit: 2.00
		Percent Markup: 0.10

	Expected:

		Company Name: Quincy's Stores
		Units: 3300
		Cost Per Unit: 2.00
		Markup: 10.0%
		Total Cost: 10835.95

	Input:

		Company Name: Muzik Shoppe
		Units: 2000
		Cost Per Unit: 1.90
		Percent Markup: 0.12

	Expected:

		Company Name: Muzik Shoppe
		Units: 2000
		Cost Per Unit: 1.90
		Markup: 12.0%
		Total Cost: 7831.95

	Input:

		Company Name: Stout Warehouse
		Units: 9999
		Cost Per Unit: 0.99
		Percent Markup: 0.07

	Expected:

		Company Name: Stout Warehouse
		Units: 9999
		Cost Per Unit: 0.99
		Markup: 7.0%
		Total Cost: 14167.89

*/

int main() {

	string name; // Name of company 

	int numberOfUnits; // Number of units user purchases 
	double costPerUnit; // Cost of each unit 
	const double SETUP_COST = 3575.95; // Constant for Setup Cost of $3575.0
	double percentMarkup; // Markup Percentage 
	double markupPrice; // Additonal price of markup 
	double markupConversion; // Converts decimal to whole double 
	double unitTotal; // Cost of units bought 
	double totalCost; // Total cost of all items with Markup

	// User enters the company name
	cout << "Enter the company name: ";
	getline(cin, name);

	// Print "Enter the number of units: "
	cout << "Enter the number of units: ";
	// Read unitsPurchased
	cin >> numberOfUnits;

	// Print "Enter the cost per unit: "
	cout << "Enter the cost per unit: ";
	// Read costPerUnit
	cin >> costPerUnit;

	// Print "Enter the percent markup: "
	cout << "Enter the percent markup: ";
	// Read percentMarkup
	cin >> percentMarkup;

	//Formula used for calculating cost of number of units
	unitTotal = numberOfUnits * costPerUnit;

	// Formula used for calculating markup price
	markupPrice = percentMarkup * unitTotal;

	// Formula used for converting markup decimal to full percentage 
	markupConversion = percentMarkup * 100;

	// Formula used for calculating total cost 
	totalCost = unitTotal + SETUP_COST + markupPrice;

	// Print Company Name, Units, Cost Per Unit, Markup, and Total Cost 
	cout << "\n\n";
	cout << name << "\n";
	cout << left << "Units:  ";
	cout << right << setw(18) << numberOfUnits << endl;
	cout << left << "Cost Per Unit:  ";
	cout << right << setw(10) << setprecision(2) << fixed << costPerUnit << endl;
	cout << left << "Markup:  ";
	cout << right << setw(16) << setprecision(1) << showpoint << markupConversion << "%" << endl;
	cout << left << "Total Cost:  ";
	cout << right << setw(13) << setprecision(2) << fixed << totalCost << endl;

	return 0;
}