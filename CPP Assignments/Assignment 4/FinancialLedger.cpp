//============================================================================
// Name        : FinancialLedger.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <utility>

using namespace std;

class LedgerEntry {
private:
    string description;
    double* amounts;
    int days;

    static int totalEntries;

public:

    // Constructor
    LedgerEntry(const string& desc, int days)
        : description(desc), days(days)
    {
        amounts = new double[days];

        for (int i = 0; i < days; i++) {
            amounts[i] = 0.0;
        }

        totalEntries++;

        cout << "[LedgerEntry Created] "
             << description << " (" << days << " days)" << endl;
    }

    // Copy Constructor - Deep Copy
    LedgerEntry(const LedgerEntry& other)
        : description(other.description),
          days(other.days)
    {
        amounts = new double[days];

        for (int i = 0; i < days; i++) {
            amounts[i] = other.amounts[i];
        }

        totalEntries++;

        cout << "[Copy Constructor] "
             << description << endl;
    }

    // Move Constructor
    LedgerEntry(LedgerEntry&& other) noexcept
        : description(move(other.description)),
          amounts(other.amounts),
          days(other.days)
    {
        other.amounts = nullptr;
        other.days = 0;

        totalEntries++;

        cout << "[Move Constructor] Ownership transferred from: "
             << description << endl;
    }

    // Copy Assignment Operator
    LedgerEntry& operator=(const LedgerEntry& other)
    {
        if (this != &other) {

            double* newAmounts = new double[other.days];

            for (int i = 0; i < other.days; i++) {
                newAmounts[i] = other.amounts[i];
            }

            delete[] amounts;

            description = other.description;
            days = other.days;
            amounts = newAmounts;
        }

        return *this;
    }

    // Move Assignment Operator
    LedgerEntry& operator=(LedgerEntry&& other) noexcept
    {
        if (this != &other) {

            delete[] amounts;

            description = move(other.description);
            amounts = other.amounts;
            days = other.days;

            other.amounts = nullptr;
            other.days = 0;

            cout << "[Move Assignment] Ownership transferred from: "
                 << description << endl;
        }

        return *this;
    }

    // Destructor
    ~LedgerEntry()
    {
        delete[] amounts;
        totalEntries--;

        cout << "[Destructor] "
             << description << " destroyed" << endl;
    }

    // Operator +
    // Adds corresponding daily amounts
    LedgerEntry operator+(const LedgerEntry& other) const
    {
        if (days != other.days) {
            throw invalid_argument(
                "Cannot add ledgers with different number of days"
            );
        }

        LedgerEntry result(
            description + " + " + other.description,
            days
        );

        for (int i = 0; i < days; i++) {
            result.amounts[i] = amounts[i] + other.amounts[i];
        }

        return result;
    }

    // Operator ==
    // Compare total amounts
    bool operator==(const LedgerEntry& other) const
    {
        if (days != other.days) {
            return false;
        }

        double total1 = 0;
        double total2 = 0;

        for (int i = 0; i < days; i++) {
            total1 += amounts[i];
            total2 += other.amounts[i];
        }

        return total1 == total2;
    }

    // Operator >
    // Compare total amounts
    bool operator>(const LedgerEntry& other) const
    {
        double total1 = 0;
        double total2 = 0;

        for (int i = 0; i < days; i++) {
            total1 += amounts[i];
            total2 += other.amounts[i];
        }

        return total1 > total2;
    }

    // Non-const [] operator
    double& operator[](int index)
    {
        if (index < 0 || index >= days) {
            throw out_of_range("LedgerEntry index out of range");
        }

        return amounts[index];
    }

    // Const [] operator
    const double& operator[](int index) const
    {
        if (index < 0 || index >= days) {
            throw out_of_range("LedgerEntry index out of range");
        }

        return amounts[index];
    }

    // Friend << operator
    friend ostream& operator<<(ostream& out,
                               const LedgerEntry& entry);

    // Friend >> operator
    friend istream& operator>>(istream& in,
                               LedgerEntry& entry);

    // Static member getter
    static int getTotalEntries()
    {
        return totalEntries;
    }
};


// Definition of static member
int LedgerEntry::totalEntries = 0;


// Stream insertion operator <<
ostream& operator<<(ostream& out,
                     const LedgerEntry& entry)
{
    out << entry.description << " : [";

    for (int i = 0; i < entry.days; i++) {

        out << fixed << setprecision(2)
            << entry.amounts[i];

        if (i < entry.days - 1) {
            out << ", ";
        }
    }

    double total = 0;

    for (int i = 0; i < entry.days; i++) {
        total += entry.amounts[i];
    }

    out << "] Total: "
        << fixed << setprecision(2)
        << total;

    return out;
}


// Stream extraction operator >>
istream& operator>>(istream& in,
                    LedgerEntry& entry)
{
    for (int i = 0; i < entry.days; i++) {
        in >> entry.amounts[i];
    }

    return in;
}


int main()
{
    // ==========================================
    // Objective 1 - Constructor & Deep Copy
    // ==========================================

    LedgerEntry jan("January Sales", 5);

    jan[0] = 1200.50;
    jan[1] = 3400.00;
    jan[2] = 800.75;
    jan[3] = 2100.00;
    jan[4] = 650.25;


    LedgerEntry feb("February Sales", 5);

    feb[0] = 900.00;
    feb[1] = 2200.50;
    feb[2] = 1750.00;
    feb[3] = 3000.00;
    feb[4] = 475.50;


    cout << jan << endl;
    cout << feb << endl;


    // ==========================================
    // Objective 2 - Operator +
    // ==========================================

    LedgerEntry combined = jan + feb;

    cout << "Combined: "
         << combined << endl;


    // ==========================================
    // Objective 3 - Relational Operators
    // ==========================================

    cout << "Jan == Feb : "
         << (jan == feb ? "Yes" : "No")
         << endl;

    cout << "Jan > Feb : "
         << (jan > feb ? "Yes" : "No")
         << endl;


    // ==========================================
    // Objective 4 - Move Constructor
    // ==========================================

    LedgerEntry moved = move(jan);

    cout << "After move, jan.amounts is null: "
         << (jan[0] ? "NO" : "YES")
         << endl;

    cout << "Moved entry: "
         << moved << endl;


    // ==========================================
    // Objective 5 - Move Assignment
    // ==========================================

    LedgerEntry q1("Q1 Total", 5);

    q1 = move(feb);

    cout << "Q1 (moved from feb): "
         << q1 << endl;


    // ==========================================
    // Objective 6 - Static Member
    // ==========================================

    cout << "Live LedgerEntry objects: "
         << LedgerEntry::getTotalEntries()
         << endl;


    return 0;
}
