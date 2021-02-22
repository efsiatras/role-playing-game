# Role Playing Game
Command line based Role Playing Game (RPG).

## Compilation
`$ make clean`

`$ make`

## Usage
`$ ./rpg`

## Design Decisions
There are four main classes: **Living**, **Item**, **Spell** and **Grid**.
- **Living**:
   
   There are two subclasses: **Hero** and **Monster**.
 - **Hero**: 
 
   There are three subclasses: **Warrior**, **Paladin** and **Sorcerer**.
 
   A group of Heroes is represented as a vector of pointers to Heroes. Pointers were used in order to handle all the subclasses of Heroes into one vector.

   The number of heroes are selected at the welcome screen (1 to 3).

   Heroes are read from the file "heroesANSI.txt" in the following form:
   
   `Name>;<Class Of Hero>\n`

   Heroes start from level 1 with 0 money.

 - **Monster**: 
 
   There are three subclasses: **Dragon**, **Exoskeleton** and **Spirit**.

   A group of Monsters is represented as a vector of pointers to Monsters. Pointers were used in order to handle all the subclasses of Monsters into one vector.

   The number of monsters are selected randomly (1 to 4).

   Monsters are read from the file "monstersANSI.txt" in the following form:

   `<Name>;<Class Of Monster>\n`

 - **Item**:

   There are three subclasses: **Armor**, **Weapon** and **Potion**.

   - **Armor**:

     A group of Armors is represented by their own vector of Armors.

     Armors are read from the file "armorsANSI.txt" in the following form:

     `<Name>;<Money Cost>;<Minimum Level>;<Defence>\n`

   - **Weapon**:

     A group of Weapons is represented by their own vector of Weapons.

     Weapons are read from the file "weaponsANSI.txt" in the following form:

     `<Name>;<Money Cost>;<Minimum Level>;<Damage>;<Two-Handed (= 1) Or One-Handed (= 0)>\n`

   - **Potion**:

     A group of Potions is represented by their own vector of Potions.

     Potions are read from the file "potionsANSI.txt" in the following form:

     `<Name>;<Money Cost>;<Minimum Level>;<Effect>;<Increasement>\n`

- **Spell**:
   
   There are three subclasses: **FireSpell**, **IceSpell** and **LightingSpell**.

   A group of Spells is represented as a vector of pointers to Spells. Pointers were used in order to handle all the subclasses of Spells into one vector.

   Spells are read from the file "spellsANSI.txt" in the following form:

   `<Name>;<Money Cost>;<Minimum Level>;<Minimum Damage>;<Maximum Damage>;<Mana Cost>;<Class of Spell>;<Decreasement>;<Duration In Number Of Battle Rounds>\n`

   Spells can be used infinite times.

- **Grid**:
   
   Grid contains three classes: **Common**, **nonAccessible** and **Market**.

   The map is designed and predetermined with 2 Markets.

   In battle, Heroes regenerate 5HP and 5MP, while Monsters regenerate 5HP.
 
## Contributors / Collaborators
- [Vassilis Panagakis](https://github.com/vaspan98 "Vasilis Panagakis")
- [Stathis Siatras](https://github.com/ssiatras "Stathis Siatras")
