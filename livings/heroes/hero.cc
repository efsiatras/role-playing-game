#include <iostream>
#include <cstdio>

#include "hero.h"
#include "../monsters/monster.h"
#include "../../spells/spell.h"

using namespace std;

Hero::Hero(const string& nam, const int& lev, const int& health, const int& magic, const int& stren, const int& dext, const int& agil, const int& mon, const int& exp) 
: Living(nam, lev, health), magicPower(magic), maxMagicPower(magic), strength(stren), dexterity(dext), agility(agil), money(mon), experience(exp), leftHand(NULL), rightHand(NULL), armor(NULL), weaponInv(), armorInv(), potionInv(), spellInv() {
	
	//cout << "Summoning a Hero" << endl;
}

Hero::Hero(const string& nam, const int& lev) 
: Living(nam, lev, 200 + 100 * (lev - 1)), magicPower(200 + 100 * (lev - 1)), maxMagicPower(200 + 100 * (lev - 1)), strength(20 + 5 * (lev - 1)), dexterity(20 + 5 * (lev - 1)), agility(20 + 5 * (lev - 1)), money(0), experience(500 * lev + 50 * (lev - 1)), leftHand(NULL), rightHand(NULL), armor(NULL), weaponInv(), armorInv(), potionInv(), spellInv() {

	//cout << "Summoning a Hero" << endl;
}

Hero::~Hero() {
	//cout << "Destroying a Hero" << endl;
	for (int i = 0; i < spellInv.size(); i++) {
		if(spellInv[i] != NULL) {

			delete spellInv[i];
			spellInv[i] = NULL;
		}
	}
}

void Hero::set_money(int mon) {	//Functions that sets hero's money
	
	money=mon;
	
}

int Hero::get_money() const {
	
	return money;
}

int Hero::get_experience() const {

	return experience;
}

int Hero::get_weaponInvSize() const {

	return weaponInv.size();
}

int Hero::get_armorInvSize() const {

	return armorInv.size();
}

int Hero::get_potionInvSize() const {

	return potionInv.size();
}

int Hero::get_spellInvSize() const {

	return spellInv.size();
}

int Hero::get_weaponInvPriceSellBack(const int& element) const {

	return (weaponInv[element].get_price() / 2);
}

int Hero::get_armorInvPriceSellBack(const int& element) const {

	return (armorInv[element].get_price() / 2);
}

int Hero::get_potionInvPriceSellBack(const int& element) const {

	return (potionInv[element].get_price() / 2);
}

int Hero::get_spellInvPriceSellBack(const int& element) const {

	return (spellInv[element]->get_price() / 2);
}

void Hero::push_weaponInv(Weapon& weapon) {	//Function that adds a weapon in weapon inventory
	
	weaponInv.push_back(weapon);
}

void Hero::push_armorInv(Armor& armor) {		//Function that adds an armor in armor inventory
	
	armorInv.push_back(armor);
}

void Hero::push_potionInv(Potion& potion) {	//Function that adds a potion in potion inventory
	
	potionInv.push_back(potion);
}

void Hero::push_spellInv(Spell*& spell) {		//Function that adds a spell in spell inventory
	
	spellInv.push_back(spell);
}				

Weapon Hero::erase_weaponInv(const int& element) {	//Function that erases and returns a weapon in weapon inventory
	Weapon erased = weaponInv[element];
	weaponInv.erase(weaponInv.begin() + element);

	return erased;
}

Armor Hero::erase_armorInv(const int& element) {		//Function that erases and returns an armor in armor inventory
	Armor erased = armorInv[element];	
	armorInv.erase(armorInv.begin() + element);

	return erased;
}

Potion Hero::erase_potionInv(const int& element) {	//Function that erases and returns a potion in potion inventory
	Potion erased = potionInv[element];
	potionInv.erase(potionInv.begin() + element);

	return erased;
}

Spell* Hero::erase_spellInv(const int& element) {		//Function that erases and returns a spell in spell inventory
	Spell* erased = spellInv[element];
	spellInv.erase(spellInv.begin() + element);

	return erased;
}

void Hero::displayWeaponInvSellBack(const int& element) const {	//Function that displays a weapon with half price in weapon inventory
	weaponInv[element].displayName();
	cout << endl;
	weaponInv[element].displayStatsSellBack();
}

void Hero::displayArmorInvSellBack(const int& element) const {		//Function that displays an armor with half price in armor inventory
	armorInv[element].displayName();
	cout << endl;
	armorInv[element].displayStatsSellBack();
}

void Hero::displayPotionInvSellBack(const int& element) const {	//Function that displays a potion with half price in potion inventory
	potionInv[element].displayName();
	cout << endl;
	potionInv[element].displayStatsSellBack();
}

void Hero::displaySpellInvSellBack(const int& element) const {		//Function that displays a spell with half price in spell inventory
	spellInv[element]->displayName();
	cout << endl;
	spellInv[element]->displayStatsSellBack();
}

void Hero::displayStats() const {
	Living::displayStats(); // Displays statistics as a living
	cout << "Magic power: " << magicPower << "/" << maxMagicPower << endl;
	cout << "Strength: " << strength << endl;
	cout << "Dexterity: " << dexterity << endl;
	cout << "Agility: " << agility << endl;
	cout << "Money: " << money << endl;
	cout << "Experience: " << experience << endl;

	if (leftHand == NULL) {

		cout << "Left hand: None" << endl;
	}

	else {

		cout << "Left hand: ";
		leftHand->displayName();
		cout << endl;
	}

	if (rightHand == NULL) {

		cout << "Right hand: None" << endl;
	}

	else {
		cout << "Right hand: ";
		leftHand->displayName();
		cout << endl;
	}

	cout << weaponInv.size() << " weapons in inventory" << endl;
	cout << armorInv.size() << " armors in inventory" << endl;
	cout << potionInv.size() << " potions in inventory" << endl;
	cout << spellInv.size() << " spells in inventory" << endl;

	cout << endl;
}

int Hero::numberOfWeapons() const {

	return weaponInv.size();
}

int Hero::numberOfArmors() const {

	return armorInv.size();
}


int Hero::numberOfPotions() const {

	return potionInv.size();
}

int Hero::numberOfSpells() const {

	return spellInv.size();
}

void Hero::win(const int& numberOfHeroes, const int& numberOfMonsters, const int& heroesLevels, const int& monstersLevels) {
	int exp = 500 + (numberOfMonsters - numberOfHeroes) * 100 + (monstersLevels - heroesLevels) * 20; // Calculates experience gained
	if (exp <= 100) { // Minimum experience gained is 100

		exp = 100;
	}

	gainExperience(exp);

	money += 500 + (numberOfMonsters - numberOfHeroes) * 100 + (monstersLevels - heroesLevels) * 20; // Calculates money gained

	if (get_healthPower() == 0) {

		respawn();
	}
}

void Hero::lose() {
	respawn();
	money /= 2;
}

void Hero::checkInventory() const {	//Function that prints the object of hero's inventory
	cout << "Inventory of ";
	displayName();
	cout << ":" << endl << endl;

	cout << "Weapons:";
	if (weaponInv.size() == 0) {
		cout << endl << "(Empty)" << endl << endl;
	}

	else {
		cout << endl;
		for(int i=0; i < weaponInv.size(); i++){	//Print weapons
			cout << i + 1 << ". ";
			weaponInv[i].displayName();
			cout << endl;
			weaponInv[i].displayStats();
			
			cout << endl << endl;
		}
	}

	cout << "Armors:";
	if (armorInv.size() == 0) {
		cout << endl << "(Empty)" << endl << endl;;
	}

	else {
		cout << endl;
		for(int i=0; i < armorInv.size(); i++){		//Print armors
			cout << i + 1 << ". ";
			armorInv[i].displayName();
			cout << endl;
			armorInv[i].displayStats();
			
			cout << endl << endl;
		}
	}	

	cout << "Potions:";
	if (potionInv.size() == 0) {
		cout << endl << "(Empty)" << endl << endl;
	}

	else {
		cout << endl;
		for(int i=0; i < potionInv.size(); i++){	//Print potions
			cout << i + 1 << ". ";
			potionInv[i].displayName();
			cout << endl;
			potionInv[i].displayStats();
			
			cout << endl << endl;
		}
	}

	cout << "Spells:";
	if (spellInv.size() == 0) {
		cout << endl << "(Empty)" << endl << endl;
	}

	else {
		cout << endl;
		for(int i=0; i < spellInv.size(); i++){		//Print spells
			cout << i + 1 << ". ";
			spellInv[i]->displayName();
			cout << endl;
			spellInv[i]->displayStats();
			
			cout << endl << endl;
		}
	}
}

void Hero::use() {
	int chosenPotion;
	do {
		if (potionInv.size() == 0) {
			chosenPotion = 0;
			cout << "You have no potions!" << endl;
		}

		else {
			cout << endl << endl << endl << " ____________" << endl;
			cout << "|            |" << endl;
			cout << "| USE POTION |" << endl;
			cout << "|____________|" << endl << endl;

			cout << "Choose a potion to use:" << endl;
			cout << "0. Go back" << endl;
			for (int k = 0; k < potionInv.size(); k++) { // Displays all potions
				cout << (k + 1) << ". ";
				potionInv[k].displayName();
				cout << " (+" << potionInv[k].get_statInc() << " " << potionInv[k].get_stat() << ")" << endl;
			}

			cout << endl << "Enter your input: ";

			cin >> chosenPotion;
			while ((chosenPotion < 0) || (chosenPotion > potionInv.size())) { // Checks if input is valid
				cin.ignore(256, '\n'); // Ignores all characters till new line
				cout << "Bad input! Try again: ";

				cin >> chosenPotion;
			}
			cin.ignore(256, '\n'); // Ignores all characters till new line

			for (int cs = 0; cs < 100; cs++) { // Clears screen
				cout << endl;
			}

			if (chosenPotion > 0) {
				if(potionInv[chosenPotion - 1].get_stat()=="healthPower")
					regenerateHP(potionInv[chosenPotion - 1].get_statInc());
					
				else if(potionInv[chosenPotion - 1].get_stat()=="magicPower")
					regenerateMP(potionInv[chosenPotion - 1].get_statInc());		 
					 
				else if(potionInv[chosenPotion - 1].get_stat()=="strength")
					strength+=potionInv[chosenPotion - 1].get_statInc();			 

				else if(potionInv[chosenPotion - 1].get_stat()=="dexterity")
					dexterity+=potionInv[chosenPotion - 1].get_statInc();
					
				else if(potionInv[chosenPotion - 1].get_stat()=="agility")
					agility+=potionInv[chosenPotion - 1].get_statInc();						 
					
				displayName();
					
				cout << " used ";

				potionInv[chosenPotion - 1].displayName();

				cout << "!" << endl;
					
				potionInv.erase(potionInv.begin() + chosenPotion - 1);
			}
		}
	}
	while (chosenPotion != 0);
}

void Hero::equip() {
	char ch;
	do {
		cout << endl << endl << endl << " _______" << endl;
		cout << "|       |" << endl;
		cout << "| EQUIP |" << endl;
		cout << "|_______|" << endl << endl;

		cout << endl << "What do you want to equip?" << endl << endl;

		cout << "w - Weapon" << endl;
		cout << "a - Armor" << endl;
		cout << "q - Go back" << endl << endl;

		cout << "Enter your input: ";
		
		cin >> ch;
		while ((ch != 'q') && (ch != 'w') && (ch != 'a')) { // Checks if input is valid
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
					if (weaponInv.size() == 0) {
						chosenItem = 0;
						cout << "There are no weapons to equip!" << endl;
					}

					else {
						cout << endl << endl << endl << " ______________" << endl;
						cout << "|              |" << endl;
						cout << "| EQUIP WEAPON |" << endl;
						cout << "|______________|" << endl << endl;
						cout << endl << "Choose a weapon to equip:" << endl << endl;

						cout << "0. Go back" << endl << endl;
						for(int i=0; i < weaponInv.size(); i++){	// Prints weapons
							cout << i + 1 << ". ";
							weaponInv[i].displayName();
							if ((leftHand == &weaponInv[i]) && (rightHand != &weaponInv[i])) {

								cout << " (Equipped on left hand)";
							}

							else if ((rightHand == &weaponInv[i]) && (leftHand != &weaponInv[i])) {

								cout << " (Equipped on right hand)";
							}

							else if ((rightHand == &weaponInv[i]) && (leftHand == &weaponInv[i])) {

								cout << " (Equipped on both hands)";
							}

							cout << endl;
							weaponInv[i].displayStats();
							
							cout << endl;
						}

						cout << "Enter your input: ";

						cin >> chosenItem;
						while ((chosenItem < 0) || (chosenItem > weaponInv.size())) { // Checks if input is valid
							cin.ignore(256, '\n'); // Ignores all characters till new line
							cout << "Bad input! Try again: ";

							cin >> chosenItem;
						}
						cin.ignore(256, '\n'); // Ignores all characters till new line

						for (int cs = 0; cs < 100; cs++) { // Clears screen
							cout << endl;
						}

						if (chosenItem > 0) {
							if ((leftHand != &weaponInv[chosenItem - 1]) && (rightHand != &weaponInv[chosenItem - 1])) { // If hero does not wear this weapon
								if (get_level() > weaponInv[chosenItem - 1].get_minLvl()) {	//If hero is big enough level
									if (weaponInv[chosenItem -1].get_handsReq() == 0) { // If weapon required one hand
										cout << endl << endl << endl << " ______________" << endl;
										cout << "|              |" << endl;
										cout << "| EQUIP WEAPON |" << endl;
										cout << "|______________|" << endl << endl;

										cout << endl << "Choose a hand:" << endl << endl;

										cout << "l - Left" << endl;
										cout << "r - Right" << endl << endl;

										cout << "Enter your input: ";
										
										cin >> ch;
										while ((ch != 'l') && (ch != 'r')) { // Checks if input is valid
											cin.ignore(256, '\n');  // Ignores all characters till new line
											cout << "Bad input! Try again: ";

											cin >> ch;
										}
										cin.ignore(256, '\n'); // Ignores all characters till new line

										for (int cs = 0; cs < 100; cs++) { // Clears screen
											cout << endl;
										}

										if (ch == 'l') {
											if (leftHand != NULL) {
												if (leftHand == rightHand) { // Two-handed weapon to be unequipped
													cout << "You just unequipped ";
													leftHand->displayName();
													cout << " from your both hands!" << endl;

													leftHand = NULL;
													rightHand = NULL;
												}

												else { 
													cout << "You just unequipped ";
													leftHand->displayName();
													cout << " from your left hand!" << endl;

													leftHand = NULL;
												}
											}

											leftHand = &weaponInv[chosenItem - 1];
											cout << "You just equipped ";
											leftHand->displayName();
											cout << " on your left hand!" << endl;
										}

										else { // ch == 'r'
											if (rightHand != NULL) {
												if (leftHand == rightHand) { // Two-handed weapon to be unequipped
													cout << "You just unequipped ";
													rightHand->displayName();
													cout << " from your both hands!" << endl;

													leftHand = NULL;
													rightHand = NULL;
												}

												else {
													cout << "You just unequipped ";
													rightHand->displayName();
													cout << " from your right hand!" << endl;

													rightHand = NULL;
												}
											}

											rightHand = &weaponInv[chosenItem - 1];
											cout << "You just equipped ";
											rightHand->displayName();
											cout << " on your right hand!" << endl;
										}
									}

									else {
										if ((leftHand != NULL) && (rightHand == leftHand)) { // Two-handed weapon to be unequipped
											cout << "You just unequipped";
											leftHand->displayName();
											cout << " from your both hands!" << endl;

											leftHand = NULL;
											rightHand = NULL;
										}

										if (leftHand != NULL) {
											cout << "You just unequipped ";
											leftHand->displayName();
											cout << " from your left hand!" << endl;

											leftHand = NULL;
										}

										if (rightHand != NULL) {
											cout << "You just unequipped ";
											rightHand->displayName();
											cout << " from your right hand!" << endl;

											leftHand = NULL;
										}

										leftHand = &weaponInv[chosenItem - 1];
										rightHand = &weaponInv[chosenItem - 1];

										cout << "You just equipped ";
										rightHand->displayName();
										cout << " on your both hands!" << endl;
									}
								}

								else {

									cout << "Your level is lower than the required one to equip this weapon!" << endl;
								}
							}

							else {

								cout << "You already have this weapon equipped!" << endl;
							}
						}
					}
				}
				while (chosenItem != 0);

				break;

			case 'a':
				do {
					if (armorInv.size() == 0) {
						chosenItem = 0;
						cout << "There are no armors to equip!" << endl;
					}

					else {
						cout << endl << endl << endl << " _____________" << endl;
						cout << "|             |" << endl;
						cout << "| EQUIP ARMOR |" << endl;
						cout << "|_____________|" << endl << endl;

						cout << endl << "Choose an armor to equip:" << endl << endl;

						cout << "0. Go back" << endl << endl;
						for(int i=0; i < armorInv.size(); i++){	// Prints armors
							cout << i + 1 << ". ";
							armorInv[i].displayName();
							if (armor == &armorInv[i]) {

								cout << " (Equipped)";
							}

							cout << endl;
							armorInv[i].displayStats();
							
							cout << endl;
						}

						cout << "Enter your input: ";

						cin >> chosenItem;
						while ((chosenItem < 0) || (chosenItem > armorInv.size())) { // Checks if input is valid
							cin.ignore(256, '\n'); // Ignores all characters till new line
							cout << "Bad input! Try again: ";

							cin >> chosenItem;
						}
						cin.ignore(256, '\n'); // Ignores all characters till new line

						for (int cs = 0; cs < 100; cs++) { // Clears screen
							cout << endl;
						}

						if (chosenItem > 0) {
							if (armor != &armorInv[chosenItem -1]) { // If hero does not wear this armor
								if (get_level() > armorInv[chosenItem - 1].get_minLvl()) {	//If hero is big enough level
									if (armor != NULL) {
										cout << "You just unequipped ";
										armor->displayName();
										cout << "!" << endl;

										armor = NULL;
									}

									armor = &armorInv[chosenItem - 1];

									cout << "You just equipped ";
									armor->displayName();
									cout << "!" << endl;
								}

								else {

									cout << "Your level is lower than the required one to equip this armor!" << endl;
								}
							}

							else {

								cout << "You already have this armor equipped!" << endl;
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

void Hero::levelUp() {
	int levelUpExp = 500 * this->get_level() + 50 * (this->get_level() - 1); // Calculates experience needed to level up (double check)
	if (experience > levelUpExp) {
		gainLevel(1);
		gainMaxHealthPower(100);
		regenerateHP(100);

		maxMagicPower += 100;
		magicPower += 100;

		strength += 5;
		dexterity += 5;
		agility += 5;

		displayName();
		cout << " reached level " << get_level() << "!" << endl;
	}
}

void Hero::gainExperience(const int& exp) {
	experience += exp; // Gains experience

	int levelUpExp = 500 * this->get_level() + 50 * (this->get_level() - 1); // Calculates experience needed to level up
	while (experience > levelUpExp) {
		this->levelUp();

		levelUpExp = 500 * this->get_level() + 50 * (this->get_level() - 1); // Calculates experience needed to level up again
	}
}

void Hero::regenerateMP(const int& regen) {
	if ((magicPower + regen) > maxMagicPower) {

		magicPower = maxMagicPower;
	}

	else {

		magicPower += regen;
	}
}

void Hero::gainMaxMagicPower(const int& magic) {

	maxMagicPower += magic;
}

void Hero::gainStrength(const int& str) {

	strength += str;
}

void Hero::gainDexterity(const int& dext) {

	dexterity += dext;
}

void Hero::gainAgility(const int& agi) {

	agility += agi;
}

int Hero::attacks() {
	int dam = 10; // Base damage
	dam += strength; // Adds up strength
	if (leftHand != NULL) { // Adds up weapon's damage
		if (rightHand != NULL) {
			if (leftHand == rightHand) {

				dam += leftHand->get_damage();
			}

			else {
				dam += leftHand->get_damage();
				dam += rightHand->get_damage();
			}
		}

		else {

			dam += leftHand->get_damage();
		}
	}

	else if (rightHand != NULL) {

		dam += rightHand->get_damage();
	}

	return dam;
}

Spell* Hero::spellAttacks(int& dexter) {
	Spell *spell;
	if (spellInv.size() == 0) {
		cout << "You have no spells!" << endl;

		spell = NULL;
	}

	else {
		dexter = dexterity;
		cout << "You have " << magicPower << "/" << maxMagicPower << " MP. Choose a spell to attack: " << endl;
		for (int k = 0; k < spellInv.size(); k++) { // Displays all spells
			cout << (k + 1) << ". ";
			spellInv[k]->displayName();
			cout << " (Costs " << spellInv[k]->get_cost() << " MP)" << endl;
		}

		cout << endl << "Enter your input: ";

		int ch;
		cin >> ch;
		while ((ch < 1) || (ch > spellInv.size() + 1)) { // Checks if input is valid
			cin.ignore(256, '\n'); // Ignores all characters till new line
			cout << "Bad input! Try again: ";

			cin >> ch;
		}
		cin.ignore(256, '\n'); // Ignores all characters till new line

		for (int cs = 0; cs < 100; cs++) { // Clears screen
			cout << endl;
		}

		if (spellInv[ch - 1]->get_cost() > magicPower) {
			cout << "You don't have enough MP for that spell!" << endl;

			spell = NULL;
		}

		else { // spellInv[ch - 1]->get_cost() < magicPower

			spell = spellInv[ch - 1];
			magicPower -= spell->get_cost();
			displayName();
			cout << " spent " << spell->get_cost() << " MP and attacked ";
		}
	}

	return spell;
}

void Hero::attacked(Monster*& monster) {
	int totalDef = 0; // Calculates total defence
	if (armor != NULL) {

		totalDef += armor->get_defence();
	}

	int totalDam = monster->attacks() - totalDef; // Calculates damage
	if (totalDam < 0) {

		totalDam = 0;
	}

	monster->displayName();
	cout << " attacked ";
	displayName();

	int random = rand() % 201; // Random number from 0 to 200 

	if (random > agility) { // Monster got hit
		if (totalDam == 0) {
			cout << ", but the attack was too weak";
		}

		else {
			cout << " and dealt " << totalDam << " damage";
			loseHP(totalDam);
		}
	}

	else { // 'random < agility' ; Monster did not get hit
	
		cout << ", but he missed";
	}

	cout << "!" << endl;
}
