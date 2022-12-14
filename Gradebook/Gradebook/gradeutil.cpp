#include "gradeutil.h" //Header file 

int getGrades(std::istream& input, double grades[], int size) {

	int numGrades = 0;
	double val;

	// loop stops when out of data or out of room

	// read a value 
	input >> val;

	while (input && numGrades < size) {
		// put a value in the array
		grades[numGrades] = val;
		// count it
		numGrades++;
		// read a value 
		input >> val;
	}

	return numGrades;
}

void outputGrades(std::ostream& output, double grades[], int count) {
	for (int i = 0; i < count; i++) {
		output << grades[i] << "\n";
	}

}

void copyGrades(double oldGrades[], double newGrades[], int count) {
	for (int i = 0; i < count; i++) {
		newGrades[i] = oldGrades[i];
	}
}

double getMinimum(double grades[], int count) {
	//pick a minimum 
	double min;

	// checks if the value is 0 and returns something that is not a minimum 
	if (count == 0) {
		return -1;
	}

	min = grades[0];

	// loop over the array (This algorithum will be used alot of this semester) 
	for (int i = 0; i < count; i++) {
		// check if there is a new minimum
		if (min > grades[i]) {
			min = grades[i];
		}
	}

	return min;

}

double sumGrades(double grades[], int count) {

	double sum = 0;

	for (int i = 0; i < count; i++) {
		sum += grades[i];
	}

	return sum;
}

double avgGrades(double grades[], int count) {

	return sumGrades(grades, count) / count; 
}

void curveGrades(double grades[], int count) {

	double curve = (75 - avgGrades(grades, count));

	// curved grade = grade + (75 - avg)
	for (int i = 0; i < count; i++) {
		grades[i] = grades[i] + (75 - avgGrades(grades, count));

	}
}

int countGrades(double grades[], int count, double low, double high) {
	int matches = 0;

	for (int i = 0; i < count; i++) {
		if (grades[i] >= low && grades[i] < high) {
			matches++;
		}
	}

	return matches;
}

int main() {

}