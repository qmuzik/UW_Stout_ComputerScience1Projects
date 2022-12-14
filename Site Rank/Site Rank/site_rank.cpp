/*
 *  @file SiteRank.cpp
 *
 *  @brief Converts the number of points earned on awesomeCode.com to a rank.
 *
 *  The program converts the number of points earned on awesomeCode.com
 *  to a rank. The rank is based on the following table:
 *
 * Points	Rank
 * < 1		Invalid
 * 1		Newbie
 * 2-9		Novice
 * 10-49	Professional
 * 50-249	Expert
 * 250+		Guru
 *
 * All members of the site start with 1 point.
 *
 *  @date 10/18/2021
 *  @author Quincy Muzik
 */

#include <iostream>
#include <string>

using namespace std;
using std::cin;
using std::cout;


/**
 *
 *
 *  @brief Converts the number of points earned on awesomeCode.com to a rank.
 *
 *  The program converts the number of points earned on awesomeCode.com
 *  to a rank. The rank is based on the following table:
 *
 * Points	Rank
 * < 1		Invalid
 * 1		Newbie
 * 2-9		Novice
 * 10-49	Professional
 * 50-249	Expert
 * 250+		Guru
 *
 * All members of the site start with 1 point.
 *
 * @return 0 on success and non-0 on error
 *
 *	TESTS:
 *
 * Test 1:
 *
 * Expierence Points: 1
 * Rank: Newbie
 *
 * Test 2:
 *
 * Expierence Points: 0
 * Rank: Invalid
 *
 * Test 3:
 *
 * Expierence Points: 3
 * Rank: Novice
 *
 * Test 4:
 *
 * Expierence Points: 13
 * Rank: Professional
 *
 * Test 5:
 *
 * Expierence Points: 54
 * Rank: Expert
 *
 * Test 6:
 *
 * Expierence Points: 260
 * Rank: Guru
 *
 */
int main() {

	string rank = "";

	int score;

	cout << "Enter your experience score: ";
	cin >> score;


	if (score < 1) {
		rank = " Invalid";
	}

	else if (score == 1) {
		rank = " Newbie";
	}

	else if (score >= 2 && score <= 9) {
		rank = " Novice";
	}

	else if (score >= 10 && score <= 49) {
		rank = " Professional";
	}

	else if (score <= 249) {
		rank = " Expert";
	}

	else {
		rank = " Guru";
	}


	cout << "\n\nWith a experience score of " << score
		<< " you have a rank of" << rank << ".\n\n";

	return 0;
}


