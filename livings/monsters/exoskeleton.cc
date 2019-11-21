#include <iostream>

#include "exoskeleton.h"

using namespace std;

Exoskeleton::Exoskeleton(const string& nam, const int& lev, const int& health, const int& min, const int& max, const int& def, const int& agi) 
: Monster(nam, lev, health, min, max, def, agi) {
	
	cout << "Summoning a Exoskeleton" << endl << endl;
}

Exoskeleton::Exoskeleton(const string& nam, const int& lev) 
: Monster(nam, lev, 200 + 100 * (lev - 1), 20 + 20 * (lev - 1), 40 + 20 * (lev - 1), 20 + 10 * (lev - 1), 20 + 5 * (lev - 1)) {
	
	cout << "Summoning a Exoskeleton" << endl << endl;
}

Exoskeleton::~Exoskeleton() {

	//cout << "Destroying a Exoskeleton" << endl;
}

void Exoskeleton::displayName() const {
	Living::displayName();

	cout << " (Exoskeleton)";
}