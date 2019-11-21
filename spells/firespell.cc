#include <iostream>
#include "firespell.h"

using namespace std;

FireSpell::FireSpell(string n, int pr, int hLR, int minD, int maxD, int mPR, int rODef, int ro):Spell(n,pr,hLR,minD,maxD,mPR, "firespell"),redOppDef(rODef),rounds(ro){	//Constructor of the class
	
}

FireSpell::~FireSpell(){	//Destructor of the class
	
}

void FireSpell::get_info(int& eff, int& rou) const {
	eff = redOppDef;
	rou = rounds;
}

void FireSpell::displayName() const {
	Spell::displayName();

	cout << " (Fire Spell)";
}

void FireSpell::displayStats() const {
	Spell::displayStats();

	cout << "Effect: -" << redOppDef << " opponent's defence" << endl;
	cout << "Duration: " <<  rounds << " rounds" << endl;
}

void FireSpell::displayStatsSellBack() const {
	Spell::displayStatsSellBack();

	cout << "Effect: -" << redOppDef << " opponent's defence" << endl;
	cout << "Duration: " <<  rounds << " rounds" << endl;
}