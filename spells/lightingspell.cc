#include <iostream>
#include "lightingspell.h"

using namespace std;

LightingSpell::LightingSpell(string n, int pr, int hLR, int minD, int maxD, int mPR, int rOA, int ro):Spell(n,pr,hLR,minD,maxD,mPR, "lightingspell"),redOppAg(rOA),rounds(ro){
	
}

LightingSpell::~LightingSpell(){	//Destructor of the class
	
}

void LightingSpell::get_info(int& eff, int& rou) const {
	eff = redOppAg;
	rou = rounds;
}

void LightingSpell::displayName() const {
	Spell::displayName();

	cout << " (Lighting Spell)";
}

void LightingSpell::displayStats() const {
	Spell::displayStats();

	cout << "Effect: -" << redOppAg << " opponent's agility" << endl;
	cout << "Duration: " <<  rounds << " rounds" << endl;
}

void LightingSpell::displayStatsSellBack() const { 
	Spell::displayStatsSellBack();

	cout << "Effect: -" << redOppAg << " opponent's agility" << endl;
	cout << "Duration: " <<  rounds << " rounds" << endl;
}