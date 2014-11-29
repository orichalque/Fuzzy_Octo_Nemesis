/**
 * \file Harpy.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Monster for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */
 class Harpy : public Monster {
    public: 
	Harpy() {
		Character::desc_ = "Une femme-oiseau extremement rapide.";
		Character::name_ = "Harpie";
		Character::symbol_ = 'H';
		Character::attack_ = 36;
		Character::def_ = 34;
		Character::life_ = 115;
		Character::dext_ = 32;
		Monster::lootList = {13};
	}
};
