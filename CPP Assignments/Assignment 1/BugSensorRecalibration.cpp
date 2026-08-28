//============================================================================
// Name        : BugSensorRecalibration.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void resetSensorPairV1(int reading1, int reading2){
	int temp = reading1;
	reading1 = reading2;
	reading2 = temp;
}


void resetSensorPairV2(int& reading1, int& reading2){
	int temp = reading1;
	reading1 = reading2;
	reading2 = temp;
}


void resetSensorPairV3(int* reading1, int* reading2){
	int temp = *reading1;
	*reading1 = *reading2;
	*reading2 = temp;
}


int main() {
	int a =55, b = 12;

	cout << "--- V1: Call by Value ---" ;
	cout << "\nBefore : A=" << a << " B=" << b ;
	resetSensorPairV1(a, b);
	cout <<"\nAfter : A=" << a << " B=" << b << endl;

	cout << endl;

	cout << "--- V2: Call by Value ---" ;
	cout << "\nBefore : A=" << a << " B=" << b;
	resetSensorPairV2(a, b);
	cout <<"\nAfter : A=" << a << " B=" << b << endl;

	cout << endl;

	cout << "--- V3: Call by Value ---" ;
	cout << "\nBefore : A=" << a << " B=" << b;
	resetSensorPairV3(&a, &b);
	cout <<"\nAfter : A=" << a << " B=" << b << endl;


	return 0;
}
