#ifndef P2_H_2021_11_10 // Creates token 
#define P2_H_2021_11_10 // Define the token 

#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <iomanip>
#include <string>
#include <sstream>

/** Enum used for group types in contest */
enum class ContestGroup { PART, REGULAR, EXECS };

/** Function used to check if file is valid and can be used getContestGroup */
bool doesFileExist(std::string fileName);

/** Function used to take employee id and determine contest group */
ContestGroup getContestGroup(std::string employeeID);

/** Function that takes our Contest group and returns it as a string */
std::string getContestGroupString(ContestGroup);

/** Function that is used to determine employee prize level */
int getPrizeLevel(int totalNumberSales, ContestGroup);

/** Funciton used to decode employees name from .txt file and return it as a normal name */
std::string fixName(std::string employeeNameBefore);

/**  Function used to calculate the sum of sales */
int sumSales(std::istream& input);

/**  Function that processes our sales info from Input file */
bool processSalesInfo(std::istream& input, std::string& employee, int& prizeLevel, ContestGroup&);

/** Function used to print the sales info from input File */
void printSalesInfo(std::ostream& output, std::string& employeeName, int& prizeLevel, ContestGroup& group);

/** Creates a contest report that is printed to an output file */
void generateContestReport(std::string inputFileName, std::string outputFileName);

/** Function that runs the whole program */
void runContest(std::istream& input, std::ostream& output);

#endif
