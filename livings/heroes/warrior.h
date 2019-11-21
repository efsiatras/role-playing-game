#ifndef WARRIOR_H
#define WARRIOR_H

#include <string>

#include "hero.h"

class Warrior : public Hero {
	public:
		Warrior(const std::string&, const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&); // Constructor with custom initialization
		Warrior(const std::string&, const int& = 1); // Constructor with initialization based on level and role

		~Warrior(); // Destructor

		void displayName() const;
		
		void levelUp();
};

#endif