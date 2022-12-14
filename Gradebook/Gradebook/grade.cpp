#include <iostream>
#include <fstream>
#include "gradeutil.h"

using std::ifstream;
using std::cout;

int main() {

	const int MAX_GRADES = 500;
	double grades[MAX_GRADES];
	double curvedGrades[MAX_GRADES];
	ifstream input("gradebook.txt");

	int numGrades = getGrades(input, grades, MAX_GRADES);

	copyGrades(grades, curvedGrades, numGrades);
	curvedGrades(curvedGrades, numGrades);

	cout << "Count: " << numGrades << "\n";
	outputGrades(cout, grades, numGrades);

	cout << "Average: " << avgGrades(grades, numGrades) << "\n";

	cout << "Curved:\n";
	outputGrades(cout, curvedGrades, numGrades);

	return 0;

}