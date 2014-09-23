/*
* Sword Class Definition for FuzzyOctoNemesis 
*
* C++ 11
*
* OPEN SOURCE @ https://github.com/orichalque/Fuzzy_Octo_Nemesis
* @author BEZIERS LA FOSSE Thibault 
* @author MERLET Corentin
* @version 1.0.0a
*/

#ifndef __SWORD_HPP__
#define __SWORD_HPP__

#include <cassert>
#include <string>

class Sword : public Weapon
{
	public:
		Sword();
		~Sword();
		virtual int attack() const;
};

#endif

