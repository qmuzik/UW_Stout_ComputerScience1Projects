/**
	@file salescontest.cpp
	@brief computes an employee sales contest

	Uses functions and input files to determine emplyee ranking in company sales contest.

	@author Quincy Muzik
	@date 11/10/2021
*/

#include "p2.h" // Header file 

using std::string;
using std::ifstream;
using std::ostream;
using std::istream;
using std::stringstream;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::left;
using std::right;
using std::setw;


/**
	@brief checks file is real

	Uses an istream to check if a file exists and then opens it

	@param fileName user inputted name of file

	@return boolean true if file exists and false if not
*/

bool doesFileExist(string fileName) {

	ifstream read; // Used to read user file

	// Check to see if the input exists and opens it
	read.open(fileName);

	if (read.good()) {
		read.close();
		return true;
	}

	return false;
}

/**
	@brief gets contest group number

	Examines employee ID and gets the ggg part using a substring

	@param employeeID employees ID number from .txt file

	@return ContestGroup Enum

	Test 1:

		Input: 123-eam-8476
		Output: PART

	Test 2:

		Input: 583-day-0192
		Output: REGULAR

	Test 3:

		Input: 392-bar-8974
		Output: EXECS
*/

ContestGroup getContestGroup(string employeeID) {

	// New varible to hold our substring value 
	string code = employeeID.substr(4, 3);

	if (code == "eam" || code == "epm" || code == "lpm") {

		return ContestGroup::PART;

	}

	else if (code == "day" || code == "wke") {

		return ContestGroup::REGULAR;

	}

	return ContestGroup::EXECS;
}

/**
	@brief takes ContestGroup and returns it as a string

	Takes ContestGroup enum and returns the name of group as a string

	@param name Either a PART, REGULAR or EXECS

	@return Group name as string

	Test 1:

		Input: PART
		Output: "Part-time"

	Test 2:

		Input: REGULAR
		Output: "Full-time"

	Test 3:

		Input: EXECS
		Output: "Executives"

*/

string getContestGroupString(ContestGroup name) {

	switch (name) {

	case ContestGroup::PART:

		return "Part-time";

	case ContestGroup::REGULAR:

		return "Full-time";

	case ContestGroup::EXECS:

		return "Executives";

	default:

		return "";
	}
}

/**
	@brief gets the employee prize level

	Finds the employees prize level based of items sold and their contest group

	@param totalNumberSales how many items sold by an employee
	@param nameOfGroup either Part, Full or exec

	@return prizeLevel

	Test 1:

		Input: 5
		Output: prizelevel 1

	Test 2:

		Input: 12
		Output: prizelevel 2

	Test 3:

		Input: 30
		Output: prizelevel 3

	Test 4:

		Input: 48
		Output: prizelevel 4

*/

int getPrizeLevel(int totalNumberSales, ContestGroup nameOfGroup) {

	int prizeLevel; // Prize level that is returned to use

	// Use a static cast to round down 

	if (nameOfGroup == ContestGroup::PART) {
		totalNumberSales = static_cast<int>(totalNumberSales * 1.25);
	}

	if (totalNumberSales < 10) {
		prizeLevel = 1;
	}

	else if (totalNumberSales >= 10 && totalNumberSales <= 20) {
		prizeLevel = 2;
	}

	else if (totalNumberSales >= 20 && totalNumberSales <= 45) {
		prizeLevel = 3;
	}

	// Assigns prize level to 4 if its over 45 
	else {
		prizeLevel = 4;
	}

	// If the group is EXECs increase the prize level by 2 
	if (nameOfGroup == ContestGroup::EXECS) {
		prizeLevel += 2;
		if (prizeLevel > 4) {
			prizeLevel = 4;
		}
	}

	return prizeLevel;

}

/**
	@brief formats name

	decodes and formats the name that is red on employee id

	@param employeeNameBefore the name of the employee when the file is read

	@return employeeNameAfter

	Test 1:

		Input: Qu_muzi***p
		Output: Qu muzip

	Test 2:

		Input: stou**t_uw
		Output: stout uw

	Test 3:

		Input: qal*w_tu**asz_p
		Output: qalw tuasz p

*/

string fixName(string employeeNameBefore) {

	string employeeNameAfter; // name after its been decoded 

	// Counts string length for the employees name before its decoded 
	for (int i = 0; i < employeeNameBefore.length(); i++) {
		if (employeeNameBefore.at(i) == '*')
		{
		}
		else if (employeeNameBefore.at(i) == '_')
		{
			employeeNameAfter += " ";
		}
		else
		{
			employeeNameAfter += employeeNameBefore.at(i);
		}
	}
	return employeeNameAfter;
}

/**
	@brief adds the sum of sales

	adds the number of sales together from the txt file input

	@param input value the txt file reads

	@return sumValue

	Test 1:

		Input: 5
		Output: 5

	Test 2:

		Input: 10
		Output: 20

	Test 3:

		Input: 20
		Output: 30

*/

int sumSales(istream& input) {

	int sumValue = 0;
	int temp;

	while (input >> temp) {

		if (temp < 10) {
			sumValue += temp;
		}

		else {
			sumValue += 10;
		}
	}

	return sumValue;
}

/**
	@brief processes the sales info

	reads the txt file and processes all of the data using the functions declared

	@param input values read in from txt value
	@param employee name of the employee
	@param prizeLevel employees prize level
	@param group employees level of employment

	@return true

	Test 1:

		Input:
		Output:

	Test 2:

		Input:
		Output:

	Test 3:

		Input:
		Output:

*/

bool processSalesInfo(istream& input, string& employee, int& prizeLevel, ContestGroup& group) {

	string temp;

	getline(input, temp);

	stringstream strstream(temp);

	string employeeName;

	if (!(strstream >> employeeName)) {
		return false;
	}

	string employeeId;

	if (!(strstream >> employeeId)) {
		return false;
	}

	int totalSales = sumSales(strstream);

	group = getContestGroup(employeeId);

	prizeLevel = getPrizeLevel(totalSales, group);

	employee = fixName(employeeName);

	return true;

}

/**

@brief prints out the sales info

formats the output and then prints it before its printed to an output file

@param output used for cout
@param employeeName the name of our employee
@param prizeLevel the employees calculated prize level
@param group enum for Exec, Part or Full

@return void

*/

void printSalesInfo(ostream& output, string& employeeName, int& prizeLevel, ContestGroup& group) {

	output << left << setw(40) << employeeName << left << setw(12)
		<< getContestGroupString(group) << right << setw(4) << prizeLevel;

	if (prizeLevel == 4) {
		output << "*";
	}

	output << "\n";
	return;
}

/**

@brief creates an output file

creates an output file after reading in input file name

@param inputFileName name of input file name from the user
@param outputFileName name of the output file name from the user

@return void

*/

void generateContestReport(std::string inputFileName, std::string outputFileName) {

	ofstream output;
	ifstream input;

	input.open(inputFileName);
	output.open(outputFileName);

	if (input.good() && output.good()) {
		output << "Sales Rewards" << "\n";

		string employeeName;
		int prizeLevel;
		ContestGroup level;

		while (input) {
			if (processSalesInfo(input, employeeName, prizeLevel, level)) {
				printSalesInfo(output, employeeName, prizeLevel, level);
			}
		}
	}

	input.close();
	output.close();

	return;

}

/**

@brief runs our program

Runs the program using functions declared and defined

@param input user input
@param output outputs the message

@return void

*/

void runContest(std::istream& input, std::ostream& output) {

	string inputFileName;
	string outputFileName;

	output << "Enter file input file name: ";
	input >> inputFileName;

	if (doesFileExist(inputFileName)) {
		output << "Enter the output file name: ";
		input >> outputFileName;
		generateContestReport(inputFileName, outputFileName);
	}

	else {
		output << "File is not valid";
	}

	return;
}

// used for testing 
int main() {

	runContest(cin, cout);

}