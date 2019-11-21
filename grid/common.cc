#include <iostream>
#include <vector>
#include <cstdlib>

#include "common.h"

using namespace std;

Common::Common(int i, int j):x(i),y(j) { //Constructor of the class
	
}

Common::~Common() {	//Destructor of the class
	
}

int Common::battle(vector<Hero*>& heroes, vector<Monster*>& monsters) { // 0 for heroes' win ; 1 for monsters' win
	for (int cs = 0; cs < 100; cs++) { // Clears screen
		cout << endl;
	}

	int heroesAlive = heroes.size();
	if (heroesAlive == 0) {
		cout << "Error! Insufficient number of heroes" << endl;

		return -1;
	}

	int monstersAlive = monsters.size();
	if (monstersAlive == 0) {
		cout << "Error! Insufficient number of monsters" << endl;

		return -2;
	}

	int i = 0; // Number of current round

	cout << "A battle has started!" << endl;
	while ((heroesAlive != 0) && (monstersAlive != 0)) { // Battle lasts till all heroes or all monsters are dead
		cout << endl << endl << endl << " ________" << endl;
		cout << "|        |" << endl;
		cout << "| BATTLE |" << endl;
		cout << "|________|" << endl << endl;

		i++;
		cout << "Round " << i << ": ";

		if (i % 2 == 1) {
			cout << "Heroes' turn!" << endl << endl;
			if (checkDisplayStats() == true) {

				displayStats(heroes, monsters);
			}

			for (int j = 0; j < heroes.size(); j++) {
				if (heroes[j]->get_healthPower() != 0) { // Checks if hero is alive
					cout << endl << endl << endl << " ________" << endl;
					cout << "|        |" << endl;
					cout << "| BATTLE |" << endl;
					cout << "|________|" << endl << endl;
					heroes[j]->displayName();
					cout << ":" << endl;
					cout << "a - Attack" << endl;
					cout << "s - Attack with a spell" << " (" << heroes[j]->numberOfSpells() << " spells in inventory)" << endl;
					cout << "u - Use a potion" << " (" << heroes[j]->numberOfPotions() << " potions in inventory)" << endl;
					cout << "v - Change weapons or armor" << " (" << heroes[j]->numberOfWeapons() << " weapons and " << heroes[j]->numberOfArmors() << " armors in inventory)" << endl << endl;

					cout << "Enter your input: ";

					char ch;
					cin >> ch;
					while ((ch != 'a') && (ch != 's') && (ch != 'u') && (ch != 'v')) { // Checks if input is valid
						cin.ignore(256, '\n');  // Ignores all characters till new line
						cout << "Bad input! Try again: ";

						cin >> ch;
					}
					cin.ignore(256, '\n'); // Ignores all characters till new line

					for (int cs = 0; cs < 100; cs++) { // Clears screen
						cout << endl;
					}

					int opponent = -1; // Chosen monster to check if he has died after attack
					switch(ch) {
						case 'a':
							opponent = chooseOpponent(monsters, monstersAlive); // Chooses opponent

							attack(heroes[j], monsters[opponent]);// Attacks

							break;

						case 's':
							opponent = chooseOpponent(monsters, monstersAlive); // Chooses opponent

							castSpell(heroes[j], monsters[opponent]);// Attacks with a spell

							break;

						case 'u':
							heroes[j]->use(); // Uses potion

							break;

						case 'v':
							heroes[j]->equip(); // Equips weapons or armor

							break;
					}

					if (opponent != -1) { // Checks if there was a monster selected and attacked
						if (monsters[opponent]->get_healthPower() == 0) { // Checks if monster has died after attack
							cout << "Nice one! ";
							monsters[opponent]->displayName();
							cout << " died!" << endl;

							monstersAlive--;
							if (monstersAlive == 0) { // Checks if all monsters are dead

								break;
							}
						}
					}
					
					cout << endl;
				}
			}
		}

		else {
			cout << "Monsters' turn!" << endl << endl;
			if (checkDisplayStats() == true) {
				
				displayStats(heroes, monsters);
			}

			for (int j = 0; j < monsters.size(); j++) {
				if (monsters[j]->get_healthPower() != 0) { // Checks if monster is alive
					int opponent = rand() % (heroes.size()); // Gets a random hero to deal damage

					while (heroes[opponent]->get_healthPower() == 0) { // Checks if random hero is dead
						opponent = rand() % (heroes.size()); // Gets another random hero
					}

					heroes[opponent]->attacked(monsters[j]); // Attacks

					if (heroes[opponent]->get_healthPower() == 0) { // Checks if hero has died after attack
						cout << "Oh no! ";
						heroes[opponent]->displayName();
						cout << " died!";

						heroesAlive--;
						if (heroesAlive == 0) { // Checks if all heroes are dead

							break;
						}
					}

					cout << endl;
				}
			}
		}

		for (int j = 0; j < heroes.size(); j++) { // Regenerates healthPower and magicPower of alive heroes
			if (heroes[j]->get_healthPower() != 0) {

				heroes[j]->regenerateHP(5);
				heroes[j]->regenerateMP(5);
			}
		}

		for (int j = 0; j < monsters.size(); j++) { // Regenerates healthPower of alive monsters and reduces rounds from spell effects
			if (monsters[j]->get_healthPower() != 0) {
				monsters[j]->reduceRounds(1);
				monsters[j]->regenerateHP(5);
			}
		}
	}

	if (monstersAlive == 0) {
		cout << endl << "Heroes won!";

		int cheering = rand() % 4;
		if (cheering == 0) {

			cout << " Congratulations!" << endl << endl;
		}

		else if (cheering == 1) {

			cout << " GG WP!" << endl << endl;
		}

		else if (cheering == 2) {

			cout << " Nicely done!" << endl << endl;
		}

		else if (cheering == 3) {

			cout << " Nailed it!" << endl << endl;
		}

		int heroesLevels = 0;
		for (int he = 0; he < heroes.size(); he++) {

			heroesLevels += heroes[he]->get_level();
		}

		int monstersLevels = 0;
		for (int mo = 0; mo < monsters.size(); mo++) {

			monstersLevels += monsters[mo]->get_level();
		}

		for (int won = 0; won < heroes.size(); won++) {

			heroes[won]->win(heroes.size(), monsters.size(), heroesLevels, monstersLevels);
		}
		
		return 0;
	}

	else {
		cout << endl << "Monsters won!";

		int sad = rand() % 4;
		if (sad == 0) {
			cout << " Better luck next time!" << endl << endl;
		}

		else if (sad == 1) {
			cout << " Ouch!" << endl << endl;
		}

		else if (sad == 2) {
			cout << " Oops!" << endl << endl;
		}

		else if (sad == 3) {
			cout << " :/" << endl << endl;
		}

		for (int lost = 0; lost < heroes.size(); lost++) {

			heroes[lost]->lose();
		}

		return 1;
	}
}

bool Common::checkDisplayStats() {
	bool answer;
	cout << "d - Display statistics" << endl;
	cout << "e - Continue" << endl << endl;

	cout << "Enter your input: ";

	char ch;
	cin >> ch;
	while ((ch != 'd') && (ch != 'e')) { // Checks if input is valid
		cin.ignore(256, '\n'); // Ignores all characters till new line
		cout << "Bad input! Try again: ";

		cin >> ch;
	}
	cin.ignore(256, '\n'); // Ignores all characters till new line

	for (int cs = 0; cs < 100; cs++) { // Clears screen
		cout << endl;
	}
	
	switch(ch) {
		case 'd':
			answer = true;
			break;

		case 'e':
			answer = false;
			break;
	}

	return answer;
}

int Common::chooseOpponent(vector<Monster*>& monsters, const int& monstersAlive) {
	cout << endl << endl << endl << " ________" << endl;
	cout << "|        |" << endl;
	cout << "| BATTLE |" << endl;
	cout << "|________|" << endl << endl;

	cout << "Choose a monster to attack: " << endl;

	int counter = 1;
	for (int k = 0; k < monsters.size(); k++) { // Displays all alive monsters
		if (monsters[k]->get_healthPower() != 0) {
			cout << counter << ". ";
			monsters[k]->displayName();
			cout << " (" << monsters[k]->get_healthPower() << "/" << monsters[k]->get_maxHealthPower() << " HP)" << endl;

			counter++;
		}
	}

	cout << endl << "Enter your input: ";

	int ch;
	cin >> ch;
	while ((ch < 1) || (ch > monstersAlive)) { // Checks if input is valid
		cin.ignore(256, '\n'); // Ignores all characters till new line
		cout << "Bad input! Try again: ";

		cin >> ch;
	}
	cin.ignore(256, '\n'); // Ignores all characters till new line

	for (int cs = 0; cs < 100; cs++) { // Clears screen
		cout << endl;
	}

	int options = 1; // Integer to count up of alive monsters till the one we chose
	int k; // Monster's position in vector to be returned
	for (k = 0; k < monsters.size(); k++) {
		if (monsters[k]->get_healthPower() != 0) {
			if (ch == options) { // The monster's position was found

				break;
			}

			else { // 'ch < options'

				options++;
			}
		}
	}
	
	return k;
}
void Common::displayStats(vector<Hero*>& heroes, vector<Monster*>& monsters) {
	int counter = 1;

	cout << endl << endl << endl << " ________" << endl;
	cout << "|        |" << endl;
	cout << "| BATTLE |" << endl;
	cout << "|________|" << endl << endl;
	cout << endl << "Choose a monster or a hero to display statistics" << endl << endl;
	cout << "0. Go back to battle" << endl;

	cout << "Heroes: " << endl;
	for (int i = 0; i < heroes.size(); i++) { // Displays names of heroes
		cout << counter << ". ";
		heroes[i]->displayName();
		cout << " (" << heroes[i]->get_healthPower() << "/" << heroes[i]->get_maxHealthPower() << " HP)" << endl;

		counter++;
	}

	cout << "Monsters: " << endl;
	for (int i = 0; i < monsters.size(); i++) { // Displays names of monsters
		cout << counter << ". ";
		monsters[i]->displayName();
		cout << " (" << monsters[i]->get_healthPower() << "/" << monsters[i]->get_maxHealthPower() << " HP)" << endl;

		counter++;
	}

	cout << endl << "Enter your input: ";

	int ch;
	cin >> ch;
	while ((ch < 0) || (ch > (heroes.size() + monsters.size()))) { // Checks if input is valid
		cin.ignore(256, '\n'); // Ignores all characters till new line
		cout << "Bad input! Try again: ";

		cin >> ch;
	}
	cin.ignore(256, '\n'); // Ignores all characters till new line

	for (int cs = 0; cs < 100; cs++) { // Clears screen
		cout << endl;
	}

	if (ch > heroes.size()) { // Checks if it is a monster to be displayed
		cout << endl << "Statistics for ";
		monsters[ch - heroes.size() - 1]->displayName();
		cout << ":" << endl << endl;
		monsters[ch - heroes.size() - 1]->displayStats();
	}

	else if ((ch <= heroes.size()) && (ch > 0)) { // Checks if it is a hero to be displayed
		cout << endl << "Statistics for ";
		heroes[ch - 1]->displayName();
		cout << ":" << endl << endl;;
		heroes[ch - 1]->displayStats();
	}

	else { // 'ch == 0'

		return;
	}

	displayStats(heroes, monsters);
}

void Common::attack(Hero*& hero, Monster*& monster) {

	monster->attacked(hero); 
}

void Common::castSpell(Hero*& hero, Monster*& monster) {

	monster->spellAttacked(hero);
}