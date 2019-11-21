#include <iostream>

#include "living.h"

using namespace std;

Living::Living(const string& nam, const int& lev, const int& health) 
: name(nam), level(lev), healthPower(health), maxHealthPower(health) {
	
	//cout << "Summoning a Living" << endl;
}

Living::~Living() {

	//cout << "Destroying a Living" << endl << endl;
}

void Living::displayName() const {
	cout << name;
}

void Living::displayStats() const {
	cout << "Level: " << level << endl;
	cout << "Health power: " << healthPower << "/" << maxHealthPower << endl;
}

string Living::get_name()const{
	
	return name;
}

int Living::get_healthPower() const {

	return healthPower;
}

int Living::get_maxHealthPower() const {

	return maxHealthPower;
}

int Living::get_level() const {

	return level;
}

void Living::regenerateHP(const int&regen) {
	if ((healthPower + regen) > maxHealthPower) {

		healthPower = maxHealthPower;
	}

	else {

		healthPower += regen;
	}
}

void Living::gainMaxHealthPower(const int& health) {
	
	maxHealthPower += health;
}

void Living::gainLevel(const int& lev) {

	level += lev;
}

void Living::loseHP(const int& dam) {
	if ((healthPower - dam) < 0) {

		healthPower = 0;
	}

	else {

		healthPower -= dam;
	}
}

void Living::respawn() {
	if (healthPower == 0) {

		healthPower = (maxHealthPower / 2);
	}
}