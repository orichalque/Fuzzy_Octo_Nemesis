/**
 * \file Item.hpp
 \class Item
 * \brief Abstract mother-class defining the items
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Define all the basic methods used by equipement and consummable classes
 *
 */

#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include <cassert>
#include <string>

class Item /* Abstract class */
{
	public:
		virtual std::string getName(); 
		virtual std::string getDescription();
		virtual int getValue();
		virtual bool isConsumable();
		virtual bool isSettable();
		virtual bool isEquipement();

	protected:
		std::string name_; /*!< Name of the item */
		std::string desc_; /*!< Description of the item*/
		int value_; /*!< Value of the item, for selling. Not implemented*/
		int id_; /*!< Id of the item*/
		bool consumable_;/*!< boolean telling if consumable or not*/
		bool settable_;/*!< boolean telling if settable or not*/
};

#endif

