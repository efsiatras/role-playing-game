#include <iostream>
#include "icespell.h"

using namespace std;

IceSpell::IceSpell(string n, int pr, int hLR, int minD, int maxD, int mPR, int rODam, int ro):Spell(n,pr,hLR,minD,maxD,mPR, "icespell"),redOppDam(rODam),rounds(ro){	//Constructor of the class
	
}

IceSpell::~IceSpell(){	//Destructor of the class
	
}

void IceSpell::get_info(int& eff, int& rou) const {
	eff = redOppDam;
	rou = rounds;
}

void IceSpell::displayName() const {
	Spell::displayName();

	cout << " (Ice Spell)";
}

void IceSpell::displayStats() const {
	Spell::displayStats();

	cout << "Effect: -" << redOppDam << " opponent's damage" << endl;
	cout << "Duration: " <<  rounds << " rounds" << endl;
}

void IceSpell::displayStatsSellBack() const {
	Spell::displayStatsSellBack();

	cout << "Effect: -" << redOppDam << " opponent's damage" << endl;
	cout << "Duration: " <<  rounds << " rounds" << endl;
}