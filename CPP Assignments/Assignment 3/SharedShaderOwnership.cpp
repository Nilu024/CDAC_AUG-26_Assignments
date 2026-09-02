//============================================================================
// Name        : SharedShaderOwnership.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <memory>
using namespace std;

class Shader{
private:
	 string name;
	 string type;

public:
	 Shader(string name, string type){
		 this->name = name;
		 this->type = type;
		 cout << "[Shader Compiled]" << endl;
	 }

	 int getReferenceCount(const shared_ptr<Shader>& shader){
		 return shader.use_count();
	 }

	 void display() const{
		 cout << left;
		 cout << setw(20) << "Shader Name" << ": " << name << endl;
		 cout << setw(20) << "Shader Type" << ": " << type << endl;
	 }

	 ~Shader(){
		 cout << "[Shader Destroyed]" << endl;
	 }
};

int main() {

	  cout << "========================================" << endl;
	    cout << "       GAME ASSET MANAGER" << endl;
	    cout << "       Part B - shared_ptr" << endl;
	    cout << "========================================" << endl;

	    // 1. Create Shader using shared_ptr
	    cout << "\nCreating Shader..." << endl;

	    auto shader = make_shared<Shader>("main_vert", "vertex");

	    shader->display();

	    // Reference count = 1
	        cout << "\n--- Initial Reference Count ---" << endl;
	        cout << "Ref count : " << shader.use_count() << endl;

	        {
	            // 2. Renderer shares the Shader
	            auto rendererRef = shader;

	            // Reference count = 2
	            cout << "\n--- Renderer Shares Shader ---" << endl;
	            cout << "Ref count : " << shader.use_count() << endl;

	            // Editor also shares the Shader
	            auto editorRef = shader;

	            // Reference count = 3
	            cout << "\n--- Editor Shares Shader ---" << endl;
	            cout << "Ref count : " << shader.use_count() << endl;

	            cout << "\nRenderer and Editor are using the same Shader." << endl;
	        }



	    cout << "\n--- After Block Ends ---" << endl;
	        cout << "Ref count : " << shader.use_count() << endl;

	        cout << "\n========================================" << endl;
	        cout << "Program Ending..." << endl;
	        cout << "========================================" << endl;


	return 0;
}
