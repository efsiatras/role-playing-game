#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include "item.h"

class Weapon: public Item {

private:

	int damage;
	bool handsReq;	
	
public:

	Weapon(std::string n, int pr, int minL, int dam, bool handsR);
	~Weapon();

	void displayName() const;
	void displayStats() const;
	void displayStatsSellBack() const;

	int get_damage() const;
	int get_handsReq() const;
};
#endif
