/**
	@file Coins.cpp
	@brief Converts coins into dollars

	Converts nickels, dimes, and quarters into a dollar amount.

	@author Quincy Muzik
	@date 9/20/2021
*/

#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::setprecision;
using std::istream;
using std::ostream;
using std::fixed;
using std::setw;
using std::left;
using std::right;
using std::getline;

// input function 
/**
@brief Gets the number of coins from the user 

 Gets the number of coins from the user. The number will be between 0 and 10,000.

 @param coinName The name of the coin to appear in the prompt.

@return Number of coins 
*/
int getCoinCount(string coinName);

// calculating value function
double calcValue(int numCoins, double coinValue);
// output function 

/**
@brief Print the coin information

Print the coin information.

@param label The labe for the coins in the output.
@param value The coin's value to display. 

*/
void printCoin(ostream& output,string label, double value);

/**
	@brief Converts coins into dollars

	Converts nickels, dimes, and quarters into a dollar amount.

	@return 0 on success, non-0 on error
*/
int main() {
	// <type> <name> 
	// types - int , double/float , string , char , bool 
	// names - camelCase 

	int numNickels;
	int numDimes;
	int numQuarters;

	double valNickels;
	double valDimes;
	double valQuarters;
	double valTotal;
	string name;

	const double NICKEL_WORTH = 0.05;
	const double DIME_WORTH = 0.10;
	const double QUARTER_WORTH = 0.25;

	// User enters their name 
	cout << "Enter your name: ";
	getline(cin, name);

	//// Print "Enter the number of nickels: "
	//cout << "Enter the number of nickels: ";
	//// Read numNickels 
	//cin >> numNickels;
	//if (numNickels < 0 || numNickels > 10000) {
	//	numNickels = 0;
	//}

	numNickels = getCoinCount("nickels");
	numDimes = getCoinCount("dimes");
	numQuarters = getCoinCount("qaurters");


	//// Print "Enter the number of dimes: "
	//cout << "Enter the number of dimes: ";
	//// Read numDimes 
	//cin >> numDimes;
	//if (numDimes < 0 || numDimes > 10000) {
	//	numDimes = 0;
	//}

	//// Print "Enter the number of qaurters: "
	//cout << "Enter the numebr of quarters: ";
	//// Read numQaurters 
	//cin >> numQuarters;
	//if (numQuarters < 0 || numQuarters > 10000) {
	//	numQuarters = 0;
	//}
	numNickels = getCoinCount(cin, cout, "nickels");
	numDimes = getCoinCount(cin, cout, "dimes");
	numQuarters = getCoinCount(cin, cout, "quarters");


	// valNickels = numNickels * 0.05
	valNickels = calcValue(numNickels, NICKEL_WORTH);

	// valDimes = numDimes * 0.10 
	valDimes = calcValue(numDimes, DIME_WORTH);

	// valQaurters = nunmQaurters * 0.25
	valQuarters = calcValue(numQuarters, QUARTER_WORTH);

	// valTotal = valNickels + valDimes + valQuarters 
	valTotal = valNickels + valDimes + valQuarters;

	// Print "Dollars: " + valTotal 
	cout << "\n\n";
	cout << "Hello " << name << "\n";
	cout << setprecision(2) << fixed;
	//setw, left/right
	printCoin(cout, "Nickels:", valNickels);
	printCoin(cout, "Dimes:", valDimes);
	printCoin(cout, "Qaurters:", valQuarters);
	printCoin(cout, "Total:", valTotal);

	//cout << left << setw(12) << "Nickels: " << setw(8) << right << valNickels << "\n";
	//cout << left << setw(12) << "Dimes: " << setw(8) << right << valDimes << "\n";
	//cout << left << setw(12) << "Qaurters: " << setw(8) << right << valQuarters << right << "\n";
	//cout << left << setw(12) << "Dollars: " << setw(8) << right << valTotal << right << "\n";

	return 0;
}

// input function 
int getCoinCount(istream &input, ostream &output, string coinName) {
	int numCoins;
	// Print "Enter the number of nickels: "
	cout << "Enter the number of " + coinName + ": ";
	// Read numCoins
	cin >> numCoins;
	if (numCoins < 0 || numCoins > 10000) {
		numCoins= 0;
	}
	
	return numCoins;
}

// calculating value function
double calcValue(int numCoins, double coinValue) {
	double value = numCoins* coinValue;
	return value;
}

// output function 
void printCoin(ostream &output, string label, double value) {
	output << setprecision(2) << fixed;
	output << left << setw(12) << label
		<< setw(8) << right << value << "\n";
}
