#include <iostream>
#include <string>
#include <cstdlib>

#include "spell.h"

using namespace std;

Spell::Spell(string n, int pr, int minL, int minD, int maxD, int mPR, string ident):name(n),price(pr),minLvl(minL),minDam(minD),maxDam(maxD),magicPowReq(mPR),identity(ident) {	//Constructor of the class
	
}

Spell::~Spell() {	//Destructor of the class
	
}

void Spell::displayName() const {
	
	cout << name;
}

void Spell::displayStats() const {
	cout << "Price: " << price << endl;
	cout << "Minimum level: " << minLvl << endl;
	cout << "Minimum damage: " << minDam << endl;
	cout << "Maximum damage: " << maxDam << endl;
	cout << "Magic power required: " << magicPowReq << endl;
	cout << "Type of spell: ";
	if (identity == "firespell") {
		cout << "FireSpell" << endl;
	}

	else if (identity == "icespell") {
		cout << "IceSpell" << endl;
	}

	else if (identity == "lightingspell") {
		cout << "LightingSpell" << endl;
	}
}

void Spell::displayStatsSellBack() const { // Function that prints stats in case of selling back to market
	cout << "Price: " << (price / 2) << endl;
	cout << "Minimum level: " << minLvl << endl;
	cout << "Minimum damage: " << minDam << endl;
	cout << "Maximum damage: " << maxDam << endl;
	cout << "Magic power required: " << magicPowReq << endl;
	cout << "Type of spell: ";
	if (identity == "firespell") {
		cout << "FireSpell" << endl;
	}

	else if (identity == "icespell") {
		cout << "IceSpell" << endl;
	}

	else if (identity == "lightingspell") {
		cout << "LightingSpell" << endl;
	}
}

void Spell::set_price(int pr) {	//Function that sets spell's price
	
	price=pr;
	
}

string Spell::get_name() const {	//Function that gets spell's name
	
	return name;

}
	
int Spell::get_price() const {	//Function that gets spell's price

	return price;
	
}

int Spell::get_minLvl() const {	//Function that gets spell's minimum level

	return minLvl;
	
}

string Spell::get_identity() const {

	return identity;
}

int Spell::get_damage() const {

	return rand() % (maxDam + 1 - minDam) + minDam;
}

int Spell::get_cost() const {

	return magicPowReq;
}