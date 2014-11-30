/**
 * \file Weapon.hpp
 * \class Weapon
 * \brief Weapon abstract class
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Define the Weapon class, inherited by all the weapon equipements, used for fights
 *
 */

#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

class Weapon : public Equipement /* Abstract class */
{
	public:
	    Weapon();
	    ~Weapon();
		virtual bool isWeapon();
};

#endif

