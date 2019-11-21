#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <vector>

#include "../livings/heroes/hero.h"
#include "../livings/monsters/monster.h"


class Common {
	
	private:
			
		int x;
		int y;
		
	public:
		
		Common(int i=0 , int j=0);	//Constructor
		~Common();	//Destructor
		
		bool checkDisplayStats();
		int chooseOpponent(std::vector<Monster*>&, const int&);
		void displayStats(std::vector<Hero*>&, std::vector<Monster*>&);
		void attack(Hero*& hero, Monster*& monster);
		void castSpell(Hero*& hero, Monster*& monster);
		int battle(std::vector<Hero*>& hereos, std::vector<Monster*>& monsters);
		
};
#endif