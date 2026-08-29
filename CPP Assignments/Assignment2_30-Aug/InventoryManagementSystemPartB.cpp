//============================================================================
// Name        : InventoryManagementSystemPartB.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

double reorderCost(int qty, double unitPrice){
	return qty * unitPrice;
}

double reorderCost(double qty, double unitPrice){
	return qty * unitPrice;
}

double reorderCost(int qty, double unitPrice, double taxRate){
	double cost = qty * unitPrice;
	return cost + (cost * taxRate / 100);
}

double applyDiscount(double price, double discountPercent = 10.0){
	return price - (price * discountPercent / 100);
}

int main() {

	double cost1 = reorderCost(10, 50.0);

	double cost2 = reorderCost(2.5, 100.0);

	double cost3 = reorderCost(10, 50.0, 18.0);

	double price1 = applyDiscount(1000.0, 20.0);

	double price2 = applyDiscount(1000.0);

	 cout << "===== RESTOCKING COST REPORT =====" << endl;

	    cout << "Integer Quantity Cost    : Rs. "
	         << cost1 << endl;

	    cout << "Fractional Quantity Cost : Rs. "
	         << cost2 << endl;

	    cout << "Cost With 18% Tax        : Rs. "
	         << cost3 << endl;

	    cout << "Price After 20% Discount : Rs. "
	         << price1 << endl;

	    cout << "Price After Default 10%  : Rs. "
	         << price2 << endl;

	return 0;
}
