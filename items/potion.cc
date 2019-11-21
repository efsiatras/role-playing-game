#include <iostream>
#include "potion.h"

using namespace std;

Potion::Potion(string n, int pr, int minL, string sta, int statI):Item(n,pr,minL),stat(sta),statInc(statI){	//Constructor of the class
	
}

Potion::~Potion(){	//Destructor of the class
		
}

void Potion::displayName() const {
	Item::displayName();

	cout << " (Potion)";
}

void Potion::displayStats() const {
	Item::displayStats();

	cout << "Offers: +" << statInc << " " << stat << endl;
}

void Potion::displayStatsSellBack() const {
	Item::displayStatsSellBack();

	cout << "Offers: +" << statInc << " " << stat << endl;
}

string Potion::get_stat() const {
	
	return stat;
	
}

int Potion::get_statInc() const {
	
	return statInc;
	
}
