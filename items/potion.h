#ifndef POTION_H
#define POTION_H

#include <iostream>
#include <string>
#include "item.h"

class Potion: public Item {

private:

	std::string stat; // Which stat increases
	int statInc; // How much it increases
	
public:

	Potion(std::string n, int pr, int minL, std::string stat, int statInc);
	~Potion();

	void displayName() const;
	void displayStats() const;
	void displayStatsSellBack() const;
	
	std::string get_stat() const;
	int get_statInc() const;
		
};
#endif
