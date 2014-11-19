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

#ifndef HELMET_HPP
#define HELMET_HPP

class Helmet : public Equipement
{
	public:
	    Helmet();
	    ~Helmet();
		virtual bool isHelmet();
		virtual bool isEquipement();
		
};

#endif

