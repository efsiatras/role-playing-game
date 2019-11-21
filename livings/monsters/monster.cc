#include <iostream>

#include "monster.h"
#include "../heroes/hero.h"
#include "../../spells/spell.h"

using namespace std;

Monster::Monster(const string& nam, const int& lev, const int& health, const int& min, const int& max, const int& def, const int& agi) 
: Living(nam, lev, health), minDamage(min), maxDamage(max), defence(def), agility(agi), redDam(0), roundsDam(0), redDef(0), roundsDef(0), redAgi(0), roundsAgi(0) {
	
	//cout << "Summoning a Monster" << endl;
}

Monster::Monster(const string& nam, const int& lev) 
: Living(nam, lev, 200 + 100 * (lev - 1)), minDamage(20 + 20 * (lev - 1)), maxDamage(40 + 20 * (lev - 1)), defence(10 + 5 * (lev - 1)), agility(20 + 5 * (lev - 1)), redDam(0), roundsDam(0), redDef(0), roundsDef(0), redAgi(0), roundsAgi(0) {
	
	//cout << "Summoning a Monster" << endl;
}

Monster::~Monster() {

	//cout << "Destroying a Monster" << endl;
}

void Monster::displayStats() const {
	Living::displayStats(); // Displays info as a living
	cout << "Minimum damage: " << minDamage << endl;
	cout << "Maximum damage: " << maxDamage << endl;
	cout << "Defence: " << defence << endl;
	cout << "Agility: " << agility << endl;
}

void Monster::reduceRounds(const int& reduce) {
	if ((roundsDam - reduce) <= 0) {
		redDam = 0;
		roundsDam = 0;
	}

	else {

		roundsDam -= reduce;
	}

	if ((roundsDef - reduce) <= 0) {
		redDef = 0;
		roundsDef = 0;
	}

	else {

		roundsDef -= reduce;
	}

	if ((roundsAgi - reduce) <= 0) {
		redAgi = 0;
		roundsDam = 0;
	}

	else {

		roundsAgi -= reduce;
	}
}

int Monster::attacks() {
	int totalDam = rand() % (maxDamage + 1 - minDamage) + minDamage - redDam; // Calculates total damage
	if (totalDam < 0) {

		totalDam = 0;
	}

	return totalDam;
}

void Monster::attacked(Hero*& hero) {
	hero->displayName();
	cout << " attacked ";
	displayName();

	int random = rand() % 201; // Random number from 0 to 200 

	int totalAgi = agility - redAgi; // Calculates total agility
	if (totalAgi < 0) {

		totalAgi = 0;
	}

	if (random > totalAgi) { // Monster got hit
		int totalDef = defence - redDef; // Calculates total defence
		if (totalDef < 0) {

			totalDef = 0;
		}

		int totalDam = hero->attacks() - totalDef; // Calculates damage
		if (totalDam < 0) {

			totalDam = 0;
		}

		if (totalDam == 0) {
			cout << ", but the attack was too weak";
		}

		else {
			cout << " and dealt " << totalDam << " damage";
			loseHP(totalDam);
		}
	}

	else { // 'random < totalAgi' ; Monster did not get hit
	
		cout << ", but he missed";
	}

	cout << "!" << endl;
}

void Monster::spellAttacked(Hero*& hero) {
	int dexterity;

	Spell *spell = hero->spellAttacks(dexterity);
	if (spell == NULL) { // No spell

		return;
	}

	else { // There is spell
		displayName();
		cout << " with ";
		spell->displayName();

		int random = rand() % 201; // Random number from 0 to 200 

		int totalAgi = agility - redAgi; // Calculates total agility
		if (totalAgi < 0) {

			totalAgi = 0;
		}

		if (random > totalAgi) { // Monster got hit
			string identity = spell->get_identity(); // Checks what type of spell it is

			int effect;
			int rounds;
			spell->get_info(effect, rounds);

			if (identity == "firespell") {
				redDam += effect;
				roundsDam += rounds;
			}

			else if (identity == "icespell") {
				redDef += effect;
				roundsDef += rounds;
			}

			else if (identity == "lightingspell") { 
				redAgi += effect;
				roundsAgi += rounds;
			}

			int totalDef = defence - redDef; // Calculates total defence
			if (totalDef < 0) {

				totalDef = 0;
			}

			int totalDam = spell->get_damage() + dexterity - totalDef; // Calculates damage
			if (totalDam < 0) {

				totalDam = 0;
			}

			if (totalDam == 0) {
				cout << ", but the spell was too weak";
			}

			else {
				cout << " and dealt " << totalDam << " magic damage";
				loseHP(totalDam);
			}
		}

		else {

			cout << ", but he missed";
		}
		
		cout << "!" << endl;
	}
}