#include <iostream>
#include <string>
#include "item.h"

using namespace std;

Item::Item(string n, int pr, int minL):name(n),price(pr),minLvl(minL) {	//Constructor of the class

}

Item::~Item() {	//Destructor of the class
	
}

void Item::displayName() const {
	
	cout << name;
}

void Item::displayStats() const {
	cout << "Price: " << price << endl;
	cout << "Minimum level: " << minLvl << endl;
}

void Item::displayStatsSellBack() const {  // Function that prints stats in case of selling back to market
	cout << "Price: " << (price / 2) << endl;
	cout << "Minimum level: " << minLvl << endl;
}

void Item::set_price(int pr) {	//Functions that sets item's price
	
	price=pr;
	
}

string Item::get_name() const {	//Functions that gets item's name
	
	return name;

}
	
int Item::get_price() const {	//Functions that gets item's price

	return price;
	
}

int Item::get_minLvl() const {	//Functions that gets item's minimum level

	return minLvl;
	
}
	
