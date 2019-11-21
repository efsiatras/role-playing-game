#ifndef FIRESPELL_H
#define FIRESPELL_H

#include <iostream>
#include <string>
#include "spell.h"

class FireSpell: public Spell {

private:

	int redOppDef;
	int rounds;
	
public:

	FireSpell(std::string n, int pr, int hLR, int minD, int maxD, int mPR, int rODef, int ro);
	~FireSpell();

	void get_info(int&, int&) const;
	
	void displayName() const;
	void displayStats() const;
	void displayStatsSellBack() const;
};
#endif
