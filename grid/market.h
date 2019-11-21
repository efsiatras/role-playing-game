#ifndef MARKET_H
#define MARKET_H

#include <iostream>
#include <vector>

#include "../items/item.h"
#include "../items/weapon.h"
#include "../items/armor.h"
#include "../items/potion.h"
#include "../spells/firespell.h"
#include "../spells/icespell.h"
#include "../spells/lightingspell.h"
#include "../livings/heroes/hero.h"

class Market {
	
	private:
		
		int x;
		int y;
		std::vector<Weapon> weapons;
		std::vector<Armor> armors;
		std::vector<Potion> potions;
		std::vector<Spell*> spells;	

	public:
	
		Market(int i=0, int j=0);	//Constructor
		~Market();	//Destructor
			
		void set(int i, int j);
		
		int get_x()const;
		int get_y()const;

		void insert_weapon(Weapon);
		void insert_armor(Armor);
		void insert_potion(Potion);
		void insert_spell(Spell*);

		int exchange(int x, int y, std::vector<Hero*>& heroes);
		void buy(Hero*& hero);
		void sell(Hero*& hero);

	
};
#endif

