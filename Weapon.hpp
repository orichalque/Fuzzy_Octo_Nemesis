/*
* Weapon Class Definition for FuzzyOctoNemesis 
*
* C++ 11
*
* OPEN SOURCE @ https://github.com/orichalque/Fuzzy_Octo_Nemesis
* @author BEZIERS LA FOSSE Thibault 
* @author MERLET Corentin
* @version 1.0.0a
*/

#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <cassert>
#include <string>

class Weapon : public Equipement /* Abstract class */
{
	public:
		virtual bool isWeapon() const = 0;
};

#endif

