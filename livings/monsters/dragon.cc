#include <iostream>

#include "dragon.h"

using namespace std;

Dragon::Dragon(const string& nam, const int& lev, const int& health, const int& min, const int& max, const int& def, const int& agi) 
: Monster(nam, lev, health, min, max, def, agi) {
	
	cout << "Summoning a Dragon" << endl << endl;
}

Dragon::Dragon(const string& nam, const int& lev) 
: Monster(nam, lev, 200 + 100 * (lev - 1), 40 + 30 * (lev - 1), 60 + 30 * (lev - 1), 10 + 5 * (lev - 1), 20 + 5 * (lev - 1)) {
	
	cout << "Summoning a Dragon" << endl << endl;
}

Dragon::~Dragon() {

	//cout << "Destroying a Dragon" << endl;
}

void Dragon::displayName() const {
	Living::displayName();

	cout << " (Dragon)";
}