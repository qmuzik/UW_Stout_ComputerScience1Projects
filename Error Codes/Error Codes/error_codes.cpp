/**
	@file error_codes.cpp
	@brief displays an error code

	Displays an error code based on user input using a switch statement

	@author Quincy Muzik
	@date 10/18/2021

	TESTS:

	Test 1:

	Input: -1
	Output: File Not Found

	Test 2:

	Input: -2
	Output: Invalid File Format

	Test 3:

	Input: -4
	Output: Out of Memory

	Test 4:

	Input: -8
	Output: Invalid Operation

	Test 5:

	Input: 2
	Output: Unknown Error

	Test 6:

	Input: 1
	Output: Unknown Error

*/

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;

/**
	@file error_codes.cpp
	@brief displays an error code

	Displays an error code based on user input using a switch statement

	@return 0 on success, non-0 on error
*/

int main() {

	int errorCode; // varible that holds error code number

	// Ask user for input of error code
	cout << "Enter in the error code: ";
	cin >> errorCode;

	// Response displays based on error code number
	switch (errorCode) {
	case -1:
		cout << "Error Code: " << errorCode << "\n";
		cout << "File Not Found \n";
		break;
	case -2:
		cout << "Error Code: " << errorCode << "\n";
		cout << "Invalid File Format \n";
		break;
	case -4:
		cout << "Error Code: " << errorCode << "\n";
		cout << "Out of Memory \n";
		break;
	case -8:
		cout << "Error Code: " << errorCode << "\n";
		cout << "Invalid Operation \n";
		break;
	default:
		cout << "Error Code: " << errorCode << "\n";
		cout << "Unknown Error \n";
	}

	return 0;

}