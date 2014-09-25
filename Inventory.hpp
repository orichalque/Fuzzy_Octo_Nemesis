/*
* Inventory Concrete class
*
* C++ 11
*
* OPEN SOURCE @ https://github.com/orichalque/Fuzzy_Octo_Nemesis
* @author BEZIERS LA FOSSE Thibault 
* @author MERLET Corentin
* @version 1.0.0a
*/

#ifndef INVENTORY.HPP
#define INVENTORY.HPP
#define NMAX 50
class Inventory {
	protected:
		int itemNb;
		Item *items[NMAX];
		int amount;
	
	public: 
		Inventory():
		~Inventory();
		void addItem(Item *item);	
		void dropItem(Item *item);
		Item* useItem(Item *item);
		
}


