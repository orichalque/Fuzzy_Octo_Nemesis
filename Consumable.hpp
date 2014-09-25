/*
* Consumable Class Definition for FuzzyOctoNemesis 
*
* C++ 11
*
* OPEN SOURCE @ https://github.com/orichalque/Fuzzy_Octo_Nemesis
* @author BEZIERS LA FOSSE Thibault 
* @author MERLET Corentin
* @version 1.0.0a
*/

#ifndef __CONSUMABLE_HPP__
#define __CONSUMABLE_HPP__

#include <cassert>
#include <string>

class Consumable : public Item
{
	public:
		bool isConsumable() const = 0;
};

#endif

