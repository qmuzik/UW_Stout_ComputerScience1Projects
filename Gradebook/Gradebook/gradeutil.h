#ifndef GRADEUTIL_H_2021_11_10 
#define GRADEUTIL_H_2021_11_10

#include <iostream>

int getGrades(std::istream& input, double grades[], int size);
void outputGrades(std::ostream& output, double grades[], int count);
void copyGrades(double oldGrades[], double newGrades[], int count);
double getMinimum(double grades[], int count);
double sumGrades(double grades[], int count);
double avgGrades(double grades[], int count);
void curveGrades(double grades[], int count);
int countGrades(double grades[], int count, double low, double high);

#endif
