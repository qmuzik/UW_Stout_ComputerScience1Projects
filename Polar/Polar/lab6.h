#ifndef LAB_6_2021_11_07 // Creates token
#define LAB_6_2021_11_07 // Defines token 

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

double calculateR(double x, double y); // Function used to calculate the r value of a polar coordinate 
double radToDegrees(double radianAngle); // Function used to convert radians to degrees 
double calculateTheta(double x, double y); // Function used to calculate Theta
std::string formatPoint(double x, double y); // Function used to convert a numeric point to a formatted string with 3 decimal points
double getValue(std::istream& input, std::ostream& output, std::string text); // Function used to read a double from the input stream 
void convertRectToPolar(std::istream& input, std::ostream& output); // Function used to read in x and y value, then it will calculate our function calculate functions


#endif // ends LAB_6_2021_11_07

