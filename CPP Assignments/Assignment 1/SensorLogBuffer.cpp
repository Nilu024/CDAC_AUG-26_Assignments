//============================================================================
// Name        : SensorLogBuffer.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    int size;

    cout << "Readings entered : ";
    cin >> size;

    double readings[100];

    int skip = 0;
    int validCount = 0;

    cout << "Enter readings : ";

    for (int i = 0; i < size; i++) {

        double value;
        cin >> value;

        if (value <= 0) {
            skip++;
            continue;
        }

        readings[validCount] = value;
        validCount++;
    }

    cout << "Valid readings: ";
    for (int i = 0; i < validCount; i++) {
        cout << fixed << setprecision(1) << readings[i] << " ";
    }

    cout << endl;

    cout << "Skipped (errors) : " << skip << endl;

    for (int i = 0; i < validCount; i++) {

        if (readings[i] >= 45) {
            cout << "First CRITICAL : Index " << i + 1
                 << " → " << fixed << setprecision(1)
                 << readings[i] << "°C" << endl;
            break;
        }
    }

    double min = readings[0];
    double max = readings[0];
    double sum = readings[0];

    for (int i = 1; i < validCount; i++) {

        if (readings[i] < min) {
            min = readings[i];
        }

        if (readings[i] > max) {
            max = readings[i];
        }

        sum += readings[i];
    }

    double avg = sum / validCount;

    cout << "Min : " << fixed << setprecision(1) << min
         << "°C Max : " << max
         << "°C Avg : " << setprecision(2) << avg
         << "°C" << endl;

    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;

    for (int i = 0; i < validCount; i++) {

        if (readings[i] < 30) {
            normal++;
        }
        else if (readings[i] < 45) {
            warning++;
        }
        else if (readings[i] < 60) {
            critical++;
        }
        else {
            shutdown++;
        }
    }

    cout << "Normal:" << normal
         << " Warning:" << warning
         << " Critical:" << critical
         << " Shutdown:" << shutdown << endl;

    return 0;
}
