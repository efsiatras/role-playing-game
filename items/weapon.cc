#include <iostream>
#include "weapon.h"

using namespace std;

Weapon::Weapon(string n, int pr, int minL, int dam, bool handsR):Item(n,pr,minL),damage(dam),handsReq(handsR){	//Constructor of the class
	
}

Weapon::~Weapon(){	//Destructor of the class
	
}

void Weapon::displayName() const {
	Item::displayName();

	if (handsReq == 0) {
		cout << " (One-handed ";
	}

	else { // 'handsReq == 1'

		cout << " (Two-handed ";
	}

	cout << "Weapon)";
}

void Weapon::displayStats() const {
	Item::displayStats();

	cout << "Damage: " << damage << endl;
	cout << "Requires: ";
	if (handsReq == 0) {
		cout << "One hand" << endl;
	}

	else { // 'handsReq == 1'

		cout << "Two hands" << endl;
	}
}

void Weapon::displayStatsSellBack() const {
	Item::displayStatsSellBack();

	cout << "Damage: " << damage << endl;
	cout << "Requires: ";
	if (handsReq == 0) {
		cout << "One hand" << endl;
	}

	else { // 'handsReq == 1'

		cout << "Two hands" << endl;
	}
}

int Weapon::get_damage() const {

	return damage;
}

int Weapon::get_handsReq() const {

	return handsReq;
}