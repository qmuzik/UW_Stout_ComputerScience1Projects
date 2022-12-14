#ifndef LAB7_H_2021_11_20 // creates the token 
#define LAB7_H_2021_11_20 // defines the token 

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

double getAverage(double prices[], int numVal); // Calculates the average of all the values in our array
double getMaximum(double prices[], int numVal); // Calculates the maximum of all the values in our array 
int updatePrices(double prices[], int numVal, double percentMarkup); // Updates the prices after the markup is applied
std::string arrayToString(double prices[], int numVal); // Converts the array to a string 
int insertValue(double prices[], int numVal, int maxArraySize, double insertValue);//


#endif // !LAB7_H_2021_11_20

