#ifndef ARMOR_H
#define ARMOR_H

#include <iostream>
#include "item.h"

class Armor: public Item {

private:

	int reDam;	
	
public:

	Armor(std::string n, int pr, int minL, int reD);
	~Armor();

	void displayName() const;
	void displayStats() const;
	void displayStatsSellBack() const;

	int get_defence() const;
		
};
#endif
