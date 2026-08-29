//============================================================================
// Name        : HospitalPatientRegistry.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <string>

using namespace std;

class Patient {

private:
    int patientId;
    string name;
    int age;
    string ward;
    const string bloodGroup;

public:

    Patient()
        : patientId(0),
          name("Unknown"),
          age(0),
          ward("General"),
          bloodGroup("O+") {

        cout << "[Constructor] Default patient registered."
             << endl;
    }

    Patient(int id, const string& name)
        : patientId(id),
          name(name),
          age(0),
          ward("Emergency"),
          bloodGroup("O+") {

        cout << "[Constructor] Emergency: "
             << name << endl;
    }

    Patient(int id,
            const string& name,
            int age,
            const string& ward,
            const string& bg)
        : patientId(id),
          name(name),
          age(age),
          ward(ward),
          bloodGroup(bg) {

        cout << "[Constructor] Full admission: "
             << name << endl;
    }

    ~Patient() {

        cout << "[Destructor] Patient "
             << name
             << " discharged."
             << endl;
    }

    void displayRecord() const {

        cout << "Patient Record:" << endl;
        cout << " ID : " << patientId << endl;
        cout << " Name : " << name << endl;
        cout << " Age : " << age << endl;
        cout << " Ward : " << ward << endl;
        cout << " Blood Grp : " << bloodGroup << endl;
        cout << endl;
    }

    void transferWard(const string& newWard) {

        cout << "Ward Transfer: "
             << name
             << " -> "
             << newWard
             << endl;

        ward = newWard;
    }
};


int main() {

    cout << "===== STACK OBJECTS =====" << endl;

    Patient meera(
        1001,
        "Meera Joshi",
        34,
        "Cardiology",
        "B+"
    );

    Patient raj(
        1002,
        "Raj Patel"
    );

    Patient defaultPatient;


    cout << endl;

    cout << "===== DYNAMIC ARRAY =====" << endl;

    Patient* patients = new Patient[4];


    cout << endl;

    cout << "===== PATIENT RECORDS =====" << endl;

    for (int i = 0; i < 4; i++) {

        patients[i].displayRecord();
    }

    cout << "===== WARD TRANSFER =====" << endl;

    patients[1].transferWard("ICU");

    cout << endl;
    cout << "===== UPDATED RECORD =====" << endl;

    patients[1].displayRecord();

    cout << "===== DELETE DYNAMIC ARRAY =====" << endl;

    delete[] patients;


    cout << endl;
    cout << "===== END OF MAIN =====" << endl;


    return 0;
}
