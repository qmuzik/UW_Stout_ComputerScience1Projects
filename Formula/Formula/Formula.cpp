/**
	@file Formula.cpp
	@brief Computes the value of xy+2/x^2 + 1

	User inputs data that is calculated in formula xy+2/x^2 + 1 and displays output.

	@author Quincy Muzik
	@date 10/4/2021
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::setprecision;
using std::fixed;

/**
	@file Formula.cpp
	@brief Computes the value of xy+2/x^2 + 1

	User inputs data that is calculated in formula xy+2/x^2 + 1 and displays output.

	@return 0 on success, non-0 on error

	Tests and Results:

		Input:

		x = 4
		y = 3

		Expected:

		x = 4
		y = 3
		Result = 0.824

		Input:

		x = 0
		y = 2

		Expected:

		x = 0
		y = 2
		Result = 2

		Input:

		x = 1
		y = 9

		Expected:

		x = 1
		y = 9
		Result = 5.5

		Input:

		x = 0
		y = 0

		Expected:

		x = 0
		y = 0
		Result = 2
*/

int main() {

	int xValue; //X value user inputs
	int yValue; //Y value user inputs

	double numeratorFormula; // xy + 2 formula used in numerator
	double denominatorFormula; // x^2 +1 formula used in denominator 
	double finalAnswer; // Numerator Formula / Demonominator Formula gives us the final answer 

	// Print "Enter a value for X: " on the screen 
	cout << "Enter a value for X: ";
	// User enters input for value of X
	cin >> xValue;

	// Print "Enter a value for Y: " on the screen
	cout << "Enter a value for Y: ";
	// User enters input for value of Y
	cin >> yValue;

	// x * y + 2 formula used in the numerator 
	numeratorFormula = xValue * yValue + 2;

	// x^2 + 1 formula used in the denominator 
	denominatorFormula = pow(xValue, 2) + 1;

	// Divides numeratorForumla by denominatorFormula to give us final answer 
	finalAnswer = numeratorFormula / denominatorFormula;

	// Displays the final output with a maximum of 3 decimal points to the right  
	cout << "After using x = " << xValue << " and y = " << yValue << ". Your answer is " << setprecision(3) << fixed << finalAnswer << "\n";

	return 0;

}