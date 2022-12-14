/**
	@file histogram.cpp
	@brief creates a histogram

	Reads a text file and creates a sideways histogram.

	@author Quincy Muzik
	@date 10/29/2021
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;
using std::endl;
using std::right;
using std::setw;

/**
	@file histogram.cpp
	@brief creates a histogram

	Reads a text file and creates a sideways histogram.

	@return 0 on success, non-0 on error
*/

int main() {
	ifstream read; // used to hold file read value
	ofstream write; // used to hold file write value
	string inputFileName; // used to hold input file value
	string outputFileName; // used to hold output file value 
	int numbersRead; // used to hold values read in the input file 

	// Checks to see if the input & output file names are valid, then opens them

	cout << "Enter the input file name: ";
	cin >> inputFileName;
	read.open(inputFileName);

	if (read.fail()) {
		cout << "Error: Input file could not be read." << endl;
		cout << "Enter the input file name: ";
		cin >> inputFileName;
		read.open(inputFileName);
	}

	cout << "Enter the output file name: ";
	cin >> outputFileName;
	write.open(outputFileName);

	if (write.fail()) {
		cout << "Error: Output could not be written." << endl;
		cout << "Enter the output file name: ";
		cin >> outputFileName;
		write.open(outputFileName);
	}

	// While loop that read integers from the file 
	while (read) {
		read >> numbersRead;
		write << right << setw(5) << numbersRead << " : ";

		// For loop that prints a row of '*'s that matches the number read in
		for (int i = 0; i < numbersRead; ++i) {
			write << "*";
		}
		write << endl;
	}

	cout << "Success: The Histogram has been created in " << outputFileName;

	// Close both files
	read.close();
	write.close();

	// Returns 0 on success 
	return 0;

}

