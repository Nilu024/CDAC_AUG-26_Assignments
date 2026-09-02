//============================================================================
// Name        : GameAssetManagerPartA.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//
//#include <iostream>
//#include <memory>
//using namespace std;
//
//class Texture{
//private:
//	string name;
//	int width;
//	int height;
//
//public:
//	Texture(string name, int width, int height){
//		this->name = name;
//		this->width = width;
//		this->height = height;
//
//		cout << "Texture Loaded..." << endl;
//	}
//
//	void display() const {
//		 cout << "Texture Name : " << name << endl;
//		 cout << "Dimensions   : " << width << " x " << height << endl;
//	}
//
//	~Texture(){
//		cout << "Texture Released..." << endl;
//	}
//};
//
//int main() {
//
//	auto tex1 = make_unique<Texture>("Player_Sprite", 512, 512);
//
//	tex1->display();
//
////	error: use of deleted function
////	 unique_ptr<Texture> tex2 = tex1;
//
//	unique_ptr<Texture> tex2 = move(tex1);
//
//	 cout << "tex1 is null: "
//	         << (tex1 == nullptr ? "YES" : "NO")
//	         << endl;
//
//	tex2->display();
//
//	return 0;
//}



#include <iostream>
#include <memory>
#include <iomanip>

using namespace std;

class Texture {

private:
    string name;
    int width;
    int height;

public:

    // Parameterized Constructor
    Texture(string name, int width, int height) {
        this->name = name;
        this->width = width;
        this->height = height;

        cout << "[Texture Loaded]" << endl;
    }

    // Display Texture Information
    void display() const {
        cout << left;
        cout << setw(20) << "Texture Name" << ": " << name << endl;
        cout << setw(20) << "Width"        << ": " << width << " px" << endl;
        cout << setw(20) << "Height"       << ": " << height << " px" << endl;
    }

    // Destructor
    ~Texture() {
        cout << "[Texture Released]" << endl;
    }
};

int main() {

    cout << "========================================" << endl;
    cout << "       GAME ASSET MANAGER" << endl;
    cout << "       Part A - unique_ptr" << endl;
    cout << "========================================" << endl;

    // Create Texture using unique_ptr
    cout << "\nCreating Texture..." << endl;

    auto tex1 = make_unique<Texture>("player_sprite", 512, 512);

    // Display Texture
    cout << "\n--- Texture Details ---" << endl;
    tex1->display();

    // Copying unique_ptr is NOT allowed
    // unique_ptr<Texture> tex2 = tex1;
    // Error: unique_ptr cannot be copied because it has exclusive ownership.

    // Transfer ownership using move()
    cout << "\n--- Transferring Ownership ---" << endl;

    unique_ptr<Texture> tex2 = move(tex1);

    // Check tex1
    cout << "tex1 is null : "
         << (tex1 == nullptr ? "YES" : "NO") << endl;

    // tex2 now owns the Texture
    cout << "\n--- New Owner (tex2) ---" << endl;
    tex2->display();

    cout << "\n========================================" << endl;
    cout << "Program Ending..." << endl;
    cout << "========================================" << endl;

    return 0;
}
