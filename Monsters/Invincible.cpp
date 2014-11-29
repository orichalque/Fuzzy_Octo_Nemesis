/**
 * \file Invincible.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Final Boss for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */

class Invincible : public Monster {
    public: 
	Invincible() {
		desc_ = "THE big boss";
		name_ = "L\'invincible";
		attack_ = 100;
		def_ = 100;
		life_ = 1000;
		dext_ = 50;
		Character::symbol_ = '&';
		Monster::lootList = {9, 14, 19, 24};
	}
	
	bool isBoss() {
		return true;
	}
	
	bool isFinalBoss() {
		return true;
	}
};
