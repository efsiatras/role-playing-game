#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <ctime>

#include "./grid/grid.h"

using namespace std;

int main() {
	srand (time(NULL)); 
	Grid game;

	if(!game.start()) {

		cout << "Bad input from file. Exiting..." << endl;
	}	
}

