//============================================================================
// Name        : BuildingSensorGrid.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    const int FLOORS = 3;
    const int ROOMS = 3;
    const double WARNING = 30.0;

    double grid[FLOORS][ROOMS];

    cout << "Enter reading for each room (total 9): ";

    for (int i = 0; i < FLOORS; i++) {
        for (int j = 0; j < ROOMS; j++) {
            cin >> grid[i][j];
        }
    }

    cout << endl;

    cout << "       "
         << setw(7) << "Room1"
         << setw(7) << "Room2"
         << setw(7) << "Room3"
         << endl;

    cout << fixed << setprecision(1);

    for (int i = 0; i < FLOORS; i++) {

        cout << "Floor " << i + 1 << " :";

        for (int j = 0; j < ROOMS; j++) {
            cout << setw(7) << grid[i][j];
        }

        cout << endl;
    }

    double maxTemp = grid[0][0];

    int maxFloor = 0;
    int maxRoom = 0;

    for (int i = 0; i < FLOORS; i++) {

        for (int j = 0; j < ROOMS; j++) {

            if (grid[i][j] > maxTemp) {

                maxTemp = grid[i][j];
                maxFloor = i;
                maxRoom = j;
            }
        }
    }

    cout << endl;

    cout << "Hottest Room : Floor " << maxFloor + 1
         << ", Room " << maxRoom + 1
         << " → " << fixed << setprecision(1)
         << maxTemp << "°C" << endl;

    double maxAvg = 0;
    int hottestFloor = 0;

    for (int i = 0; i < FLOORS; i++) {

        double sum = 0;

        for (int j = 0; j < ROOMS; j++) {
            sum += grid[i][j];
        }

        double avg = sum / ROOMS;

        if (avg > maxAvg) {
            maxAvg = avg;
            hottestFloor = i;
        }
    }

    cout << "Hottest Floor : Floor "
         << hottestFloor + 1
         << " (avg " << fixed << setprecision(2)
         << maxAvg << "°C)" << endl;

    int roomWarn = 0;

    for (int i = 0; i < FLOORS; i++) {

        for (int j = 0; j < ROOMS; j++) {

            if (grid[i][j] >= WARNING) {
                roomWarn++;
            }
        }
    }

    cout << "Rooms at WARNING or above : "
         << roomWarn << endl;


    return 0;
}
