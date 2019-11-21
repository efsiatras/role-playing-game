#include <iostream>

#include "spirit.h"

using namespace std;

Spirit::Spirit(const string& nam, const int& lev, const int& health, const int& min, const int& max, const int& def, const int& agi) 
: Monster(nam, lev, health, min, max, def, agi) {
	
	cout << "Summoning a Spirit" << endl << endl;
}

Spirit::Spirit(const string& nam, const int& lev) 
: Monster(nam, lev, 200 + 100 * (lev - 1), 20 + 20 * (lev - 1), 40 + 20 * (lev - 1), 10 + 5 * (lev - 1), 30 + 10 * (lev - 1)) {
	
	cout << "Summoning a Spirit" << endl << endl;
}

Spirit::~Spirit() {

	//cout << "Destroying a Spirit" << endl;
}

void Spirit::displayName() const {
	Living::displayName();

	cout << " (Spirit)";
}