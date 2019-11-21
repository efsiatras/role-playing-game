#ifndef EXOSKELETON_H
#define EXOSKELETON_H

#include <string>

#include "monster.h"

class Exoskeleton : public Monster {
	public:
		Exoskeleton(const std::string&, const int&, const int&, const int&, const int&, const int&, const int&); // Constructor with custom initialization
		Exoskeleton(const std::string&, const int& = 1); // Constructor with initialization based on level and role

		~Exoskeleton(); // Destructor

		void displayName() const;
};

#endif