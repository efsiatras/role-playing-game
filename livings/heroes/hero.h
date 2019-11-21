#ifndef HERO_H
#define HERO_H

#include <string>
#include <vector>

#include "../living.h"
#include "../../items/weapon.h"
#include "../../items/armor.h"
#include "../../items/potion.h"
#include "../../spells/spell.h"

class Monster;

class Hero : public Living {
	private:
		int magicPower; // Magic energy of the hero
		int maxMagicPower; // Maximum health energy of the living

		int strength; //  Strength value of the hero
		int dexterity; // Dexterity value of the hero
		int agility; // Agility value of the hero

		int money; // Money of the hero
		int experience; // Experience of the hero

		Weapon* leftHand; // Equipped weapon on left hand
		Weapon* rightHand; // Equipped weapon on right hand
		Armor* armor; // Equipped armor

		std::vector<Weapon> weaponInv; // Inventory of weapons
		std::vector<Armor> armorInv; // Inventory of armors
		std::vector<Potion> potionInv; // Inventory of potions
		std::vector<Spell*> spellInv; // Inventory of spells

	public:
		Hero(const std::string&, const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&); // Constructor with custom initialization
		Hero(const std::string&, const int& = 1); // Constructor with initialization based on level and role

		~Hero(); // Destructor

		void set_money(int mon);
		int get_money() const;
		int get_experience() const;
		int get_weaponInvSize() const;
		int get_armorInvSize() const;
		int get_potionInvSize() const;
		int get_spellInvSize() const;
		int get_weaponInvPriceSellBack(const int&) const;
		int get_armorInvPriceSellBack(const int&) const;
		int get_potionInvPriceSellBack(const int&) const;
		int get_spellInvPriceSellBack(const int&) const;
		
		void push_weaponInv(Weapon&);
		void push_armorInv(Armor&);
		void push_potionInv(Potion&);
		void push_spellInv(Spell*&);

		Weapon erase_weaponInv(const int&);
		Armor erase_armorInv(const int&);
		Potion erase_potionInv(const int&);
		Spell* erase_spellInv(const int&);	

		void displayWeaponInvSellBack(const int&) const;
		void displayArmorInvSellBack(const int&) const;
		void displayPotionInvSellBack(const int&) const;
		void displaySpellInvSellBack(const int&) const;
		void displayStats() const;

		int numberOfWeapons() const;
		int numberOfArmors() const;
		int numberOfPotions() const;
		int numberOfSpells() const;

		void win(const int&, const int&, const int&, const int&);
		void lose();

		void checkInventory() const;
		void use();
		void equip();

		virtual void levelUp();
		void gainExperience(const int&);
		void regenerateMP(const int&);
		void gainMaxMagicPower(const int&);
		void gainStrength(const int&);
		void gainDexterity(const int&);
		void gainAgility(const int&);

		int attacks();
		Spell* spellAttacks(int&);
		
		void attacked(Monster*&);
};

#endif