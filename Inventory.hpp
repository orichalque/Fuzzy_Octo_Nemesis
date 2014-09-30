/*
* Inventory Concrete class. Each item have an Id that corresponds to his 
* position in the item pointer array
* C++ 11
*
* OPEN SOURCE @ https://github.com/orichalque/Fuzzy_Octo_Nemesis
* @author BEZIERS LA FOSSE Thibault 
* @author MERLET Corentin
* @version 1.0.0a
*/

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include"Item.hpp"

class Inventory {
	private:
		static const int NMAX = 50;
		int itemNb; //Number of item in the bag
		Item *items[NMAX]; //Array of 50 ptrs, for 50 differents items
		int amount[NMAX]; //Number of item of 1 kind
		
	public: 
		Inventory();
		~Inventory();
		Item* getItem(int id);
		int getitemAmount(int id);
		void addItem(Item *_item);	
		void dropItem(Item *item);
		Item* useItem(Item *item);
		
};


#endif

