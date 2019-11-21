#include <iostream>
#include "armor.h"

using namespace std;

Armor::Armor(string n, int pr, int minL, int reD):Item(n,pr,minL),reDam(reD){	//Constructor of the class
	
}

Armor::~Armor(){	//Destructor of the class
	
}

void Armor::displayName() const {
	Item::displayName();

	cout << " (Armor)";
}

void Armor::displayStats() const {
	Item::displayStats();

	cout << "Defence: " << reDam << endl;
}

void Armor::displayStatsSellBack() const {
	Item::displayStatsSellBack();

	cout << "Defence: " << reDam << endl;
}

int Armor::get_defence() const {

	return reDam;
}