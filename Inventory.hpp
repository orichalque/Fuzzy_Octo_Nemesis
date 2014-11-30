/**
 * \file Inventory.hpp
 * \brief Define the Inventory of the Character
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Inventory class definition, containing a list of Item. Was in the main project but were abandoned by lack of time
 * Maybe defined an other day.
 *
 */

#ifndef __INVENTORY_HPP__
#define __INVENTORY_HPP__

#include"Item.hpp"
class Inventory {
	private:
		static const int NMAX = 50; /*!< Max item amount in the inventory */
		int itemNb; /*!< number of item in the bag */
		Item *items[NMAX];  /*!< Array of 50 ptrs, for 50 differents items */
		int amount[NMAX];  /*!< Number of item of 1 kind */
		
	public: 
		Inventory();
		~Inventory();
		Item* getItem(int id);
		int getItemAmount(int id);
		void addItem(Item *_item);	
		void dropItem(Item *item);
		bool useItem(Item *item);
		
};

#endif

