//============================================================================
// Name        : GameEngineEntitySystemPartC.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int R, C;

	cout << "Enter Rows: ";
	cin >> R;
	cout << "Enter Columns: ";
	cin >> C;

	int** row = new int*[R];
	for(int i = 0; i < R; i++){
		row[i] = new int[C];
	}

	cout << "Enter " << R*C << " Values: ";
	for (int i = 0; i < R; i++) {
	    for (int j = 0; j < C; j++) {
	    	int value;
	    	cin >> value;
	        row[i][j] = value;
	    }
	    cout << endl;
	}

	cout << "===== GAME MAP (" << R << " x " << C << ") =====" << endl;
	for (int i = 0; i < R; i++) {
	    for (int j = 0; j < C; j++) {
	        cout << row[i][j] << " ";
	    }
	    cout << endl;
	}

	cout <<"" << endl;
	cout << "Legend: 0=Grass 1=Water 2=Mountain 3=Forest 4=Dungeon " << endl;
	cout <<"" << endl;

	int grass = 0, water = 0, mountain = 0, forest = 0, dungeon = 0;
	for (int i = 0; i < R; i++) {
		    for (int j = 0; j < C; j++) {
		    	if(row[i][j] == 0){
		    		grass++;
		    	} else if(row[i][j] == 1){
		    		water++;
		    	} else if(row[i][j] == 2){
		    		mountain++;
		    	} else if(row[i][j] == 3){
		    		forest++;
		    	} else if(row[i][j] == 4){
		    		dungeon++;
		    	}
		    }
		}

	cout << "Tile Count: " << "\n"
			<< "Grass: " << grass << "\n"
			<< "Water: " << water << "\n"
			<< "Mountain: " << mountain << "\n"
			<< "Forest: " << forest << "\n"
			<< "Dungeon: " << dungeon << "\n" << endl;



	for (int i = 0; i < R; i++) {
	    delete[] row[i];
	}

	delete[] row;



	return 0;
}
