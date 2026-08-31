//============================================================================
// Name        : GameEngineEntitySystemPartB.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

namespace Physics {

// clamp a velocity
 double clamp(double val, double min, double max){
	 if(min < val){
		 return min;
	 }
	 if(max > val){
		 return max;
	 }
	 return val;
 }

 // linear interpolation for physics
 double lerp(double a, double b, double t){
	 return a + (b - a) * t;
 }

}

namespace GameMath {
// clamp an integer stat (health, level)
 int clamp(int val, int min, int max){
	 if(min < val){
	 		 return min;
	 	 }
	 	 if(max > val){
	 		 return max;
	 	 }
	 	 return val;
 }

 // lerp for UI animations
 double lerp(double a, double b, double t){
	 return a + (b - a) * t;
 }

}

int main() {

	cout << fixed << setprecision(2);

	//================================================= // Calling Physics::clamp() //=================================================
	double velocity = Physics::clamp( 120.5, 0.0, 100.0 );
	cout << "Physics Clamp : " << velocity << endl;

	//================================================= // Calling GameMath::clamp() //=================================================
	int health = GameMath::clamp( 120, 0, 100 );
	cout << "GameMath Clamp : " << health << endl;

	//================================================= // Calling Physics::lerp() //=================================================
	double physicsValue = Physics::lerp( 0.0, 100.0, 0.5 );
	cout << "Physics Lerp : " << physicsValue << endl;

	//================================================= // Calling GameMath::lerp() //=================================================
	double uiValue = GameMath::lerp( 10.0, 20.0, 0.25 );
	cout << "GameMath Lerp : " << uiValue << endl;


	//================================================= // Limited using namespace scope //=================================================
	{
		using namespace Physics; cout << endl;

		cout << "===== LIMITED USING NAMESPACE =====" << endl;

		// No Physics:: required inside this block
		double speed = clamp(150.0, 0.0, 100.0);
		double position = lerp(0.0, 200.0, 0.25);

		cout << "Physics Clamp : " << speed << endl;
		cout << "Physics Lerp : " << position << endl;
	}

		//================================================= // Outside the block, Physics namespace // must be specified again //=================================================
		double speed2 = Physics::clamp( 80.0, 0.0, 100.0 ); cout << endl;
		cout << "Outside Block Physics Clamp : " << speed2 << endl;

		return 0;
}
