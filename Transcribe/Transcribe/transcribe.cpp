/**
	@file transcribe.cpp
	@brief transcribes data and outputs it

	Reads a text file, transcribes it and then displays output in a readable format

	@author Quincy Muzik
	@date 10/29/2021
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;
using std::endl;
using std::pow;
using std::sqrt;
using std::setprecision;
using std::fixed;

/**
	@file transcribe.cpp
	@brief transcribes data and outputs it

	Reads a text file, transcribes it and then displays output in a readable format

	@return 0 on success, non-0 on error
*/

int main() {

	ifstream read; // Variable used to read file
	ofstream write; // Varaible used to write files 
	string inputFileName; // Varible used to store input file name 
	string outputFileName; // Varible used to store output file name 
	string numPrimingRead; // Varible used for priming read 

	// Varibles used to hold varibles in distance formula y = sqaure root ((x2-x1)^2 + (y2-y1)^2))
	int x1;
	int x2;
	int y1;
	int y2;

	double distanceFormulaCalculated; // Varible used to hold value after calculating distance 

	// Checks to see if the input file name is valid and opens it
	do {
		cout << "Enter the file name: ";
		cin >> inputFileName;
		read.open(inputFileName);
	} while (read.fail());

	// Checks if filename is eqaul to .txt and then it removes it
	outputFileName = inputFileName;
	if (outputFileName.substr(outputFileName.length() - 4, 4) == ".txt") {
		outputFileName = outputFileName.substr(0, outputFileName.length() - 4);
	}

	// Adds .log to the file name 
	outputFileName += ".log";

	// Opens the output file that ends with .log 
	write.open(outputFileName);

	// Priming read 
	read >> x1 >> y1 >> x2 >> y2;

	// Loop that reads input file 
	while (read) {

		distanceFormulaCalculated = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

		write << "(" << x1 << ", " << y1 << ")" << " : " << "(" << x2 << ", " << y2 << ")" << " -> " << setprecision(3) << fixed << distanceFormulaCalculated << endl;

		read >> x1 >> y1 >> x2 >> y2;
	}

	// Displays a message that informs the user that the program has completed
	cout << "File has been read. \n ";

	// Closes both files 
	read.close();
	write.close();

	// Returns 0 on success 
	return 0;
}
