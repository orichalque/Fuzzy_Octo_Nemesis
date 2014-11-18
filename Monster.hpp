/*
* Monster abstract Class Definition for FuzzyOctoNemesis
* Will be able to drop item with a certain probability 
*
* C++ 11
*
* OPEN SOURCE @ https://github.com/orichalque/Fuzzy_Octo_Nemesis
* @author BEZIERS LA FOSSE Thibault 
* @author MERLET Corentin
* @version 1.0.0a
*/

#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <iostream>
#include <cstdlib> 
#include <string>
#include "Character.cpp"


class Monster : public Character {
	protected:
		//Item lootList; //array of item
		int nbLoot; //number of item the monster will have
		int lootPb; //loot probability of an item.
		
	public:
		//constructor
		Monster();
		~Monster();
		
		//getter
		//Item lootList();
		int getNbLoot();
		int getLootPb();		
		
		
		//methods
	//	Item loot(void); //Return an item from the dropList
	
};

#endif 
