/**
* @file Rectangle.cpp
*
* @brief Computes the area and perimter of a rectangle.
*
* This computes the area and perimeter of a rectangle given
* the rectangle's length and width.
*
* @author Quincy Muzik
* @date 9/24/2021
*
*/
#include <string>
#include <iostream>

using std::cout;
using std::cin;

/**
* @brief Computes the area and perimter of a rectangle.
*
* This computes the area and perimeter of a rectangle given
* the rectangle's length and width.
*
*
* @return 0 is sucessful, non-0 on error
*
* TODO TESTS
* Put your tests in the comments here:
*
* Input:
*
*	length: 10
	width: 5

* Expected:
*
*	perimeter: 30
*	area: 50
*
*
* Input:
*
*	length: 10
	width:  10
*
* Expected:
*
*	perimeter: 40
*	area: 100
*
* Input:
*
*	length: 4
	width: 0

* Expected:
*
*	perimeter: 8
*	area: 0
*
*/
int main() {
	double length;
	double width;
	double perimeter;
	double area;

	//prompt for and read in length and width
	cout << "Enter the length of the rectangle: ";
	cin >> length;

	cout << "Enter the width of the rectangle: ";
	cin >> width;

	//compute perimeter and area
	perimeter = 2 * (length + width);
	area = length * width;

	//output results
	cout << "For a " << length << " x " << width
		<< " rectangle, the perimeter is " << perimeter
		<< " and the area is " << area << ".\n";

	return 0;
}