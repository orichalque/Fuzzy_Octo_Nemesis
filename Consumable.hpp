/**
 * \file Consumable.hpp
 * \class Consumable
 * \brief Define the consumable items
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * 
 *
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

