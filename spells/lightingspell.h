#ifndef LIGHTINGSPELL_H
#define LIGHTINGSPELL_H

#include <iostream>
#include "spell.h"

class LightingSpell: public Spell {

private:

	int redOppAg;
	int rounds;	
	
public:

	LightingSpell(std::string n, int pr, int hLR, int minD, int maxD, int mPR, int rOA, int ro);
	~LightingSpell();

	void get_info(int&, int&) const;

	void displayName() const;
	void displayStats() const;
	void displayStatsSellBack() const;
		
};
#endif
