#ifndef LIVING_H
#define LIVING_H

#include <string>

class Living {
	private:
		const std::string name; // Name of the living
		int level; // Level of the living

		int healthPower; // Health energy of the living
		int maxHealthPower; // Maximum health energy of the living

	public:
		Living(const std::string&, const int& = 1, const int& = 500); // Constructor

		virtual ~Living(); // Destructor

		virtual void displayName() const;
		virtual void displayStats() const;
		
		std::string get_name() const;
		int get_healthPower() const;
		int get_maxHealthPower() const;
		int get_level() const;

		void regenerateHP(const int&);
		void gainMaxHealthPower(const int&);
		void gainLevel(const int&);

		void loseHP(const int&);

		void respawn();
};

#endif