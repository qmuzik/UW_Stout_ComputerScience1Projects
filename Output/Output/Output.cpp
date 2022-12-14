/**
	@file Output.cpp
	@brief Displays a paragraph message

	Displays a message that is properly formatted

	@author Quincy Muzik
	@date 9/24/2021
*/

#include <iostream>

using std::cout;

/**
	@brief Displays a paragraph message

	Displays a properly formatted paragraph message

	@return 0 on success, non-0 on error

*/

int main() {

	cout << "\tIn Windows, putting the path to " // First part of the first line
		<< "a file into the code is a little\n" // Second part of the first line

		<< "difficult as each \"\\\" in" // First part of the second line
		<< " the path must be escaped. So, if your\n"  // Second part of the second line 

		<< "file is located at C:\\temp\\data.csv, " // First part of the third line
		<< "then you would need to\n" // Second part of the third line 

		<< "escape it so that it looks like " // First part of the fourth line
		<< "C:\\\\temp\\\\data.csv. It is also \n" // Second part of the fourth line

		<< "good practice to put \"""\'s around " // First part of the fifth line
		<< "the path. This avoids problems \n" // Second part of the fifth line

		<< "with spaces in the file name or " // First part of the sixth line
		<< "the path. The \"""\'s would have\n" // Second part of the sixth line

		<< "to be escaped as well.\n"; // Final line 

	return 0;

}