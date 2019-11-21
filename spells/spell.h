#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include <string>

class Spell {

private:

	std::string name;
	int price;
	int minLvl;
	int minDam;
	int maxDam;
	int magicPowReq;
	std::string identity;
	
public:

	Spell(std::string n, int pr, int minL, int minD, int maxD, int mPR, std::string ident);
	virtual ~Spell();

	virtual void displayName() const;
	virtual void displayStats() const;
	virtual void displayStatsSellBack() const;
	
	void set_price(int pr);

	std::string get_name() const;
	int get_price() const;
	int get_minLvl() const;
	std::string get_identity() const;
	int get_damage() const;
	int get_cost() const;

	virtual void get_info(int& eff, int& rou) const = 0;		
};
#endif
