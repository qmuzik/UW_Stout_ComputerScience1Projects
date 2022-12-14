/**
	@file priceupdater.cpp
	@brief uses arrays in price markup

	Reads in percents/markup and list of prices, then processes them using an array.

	@author Quincy Muzik
	@date 11/20/2021
*/

#include "lab7.h" // Header file 

using std::string;
using std::stringstream;

/**
	@brief calculates average

	Calculate the average of values inside the array

	@param prices array used to hold values
	@param numVal number of values read in

	@return averagePrices

	Test 1:
		Input: 42, 16 20
		Output: 26

	Test 2:
		Input: 1, 0, 20, 40
		Output: 15.25

	Test 3:
		Input: 9, 100, 300
		Output: 163.333
*/

double getAverage(double prices[], int numVal) {

	double sum = 0; // all of our values added up together 
	double averagePrice; // sum of values / numValues 

	// Returns 0 if the value is 0 
	if (numVal == 0) {
		return 0;
	}

	// Calculate the sum
	for (int i = 0; i < numVal; i++) {
		sum += prices[i];
	}

	// Calculate the average 
	averagePrice = sum / numVal;

	return averagePrice;

}

/**
	@brief calculates the maximum

	Calculates the maximum value inside our array

	@param prices array used to hold values
	@param numVal number of values read in

	@return maximumPrice

	Test 1:
		Input: 0, 100, 200
		Output: 200

	Test 2:
		Input: 13, 400.5, 200
		Output: 400.5

	Test 3:
		Input: 56, 100, 75
		Output: 100
*/

double getMaximum(double prices[], int numVal) {

	double maximumPrice; // The maximum price in our array 

	// Returns 0 if the value is 0 
	if (numVal == 0) {
		return 0;
	}

	maximumPrice = prices[0];

	// Calculates the maximum
	for (int i = 0; i < numVal; i++) {
		if (maximumPrice < prices[i]) {
			maximumPrice = prices[i];
		}
	}

	return maximumPrice;

}

/**
	@brief updates prices

	Updates the prices inside the array after the markup has been applied

	@param prices array used to hold values
	@param numVal number of values read in
	@param percentMarkup sale markup percent value

	@return

	Test 1:
		Input: 4, 10, 86
		Output: 3

	Test 2:
		Input: 176, 50, 32, 76
		Output: 3

	Test 3:
		Input: 200, 32, 10
		Output: 2
*/

int updatePrices(double prices[], int numVal, double percentMarkup) {

	int numberOfPricesUpdated = 0; // Return value 

	// Calculates markup price and counts prices updated 
	for (int i = 0; i < numVal; i++) {
		if (prices[i] < 175) {
			prices[i] += prices[i] * percentMarkup;
			numberOfPricesUpdated++;
		}
	}

	return numberOfPricesUpdated;

}

/**
	@brief Converts values to a string

	Takes array values inputted and returns them as a string

	@param prices array used to hold values
	@param numVal number of values read in

	@return

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

string arrayToString(double prices[], int numVal) {

	stringstream convert;

	for (int i = 0; i < numVal; i++) {
		convert << prices[i] << " ";
	}

	return convert.str();
}

int insertValue(double prices[], int numVal, int maxArraySize, double insertValue) {

	if (numVal >= maxArraySize) {
		return maxArraySize;
	}

	int i = numVal;

	while (i > 0 && prices[i - 1] > insertValue) {
		prices[i] = prices[i - 1]; 
		i--;
	}

	prices[i] = insertValue;

	return numVal + 1;
}

// used for testing
int main() {

	double array1[] = { 200, 32, 10 };
	std::cout << arrayToString(array1, 3) << "\n";

}