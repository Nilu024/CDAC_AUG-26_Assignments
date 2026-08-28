//============================================================================
// Name        : HardwareRegisterAccess.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

    int statusReg = 0b10110001;   // Read-only from firmware side
    int controlReg = 0b00000000;  // Firmware writes here
    int dataReg = 0b11001010;     // For reassignment demo

    // 1. Pointer to constant integer
    const int* regPtr1 = &statusReg;

    cout << "Status Register: " << *regPtr1 << endl;

    // Cannot modify the value
    // *regPtr1 = 30;  // ERROR: assignment of read-only location

    // Can repoint the pointer
    regPtr1 = &controlReg;

    cout << "After repointing regPtr1: " << *regPtr1 << endl;


    // 2. Constant pointer to integer
    int* const regPtr2 = &controlReg;

    cout << "Control Register: " << *regPtr2 << endl;

    // Can modify the value
    *regPtr2 = 50;

    cout << "After writing: " << *regPtr2 << endl;

    // Cannot repoint the pointer
    // regPtr2 = &dataReg;  // ERROR: assignment of read-only variable


    // 3. Constant pointer to constant integer
    const int* const regPtr3 = &statusReg;

    cout << "Status Register: " << *regPtr3 << endl;

    // Cannot repoint the pointer
    // regPtr3 = &dataReg;  // ERROR: assignment of read-only variable

    // Cannot modify the value
    // *regPtr3 = 40;       // ERROR: assignment of read-only location

    return 0;
}
