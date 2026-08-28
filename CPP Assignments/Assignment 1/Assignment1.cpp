//============================================================================
// Name        : Assignment1.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	double temp;
	cout << "Enter Temperature in Degree: " << endl;
	cin >> temp;

	int statusCode;

	if(temp < 0){
		statusCode = -1;
	}else if(temp > 0  && temp < 30){
		statusCode = 0;
	}else if(temp >=30 && temp < 45){
		statusCode = 1;
	}else if(temp >= 45 && temp < 60){
		statusCode = 2;
	}else if(temp >= 60){
		statusCode = 3;
	}

	string statusLable;
	string action;

	switch(statusCode){
	case -1:
		statusLable = "SENSOR_ERROR";
		action = "Sensor fault — check wiring";
		break;
	case 0:
		statusLable = "NORMAL";
		action = "No action required";
		break;
	case 1:
		statusLable = "WARNING";
		action = "Alert sent to superviso";
		break;
	case 2:
		statusLable = "CRITICAL";
		action = "Cooling system triggered";
		break;
	case 3:
		statusLable = "SHUTDOWN";
		action = "Emergency shutdown initiated";
		break;
	}


	double inFahrenheit = ((temp * 9)/5) + 32;


	cout << "Temperature : " << temp << "°C / " << inFahrenheit << "°F" << endl;
	cout << "Status : " << statusLable << endl;
	cout << "Action : " << action << endl;
	cout << "Reading : " << ((temp >= 25) ? "Above Average" : "Below Average") << endl;




	return 0;
}
