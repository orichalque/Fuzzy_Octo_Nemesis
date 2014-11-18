/*
* Item Class Definition for FuzzyOctoNemesis 
*
* C++ 11
*
* OPEN SOURCE @ https://github.com/orichalque/Fuzzy_Octo_Nemesis
* @author BEZIERS LA FOSSE Thibault 
* @author MERLET Corentin
* @version 1.0.0a
*/

#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include <cassert>
#include <string>

class Item /* Abstract class */
{
	public:
		Item();
		std::string getName();
		std::string getDescription();
		int getValue();
		bool isConsumable();
		bool isSettable();
		int getId();
		virtual bool isEquipement() = 0;

	protected:
		std::string name_;
		std::string desc_;
		int value_;
		int id_;
		bool consumable_;
		bool settable_;
};

#endif

