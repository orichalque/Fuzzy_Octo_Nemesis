/**
 * \file Item.hpp
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
		std::string name_;
		std::string desc_;
		int value_;
		int id_;
		bool consumable_;
		bool settable_;
};

#endif

