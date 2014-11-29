/**
 * \file Zombie.cpp
 * \brief Concrete monster
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Monster for FuzzyOctoNemesis. Can be found in the dungeon
 *
 */
 class Zombie : public Monster {
    public: 
	Zombie() {
		Character::desc_ = "Un zombie ... Il danse ?!";
		Character::name_ = "Zombie";
		Character::symbol_ = 'Z';
		Character::attack_ = 34;
		Character::def_ = 36;
		Character::life_ = 120;
		Character::dext_ = 23;
		Monster::lootList = {6 ,23};
	}
};
