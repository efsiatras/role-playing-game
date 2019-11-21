#ifndef SPIRIT_H
#define SPIRIT_H

#include <string>

#include "monster.h"

class Spirit : public Monster {
	public:
		Spirit(const std::string&, const int&, const int&, const int&, const int&, const int&, const int&); // Constructor with custom initialization
		Spirit(const std::string&, const int& = 1); // Constructor with initialization based on level and role

		~Spirit(); // Destructor

		void displayName() const;
};

#endif