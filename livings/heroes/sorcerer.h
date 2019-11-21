#ifndef SORCERER_H
#define SORCERER_H

#include <string>

#include "hero.h"

class Sorcerer : public Hero {
	public:
		Sorcerer(const std::string&, const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&); // Constructor with custom initialization
		Sorcerer(const std::string&, const int& = 1); // Constructor with initialization based on level and role

		~Sorcerer(); // Destructor

		void displayName() const;
		
		void levelUp();
};

#endif