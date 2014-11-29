/**
 * \file Golem.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Boss for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */
 class Golem : public Monster {
    public: 
	Golem() {
		Character::desc_ = "Un Golem de pierre d'au moins cinq mètres de haut !";
		Character::name_ = "Golem";
		Character::attack_ = 37;
		Character::def_ = 40;
		Character::life_ = 150;
		Character::dext_ = 19;
		Character::symbol_ = 'G';
		Monster::lootList = {8, 13, 18, 23};
	}
	
	bool isBoss() {
		return true;
	}
};
