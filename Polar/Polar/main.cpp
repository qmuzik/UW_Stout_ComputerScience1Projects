/**
	@file main.cpp
	@brief uses functions to solve an equation

	Uses functions declared in a header file to solve an eqaution that finds theta.

	@author Quincy Muzik
	@date 11/6/21
*/

#include "lab6.h" /** Header filed for this assignment */

using std::cin;
using std::cout;
using std::sqrt;
using std::atan2;
using std::pow;
using std::string;
using std::stringstream;
using std::setprecision;
using std::fixed;
using std::istream;
using std::ostream;
using std::endl;

/** Constant value of Pi */
const double PI = 3.14159265;


/**
	@brief caluclates the r value of polar

	Calculates the r value of polar using a function

	@param x user inputted x value
	@param y user inputted y value

	@return the calculate value of R from user input

	Test 1:

		Input X value: 1
		Input Y value: 2
		Output: 2.2361

	Test 2:

		Input X value: 0
		Input Y value: 3
		Output: 3

	Test 3:

		Input X value: 1.5
		Input Y value: 4
		Output: 4.2720

*/

/** Calculates the r value of polar and returns that value */
double calculateR(double x, double y) {
	return sqrt(pow(x, 2) + pow(y, 2));
}

/**
	@brief converts radians to degrees

	Takes user input of radians and then convert its to degrees

	@param radianAngle user inputted radian angle

	@return converted value of angle into into degrees

	Test 1:

		Input Radian Angle: 90
		Output: 5156.62

	Test 2:

		Input Radian Angle: 0
		Output: 0

	Test 3:

		Input Radian Angle: 20.4
		Output: 1168.83

*/

/** Converts an angle in radians to degrees and returns the value in degrees */
double radToDegrees(double radianAngle) {
	return (180 * radianAngle) / PI;
}

/**
	@brief calculates theta

	Takes user inputted values of X and Y into a formula for calculating theta

	@param x user inputted x value
	@param y user inputted y value

	@return the value of theta that was calculated in the function

	Test 1:

		Input X value: 0
		Input Y value: 2
		Output: 90

	Test 2:

		Input X value: 1.5
		Input Y value: 4
		Output: 69.444

	Test 3:

		Input X value: 3.2
		Input Y value: 6
		Output: 61.928

*/

double calculateTheta(double x, double y) {
	double thetaValue = radToDegrees(atan2(y, x));

	// checks to see if thethaValue is negative 
	if (thetaValue < 0) {
		thetaValue += 360;
	}

	return thetaValue;
}

/**
	@brief formats decimal point

	Converts numeric point to a formatted string with 3 decimal places

	@param x user inputted x value
	@param y user inputted y value

	@return value formatted with decimal as a string

	Test 1:

		Input X value: 2
		Input Y value: 3
		Output X value: 2.000
		Output Y value: 3.000

	Test 2:

		Input X value: 4
		Input Y value: 5
		Output X value: 4.000
		Output Y value: 5.000

	Test 3:

		Input X value: 10
		Input Y value: 320
		Output X value: 10.000
		Output Y value: 320.000

*/

string formatPoint(double x, double y) {

	stringstream formatter;

	formatter << fixed << setprecision(3) << "(" << x << ", " << y << ")";

	return formatter.str();
}

/**
	@brief gets the value

	Converts numeric point to a formatted string with 3 decimal places

	@param input used for user input
	@param output used for output
	@param text message that will display for user to enter in message

	@return userInput value that was entered in

*/
double getValue(istream& input, ostream& output, string text) {

	double userInput;

	output << text;
	input >> userInput;

	return userInput;

}

/**
	@brief converts rectangle to polar

	Uses all of our previosly stated functions to produce a final product of polar

	@param x user inputted x value
	@param y user inputted y value

	@return final output of all values calculated as a string

	Test 1:

		Input X value: 10
		Input Y value: 15
		Output: (10.000, 15.000) -> 18.028 ,56.310

	Test 2:

		Input X value: 1
		Input Y value: 4
		Output: (1.000, 4.000) -> 4.123, 75.964

	Test 3:

		Input X value: 5
		Input Y value: 3
		Output: (5.000, 3.000) -> 5.831, 30.964

*/

void convertRectToPolar(istream& input, ostream& output) {

	double x;
	double y;
	double rValue;
	double thetaValue;

	x = getValue(input, output, "Enter a value for X: ");
	y = getValue(input, output, "Enter a value for Y: ");

	// Used to check if istream is in a good state
	if (input.fail()) {
		output << "Error: Bad istream ";
		return;
	}

	// Functions used to calculate rValue and Theta value from user input 
	rValue = calculateR(x, y);
	thetaValue = calculateTheta(x, y);

	// Final Output 
	output << formatPoint(x, y) << " -> " << fixed << setprecision(3) << rValue << " , " << thetaValue << endl;

	return;
}

// Used for testing 
int main() {

	convertRectToPolar(cin, cout);

}