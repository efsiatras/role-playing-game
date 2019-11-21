#include <iostream>

#include "paladin.h"

using namespace std;

Paladin::Paladin(const string& nam, const int& lev, const int& health, const int& magic, const int& stren, const int& dext, const int& agil, const int& mon, const int& exp) 
: Hero(nam, lev, health, magic, stren, dext, agil, mon, exp) {
	
	cout << "Summoning a Paladin" << endl << endl;
}

Paladin::Paladin(const string& nam, const int& lev) 
: Hero(nam, lev, 200 + 100 * (lev - 1), 200 + 100 * (lev - 1), 30 + 10 * (lev - 1), 30 + 10 * (lev - 1), 20 + 5 * (lev - 1), 0, 500 * lev + 50 * (lev - 1)) {
	
	cout << "Summoning a Paladin" << endl << endl;
}

Paladin::~Paladin() {

	//cout << "Destroying a Paladin" << endl;
}

void Paladin::displayName() const {
	Living::displayName();

	cout << " (Paladin)";
}

void Paladin::levelUp() {
	int levelUpExp = 500 * this->get_level() + 50 * (this->get_level() - 1); // Calculates experience needed to level up (double check)
	if (get_experience() > levelUpExp) {
		gainLevel(1);
		gainMaxHealthPower(100);
		regenerateHP(100);

		gainMaxMagicPower(100);
		regenerateMP(100);

		gainStrength(10);
		gainDexterity(10);
		gainAgility(5);

		displayName();
		cout << " reached level " << get_level() << "!" << endl;
	}
}