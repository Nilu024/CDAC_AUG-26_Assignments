//============================================================================
// Name        : InventoryManagementSystem.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

class Product{

private:
	int productId;
	string name;
	double price;
	int quantity;

public:

	 // Read all fields from user
	void acceptDetails(){
		cout << "Enter details = product id, name, price, quantity : ";
		cin >> productId >> name >> price >> quantity ;
	}

	 // Print formatted product info
	void displayDetails() const{
		cout << "\n" << "Product ID: " << productId << "\n"
				<< "Name: " << name << "\n"
				<< "Price: " << price << "\n"
				<< "Qyantity: " << quantity << endl;

	}

	 // price * quantity
	double totalValue() const{
		return price * quantity;
	}

	 // true if quantity < threshold
	bool isLowStock(int threshold) const{
		return quantity < threshold;
	}
};

int main() {

	Product p[5];

	for(int i = 0; i < 5; i++){
		p[i].acceptDetails();
	}

	for(int i = 0; i < 5; i++){
			p[i].displayDetails();
		}

	int highestInd = 0;
	for(int i = 0; i < 5; i++){
		if(p[i].totalValue() > p[highestInd].totalValue()) {
			highestInd = i;
		}
	}

	cout << "Highest Value Product : ";
	p[highestInd].displayDetails();


	int threshold;
	cout << "Enter low stock threshold: ";
	cin >> threshold;

	for(int i = 0; i < 5; i++){
		if(p[i].isLowStock(threshold)){
			p[i].displayDetails();
		}
	}

	return 0;
}
