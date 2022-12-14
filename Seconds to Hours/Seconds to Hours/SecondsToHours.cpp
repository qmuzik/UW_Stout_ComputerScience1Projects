/**
	@file Sec to Hour.cpp
	@brief Converts seconds to hours

	Takes users input of seconds and then converts it into Hours.

	@author Quincy Muzik
	@date 9/28/2021
*/

#include <iostream>

using std::cout;
using std::cin;

/**
	@brief Converts Seconds into Hours

	Converts a users input of seconds into Hours

	@return 0 on success, non-0 on error

	Tests and Results:

	Input:

		Seconds: 3600

	Expected:

		Hours: 1


	Input:

		Seconds: 8000

	Expected:

		Hours: 2.22

	Input:

		Seconds: 2800

	Expected:

		Hours: 0.78

*/

int main() {

	int numSeconds;

	double numHours;

	const double SECONDS_IN_HOUR = 3600;

	// Asks the User to input number of seconds 
	cout << "Enter the number of seconds: ";
	// Reads numSeconds  
	cin >> numSeconds;

	// Calculates how many hours in seconds
	numHours = numSeconds / SECONDS_IN_HOUR;

	//Displays final output 
	cout << "\n";
	cout << "Seconds: " << numSeconds << "\n";
	cout << "Hours: " << numHours;
	cout << "\n";

	//Returns zero if successful and non-zero if unsuccessful
	return 0;
}
