//============================================================================
// Name        : VehicleFleetManagement.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// ============================================================
// BASE CLASS : Vehicle
// ============================================================

class Vehicle {
protected:
    string registrationNo;
    string ownerName;
    int yearOfManufacture;
    double kmDriven;

public:

    // Constructor
    Vehicle(const string& reg,
            const string& owner,
            int year,
            double km)
        : registrationNo(reg),
          ownerName(owner),
          yearOfManufacture(year),
          kmDriven(km)
    {
        cout << "[Vehicle Constructor] "
             << registrationNo << " : "
             << ownerName << endl;
    }

    // Pure virtual function
    virtual double fuelCost(double kmToTravel) const = 0;

    // Virtual function
    virtual void describe() const
    {
        cout << "Registration : " << registrationNo << endl;
        cout << "Owner        : " << ownerName << endl;
        cout << "Year         : " << yearOfManufacture << endl;
        cout << "Km Driven    : " << kmDriven << endl;
    }

    // Pure virtual function
    virtual string vehicleType() const = 0;

    // Virtual destructor
    virtual ~Vehicle()
    {
        cout << "[Vehicle Destructor] "
             << registrationNo << endl;
    }

    // Getter
    double getKmDriven() const
    {
        return kmDriven;
    }

    // Getter
    string getRegNo() const
    {
        return registrationNo;
    }

    // Getter
    string getOwnerName() const
    {
        return ownerName;
    }
};


// ============================================================
// CAR : Single Inheritance
// ============================================================

class Car : public Vehicle {
private:
    string fuelType;
    double mileageKmpl;

public:

    Car(const string& reg,
        const string& owner,
        int year,
        double km,
        const string& fuel,
        double mileage)
        : Vehicle(reg, owner, year, km),
          fuelType(fuel),
          mileageKmpl(mileage)
    {
        cout << "[Car Constructor] "
             << registrationNo << endl;
    }

    // Function overriding
    double fuelCost(double kmToTravel) const override
    {
        double fuelPrice;

        if (fuelType == "Petrol")
            fuelPrice = 106.00;
        else
            fuelPrice = 93.00;

        return (kmToTravel / mileageKmpl) * fuelPrice;
    }

    // Function overriding
    string vehicleType() const override
    {
        return "Car";
    }

    // Function overriding
    void describe() const override
    {
        Vehicle::describe();

        cout << "Fuel Type    : " << fuelType << endl;
        cout << "Mileage      : " << mileageKmpl
             << " km/L" << endl;
    }

    ~Car() override
    {
        cout << "[Car Destructor] "
             << registrationNo << endl;
    }

    string getFuelType() const
    {
        return fuelType;
    }
};


// ============================================================
// TRUCK : Single Inheritance
// ============================================================

class Truck : public Vehicle {
protected:
    double payloadCapacityTons;
    double fuelEfficiencyKmpl;

public:

    Truck(const string& reg,
          const string& owner,
          int year,
          double km,
          double payload,
          double efficiency)
        : Vehicle(reg, owner, year, km),
          payloadCapacityTons(payload),
          fuelEfficiencyKmpl(efficiency)
    {
        cout << "[Truck Constructor] "
             << registrationNo << endl;
    }

    // Function overriding
    double fuelCost(double kmToTravel) const override
    {
        // Efficiency drops 5% per ton of payload
        double effectiveEfficiency =
            fuelEfficiencyKmpl *
            (1.0 - (0.05 * payloadCapacityTons));

        return (kmToTravel / effectiveEfficiency) * 93.00;
    }

    // Function overriding
    string vehicleType() const override
    {
        return "Truck";
    }

    // Function overriding
    void describe() const override
    {
        Vehicle::describe();

        cout << "Payload      : "
             << payloadCapacityTons
             << " tons" << endl;

        cout << "Efficiency   : "
             << fuelEfficiencyKmpl
             << " km/L" << endl;
    }

    ~Truck() override
    {
        cout << "[Truck Destructor] "
             << registrationNo << endl;
    }
};


// ============================================================
// ELECTRIC TRUCK : Multilevel Inheritance
//
// Vehicle -> Truck -> ElectricTruck
// ============================================================

class ElectricTruck : public Truck {
private:
    double batteryCapacityKWh;
    double rangePerChargeKm;

public:

    ElectricTruck(const string& reg,
                  const string& owner,
                  int year,
                  double km,
                  double payload,
                  double efficiency,
                  double battery,
                  double range)
        : Truck(reg, owner, year, km,
                payload, efficiency),
          batteryCapacityKWh(battery),
          rangePerChargeKm(range)
    {
        cout << "[ElectricTruck Constructor] "
             << registrationNo << endl;
    }

    // Function overriding
    double fuelCost(double kmToTravel) const override
    {
        return (kmToTravel / rangePerChargeKm)
               * batteryCapacityKWh
               * 9.50;
    }

    // Function overriding
    string vehicleType() const override
    {
        return "Electric Truck";
    }

    // Function overriding
    void describe() const override
    {
        Vehicle::describe();

        cout << "Payload      : "
             << payloadCapacityTons
             << " tons" << endl;

        cout << "Battery      : "
             << batteryCapacityKWh
             << " kWh" << endl;

        cout << "Range        : "
             << rangePerChargeKm
             << " km/charge" << endl;
    }

    ~ElectricTruck() override
    {
        cout << "[ElectricTruck Destructor] "
             << registrationNo << endl;
    }

    double getBatteryCapacity() const
    {
        return batteryCapacityKWh;
    }
};


// ============================================================
// VAN : Hierarchical Inheritance
//
// Vehicle -> Van
// ============================================================

class Van : public Vehicle {
private:
    int seatingCapacity;
    double mileageKmpl;

public:

    Van(const string& reg,
        const string& owner,
        int year,
        double km,
        int seating,
        double mileage)
        : Vehicle(reg, owner, year, km),
          seatingCapacity(seating),
          mileageKmpl(mileage)
    {
        cout << "[Van Constructor] "
             << registrationNo << endl;
    }

    // Function overriding
    double fuelCost(double kmToTravel) const override
    {
        // Standard petrol calculation
        return (kmToTravel / mileageKmpl) * 106.00;
    }

    // Function overriding
    string vehicleType() const override
    {
        return "Van";
    }

    // Function overriding
    void describe() const override
    {
        Vehicle::describe();

        cout << "Seats        : "
             << seatingCapacity << endl;

        cout << "Mileage      : "
             << mileageKmpl
             << " km/L" << endl;
    }

    ~Van() override
    {
        cout << "[Van Destructor] "
             << registrationNo << endl;
    }
};


// ============================================================
// FLEET REPORT
// ============================================================

void printFleetReport(const vector<Vehicle*>& fleet,
                      double tripKm)
{
    cout << endl;
    cout << "============================================================"
         << endl;

    cout << "       FLEET REPORT - Trip Distance: "
         << tripKm << " km" << endl;

    cout << "============================================================"
         << endl;

    // Table header
    cout << left
         << setw(15) << "Registration"
         << setw(20) << "Type"
         << setw(25) << "Owner"
         << setw(15) << "Km Driven"
         << endl;

    cout << "---------------------------------------------------------------------"
         << endl;


    // --------------------------------------------------------
    // Display all vehicles
    // --------------------------------------------------------

    for (Vehicle* vehicle : fleet)
    {
        cout << left
             << setw(15) << vehicle->getRegNo()
             << setw(20) << vehicle->vehicleType()
             << setw(25) << vehicle->getOwnerName()
             << setw(15) << fixed
             << setprecision(0)
             << vehicle->getKmDriven()
             << endl;
    }


    // --------------------------------------------------------
    // Fuel / Charge Cost
    // --------------------------------------------------------

    cout << endl;

    cout << "============================================================"
         << endl;

    cout << "             FUEL / CHARGE COST ESTIMATE"
         << endl;

    cout << "============================================================"
         << endl;


    double minimumCost = 1e9;
    Vehicle* mostEfficient = nullptr;


    for (Vehicle* vehicle : fleet)
    {
        double cost = vehicle->fuelCost(tripKm);

        cout << fixed << setprecision(2);

        cout << vehicle->getRegNo()
             << " (" << vehicle->vehicleType()
             << ") : Rs. "
             << cost;


        // ----------------------------------------------------
        // Identify fuel type for Car
        // ----------------------------------------------------

        if (Car* car = dynamic_cast<Car*>(vehicle))
        {
            cout << " (" << car->getFuelType()
                 << ")";
        }


        // ----------------------------------------------------
        // Identify Electric Truck
        // ----------------------------------------------------

        if (ElectricTruck* electric =
                dynamic_cast<ElectricTruck*>(vehicle))
        {
            cout << " [Battery: 85% charged]";
        }


        cout << endl;


        // Find minimum cost
        if (cost < minimumCost)
        {
            minimumCost = cost;
            mostEfficient = vehicle;
        }
    }


    // --------------------------------------------------------
    // Most Efficient Vehicle
    // --------------------------------------------------------

    cout << endl;

    if (mostEfficient != nullptr)
    {
        cout << "Most Efficient Vehicle: "
             << mostEfficient->getRegNo()
             << " ("
             << mostEfficient->vehicleType()
             << ") - Rs. "
             << fixed << setprecision(2)
             << minimumCost
             << " for "
             << tripKm
             << " km"
             << endl;
    }
}


// ============================================================
// MAIN
// ============================================================

int main()
{
    // ========================================================
    // PART B
    // Constructor / Destructor Execution Order
    // ========================================================

    cout << "========== CONSTRUCTOR / DESTRUCTOR TEST =========="
         << endl;

    {
        ElectricTruck electricTruck(
            "V-ET001",
            "Green Logistics",
            2024,
            89000,
            5.0,
            4.0,
            85.0,
            400.0
        );

        cout << endl;

        electricTruck.describe();
    }

    cout << endl;


    // ========================================================
    // PART C
    // Polymorphic Fleet
    // ========================================================

    vector<Vehicle*> fleet;


    // Car
    fleet.push_back(
        new Car(
            "KA01AA001",
            "Ramesh Kumar",
            2022,
            45200,
            "Petrol",
            18.75
        )
    );


    // Truck
    fleet.push_back(
        new Truck(
            "MH04BB002",
            "Shyam Logistics",
            2020,
            123500,
            3.0,
            4.5
        )
    );


    // Electric Truck
    fleet.push_back(
        new ElectricTruck(
            "GJ07CC003",
            "Green Fleet Co",
            2024,
            89000,
            2.0,
            4.0,
            85.0,
            400.0
        )
    );


    // Van
    fleet.push_back(
        new Van(
            "DL05DD004",
            "City Transport",
            2021,
            67800,
            8,
            15.0
        )
    );


    // Another Car
    fleet.push_back(
        new Car(
            "MH12EE005",
            "Amit Services",
            2023,
            32100,
            "Diesel",
            20.0
        )
    );


    // ========================================================
    // Generate Fleet Report
    // ========================================================

    printFleetReport(fleet, 200.0);


    // ========================================================
    // BONUS - dynamic_cast Safety Check
    // ========================================================

    cout << endl;

    cout << "========== dynamic_cast SAFETY CHECK =========="
         << endl;

    for (Vehicle* vehicle : fleet)
    {
        if (ElectricTruck* electric =
                dynamic_cast<ElectricTruck*>(vehicle))
        {
            cout << "Found Electric Truck: "
                 << electric->getRegNo()
                 << endl;
        }
        else if (Car* car =
                     dynamic_cast<Car*>(vehicle))
        {
            cout << "Found Car: "
                 << car->getRegNo()
                 << endl;
        }
    }


    // ========================================================
    // CLEANUP
    // ========================================================

    cout << endl;

    cout << "========== CLEANUP =========="
         << endl;

    for (Vehicle* vehicle : fleet)
    {
        delete vehicle;
    }

    fleet.clear();


    cout << endl;
    cout << "Program finished successfully."
         << endl;

    return 0;
}
