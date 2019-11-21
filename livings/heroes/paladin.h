#ifndef PALADIN_H
#define PALADIN_H

#include <string>

#include "hero.h"

class Paladin : public Hero {
	public:
		Paladin(const std::string&, const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&); // Constructor with custom initialization
		Paladin(const std::string&, const int& = 1); // Constructor with initialization based on level and role

		~Paladin(); // Destructor

		void displayName() const;

		void levelUp();
};

#endif