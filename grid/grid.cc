#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>
#include <sstream>

#include "grid.h"

using namespace std;

Grid::Grid(int i, int j, int xx, int yy, int m_x, int m_y, int c_x, int c_y, int mar):m1(m_x,m_y),m2(m_x,m_y),blank(c_x,c_y),max_X(i),max_Y(j),x(xx),y(yy),marketCounter(mar),heroSource("./heroesANSI.txt"), monsterSource("./monstersANSI.txt"), weaponSource("./weaponsANSI.txt"),armorSource("./armorsANSI.txt"),potionSource("./potionsANSI.txt"),spellSource("./spellsANSI.txt"){	//Constructor of the class
	
	//cout << "A Grid was created" << endl; 
}

Grid::~Grid() {	//Destructor of the class
	//cout << "A Grid was destroyed" << endl;
	heroSource.close();
	monsterSource.close();
	weaponSource.close();
	armorSource.close();
	potionSource.close();
	spellSource.close();

	for (int i = 0; i < h.size(); i++) {
		if(h[i] != NULL) {

			delete h[i];
			h[i] = NULL;
		}
	}

	for (int i = 0; i < m.size(); i++) {
		if(m[i] != NULL) {

			delete m[i];
			m[i] = NULL;
		}
	}
}

int Grid::set_hero(int check) {
	if(!heroSource) {
		
		return 0;
	}

	string line;
	
	while ((getline(heroSource, line)) && (check != 0)) { // Gets a line of file as string
		istringstream iline(line); // An input stream to operate on string

		string name;
		if (!getline(iline, name, ';')) { // Gets name from istringstream

			return 0;
		}

		string type;
		if (!getline(iline, type)) { // Gets type from istringstream

			return 0;
		}
		
		if(type=="Paladin") 
			h.push_back(new Paladin(name));
		if(type=="Sorcerer")
			h.push_back(new Sorcerer(name));
		if(type=="Warrior")
			h.push_back(new Warrior(name));

		check--;
	}
		
			return 1;
}

int Grid::set_monster(int check) {
	if(!monsterSource) {

		return 0;
	}

	string line;
	
	while ((getline(monsterSource, line)) && (check != 0)) { // Gets a line of file as string
		istringstream iline(line); // An input stream to operate on string

		string name;
		if (!getline(iline, name, ';')) { // Gets name from istringstream

			return 0;
		}

		string type;
		if (!getline(iline, type)) { // Gets type from istringstream

			return 0;
		}
	
	
		if(type=="Dragon")
			m.push_back(new Dragon(name));
		if(type=="Exoskeleton")
			m.push_back(new Exoskeleton(name));
		if(type=="Spirit")
			m.push_back(new Spirit(name));
		
		check--;
		
	}
	
		return 1;
		
}

int Grid::set_weapon(int check1, int check2) {
	if(!weaponSource) {

		return 0;
	}

	string line;
	
	while ((getline(weaponSource, line)) && ((check1 + check2) != 0)) { // Gets a line of file as string
		istringstream iline(line); // An input stream to operate on string

		string name;
		if (!getline(iline, name, ';')) { // Gets name from istringstream

			return 0;
		}

		string price;
		if (!getline(iline, price, ';')) { // Gets price from istringstream

			return 0;
		}

		string minLvl;
		if (!getline(iline, minLvl, ';')) { // Gets price from istringstream

			return 0;
		}

		string damage;
		if (!getline(iline, damage, ';')) { // Gets damage from istringstream

			return 0;
		}

		string handsReq;
		if (!getline(iline, handsReq)) { // Gets handsReq from istringstream

			return 0;
		}

		if (check1 != 0) {
			m1.insert_weapon(Weapon(name, atoi(price.c_str()), atoi(minLvl.c_str()), atoi(damage.c_str()), atoi(handsReq.c_str())));

			check1--;
		}

		else {
			m2.insert_weapon(Weapon(name, atoi(price.c_str()), atoi(minLvl.c_str()), atoi(damage.c_str()), atoi(handsReq.c_str())));

			check2--;
		}
	}
		
			return 1;
}

int Grid::set_armor(int check1, int check2) {
	if(!armorSource) {
		
		return 0;
	}

	string line;
	
	while ((getline(armorSource, line)) && ((check1 + check2) != 0)) { // Gets a line of file as string
		istringstream iline(line); // An input stream to operate on string

		string name;
		if (!getline(iline, name, ';')) { // Gets name from istringstream

			return 0;
		}

		string price;
		if (!getline(iline, price, ';')) { // Gets price from istringstream

			return 0;
		}

		string minLvl;
		if (!getline(iline, minLvl, ';')) { // Gets price from istringstream

			return 0;
		}

		string reDam;
		if (!getline(iline, reDam)) { // Gets reDam from istringstream

			return 0;
		}

		if (check1 != 0) {
			m1.insert_armor(Armor(name, atoi(price.c_str()), atoi(minLvl.c_str()), atoi(reDam.c_str())));

			check1--;
		}

		else {
			m2.insert_armor(Armor(name, atoi(price.c_str()), atoi(minLvl.c_str()), atoi(reDam.c_str())));

			check2--;
		}
	}
		
			return 1;
}

int Grid::set_potion(int check1, int check2) {
	if(!potionSource) {
		
		return 0;
	}

	string line;
	
	while ((getline(potionSource, line)) && ((check1 + check2) != 0)) { // Gets a line of file as string
		istringstream iline(line); // An input stream to operate on string

		string name;
		if (!getline(iline, name, ';')) { // Gets name from istringstream

			return 0;
		}

		string price;
		if (!getline(iline, price, ';')) { // Gets price from istringstream

			return 0;
		}

		string minLvl;
		if (!getline(iline, minLvl, ';')) { // Gets price from istringstream

			return 0;
		}

		string stat;
		if (!getline(iline, stat, ';')) { // Gets stat from istringstream

			return 0;
		}

		string statInc;
		if (!getline(iline, statInc)) { // Gets statInc from istringstream

			return 0;
		}

		if (check1 != 0) {
			m1.insert_potion(Potion(name, atoi(price.c_str()), atoi(minLvl.c_str()), stat, atoi(statInc.c_str())));

			check1--;
		}

		else {
			m2.insert_potion(Potion(name, atoi(price.c_str()), atoi(minLvl.c_str()), stat, atoi(statInc.c_str())));

			check2--;
		}
	}
		
			return 1;
}

int Grid::set_spell(int check1, int check2) {
	if(!spellSource) {
		
		return 0;
	}

	string line;
	
	while ((getline(spellSource, line)) && ((check1 + check2) != 0)) { // Gets a line of file as string
		istringstream iline(line); // An input stream to operate on string

		string name;
		if (!getline(iline, name, ';')) { // Gets name from istringstream

			return 0;
		}

		string price;
		if (!getline(iline, price, ';')) { // Gets price from istringstream

			return 0;
		}

		string minLvl;
		if (!getline(iline, minLvl, ';')) { // Gets minLvl from istringstream

			return 0;
		}

		string minDam;
		if (!getline(iline, minDam, ';')) { // Gets minDam from istringstream

			return 0;
		}

		string maxDam;
		if (!getline(iline, maxDam, ';')) { // Gets maxDam from istringstream

			return 0;
		}

		string magicPowReq;
		if (!getline(iline, magicPowReq, ';')) { // Gets magicPowReq from istringstream

			return 0;
		}

		string identity;
		if (!getline(iline, identity, ';')) { // Gets identity from istringstream

			return 0;
		}

		string effect;
		if (!getline(iline, effect, ';')) { // Gets effect from istringstream

			return 0;
		}

		string rounds;
		if (!getline(iline, rounds)) { // Gets rounds from istringstream

			return 0;
		}

		if (check1 != 0) {
			if(identity=="firespell") 
				m1.insert_spell(new FireSpell(name, atoi(price.c_str()), atoi(minLvl.c_str()), atoi(minDam.c_str()), atoi(maxDam.c_str()), atoi(magicPowReq.c_str()), atoi(effect.c_str()), atoi(rounds.c_str())));
			else if(identity=="icespell")
				m1.insert_spell(new IceSpell(name, atoi(price.c_str()), atoi(minLvl.c_str()), atoi(minDam.c_str()), atoi(maxDam.c_str()), atoi(magicPowReq.c_str()), atoi(effect.c_str()), atoi(rounds.c_str())));
			else if(identity=="lightingspell")
				m1.insert_spell(new LightingSpell(name, atoi(price.c_str()), atoi(minLvl.c_str()), atoi(minDam.c_str()), atoi(maxDam.c_str()), atoi(magicPowReq.c_str()), atoi(effect.c_str()), atoi(rounds.c_str())));

			check1--;
		}

		else {
			if(identity=="firespell") 
				m2.insert_spell(new FireSpell(name, atoi(price.c_str()), atoi(minLvl.c_str()), atoi(minDam.c_str()), atoi(maxDam.c_str()), atoi(magicPowReq.c_str()), atoi(effect.c_str()), atoi(rounds.c_str())));
			else if(identity=="icespell")
				m2.insert_spell(new IceSpell(name, atoi(price.c_str()), atoi(minLvl.c_str()), atoi(minDam.c_str()), atoi(maxDam.c_str()), atoi(magicPowReq.c_str()), atoi(effect.c_str()), atoi(rounds.c_str())));
			else if(identity=="lightingspell")
				m2.insert_spell(new LightingSpell(name, atoi(price.c_str()), atoi(minLvl.c_str()), atoi(minDam.c_str()), atoi(maxDam.c_str()), atoi(magicPowReq.c_str()), atoi(effect.c_str()), atoi(rounds.c_str())));

			check2--;
		}
	}
		
			return 1;
}

int Grid::get_max_X()const { // Function that returns maximum value of x

	return max_X;
	
}

int Grid::get_max_Y()const { // Function that returns maximum value of y

	return max_Y;
	
}

void Grid::remove_monster() {
	int numberMonsters = m.size();

	for(int i=0; i < numberMonsters; i++) {
		delete m[m.size() - 1];
		m[m.size() - 1] = NULL;
		m.pop_back();
	}
}

void Grid::displayMap(int x, int y) { // Function that displays the grid
	cout << endl << endl << endl << " _____________" << endl;
	cout << "|             |" << endl;
	cout << "| MAIN SCREEN |" << endl;
	cout << "|_____________|" << endl << endl;



	cout << "Controller setup: " << endl << endl;
	
	cout << "w/a/s/d - Move" << endl;
	cout << "p - View heroes' profiles" << endl;
	cout << "c - View heroes' inventories" << endl;
	cout << "u - Use a potion" << endl;
	cout << "e - Equip an item" << endl;
	cout << "q - Quit game" << endl << endl;
	
	int row,col; // row,column
	
	for(col=0; col < max_Y; col++) // Print upper side of grid									
		cout << "*";														
	
		cout << endl;
		
		for(row=0; row < max_X; row++){
		
			for(col=0; col < max_Y; col++){						
	
				if (col==0) // Print left side of grid					
					putchar('*');
				
				if (col==y && row==x){					
					
					putchar ('H'); // Print 'H' to display heroes' moves
					continue;
				
				}

				if(row==(max_X - 16) && col==(max_Y - 9)){
					
					m1.set(row,col); // Print 'm' to display upper market 
					putchar ('m');
					continue;

				}
				
				if(row==(max_X - 3) && col==(max_Y - 17)){
					
					m2.set(row,col); // Print 'm' to display lower market
					putchar ('m');
					continue;
												
				}
				
				if ((row==(max_X - 5) || row==(max_X - 4) || row==(max_X - 3)) && (col==(max_Y - 8))){					
					
					nonAccessible area1; // First non accessible area				
					area1.set(row,col);
					nonA.push_back(area1);
					continue;																						
					
				}
				
				if (row==(max_X - 7) && (col==(max_Y - 16) || col==(max_Y - 17)|| col==(max_Y - 18))){					
					
					nonAccessible area2; // Second non accessible area				
					area2.set(row,col);
					nonA.push_back(area2);
					continue;																						
					
				}
				
				if ((row==(max_X - 15) || row==(max_X - 16) || row==(max_X - 17)) &&  col==(max_Y - 15)){					
					
					nonAccessible area3; // Third non accessible area				
					area3.set(row,col);
					nonA.push_back(area3);
					continue;																						
					
				}
				
				if (row==(max_X - 12) && (col==(max_Y - 9) || col==(max_Y - 8)|| col==(max_Y - 7))){					
					
					nonAccessible area4; // Fourth non accessible area				
					area4.set(row,col);
					nonA.push_back(area4);
					continue;																						
					
				}
				
				if (col!=0 || col < max_Y-1){
					
					putchar(' '); // Print a blank space to display a 'common' area
					
				}						
			
				if (col==max_Y-3) // Print right side of grid					
					putchar('*');
				
			}		
					
				cout << endl;							
	
	}
	   
				for(col=0; col < max_Y; col++) // Print lower side of grid								
					cout << "*";
    
					cout << endl;
					
}

int Grid::start() {
	for (int cs = 0; cs < 100; cs++) { // Clears screen
		cout << endl;
	}

cout << "  |\\                     /)" << endl;
cout << " /\\_\\\\__               (_//" << endl;
cout << "|   `>\\-`     _._       //`)" << endl;
cout << " \\ /` \\\\  _.-`:::`-._  //" << endl;
cout << "  `    \\|`    :::    `|/" << endl;
cout << "        |     :::     |" << endl;
cout << "        |.....:::.....|" << endl;
cout << "        |:::::::::::::|" << endl;
cout << "        |     :::     |" << endl;
cout << "        \\     :::     /" << endl;
cout << "         \\    :::    /" << endl;
cout << "          `-. ::: .-'" << endl;
cout << "           //`:::`\\" << endl;
cout << "          //   '   \\" << endl;
cout << "         |/         \\" << endl;

	cout << endl << endl << " ________________" << endl;
	cout << "|                |" << endl;
	cout << "| WELCOME SCREEN |" << endl;
	cout << "|________________|" << endl << endl;

	cout << "Welcome! Choose the number of your heroes (1 - 3)" << endl;

	cout << endl << "Enter your input: ";

	int number;
	cin >> number;
	while ((number < 1) || (number > 3)) { // Checks if input is valid
		cin.ignore(256, '\n'); // Ignores all characters till new line
		cout << "Bad input! Try again: ";

		cin >> number;
	}
	cin.ignore(256, '\n'); // Ignores all characters till new line

	for (int cs = 0; cs < 100; cs++) { // Clears screen
		cout << endl;
	}

	if (!set_hero(number)) { 

		return 0;
	}

	if (!set_weapon(3, 7)) { // 3 weapons in the first market ; 7 weapons in the second market

		return 0;
	}

	if (!set_armor(3, 7)) { // 3 armors in the first market ; 7 armors in the second market

		return 0;
	}

	if (!set_potion(3, 7)) { // 3 potions in the first market ; 7 potions in the second market

		return 0;
	}

	if (!set_spell(3, 7)) { // 3 spells in the first market ; 7 spells in the second market

		return 0;
	}

	move('\n');

	char ch;

	do {
		cout << endl << "Enter your input: ";
		cin >> ch;

		while ((ch != 'd') && (ch != 'a') && (ch != 'w') && (ch != 's') && (ch != 'p') && (ch != 'c') && (ch != 'u') && (ch != 'e') && (ch != 'q')) { // Checks if input is valid
			cin.ignore(256, '\n');  // Ignores all characters till new line
			cout << "Bad input! Try again: ";

			cin >> ch;
		}
		cin.ignore(256, '\n'); // Ignores all characters till new line

		for (int cs = 0; cs < 100; cs++) { // Clears screen
			cout << endl;
		}
			
		switch(ch) {
			case 'd':
				move(ch);
				
				break;

			case 'a':
				move(ch);
				
				break;

			case 'w':
				move(ch);
				
				break;

			case 's':
				move(ch);
				
				break;

			case 'p':
				this->displayProfile();
				this->displayMap(x,y);
				
				break;

			case 'c':
				this->checkInventory();
				this->displayMap(x,y);
				
				break;
				
			case 'u':
				this->use();
				this->displayMap(x,y);
				
				break;
				
			case 'e':
				this->equip();
				this->displayMap(x,y);
				
				break;
		}
	}
		
	while(!quitGame(ch));

	return 1;
}

void Grid::move(int ch) { // Functions that determines the moves of heroes using w,a,s,d keyboard keys 

	if (ch=='\n'){ // If given character is 'enter' key
	
		if(marketCounter == 1){	// Heroes retain position when they leave market m1
			
			x=m1.get_x();
			y=m1.get_y();
			getchar();
		
		}
		else if(marketCounter==2){ // Heroes retain position when they leave market m2
			
			x=m2.get_x();
			y=m2.get_y();
			getchar();
		
		}
	
	}
	
	if (ch=='d' && y >= 0 && y < max_Y - 3){ // If given character is 'd' and heroes remain inside the limits of the grid
		
		for (vector<nonAccessible>::iterator it = nonA.begin() ; it != nonA.end(); ++it)
				y=it->block(x,y,'d'); // Don't access the blocked areas
						
						y+=1; // Move one step to the right
						
						if(random(x,y)==1) { // If random() functions returns 1, battle begins
							set_monster((rand() % 4) + 1); // Add monsters
							blank.battle(h,m);
							remove_monster(); // Remove monsters
						}
						
						if(m1.exchange(x,y,h)==1) // If heroes are currently in market m1
							marketCounter=1;
							
						if(m2.exchange(x,y,h)==1) // If heroes are currently in market m2
							marketCounter=2;
												
	}
	
	if (ch=='d' && y >= max_Y - 3){	// If given character is 'd' and heroes are in the right side of the grid
		
		y=max_Y-3; // Don't move
		
		if(random(x,y)==1) { // If random() functions returns 1, battle begins
			set_monster((rand() % 4) + 1); // Add monsters
			blank.battle(h,m);
			remove_monster(); // Remove monsters
		}
		
	}

	if (ch=='a' && y > 0 && y <= max_Y - 3){ // If given character is 'a' and heroes remain inside the limits of the grid
		
		for (vector<nonAccessible>::iterator it = nonA.begin() ; it != nonA.end(); ++it)
				y=it->block(x,y,'a'); // Don't access the blocked areas
				
						y-=1; // Move one step to the left
						
						if(random(x,y)==1) { // If random() functions returns 1, battle begins
							set_monster((rand() % 4) + 1); // Add monsters
							blank.battle(h,m);
							remove_monster(); // Remove monsters
						}
		
						if(m1.exchange(x,y,h)==1) // If heroes are currently in market m1
							marketCounter=1;
							
						if(m2.exchange(x,y,h)==1) // If heroes are currently in market m2
							marketCounter=2;
						
	}	
	
	if (ch=='a' && y <= 0){	// If given character is 'a' and heroes are in the left side of the grid
	
		y=0; //Don't move
		
		if(random(x,y)==1) { // If random() functions returns 1, battle begins
			set_monster((rand() % 4) + 1); // Add monsters
			blank.battle(h,m);
			remove_monster(); // Remove monsters
		}
	}

	if (ch=='w' && x > 0 && x < max_X){	// If given character is 'w' and heroes remain inside the limits of the grid
		
		for (vector<nonAccessible>::iterator it = nonA.begin() ; it != nonA.end(); ++it)
				x=it->block(x,y,'w'); // Don't access the blocked areas
	
						x-=1; // Move one step up
						
						if(random(x,y)==1) { // If random() functions returns 1, battle begins
							set_monster((rand() % 4) + 1); // Add monsters
							blank.battle(h,m);
							remove_monster(); // Remove monsters
						}
		
						if(m1.exchange(x,y,h)==1) // If heroes are currently in market m1
							marketCounter=1;
							
						if(m2.exchange(x,y,h)==1) // If heroes are currently in market m2
							marketCounter=2;
						
	}
	
	if (ch=='w' && x <= 0){	// If given character is 'w' and heroes are in the upper side of the grid
	
		x=0; // Don't move
		
		if(random(x,y)==1) { // If random() functions returns 1, battle begins
			set_monster((rand() % 4) + 1); // Add monsters
			blank.battle(h,m);
			remove_monster(); // Remove monsters
		}
		
	}
	
	if (ch=='s' && x >= 0 && x < max_X - 1){ // If given character is 's' and heroes remain inside the limits of the grid
	
			for (vector<nonAccessible>::iterator it = nonA.begin() ; it != nonA.end(); ++it)
				x=it->block(x,y,'s'); // Don't access the blocked areas
	
						x+=1; // Move one step down
						
						if(random(x,y)==1) { // If random() functions returns 1, battle begins
							set_monster((rand() % 4) + 1); // Add monsters
							blank.battle(h,m);
							remove_monster(); // Remove monsters
						}
			
						if(m1.exchange(x,y,h)==1) // If heroes are currently in market m1
							marketCounter=1;
							
						if(m2.exchange(x,y,h)==1) // If heroes are currently in market m2
							marketCounter=2;
						
	}
	
	if (ch=='s' && x >= max_X -1){ // If given character is 's' and heroes are in the lower side of the grid
		
		x=max_X-1; // Don't move
		
		if(random(x,y)==1) { // If random() functions returns 1, battle begins
			set_monster((rand() % 4) + 1); // Add monsters
			blank.battle(h,m);
			remove_monster(); // Remove monsters
		}
		
	}

	this->displayMap(x,y);	//Display the grid
}

void Grid::displayProfile() { // Function that displays information about the heroes
	int chosenHero;
	do {
		cout << endl << endl << endl << " _________________" << endl;
		cout << "|                 |" << endl;
		cout << "| DISPLAY PROFILE |" << endl;
		cout << "|_________________|" << endl << endl;

		cout << "Choose a hero:" << endl << endl;

		cout << "0. Go back" << endl;
		for (int i = 0; i < h.size(); i++) { // Displays names of heroes
			cout << i + 1 << ". ";
			h[i]->displayName();
			cout << endl;
		}

		cout << endl << "Enter your input: ";

		cin >> chosenHero;
		while ((chosenHero < 0) || (chosenHero > (h.size()))) { // Checks if input is valid
			cin.ignore(256, '\n'); // Ignores all characters till new line
			cout << "Bad input! Try again: ";

			cin >> chosenHero;
		}
		cin.ignore(256, '\n'); // Ignores all characters till new line

		for (int cs = 0; cs < 100; cs++) { // Clears screen
			cout << endl;
		}

		if (chosenHero > 0) {
			cout << "Profile of ";
			h[chosenHero - 1]->displayName();
			cout << ":";
			cout << endl << endl;
			h[chosenHero - 1]->displayStats();
		}
	}
	while (chosenHero != 0);
}

void Grid::checkInventory() {
	int chosenHero;
	do {
		cout << endl << endl << endl << " _________________" << endl;
		cout << "|                 |" << endl;
		cout << "| CHECK INVENTORY |" << endl;
		cout << "|_________________|" << endl << endl;

		cout << "Choose a hero:" << endl << endl;

		cout << "0. Go back" << endl;
		for (int i = 0; i < h.size(); i++) { // Displays names of heroes
			cout << i + 1 << ". ";
			h[i]->displayName();
			cout << endl;
		}

		cout << endl << "Enter your input: ";

		cin >> chosenHero;
		while ((chosenHero < 0) || (chosenHero > (h.size()))) { // Checks if input is valid
			cin.ignore(256, '\n'); // Ignores all characters till new line
			cout << "Bad input! Try again: ";

			cin >> chosenHero;
		}
		cin.ignore(256, '\n'); // Ignores all characters till new line

		for (int cs = 0; cs < 100; cs++) { // Clears screen
			cout << endl;
		}

		if (chosenHero > 0) {

			h[chosenHero-1]->checkInventory();
		}
	}
	while (chosenHero != 0);
}

void Grid::use() { // Function to use potion
	int chosenHero;
	do {
		cout << endl << endl << endl << " ____________" << endl;
		cout << "|            |" << endl;
		cout << "| USE POTION |" << endl;
		cout << "|____________|" << endl << endl;

		cout << "Choose a hero:" << endl << endl;

		cout << "0. Go back" << endl;
		for (int i = 0; i < h.size(); i++) { // Displays names of heroes
			cout << i + 1 << ". ";
			h[i]->displayName();
			cout << " (" << h[i]->numberOfPotions() << " potions in inventory)" << endl;
		}

		cout << endl << "Enter your input: ";

		cin >> chosenHero;
		while ((chosenHero < 0) || (chosenHero > (h.size()))) { // Checks if input is valid
			cin.ignore(256, '\n'); // Ignores all characters till new line
			cout << "Bad input! Try again: ";

			cin >> chosenHero;
		}
		cin.ignore(256, '\n'); // Ignores all characters till new line

		for (int cs = 0; cs < 100; cs++) { // Clears screen
			cout << endl;
		}
		
		if (chosenHero > 0) {

			h[chosenHero-1]->use();
		}
	}
	while (chosenHero != 0);
}

void Grid::equip() { // Functon to equip
	int chosenHero;

	do {
		cout << endl << endl << endl << " _______" << endl;
		cout << "|       |" << endl;
		cout << "| EQUIP |" << endl;
		cout << "|_______|" << endl << endl;

		cout << "Choose a hero:" << endl << endl;

		cout << "0. Go back" << endl;
		for (int i = 0; i < h.size(); i++) { // Displays names of heroes
			cout << i + 1 << ". ";
			h[i]->displayName();
			cout << " (" << h[i]->numberOfWeapons() << " weapons and " << h[i]->numberOfArmors() << " armors in inventory)" << endl;
		}

		cout << endl << "Enter your input: ";

		cin >> chosenHero;
		while ((chosenHero < 0) || (chosenHero > (h.size()))) { // Checks if input is valid
			cin.ignore(256, '\n'); // Ignores all characters till new line
			cout << "Bad input! Try again: ";

			cin >> chosenHero;
		}
		cin.ignore(256, '\n'); // Ignores all characters till new line

		for (int cs = 0; cs < 100; cs++) { // Clears screen
			cout << endl;
		}

		if (chosenHero > 0) {
			h[chosenHero-1]->equip();
		}
	}
	while (chosenHero != 0);
}

bool Grid::random(int i, int j) {	//Boolean function that decides randomly the possibility of a battle
	
	int r,r1,r2;

	srand(time(NULL));
	
	r=rand();
	
	for(int k=0; k < nonA.size(); k++){
		
		vector<int> nonA_x=nonA[k].get_x();
		vector<int> nonA_y=nonA[k].get_y();
		
		for(int m=0; m < nonA_x.size(); m++)
			if(nonA_x[m] != i && m1.get_x() != i && m2.get_x() != i)
				r1=i%2;			
	
		for(int n=0; n < nonA_y.size(); n++)
			if(nonA_y[n] != j && m1.get_y() != j && m2.get_y() != j)
				r2=j%2;			
	
	}
			
			if((r%2 == 1) && (r1 == 1) && (r2 == 1))
				return 1;
			else 			
				return 0;	
	
}

int Grid::quitGame(int ch) { //Function that returns 0, when user exits game	
	if(ch == 'q') {
		char ch2;
		cout << endl << endl << endl << " _____________" << endl;
		cout << "|             |" << endl;
		cout << "| QUIT SCREEN |" << endl;
		cout << "|_____________|" << endl << endl;

		cout << "Are you sure you want to quit? " << endl << endl;

		cout << "y - Yes" << endl;
		cout << "n - No" << endl;

		cout << endl << "Enter your input: ";
		
		cin >> ch2;
		while ((ch2 != 'n') && (ch2 != 'y')) { // Checks if input is valid
			cin.ignore(256, '\n');  // Ignores all characters till new line
			cout << "Bad input! Try again: ";

			cin >> ch2;
		}
		cin.ignore(256, '\n'); // Ignores all characters till new line

		for (int cs = 0; cs < 100; cs++) { // Clears screen
			cout << endl;
		}

		if (ch2 == 'y') {

			return 1;
		}

		else { // ch2 == 'n'
			this->displayMap(x,y);

			return 0;
		}
	}

	else { // ch != 'q'

		return 0;
	}
}
