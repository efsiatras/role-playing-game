#ifndef DRAGON_H
#define DRAGON_H

#include <string>

#include "monster.h"

class Dragon : public Monster {
	public:
		Dragon(const std::string&, const int&, const int&, const int&, const int&, const int&, const int&); // Constructor with custom initialization
		Dragon(const std::string&, const int& = 1); // Constructor with initialization based on level and role

		~Dragon(); // Destructor

		void displayName() const;
};

#endif