#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item {

private:

	std::string name;
	int price;
	int minLvl;	
	
public:

	Item(std::string n, int pr, int minL);
	virtual ~Item();
	
	virtual void displayName() const;
	virtual void displayStats() const;
	virtual void displayStatsSellBack() const;
	
	void set_price(int pr);

	std::string get_name() const;
	int get_price() const;
	int get_minLvl() const;
		
};
#endif
