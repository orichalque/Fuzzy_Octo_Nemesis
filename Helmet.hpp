/*
* Helmet Class Definition for FuzzyOctoNemesis 
*
* C++ 11
*
* OPEN SOURCE @ https://github.com/orichalque/Fuzzy_Octo_Nemesis
* @author BEZIERS LA FOSSE Thibault 
* @author MERLET Corentin
* @version 1.0.0a
*/

#ifndef __HELMET_HPP__
#define __HELMET_HPP__

#include <cassert>
#include <string>

class Helmet : public Armor
{
	public:
		Helmet();
		~Helmet();

		bool isHelmet() const;
};

#endif

