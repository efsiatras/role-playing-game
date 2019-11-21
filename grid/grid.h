#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "common.h"
#include "market.h"
#include "nonAccessible.h"

#include "../livings/heroes/hero.h"
#include "../livings/heroes/paladin.h"
#include "../livings/heroes/sorcerer.h"
#include "../livings/heroes/warrior.h"

#include "../livings/monsters/monster.h"
#include "../livings/monsters/dragon.h"
#include "../livings/monsters/exoskeleton.h"
#include "../livings/monsters/spirit.h"
class Grid {
	
	private:
			
		int max_X;	//Maximum value of x
		int max_Y;	//Maximum value of y
		int x;
		int y;
		Market m1;
		Market m2;
		int marketCounter;	//1 for market m1, 2 for market m2, 0 for none
		std::vector<nonAccessible> nonA;	//vector to store non accessible areas
		Common blank; 
		std::vector<Hero*> h;
		std::vector<Monster*> m;

		std::ifstream heroSource;
		std::ifstream monsterSource;

		std::ifstream weaponSource;
		std::ifstream armorSource;
		std::ifstream potionSource;
		std::ifstream spellSource;
	
	public:
	
		Grid(int i=18, int j=20, int xx=0, int yy=0, int m_x=0, int m_y=0, int c_x=0, int c_y=0, int mar=0);	//Constructor
		~Grid();	//Destructor
		
		int set_hero(int check);
		int set_monster(int check);

		int set_weapon(int check1, int check2);
		int set_armor(int check1, int check2);
		int set_potion(int check1, int check2);
		int set_spell(int check, int check2);
		
		int get_max_X()const;
		int get_max_Y()const;
		
		void remove_monster();

		bool random(int i, int j);
		int start();
		void displayProfile();
		void checkInventory();
		void use();
		void equip();
		void move(int ch);
		void displayMap(int x, int y);
		int quitGame(int ch);
				
};
#endif