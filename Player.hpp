/*
* Player abstract Class Definition for FuzzyOctoNemesis
* Implements principal player methods
*
* C++ 11
*
* OPEN SOURCE @ https://github.com/orichalque/Fuzzy_Octo_Nemesis
* @author BEZIERS LA FOSSE Thibault 
* @author MERLET Corentin
* @version 1.0.0a
*/

#ifndef Player.HPP
#define Player.HPP

#include <iostream>
#include <stdlib.h> 
#include "Character.hpp"


class Player : public Character {
	protected:
		
		
	public:
		//constructor
		Player();
		~Player();
		
		//getter
		item lootList();
		int nbLoot();
		virtual int lootPb() = 0;		
		
		//methods
		Item loot(void); //Return an item from the dropList
	
}

#include "Player.cpp"
#endif 
