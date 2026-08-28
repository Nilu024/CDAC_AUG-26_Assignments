//============================================================================
// Name        : CalibrationPacketParser.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool parsePacket(const int* rawData, int size, const int** outMin, const int** outMax){

	// If size <= 0 : return false, leave output pointers unchanged
	if(size <= 0){
		return false;
	}
	*outMin = rawData;
	*outMax = rawData;

	for(int i = 1; i < size; i++){

		// set *outMin to point at the minimum element in rawData
		if(**outMin > *(rawData+i))
			*outMin = rawData+i;

		// set *outMax to point at the maximum element in rawData
		if(**outMax < *(rawData+i))
			*outMax = rawData+i;
	}
	 return true;
}

int main() {

	int packet[] = {45, 12, 67, 8, 55, 31};
	const int* minPtr = nullptr;
	const int* maxPtr = nullptr;
	if (parsePacket(packet, 6, &minPtr, &maxPtr)) {
	 cout << "Calibration Min : " << *minPtr << endl;
	 cout << "Calibration Max : " << *maxPtr << endl;
	}

	return 0;
}

//
//#include <iostream>
//using namespace std;
//
//bool parsePacket(const int* rawData, int size,
//                 const int** outMin, const int** outMax) {
//
//    // If size <= 0, return false
//    if (size <= 0) {
//        return false;
//    }
//
//    // Initially point both to the first element
//    *outMin = rawData;
//    *outMax = rawData;
//
//    // Find minimum and maximum
//    for (int i = 1; i < size; i++) {
//
//        // Set outMin to point to minimum element
//        if (**outMin > *(rawData + i)) {
//            *outMin = rawData + i;
//        }
//
//        // Set outMax to point to maximum element
//        if (**outMax < *(rawData + i)) {
//            *outMax = rawData + i;
//        }
//    }
//
//    return true;
//}
//
//int main() {
//
//    int packet[] = {45, 12, 67, 8, 55, 31};
//
//    const int* minPtr = nullptr;
//    const int* maxPtr = nullptr;
//
//    if (parsePacket(packet, 6, &minPtr, &maxPtr)) {
//
//        cout << "Calibration Min : " << *minPtr << endl;
//        cout << "Calibration Max : " << *maxPtr << endl;
//    }
//
//    return 0;
//}
