/**
 * \file Armor.hpp
 * \class Armor
 * \brief Armor class for FuzzyOctoNemesis
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Define the abstract class Armor 
 *
 */

#ifndef ARMOR_HPP
#define ARMOR_HPP

class Armor : public Equipement
{
	public:
	    Armor();
	    ~Armor();
		virtual bool isArmor();
};

#endif

