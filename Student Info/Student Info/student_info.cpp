/**
	@file student_info.cpp
	@brief determines student class level

	Determines a students class level based on credits earned

	@author Quincy Muzik
	@date 10/17/2021

	Test 1:

	Input:
		GPA: 2.0
		Credits: 59

	Expected:
		GPA: 2.0
		Credits: 59
		You are a Sophmore
		You are in good standing

	Test 2:

	Input:
		GPA: 0
		Credits: 0

	Expected:
		GPA: 0.0
		Credits: 0

		You are a Freshman
		You are on probation

	Test 3:

	Input:
		GPA: 3.5
		Credits: 64

	Expected:
		GPA: 3.5
		Credits: 64
		You are a Junior
		You are in good standing

	Test 4:

	Input:
		GPA: -2.6
		Credits: 61

	Expected:
		GPA: 2.6
		Credits: 61
		You are a Junior
		You are on probation

	Test 5:

	Input:
		GPA: 2.36
		Credits: 62

	Expected:
		GPA: 2.4
		Credits: 62
		You are a Junior
		You are on probation

	Test 6:

	Input:
		GPA: 2.7
		Credits: -12

	Expected:
		GPA: 2.7
		Credits: 12
		You are a Freshman
		You are in good standing

	Test 7:

	Input:
		GPA:
		Credits:

	Expected:
		GPA:
		Credits:


*/

#include <iostream>
#include <iomanip>
#include <cmath>

using std::cin;
using std::cout;
using std::string;
using std::min;
using std::max;
using std::endl;
using std::setprecision;
using std::fixed;


/**
	@file student_info.cpp
	@brief determines student class level

	Determines a students class level based on credits earned

	@return 0 on success, non-0 on error
*/

int main() {
	
	string freshmanClassLevel = "Freshman"; // Freshman class rank
	string sophomoreClassLevel = "Sophomore"; // Sophmore class rank
	string juniorClassLevel = "Junior"; // Junior class rank 
	string seniorClassLevel = "Senior"; // Senior class rank 

	const int FRESHMAN = 29; // Maximum credits to be considered a freshman
	const int SOPHOMORE = 59; // Maximum credits to be considered a sophmore
	const int JUNIOR = 89; // Maximum credits to be considered a junior
	const int SENIOR = 90; // Maximum credits to be considered a senior 

	double userGPA; // The users GPA that is enterned in 
	int userCreditsCompleted; // The number of credits a student has completed
	
	// Ask user for their GPA 
	cout << "Enter your GPA: ";
	// Read userGPA
	cin >> userGPA;

	// Ask user for the amount of credits completed
	cout << "Enter how many credits you have completed: ";
	// Read userCreditsCompleted
	cin >> userCreditsCompleted;

	// Declares at least 0.0 and 4.0 for GPA
	userGPA = max(0.0, userGPA);

	// Declares at least 0 for the credits
	userCreditsCompleted = max(0, userCreditsCompleted);

	// Display GPA and Credit output
	cout << "GPA: ";
	cout << setprecision(1) << fixed << userGPA << endl;
	cout << "Credits: ";
	cout << fixed << userCreditsCompleted << endl;

	// If statements that determines class level 
	if (userCreditsCompleted <= FRESHMAN) {
		cout << "You are a " << freshmanClassLevel << "\n";
	}

	else if (userCreditsCompleted <= SOPHOMORE) {
		cout << "You are a " << sophomoreClassLevel << "\n";
	}

	else if (userCreditsCompleted <= JUNIOR) {
		cout << "You are a " << juniorClassLevel << "\n";
	}

	else {
		cout << "You are a " << seniorClassLevel << "\n";
	}

	// If statements that determine academic standing 
	if (userCreditsCompleted <= 59 && userGPA >= 2.0) {
		cout << "You are in good standing \n";
	}

	else if (userCreditsCompleted > 59 && userGPA >= 2.5) {
		cout << "You are in good standing \n ";
	}

	else {
		cout << "You are on probation \n";
	}

	return 0;
}