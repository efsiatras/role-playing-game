#ifndef ICESPELL_H
#define ICESPELL_H

#include <iostream>
#include "spell.h"

class IceSpell: public Spell {

private:

	int redOppDam;
	int rounds;
	
public:

	IceSpell(std::string n, int pr, int hLR, int minD, int maxD, int mPR, int rODam, int ro);
	~IceSpell();

	void get_info(int&, int&) const;
	
	void displayName() const;
	void displayStats() const;
	void displayStatsSellBack() const;
};
#endif
