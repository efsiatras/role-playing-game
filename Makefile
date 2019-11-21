CC= g++
CFLAGS=-g

OBJECTS=rpg.o common.o market.o nonAccessible.o grid.o living.o hero.o paladin.o sorcerer.o warrior.o monster.o dragon.o exoskeleton.o spirit.o spell.o firespell.o icespell.o lightingspell.o item.o weapon.o armor.o potion.o

rpg:$(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o rpg

rpg.o: rpg.cc
	$(CC) $(CFLAGS) -c rpg.cc

common.o: ./grid/common.cc
	$(CC) $(CFLAGS) -c ./grid/common.cc

market.o: ./grid/market.cc
	$(CC) $(CFLAGS) -c  ./grid/market.cc 

nonAccessible.o: ./grid/nonAccessible.cc
	$(CC) $(CFLAGS) -c ./grid/nonAccessible.cc 

grid.o: ./grid/grid.cc
	$(CC) $(CFLAGS) -c ./grid/grid.cc

living.o: ./livings/living.cc
	$(CC) $(CFLAGS) -c ./livings/living.cc

hero.o: ./livings/heroes/hero.cc
	$(CC) $(CFLAGS) -c ./livings/heroes/hero.cc

paladin.o: ./livings/heroes/paladin.cc
	$(CC) $(CFLAGS) -c ./livings/heroes/paladin.cc

sorcerer.o: ./livings/heroes/sorcerer.cc
	$(CC) $(CFLAGS) -c ./livings/heroes/sorcerer.cc

warrior.o: ./livings/heroes/warrior.cc
	$(CC) $(CFLAGS) -c ./livings/heroes/warrior.cc

monster.o: ./livings/monsters/monster.cc
	$(CC) $(CFLAGS) -c ./livings/monsters/monster.cc

dragon.o: ./livings/monsters/dragon.cc
	$(CC) $(CFLAGS) -c ./livings/monsters/dragon.cc

exoskeleton.o: ./livings/monsters/exoskeleton.cc
	$(CC) $(CFLAGS) -c ./livings/monsters/exoskeleton.cc

spirit.o: ./livings/monsters/spirit.cc
	$(CC) $(CFLAGS) -c ./livings/monsters/spirit.cc

spell.o: ./spells/spell.cc
	$(CC) $(CFLAGS) -c ./spells/spell.cc

firespell.o: ./spells/firespell.cc
	$(CC) $(CFLAGS) -c ./spells/firespell.cc

icespell.o: ./spells/icespell.cc
	$(CC) $(CFLAGS) -c ./spells/icespell.cc

lightingspell.o: ./spells/lightingspell.cc
	$(CC) $(CFLAGS) -c ./spells/lightingspell.cc

item.o: ./items/item.cc
	$(CC) $(CFLAGS) -c ./items/item.cc 

weapon.o: ./items/weapon.cc
	$(CC) $(CFLAGS) -c ./items/weapon.cc 

armor.o: ./items/armor.cc
	$(CC) $(CFLAGS) -c ./items/armor.cc 

potion.o: ./items/potion.cc
	$(CC) $(CFLAGS) -c ./items/potion.cc 

.PHONY: clean

clean:
	rm -f rpg $(OBJECTS)
