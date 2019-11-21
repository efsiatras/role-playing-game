#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "market.h"

using namespace std;

Market::Market(int i, int j):x(i),y(j) {	//Constructor of the class

}

Market::~Market() {	//Destructor of the class
	for (int i = 0; i < spells.size(); i++) {
		if(spells[i] != NULL) {

			delete spells[i];
			spells[i] = NULL;
		}
	}
}

void Market::set(int i, int j) {	//Function that sets market coordinates
	
	x=i;
	y=j;
}

int Market::get_x()const {	//Functions that returns x
	
	return x;
	
}

int Market::get_y()const {	//Functions that returns y
	
	return y;
	
}
void Market::insert_weapon(Weapon weapon) {

	weapons.push_back(weapon);
}

void Market::insert_armor(Armor armor) {

	armors.push_back(armor);
}

void Market::insert_potion(Potion potion) {

	potions.push_back(potion);
}

void Market::insert_spell(Spell* spell) {

	spells.push_back(spell);
}


void Market::buy(Hero*& hero) {	//Function that represents the buying procedure in market
	char ch;
	do {
		cout << endl << "What do you want to buy?" << endl << endl;

		cout << "w - Weapon" << endl;
		cout << "a - Armor" << endl;
		cout << "p - Potion" << endl;
		cout << "s - Spell" << endl;
		cout << "q - Go back" << endl << endl;

		cout << "Enter your input: ";
		
		cin >> ch;
		while ((ch != 'q') && (ch != 'w') && (ch != 'a') && (ch != 'p') && (ch != 's')) { // Checks if input is valid
			cin.ignore(256, '\n');  // Ignores all characters till new line
			cout << "Bad input! Try again: ";

			cin >> ch;
		}
		cin.ignore(256, '\n'); // Ignores all characters till new line

		for (int cs = 0; cs < 100; cs++) { // Clears screen
			cout << endl;
		}

		int chosenItem;
		switch(ch) {
			case 'w':
				do {
					if (weapons.size() == 0) {
						chosenItem = 0;
						cout << "There are no weapons to buy!" << endl << endl;
					}

					else {
						cout << endl << "Choose a weapon to buy:" << endl << endl;

						cout << "0. Go back" << endl << endl;
						for(int i=0; i < weapons.size(); i++){	// Prints weapons
							cout << i + 1 << ". ";
							weapons[i].displayName();
							cout << endl;
							weapons[i].displayStats();
							
							cout << endl;
						}

						cout << "Enter your input: ";

						cin >> chosenItem;
						while ((chosenItem < 0) || (chosenItem > weapons.size())) { // Checks if input is valid
							cin.ignore(256, '\n'); // Ignores all characters till new line
							cout << "Bad input! Try again: ";

							cin >> chosenItem;
						}
						cin.ignore(256, '\n'); // Ignores all characters till new line

						for (int cs = 0; cs < 100; cs++) { // Clears screen
							cout << endl;
						}

						if (chosenItem > 0) {
							if(hero->get_money() > weapons[chosenItem - 1].get_price()) { // If hero has enough money
								if (hero->get_level() > weapons[chosenItem - 1].get_minLvl()) {	//If hero is big enough level
									hero->push_weaponInv(weapons[chosenItem - 1]); //Add weapon in hero's inventory
		
									hero->set_money(hero->get_money() - weapons[chosenItem - 1].get_price()); //Recalculate hero's money after buying the object

									weapons.erase(weapons.begin() + chosenItem - 1);	//Remove weapon from market

									cout << "Congratulations! You just bought a new weapon! You currently have " << hero->get_money() << " money!" << endl << endl;
								}

								else {

									cout << "Your level is lower than the required one to buy this weapon!" << endl << endl;
								}
							}

							else {

								cout << "You don't have enough money for this weapon!" << endl << endl;
							}
						}
					}
				}
				while (chosenItem != 0);

				break;

			case 'a':
				do {
					if (armors.size() == 0) {
						chosenItem = 0;
						cout << "There are no armors to buy!" << endl << endl;
					}

					else {
						cout << endl << "Choose an armor to buy:" << endl << endl;

						cout << "0. Go back" << endl << endl;
						for(int i=0; i < armors.size(); i++){	// Prints armors
							cout << i + 1 << ". ";
							armors[i].displayName();
							cout << endl;
							armors[i].displayStats();
							
							cout << endl;
						}

						cout << "Enter your input: ";

						cin >> chosenItem;
						while ((chosenItem < 0) || (chosenItem > armors.size())) { // Checks if input is valid
							cin.ignore(256, '\n'); // Ignores all characters till new line
							cout << "Bad input! Try again: ";

							cin >> chosenItem;
						}
						cin.ignore(256, '\n'); // Ignores all characters till new line

						for (int cs = 0; cs < 100; cs++) { // Clears screen
							cout << endl;
						}

						if (chosenItem > 0) {
							if(hero->get_money() > armors[chosenItem - 1].get_price()) { // If hero has enough money
								if (hero->get_level() > armors[chosenItem - 1].get_minLvl()) {	//If hero is big enough level
									hero->push_armorInv(armors[chosenItem - 1]); //Add armor in hero's inventory

									hero->set_money(hero->get_money() - armors[chosenItem - 1].get_price()); //Recalculate hero's money after buying the object

									armors.erase(armors.begin() + chosenItem - 1);	//Remove armor from market

									cout << "Congratulations! You just bought a new armor! You currently have " << hero->get_money() << " money!" << endl << endl;
								}

								else {

									cout << "Your level is lower than the required one to buy this armor!" << endl << endl;
								}
							}

							else {

								cout << "You don't have enough money for this armor!" << endl << endl;
							}
						}
					}
				}
				while (chosenItem != 0);

				break;

			case 'p':
				do {
					if (potions.size() == 0) {
						chosenItem = 0;
						cout << "There are no potions to buy!" << endl << endl;
					}

					else {
						cout << endl << "Choose a potion to buy:" << endl << endl;

						cout << "0. Go back" << endl << endl;
						for(int i=0; i < potions.size(); i++){	// Prints potions
							cout << i + 1 << ". ";
							potions[i].displayName();
							cout << endl;
							potions[i].displayStats();
							
							cout << endl;
						}

						cout << "Enter your input: ";

						cin >> chosenItem;
						while ((chosenItem < 0) || (chosenItem > potions.size())) { // Checks if input is valid
							cin.ignore(256, '\n'); // Ignores all characters till new line
							cout << "Bad input! Try again: ";

							cin >> chosenItem;
						}
						cin.ignore(256, '\n'); // Ignores all characters till new line

						for (int cs = 0; cs < 100; cs++) { // Clears screen
							cout << endl;
						}

						if (chosenItem > 0) {
							if(hero->get_money() > potions[chosenItem - 1].get_price()) { // If hero has enough money
								if (hero->get_level() > potions[chosenItem - 1].get_minLvl()) {	//If hero is big enough level
									hero->push_potionInv(potions[chosenItem - 1]); //Add potion in hero's inventory

									hero->set_money(hero->get_money() - potions[chosenItem - 1].get_price()); //Recalculate hero's money after buying the object

									potions.erase(potions.begin() + chosenItem - 1);	//Remove potion from market

									cout << "Congratulations! You just bought a new potion! You currently have " << hero->get_money() << " money!" << endl << endl;
								}

								else {

									cout << "Your level is lower than the required one to buy this potion!" << endl << endl;
								}
							}

							else {

								cout << "You don't have enough money for this potion!" << endl << endl;
							}
						}
					}
				}
				while (chosenItem != 0);

				break;

			case 's':
				do {
					if (spells.size() == 0) {
						chosenItem = 0;
						cout << "There are no spells to buy!" << endl << endl;
					}

					else {
						cout << endl << "Choose a spell to buy:" << endl << endl;

						cout << "0. Go back" << endl << endl;
						for(int i=0; i < spells.size(); i++){	// Prints spells
							cout << i + 1 << ". ";
							spells[i]->displayName();
							cout << endl;
							spells[i]->displayStats();
							
							cout << endl;
						}

						cout << "Enter your input: ";

						cin >> chosenItem;
						while ((chosenItem < 0) || (chosenItem > spells.size())) { // Checks if input is valid
							cin.ignore(256, '\n'); // Ignores all characters till new line
							cout << "Bad input! Try again: ";

							cin >> chosenItem;
						}
						cin.ignore(256, '\n'); // Ignores all characters till new line

						for (int cs = 0; cs < 100; cs++) { // Clears screen
							cout << endl;
						}

						if (chosenItem > 0) {
							if(hero->get_money() > spells[chosenItem - 1]->get_price()) { // If hero has enough money
								if (hero->get_level() > spells[chosenItem - 1]->get_minLvl()) {	//If hero is big enough level
									hero->push_spellInv(spells[chosenItem - 1]); //Add spell in hero's inventory

									hero->set_money(hero->get_money() - spells[chosenItem - 1]->get_price()); //Recalculate hero's money after buying the object

									spells.erase(spells.begin() + chosenItem - 1);	//Remove spell from market

									cout << "Congratulations! You just bought a new spell! You currently have " << hero->get_money() << " money!" << endl << endl;
								}

								else {

									cout << "Your level is lower than the required one to buy this spell!" << endl << endl;
								}
							}

							else {

								cout << "You don't have enough money for this spell!" << endl << endl;
							}
						}
					}
				}
				while (chosenItem != 0);

				break;
		}
	}
	while (ch != 'q');
}
			
void Market::sell(Hero*& hero) {	//Function that represents the selling procedure in market
	char ch;
	do {
		cout << endl << "What do you want to sell?" << endl << endl;

		cout << "w - Weapon" << endl;
		cout << "a - Armor" << endl;
		cout << "p - Potion" << endl;
		cout << "s - Spell" << endl;
		cout << "q - Go back" << endl << endl;

		cout << "Enter your input: ";
		
		cin >> ch;
		while ((ch != 'q') && (ch != 'w') && (ch != 'a') && (ch != 'p') && (ch != 's')) { // Checks if input is valid
			cin.ignore(256, '\n');  // Ignores all characters till new line
			cout << "Bad input! Try again: ";

			cin >> ch;
		}
		cin.ignore(256, '\n'); // Ignores all characters till new line

		for (int cs = 0; cs < 100; cs++) { // Clears screen
			cout << endl;
		}

		int chosenItem;
		switch(ch) {
			case 'w':
				do {
					if (hero->get_weaponInvSize() == 0) {
						chosenItem = 0;
						cout << "There are no weapons to sell!" << endl << endl;
					}

					else {
						cout << endl << "Choose a weapon to sell:" << endl << endl;

						cout << "0. Go back" << endl << endl;
						for(int i=0; i < hero->get_weaponInvSize(); i++){	// Prints weapons
							cout << i + 1 << ". ";
							hero->displayWeaponInvSellBack(i);
							cout << endl;
						}

						cout << "Enter your input: ";

						cin >> chosenItem;
						while ((chosenItem < 0) || (chosenItem > hero->get_weaponInvSize())) { // Checks if input is valid
							cin.ignore(256, '\n'); // Ignores all characters till new line
							cout << "Bad input! Try again: ";

							cin >> chosenItem;
						}
						cin.ignore(256, '\n'); // Ignores all characters till new line

						for (int cs = 0; cs < 100; cs++) { // Clears screen
							cout << endl;
						}

						if (chosenItem > 0) {	
							hero->set_money(hero->get_money() + hero->get_weaponInvPriceSellBack(chosenItem - 1)); //Recalculates hero's money after selling the object
							weapons.push_back(hero->erase_weaponInv(chosenItem - 1)); //Adds weapon in market and removes weapon from hero's inventory

							cout << "Congratulations! You just sold a weapon! You currently have " << hero->get_money() << " money!" << endl << endl;
						}
					}
				}
				while (chosenItem != 0);

				break;

			case 'a':
				do {
					if (hero->get_armorInvSize() == 0) {
						chosenItem = 0;
						cout << "There are no armors to sell!" << endl << endl;
					}

					else {
						cout << endl << "Choose an armor to sell:" << endl << endl;

						cout << "0. Go back" << endl << endl;
						for(int i=0; i < hero->get_armorInvSize(); i++){	// Prints armors
							cout << i + 1 << ". ";
							hero->displayArmorInvSellBack(i);
							cout << endl;
						}

						cout << "Enter your input: ";

						cin >> chosenItem;
						while ((chosenItem < 0) || (chosenItem > hero->get_armorInvSize())) { // Checks if input is valid
							cin.ignore(256, '\n'); // Ignores all characters till new line
							cout << "Bad input! Try again: ";

							cin >> chosenItem;
						}
						cin.ignore(256, '\n'); // Ignores all characters till new line

						for (int cs = 0; cs < 100; cs++) { // Clears screen
							cout << endl;
						}

						if (chosenItem > 0) {
							hero->set_money(hero->get_money() + hero->get_armorInvPriceSellBack(chosenItem - 1)); //Recalculates hero's money after selling the object
							armors.push_back(hero->erase_armorInv(chosenItem - 1)); //Adds armor in market and removes armor from hero's inventory
			
							cout << "Congratulations! You just sold an armor! You currently have " << hero->get_money() << " money!" << endl << endl;
						}
					}
				}
				while (chosenItem != 0);

				break;

			case 'p':
				do {
					if (hero->get_potionInvSize() == 0) {
						chosenItem = 0;
						cout << "There are no potions to sell!" << endl << endl;
					}

					else {
						cout << endl << "Choose a potion to sell:" << endl << endl;

						cout << "0. Go back" << endl << endl;
						for(int i=0; i < hero->get_potionInvSize(); i++){	// Prints potions
							cout << i + 1 << ". ";
							hero->displayPotionInvSellBack(i);
							cout << endl;
						}

						cout << "Enter your input: ";

						cin >> chosenItem;
						while ((chosenItem < 0) || (chosenItem > hero->get_potionInvSize())) { // Checks if input is valid
							cin.ignore(256, '\n'); // Ignores all characters till new line
							cout << "Bad input! Try again: ";

							cin >> chosenItem;
						}
						cin.ignore(256, '\n'); // Ignores all characters till new line

						for (int cs = 0; cs < 100; cs++) { // Clears screen
							cout << endl;
						}

						if (chosenItem > 0) {
							hero->set_money(hero->get_money() + hero->get_potionInvPriceSellBack(chosenItem - 1)); //Recalculates hero's money after selling the object
							potions.push_back(hero->erase_potionInv(chosenItem - 1)); //Adds potion in market and removes armor from hero's inventory

							cout << "Congratulations! You just sold a potion! You currently have " << hero->get_money() << " money!" << endl << endl;
						}
					}
				}
				while (chosenItem != 0);

				break;

			case 's':
				do {
					if (hero->get_spellInvSize() == 0) {
						chosenItem = 0;
						cout << "There are no spells to sell!" << endl << endl;
					}

					else {
						cout << endl << "Choose a spell to sell:" << endl << endl;

						cout << "0. Go back" << endl << endl;
						for(int i=0; i < hero->get_spellInvSize(); i++){	// Prints spells
							cout << i + 1 << ". ";
							hero->displaySpellInvSellBack(i);
							cout << endl;
						}

						cout << "Enter your input: ";

						cin >> chosenItem;
						while ((chosenItem < 0) || (chosenItem > hero->get_spellInvSize())) { // Checks if input is valid
							cin.ignore(256, '\n'); // Ignores all characters till new line
							cout << "Bad input! Try again: ";

							cin >> chosenItem;
						}
						cin.ignore(256, '\n'); // Ignores all characters till new line

						for (int cs = 0; cs < 100; cs++) { // Clears screen
							cout << endl;
						}

						if (chosenItem > 0) {
							hero->set_money(hero->get_money() + hero->get_spellInvPriceSellBack(chosenItem - 1)); //Recalculates hero's money after selling the object
							spells.push_back(hero->erase_spellInv(chosenItem - 1)); //Adds spell in market and removes armor from hero's inventory
			
							cout << "Congratulations! You just sold a spell! You currently have " << hero->get_money() << " money!" << endl << endl;
						}
					}
				}
				while (chosenItem != 0);

				break;
		}
	}
	while (ch != 'q');
}

int Market::exchange(int i, int j, vector<Hero*>& heroes) {	//Function that implements buy/sell procedure in market
	int flag=0;

	if(x==i && y==j) {
		flag=1;
		char ch;
		cout << "Do you want to enter the market? " << endl << endl;

		cout << "y - Yes" << endl;
		cout << "n - No" << endl << endl;

		cout << "Enter your input: ";
		
		cin >> ch;
		while ((ch != 'n') && (ch != 'y')) { // Checks if input is valid
			cin.ignore(256, '\n');  // Ignores all characters till new line
			cout << "Bad input! Try again: ";

			cin >> ch;
		}
		cin.ignore(256, '\n'); // Ignores all characters till new line

		for (int cs = 0; cs < 100; cs++) { // Clears screen
			cout << endl;
		}
		
		if (ch=='n') {}	//Exit market without buying or selling an object
			
		else { // ch == 'y'
			int chosenHero;
			do {
				cout << endl << "Choose a hero:" << endl << endl;

				cout << "0. Exit market" << endl;

				for (int i = 0; i < heroes.size(); i++) { // Displays names of heroes
					cout << i+1 << ". ";
					heroes[i]->displayName();
					cout << " (level " << heroes[i]->get_level() << " / " << heroes[i]->get_money() << " money)" << endl;
				}

				cout << endl << "Enter your input: ";

				cin >> chosenHero;
				while ((chosenHero < 0) || (chosenHero > (heroes.size()))) { // Checks if input is valid
					cin.ignore(256, '\n'); // Ignores all characters till new line
					cout << "Bad input! Try again: ";

					cin >> chosenHero;
				}
				cin.ignore(256, '\n'); // Ignores all characters till new line

				for (int cs = 0; cs < 100; cs++) { // Clears screen
					cout << endl;
				}

				if (chosenHero > 0) {
					char ch2;
					do {
						char ch2;
						cout << endl << "Choose one of the following options:" << endl << endl;

						cout << "b - Buy" << endl;
						cout << "s - Sell" << endl;
						cout << "q - Go back" << endl << endl;

						cout << "Enter your input: ";

						cin >> ch2;
						while ((ch2 != 'b') && (ch2 != 's') && (ch2 != 'q')) { // Checks if input is valid
							cin.ignore(256, '\n');  // Ignores all characters till new line
							cout << "Bad input! Try again: ";

							cin >> ch2;
						}
						cin.ignore(256, '\n'); // Ignores all characters till new line

						for (int cs = 0; cs < 100; cs++) { // Clears screen
							cout << endl;
						}
						
						if (ch2=='b')	
							buy(heroes[chosenHero - 1]);	//Buy an object
						else if (ch2=='s')
							sell(heroes[chosenHero - 1]);	//Sell an object
						else
							break;
					}

					while (ch2 != 'q');
				}
			}

			while (chosenHero != 0);

			cout << "Exiting market..." << endl << endl;	
		}
	}
		
	return flag;	
}
