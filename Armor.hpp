/*
* Armor Class Definition for FuzzyOctoNemesis 
*
* C++ 11
*
* OPEN SOURCE @ https://github.com/orichalque/Fuzzy_Octo_Nemesis
* @author BEZIERS LA FOSSE Thibault 
* @author MERLET Corentin
* @version 1.0.0a
*/

#ifndef ARMOR_HPP
#define ARMOR_HPP

class Armor : public Equipement
{
	public:
		virtual bool isArmor() const = 0;
};

#endif

