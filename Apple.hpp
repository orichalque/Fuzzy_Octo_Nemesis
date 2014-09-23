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

#ifndef __APPLE_HPP__
#define __APPLE_HPP__

#include <cassert>
#include <string>

class Apple : public Misc
{
	public:
		Apple();
		~Apple();

		int use() const;
};

#endif

