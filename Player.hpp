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
#include <cstdlib> 
#include "Character.hpp"


class Player : public Character {
	protected:
		Inventory inventory;
		Item equipement;
	public:
		//constructor
		Player();
		~Player();
		
		//getter
		Inventory inventory();
		
		//methods
		//Item methods
		void addItem(Item item);
		void useItem(Item item);
		void dropItem(Item item);
		void equipItem(Item item);
		void unequipItem(int i);
		
		//Fighting methods
		int attacking(); //return attack + att weapon stat
		int defending(); //return defense + def armor stat
	
}

#endif 
