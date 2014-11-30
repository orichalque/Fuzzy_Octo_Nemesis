/**
 * \file Monster.hpp
 * \brief Define the monsters for F.O.Nemesis
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Monster abstract Class Definition for FuzzyOctoNemesis, can fight and drop item with random probability
 *
 */

#ifndef MONSTER_HPP
#define MONSTER_HPP

class Monster : public Character {
	protected:
		std::vector<int> lootList; /*!< array of item */
		int nbLoot; /*!<number of item the monster will have*/
		int lootPb; /*!<loot probability of an item.*/
		
	public:
		//constructor
		Monster();
		~Monster();
		
		//getter
		virtual std::vector<int> getLootList();
		virtual int getNbLoot();
		virtual int getLootPb();		
		virtual	bool isBoss();
		virtual bool isFinalBoss();
};

#endif 
