/*
* Shield Class Definition for FuzzyOctoNemesis 
*
* C++ 11
*
* OPEN SOURCE @ https://github.com/orichalque/Fuzzy_Octo_Nemesis
* @author BEZIERS LA FOSSE Thibault 
* @author MERLET Corentin
* @version 1.0.0a
*/

#ifndef Shield_HPP
#define Shield_HPP

class Shield : public Equipement {
	public:
	    ~Shield();
		virtual bool isShield();
		virtual bool isEquipement();
		
};

#endif

