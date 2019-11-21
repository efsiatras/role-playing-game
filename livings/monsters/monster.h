#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <cstdlib>

#include "../living.h"

class Hero;

class Monster : public Living {
	private:
		int minDamage; // Minimum damage of the monster
		int maxDamage; // Maximum damage of the Monster

		int defence; // Defence value of the monster
		int agility; // Agility value of the hero

		int redDam; // Effect from ice spell ; Reduces damage
		int roundsDam;

		int redDef; // Effect from fire spell ; Reduces defence
		int roundsDef;

		int redAgi; // Effect from fire spell ; Reduces agility
		int roundsAgi;

	public:
		Monster(const std::string&, const int&, const int&, const int&, const int&, const int&, const int&); // Constructor with custom initialization
		Monster(const std::string&, const int& = 1); // Constructor with initialization based on level and role

		~Monster(); // Destructor

		void displayStats() const;

		void reduceRounds(const int&);

		int attacks();
		void attacked(Hero*&);

		void spellAttacked(Hero*&);
};

#endif